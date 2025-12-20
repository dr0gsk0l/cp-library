#pragma once
#include <cassert>
#include <cmath>
#include "../Base.hpp"
#include "./exp.hpp"
#include "./log.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> pow(FormalPowerSeries<T, MX> f, long long n) {
    using FPS = FormalPowerSeries<T, MX>;

    assert(n >= 0);
    f.shrink();

    if (n == 0)
        return FPS::unit();
    if (n == 1)
        return f;

    if (f.size() == 0)
        return f;
    if (f.size() == 1)
        return FPS{f[0].pow(n)};

    int d = f.order();

    if (d > 0 && n > MX / d)
        return FPS(0);

    // f(x) = x^d g(x) の時 f^n = x^{dn} g^n
    f >>= d;

    // f(x) = f_0 * g(x) のとき f^n = f_0^n g^n
    auto f_0 = f[0];
    if (f_0 != 1)
        f /= f_0;

    // f^n = exp(n log(f))
    return f_0.pow(n) * fps::exp(n * fps::log(f)) << (d * n);
}

} // namespace fps
