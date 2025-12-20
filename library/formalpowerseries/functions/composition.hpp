#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include "./power_projection.hpp"
#include <algorithm>
#include <bit>
#include <ranges>

namespace fps {

namespace {
template <typename T, int MX> using FPS = FormalPowerSeries<T, MX>;
template <typename T, int MX>
using FPS2D = std::vector<FPS<T, MX>>; // A[i][j] : [x^i][y^j]A

template <typename T, int MX>
FPS<T, MX> transport_convolution(FPS<T, MX> grad, FPS<T, MX> kernel) {
    /*
    conv の転置（相関）: grad と kernel の相関を、入力長さ |grad| に揃えて返す。
    実装は kernel を反転して畳み込み、その中央 |grad| 項を取り出す。
    */
    std::ranges::reverse(kernel);
    auto c = grad * kernel;
    FPS<T, MX> res(grad.size(), T(0));
    const size_t start = kernel.size() ? kernel.size() - 1 : 0;
    const size_t end = std::min(c.size(), start + res.size());
    auto window = std::ranges::subrange(c.begin() + std::min(start, c.size()),
                                        c.begin() + end);
    for (auto const &[i, val] : window | std::views::enumerate)
        res[i] = val;
    return res;
}

template <typename T, int MX>
FPS2D<T, MX> next_F_transpose(const FPS2D<T, MX> &G,
                              const FPS2D<T, MX> &G_kernel, size_t n,
                              size_t f_size_prev) {
    // transpose of next_F
    // next_F: keep odd x-terms then decimate; here we pull gradients back
    const size_t f_size_now = G.size();
    const size_t n_outer = f_size_now / 2; // conv returned 2 * n_outer rows

    auto [_, m_kernel] = size_2d(G_kernel);
    size_t m = std::max(n, m_kernel);

    auto B = co_x(G_kernel);
    auto B_flat = flatten_2d(B, n_outer, m);

    FPS<T, MX> grad_flat(2 * n_outer * m, T(0));
    for (auto const &[i, row] : G | std::views::enumerate)
        for (auto const &[j, val] : row | std::views::enumerate) {
            const size_t jj = 2 * j + 1;
            if (jj < 2 * m)
                grad_flat[2 * m * i + jj] = val;
        }

    auto dA_flat = transport_convolution(grad_flat, B_flat);
    auto dA_unflat = unflatten_2d(dA_flat, n_outer, m);

    FPS2D<T, MX> res(f_size_prev, FPS<T, MX>(n, T(0)));
    for (auto const &[i, row] :
         dA_unflat | std::views::take(f_size_prev) | std::views::enumerate) {
        size_t lim = std::min(n, row.size());
        for (size_t j : std::views::iota(0uz, lim))
            res[i][j] = row[j];
    }
    return res;
}

template <typename T, int MX>
FPS<T, MX> internal_power_projection_transpose(FPS<T, MX> g, FPS<T, MX> a) {
    /*
    Transpose of internal_power_projection.
    Args:
        g: n項 (n は 2 冪), g[0]=0 の仮定
        a: n項, 最終的に [x^{n-1}] f(x) g(x)^i に掛かる重み
    Return:
        result s.t. <a, pp(g,f)> = <result, f> を満たす線形写像値
    */
    const size_t n = a.size();
    if (n == 0)
        return {};
    assert(std::has_single_bit(n));
    assert(g.size() == n);

    const int log = std::countr_zero(n);
    auto G_list = fps::build_G_chain(g, log);

    std::vector<size_t> f_size(log + 1);
    f_size[0] = 1;
    for (int k = 1; k <= log; k++) {
        size_t outer = std::max(f_size[k - 1], G_list[k - 1].size());
        f_size[k] = outer * 2;
    }

    FPS2D<T, MX> grad(f_size[log], FPS<T, MX>(1, T(0)));
    for (auto const &[i, val] : a | std::views::enumerate)
        grad[i][0] = val;

    for (int k = log; k >= 1; k--)
        grad =
            next_F_transpose(grad, G_list[k - 1], n >> (k - 1), f_size[k - 1]);

    return grad[0];
}
} // namespace

template <typename T, int MX>
FPS<T, MX> composition(FPS<T, MX> f, FPS<T, MX> g) {
    /*
    Compute f(g(x)) up to deg n-1 where n=f.size().
    Requirements: g[0]=0, g has length >= n.
    Uses transposed power projection to evaluate all g(x)^i contributions.
    */
    const size_t n = f.size();
    if (n == 0)
        return {};
    if (n == 1) {
        f.strict(1);
        return f;
    }
    assert(g.size() >= n);
    assert(g[0] == 0);

    g.strict(n);
    g.resize(std::bit_ceil(n));

    const size_t N = g.size();
    if (f.size() < N)
        f.resize(N, T(0));
    else
        f.strict(N);

    const T c0 = f[0];
    f[0] = 0;

    auto weights = f;
    weights.strict(N);

    auto res = internal_power_projection_transpose(g, weights);
    std::ranges::reverse(res);
    res.strict(n);
    if (res.size() < n)
        res.resize(n, T(0));
    res[0] += c0;
    return res;
}

} // namespace fps
