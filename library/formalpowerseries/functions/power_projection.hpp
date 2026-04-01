#pragma once
#include <algorithm>
#include <bit>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <ranges>
#include <utility>
#include <vector>
#include "../Base.hpp"
#include "./egf.hpp"
#include "./exp.hpp"

namespace fps {

template <typename T, int MX>
std::pair<size_t, size_t>
size_2d(const std::vector<FormalPowerSeries<T, MX>> &f2d) {
    size_t n = f2d.size();
    size_t m = std::ranges::max(f2d | std::views::transform(
                                          [](auto const &row) {
                                              return row.size();
                                          }));
    return {n, m};
}

template <typename T, int MX>
FormalPowerSeries<T, MX>
flatten_2d(const std::vector<FormalPowerSeries<T, MX>> &f2d, size_t n,
           size_t m) {
    FormalPowerSeries<T, MX> flat(2 * n * m, T{0});
    for (auto const &[i, row] : f2d | std::views::enumerate)
        for (auto const &[j, val] : row | std::views::enumerate)
            flat[2 * m * i + j] = val;
    return flat;
}

template <typename T, int MX>
std::vector<FormalPowerSeries<T, MX>>
unflatten_2d(const FormalPowerSeries<T, MX> &flat, size_t n, size_t m) {
    std::vector<FormalPowerSeries<T, MX>> f2d(
        2 * n, FormalPowerSeries<T, MX>(2 * m, T{0}));
    for (size_t i : std::views::iota(0uz, 2 * n))
        for (size_t j : std::views::iota(0uz, 2 * m))
            if (size_t index = 2 * m * i + j; index < flat.size())
                f2d[i][j] = flat[index];
    return f2d;
}

template <typename T, int MX>
std::vector<FormalPowerSeries<T, MX>>
convolution_2D(const std::vector<FormalPowerSeries<T, MX>> &f2d,
               const std::vector<FormalPowerSeries<T, MX>> &g2d) {
    auto [f_n, f_m] = size_2d(f2d);
    auto [g_n, g_m] = size_2d(g2d);
    const size_t n = std::max(f_n, g_n);
    const size_t m = std::max(f_m, g_m);

    if (n == 0 || m == 0)
        return {};

    return unflatten_2d(flatten_2d(f2d, n, m) * flatten_2d(g2d, n, m), n, m);
}

template <typename T, int MX>
FormalPowerSeries<T, MX>
to_FPS(const std::vector<FormalPowerSeries<T, MX>> &f2d) {
    return f2d |
           std::views::transform(
               [](const FormalPowerSeries<T, MX> &row) { return row[0]; }) |
           std::ranges::to<FormalPowerSeries<T, MX>>();
}

template <typename T, int MX>
std::vector<FormalPowerSeries<T, MX>>
negate_y(std::vector<FormalPowerSeries<T, MX>> f2d) {
    for (auto &vec : f2d)
        for (auto &coef : vec | std::views::drop(1) | std::views::stride(2))
            coef = -coef;
    return f2d;
}

template <typename T, int MX>
std::vector<FormalPowerSeries<T, MX>>
next_F(const std::vector<FormalPowerSeries<T, MX>> &f2d, size_t m) {
    auto conv = convolution_2D(f2d, negate_y(f2d));

    for (auto &vec : conv)
        vec = std::ranges::to<FormalPowerSeries<T, MX>>(
            vec | std::views::stride(2) | std::views::take(m));
    return conv;
}

template <typename T, int MX>
std::vector<std::vector<FormalPowerSeries<T, MX>>>
build_F_chain(const FormalPowerSeries<T, MX> &f, const size_t log) {
    std::vector<std::vector<FormalPowerSeries<T, MX>>> fs = {
        std::vector<FormalPowerSeries<T, MX>>{FormalPowerSeries<T, MX>{1}, -f}};

    for (size_t i : std::views::iota(0uz, log))
        fs.push_back(next_F(fs.back(), 1 << (log - i - 1)));
    return fs;
}

template <typename T, int MX>
std::vector<FormalPowerSeries<T, MX>>
next_G(const std::vector<FormalPowerSeries<T, MX>> &f2d,
       const std::vector<FormalPowerSeries<T, MX>> &g2d, size_t m) {
    auto conv = convolution_2D(g2d, negate_y(f2d));
    for (auto &vec : conv)
        vec = std::ranges::to<FormalPowerSeries<T, MX>>(
            vec | std::views::drop(1) | std::views::stride(2) |
            std::views::take(m));
    return conv;
}

template <typename T, int MX>
FormalPowerSeries<T, MX>
internal_power_projection(const FormalPowerSeries<T, MX> &f,
                          const FormalPowerSeries<T, MX> &g) {
    const size_t n = f.size();

    assert(n >= 2);
    assert(g.size() == n);
    assert(std::has_single_bit(n));

    auto log = std::countr_zero(n);

    auto fs = build_F_chain(f, log);

    std::vector<FormalPowerSeries<T, MX>> g2d = {g};

    for (int k = 1; k <= log; k++)
        g2d = next_G(fs[k - 1], g2d, 1 << (log - k));

    return to_FPS(g2d) / to_FPS(fs.back());
}

template <typename T, int MX>
FormalPowerSeries<T, MX> power_projection(FormalPowerSeries<T, MX> f,
                                          FormalPowerSeries<T, MX> g) {
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
