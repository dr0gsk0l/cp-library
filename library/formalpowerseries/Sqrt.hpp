#pragma once
#include <algorithm>
#include <cmath>
#include "library/formalpowerseries/Base.hpp"
#include "library/math/ModularSqrt.hpp"
#include <optional>

// Computes the square root of a formal power series f.
// Returns std::nullopt if the square root does not exist.
template <typename FPS> std::optional<FPS> sqrt(FPS f, int n = -1) {
    using T = typename FPS::value_type;
    if (n < 0)
        n = int(f.size());
    if (n == 0)
        return FPS{};
    f.strict(n);
    if (f.size() < size_t(n))
        f.resize(n, T(0));

    int d = 0;
    while (d < f.size() && f[d] == 0) {
        d++;
    }
    if (d == f.size()) {
        return FPS(n, T(0));
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
    int m = 1;
    while (m < n) {
        m <<= 1;
        const int k = std::min(n, m);
        res = ((res + f.pre(k) * res.inv(k)) / 2).pre(k);
    }
    if (res.size() < size_t(n))
        res.resize(n, T(0));
    else
        res.strict(n);
    res <<= (d / 2);
    res.strict(n);
    return res;
}
