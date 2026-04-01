#pragma once
#include <cassert>
#include <cmath>
#include "../Base.hpp"
#include "./exp.hpp"
#include "./log.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> pow(FormalPowerSeries<T, MX> f, long long n,
                             int m = -1) {
    using FPS = FormalPowerSeries<T, MX>;
    if (m < 0)
        m = int(f.size());

    assert(n >= 0);
    f.strict(m);
    if (f.size() < size_t(m))
        f.resize(m, T(0));

    if (m == 0)
        return {};
    if (n == 0) {
        FPS one(m, T(0));
        one[0] = 1;
        return one;
    }
    if (n == 1)
        return f;

    if (f.size() == 1)
        return FPS{f[0].pow(n)}.pre(m);

    int d = f.order();

    if (d > 0 && n > m / d)
        return FPS(m, T(0));

    // f(x) = x^d g(x) の時 f^n = x^{dn} g^n
    f >>= d;

    // f(x) = f_0 * g(x) のとき f^n = f_0^n g^n
    auto f_0 = f[0];
    if (f_0 != 1)
        f /= f_0;

    // f^n = exp(n log(f))
    auto res = (f_0.pow(n) * fps::exp(n * fps::log(f, m), m)) << (d * n);
    if (res.size() < size_t(m))
        res.resize(m, T(0));
    else
        res.strict(m);
    return res;
}

} // namespace fps
