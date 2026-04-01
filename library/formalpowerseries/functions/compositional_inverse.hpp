#pragma once
#include "./pow.hpp"
#include "./power_projection.hpp"
#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstddef>
#include <ranges>

namespace fps {


template <typename T>
FormalPowerSeries<T> internal_compositional_inverse(FormalPowerSeries<T> f) {
    /*
    Args:
        n := len(f) >= 2
        [x^0]f = 0
        [x^1]f = 1

    Return:
        f⁻¹(x)
    */
    const size_t n = f.size();
    assert(n >= 2);
    assert(f[0] == 0);
    assert(f[1] == 1);

    /*
    Lagrange Reverse Theorem
        (n-1)[xⁿ⁻¹]f(x)ⁱ = [xⁿ⁻ⁱ⁻¹] i(f⁻¹(x) / x)⁻⁽ⁿ⁻¹⁾
    左辺は g(x) = n-1 に対する [xⁱ]power_projection(f, g)
    */

    FormalPowerSeries<T> g{n - 1};
    auto h = power_projection(f, g);
    if (h.size() < n)
        h.resize(n);
    assert(h.size() == n);
    assert(h[0] == 0);
    // [xⁱ]h(x) = (n-1)[xⁿ⁻¹]f(x)ⁱ = [xⁿ⁻ⁱ⁻¹] i(f⁻¹(x) / x)⁻⁽ⁿ⁻¹⁾

    for (auto &&[i, h_i] : h | std::views::enumerate)
        if (i)
            h_i /= i;
    // [xⁱ]h(x) = [xⁿ⁻ⁱ⁻¹] (f⁻¹(x) / x)⁻⁽ⁿ⁻¹⁾

    std::ranges::reverse(h);
    // h(x) = (f⁻¹(x) / x)⁻⁽ⁿ⁻¹⁾

    h = fps::pow(h, (T(-int(n) + 1).inv().val()));
    // h(x) = f⁻¹(x) / x

    h <<= 1;
    h.strict(n);
    // h(x) = f⁻¹(x)

    return h;
}

// compositional inverse via Lagrange inversion using power_projection
template <typename T>
FormalPowerSeries<T> compositional_inverse(FormalPowerSeries<T> f) {
    /*
    Args:
        n := len(f) >= 2
        [x^0]f = 0
        [x^1]f ≠ 0

    Return:
        f⁻¹(x)
    */
    const size_t n = f.size();
    assert(n >= 2);
    assert(f[0] == 0);

    T c = f[1];
    assert(c != 0);

    if (c == 1)
        return internal_compositional_inverse(f);

    /*
    h(x) := f(x)/c
    h⁻¹(x/c) = f⁻¹(x)
    */
    auto c_inv = c.inv();
    auto h = f * c_inv;
    auto h_inv = internal_compositional_inverse(h);

    T c_inv_pow = 1;
    for (auto &coef : h_inv) {
        coef *= c_inv_pow;
        c_inv_pow *= c_inv;
    }

    return h_inv;
}

} // namespace fps
