#pragma once
#include "../Base.hpp"
#include "./log.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> exp(const FormalPowerSeries<T, MX>& f) {
    if (!f.size()) {
        return {1};
    }
    assert(f.size() > 0 && f[0] == 0);
    FormalPowerSeries<T, MX> res = {1};
    for (int n = 1; n < MX; n <<= 1) {
        res = res * (f.pre(n << 1) + 1 - log(res).pre(n << 1));
        res.strict(n << 1);
    }
    return res;
}

template <typename T, int MX>
FormalPowerSeries<T, MX> exp(const T& n) {
    if (n == 0) {
        return {1};
    }
    FormalPowerSeries<T, MX> res(MX);
    res[0] = 1;
    for (int i = 1; i < MX; i++) {
        res[i] = res[i - 1] * n / i;
    }
    return res;
}

} // namespace fps
