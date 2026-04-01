#pragma once
#include <cassert>
#include <cmath>
#include "../Base.hpp"
#include "./differential.hpp"
#include "./integral.hpp"

namespace fps {

template <typename T>
FormalPowerSeries<T> log(const FormalPowerSeries<T> &f, int n = -1) {
    if (n < 0)
        n = int(f.size());
    if (n == 0)
        return {};
    assert(f.size() and f[0] == 1);
    auto df = differential(f).pre(n - 1);
    auto res = integral((df * f.inv(n)).pre(n), n);
    res.strict(n);
    return res;
}

} // namespace fps
