#pragma once
#include <cassert>
#include <cmath>
#include "../Base.hpp"
#include "./log.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> exp(const FormalPowerSeries<T, MX> &f, int n = -1) {
    // Return exp(f)
    if (n < 0)
        n = int(f.size());
    if (n == 0)
        return {};

    if (!f.size()) {
        FormalPowerSeries<T, MX> one(n, T(0));
        one[0] = 1;
        return one;
    }

    assert(f[0] == 0);

    FormalPowerSeries<T, MX> res = {1};
    for (int m = 1; m < n; m <<= 1) {
        const int k = std::min(n, m << 1);
        res = (res * (f.pre(k) + 1 - log(res, k))).pre(k);
        res.strict(k);
    }
    if (res.size() < size_t(n))
        res.resize(n, T(0));
    else
        res.strict(n);
    return res;
}

template <typename T, int MX = -1>
FormalPowerSeries<T, MX> exp(const T &a, int n) {
    // Return exp(nx)
    if (n <= 0)
        return {};

    FormalPowerSeries<T, MX> res(n, T(0));
    res[0] = 1;
    for (int i = 1; i < n; i++)
        res[i] = res[i - 1] * a / i;
    return res;
}

} // namespace fps
