#pragma once
#include <cmath>
#include <cstddef>
#include <utility>
#include <vector>
#include "../Base.hpp"
#include "./egf.hpp"
#include "./exp.hpp"
#include <algorithm>
#include <bit>
#include <cassert>
#include <ranges>

namespace fps {

template <typename T, int MX> using FPS = FormalPowerSeries<T, MX>;
template <typename T, int MX>
using FPS2D = std::vector<FPS<T, MX>>; // F[i][j] : [x^i][y^j]F

template <typename T, int MX>
std::pair<size_t, size_t> size_2d(const FPS2D<T, MX> &F) {
    size_t n = F.size();
    size_t m = std::ranges::max(
        F | std::views::transform([](auto const &row) { return row.size(); }));
    return {n, m};
}

template <typename T, int MX>
FPS<T, MX> flatten_2d(const FPS2D<T, MX> &F, size_t n, size_t m) {
    // f[2mi+j] = F[i][j]

    FPS<T, MX> f(2 * n * m, T{0});
    for (auto const &[i, row] : F | std::views::enumerate)
        for (auto const &[j, val] : row | std::views::enumerate)
            f[2 * m * i + j] = val;
    return f;
}

template <typename T, int MX>
FPS2D<T, MX> unflatten_2d(const FPS<T, MX> &f, size_t n, size_t m) {
    // F[i][j] = f[2mi+j]

    FPS2D<T, MX> F(2 * n, FPS<T, MX>(2 * m, T{0}));
    for (size_t i : std::views::iota(0uz, 2 * n))
        for (size_t j : std::views::iota(0uz, 2 * m))
            if (size_t index = 2 * m * i + j; index < f.size())
                F[i][j] = f[index];
    return F;
}

template <typename T, int MX>
FPS2D<T, MX> convolution_2D(const FPS2D<T, MX> &F, const FPS2D<T, MX> &G) {
    /*
    n*m 型の2 変数多項式 F(x,y), G(x,y) の積 2n*2m 型を返す
    N=nm として O(N\log N)
    */
    auto [F_n, F_m] = size_2d(F);
    auto [G_n, G_m] = size_2d(G);
    const size_t n = std::max(F_n, G_n);
    const size_t m = std::max(F_m, G_m);

    if (n == 0 || m == 0)
        return {};

    return unflatten_2d(flatten_2d(F, n, m) * flatten_2d(G, n, m), n, m);
}

template <typename T, int MX> FPS<T, MX> to_FPS(const FPS2D<T, MX> &F) {
    return F |
           std::views::transform([](const FPS<T, MX> &row) { return row[0]; }) |
           std::ranges::to<FPS<T, MX>>();
}

template <typename T, int MX> FPS2D<T, MX> negate_y(FPS2D<T, MX> F) {
    // return F(x, -y)
    for (auto &vec : F)
        for (auto &coef : vec | std::views::drop(1) | std::views::stride(2))
            coef = -coef;
    return F;
}

template <typename T, int MX>
FPS2D<T, MX> next_F(const FPS2D<T, MX> &F, size_t m) {
    // F_{k+1}: F_k(x,y) F_k(x,-y) の y 偶数次の mod y^m
    auto conv = convolution_2D(F, negate_y(F));

    for (auto &vec : conv)
        vec = std::ranges::to<FPS<T, MX>>(vec | std::views::stride(2) |
                                          std::views::take(m));
    return conv;
}

template <typename T, int MX>
std::vector<FPS2D<T, MX>> build_F_chain(const FPS<T, MX> &f, const size_t log) {
    /*
    Return (F_0, F_1, ..., F_{l-1})

    s.t.  F_0 = 1 - xf(y)
          F_i+1 : next_F(F_i)
    */
    std::vector<FPS2D<T, MX>> Fs = {FPS2D{FPS<T, MX>{1}, -f}};

    for (size_t i : std::views::iota(0uz, log))
        Fs.push_back(next_F(Fs.back(), 1 << (log - i - 1)));
    return Fs;
}

template <typename T, int MX>
FPS2D<T, MX> next_G(const FPS2D<T, MX> &F, const FPS2D<T, MX> &G, size_t m) {
    // G(x,y)F(x,-y) のy奇数次 の n/2 項の mod y^m

    auto conv = convolution_2D(G, negate_y(F));
    for (auto &vec : conv)
        vec = std::ranges::to<FPS<T, MX>>(vec | std::views::drop(1) |
                                          std::views::stride(2) |
                                          std::views::take(m));
    return conv;
}

template <typename T, int MX>
FPS<T, MX> internal_power_projection(const FPS<T, MX> &f, const FPS<T, MX> &g) {
    /*
    Args:
        f, g : n項多項式（n:二冪）
        f[0] = 0

    Return:
        h s.t. h_i = [x^{n-1}]g(x)f(x)^i
    */
    const size_t n = f.size();

    assert(n >= 2);
    assert(g.size() == n);
    assert(std::has_single_bit(n));

    auto log = std::countr_zero(n);

    auto Fs = build_F_chain(f, log);

    // G_0(x,y) = g(y)
    FPS2D<T, MX> G = {g};

    for (int k = 1; k <= log; k++)
        G = next_G(Fs[k - 1], G, 1 << (log - k));

    return to_FPS(G) / to_FPS(Fs.back());
}

template <typename T, int MX>
FPS<T, MX> power_projection(FPS<T, MX> f, FPS<T, MX> g) {
    /*
    Args:
        f, g : n項多項式(n>0)

    Return:
        h s.t. h_i = [x^{n-1}]g(x)f(x)^i
    */

    const size_t n = f.size();
    assert(n);
    assert(g.size() <= n);
    g.resize(n);

    size_t n_2_ceil = std::bit_ceil(n);
    f.resize(n_2_ceil);
    g <<= n_2_ceil - n;
    assert(g.size() == n_2_ceil);
    auto h = internal_power_projection(f, g);
    h.strict(n);
    if (h.size() < n)
        h.resize(n);
    assert(h.size() == n);

    return h;
}
} // namespace fps
