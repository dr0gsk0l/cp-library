#pragma once
#include "library/formalpowerseries/Base.hpp"
#include "library/math/ModularSqrt.hpp"
#include <optional>

// Computes the square root of a formal power series f.
// Returns std::nullopt if the square root does not exist.
template <typename FPS> std::optional<FPS> sqrt(FPS f) {
    using T = typename FPS::value_type;
    f.shrink();
    if (f.size() == 0) {
        return FPS(0);
    }

    int d = 0;
    while (d < f.size() && f[d] == 0) {
        d++;
    }
    if (d == f.size()) {
        return FPS(0);
    }

    if (d % 2 != 0) {
        return std::nullopt;
    }

    f >>= d;

    std::optional<T> s0 = mod_sqrt(f[0]);
    if (!s0) {
        return std::nullopt;
    }

    FPS res(1, *s0);
    int n = 1;
    constexpr int MX = FPS::max_size;
    while (n < MX) {
        n <<= 1;
        res = (res + f.pre(n) * res.inv(n)) / 2;
    }
    res.strict(MX);
    res <<= (d / 2);
    return res;
}