#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <ranges>
#include <vector>
#include "./power_projection.hpp"

namespace fps {

namespace {

template <typename T>
FormalPowerSeries<T> transport_convolution(FormalPowerSeries<T> grad,
                                           FormalPowerSeries<T> kernel) {
    std::ranges::reverse(kernel);
    auto conv = grad * kernel;
    FormalPowerSeries<T> res(grad.size(), T(0));
    const size_t start = kernel.size() ? kernel.size() - 1 : 0;
    const size_t end = std::min(conv.size(), start + res.size());
    auto window = std::ranges::subrange(conv.begin() + std::min(start, conv.size()),
                                        conv.begin() + end);
    for (auto const &[i, val] : window | std::views::enumerate)
        res[i] = val;
    return res;
}

template <typename T>
std::vector<FormalPowerSeries<T>>
next_F_transpose(const std::vector<FormalPowerSeries<T>> &g2d,
                 const std::vector<FormalPowerSeries<T>> &g_kernel, size_t n,
                 size_t f_size_prev) {
    const size_t f_size_now = g2d.size();
    const size_t n_outer = f_size_now / 2;

    auto [_, m_kernel] = size_2d(g_kernel);
    size_t m = std::max(n, m_kernel);

    auto b = co_x(g_kernel);
    auto b_flat = flatten_2d(b, n_outer, m);

    FormalPowerSeries<T> grad_flat(2 * n_outer * m, T(0));
    for (auto const &[i, row] : g2d | std::views::enumerate)
        for (auto const &[j, val] : row | std::views::enumerate) {
            const size_t jj = 2 * j + 1;
            if (jj < 2 * m)
                grad_flat[2 * m * i + jj] = val;
        }

    auto dA_flat = transport_convolution(grad_flat, b_flat);
    auto dA_unflat = unflatten_2d(dA_flat, n_outer, m);

    std::vector<FormalPowerSeries<T>> res(
        f_size_prev, FormalPowerSeries<T>(n, T(0)));
    for (auto const &[i, row] :
         dA_unflat | std::views::take(f_size_prev) | std::views::enumerate) {
        size_t lim = std::min(n, row.size());
        for (size_t j : std::views::iota(0uz, lim))
            res[i][j] = row[j];
    }
    return res;
}

template <typename T>
FormalPowerSeries<T>
internal_power_projection_transpose(FormalPowerSeries<T> g,
                                    FormalPowerSeries<T> a) {
    const size_t n = a.size();
    if (n == 0)
        return {};
    assert(std::has_single_bit(n));
    assert(g.size() == n);

    const int log = std::countr_zero(n);
    auto g_list = fps::build_G_chain(g, log);

    std::vector<size_t> f_size(log + 1);
    f_size[0] = 1;
    for (int k = 1; k <= log; k++) {
        size_t outer = std::max(f_size[k - 1], g_list[k - 1].size());
        f_size[k] = outer * 2;
    }

    std::vector<FormalPowerSeries<T>> grad(
        f_size[log], FormalPowerSeries<T>(1, T(0)));
    for (auto const &[i, val] : a | std::views::enumerate)
        grad[i][0] = val;

    for (int k = log; k >= 1; k--)
        grad =
            next_F_transpose(grad, g_list[k - 1], n >> (k - 1), f_size[k - 1]);

    return grad[0];
}
} // namespace

template <typename T>
FormalPowerSeries<T> composition(FormalPowerSeries<T> f,
                                 FormalPowerSeries<T> g) {
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

    const size_t n2 = g.size();
    if (f.size() < n2)
        f.resize(n2, T(0));
    else
        f.strict(n2);

    const T c0 = f[0];
    f[0] = 0;

    auto weights = f;
    weights.strict(n2);

    auto res = internal_power_projection_transpose(g, weights);
    std::ranges::reverse(res);
    res.strict(n);
    if (res.size() < n)
        res.resize(n, T(0));
    res[0] += c0;
    return res;
}

} // namespace fps
