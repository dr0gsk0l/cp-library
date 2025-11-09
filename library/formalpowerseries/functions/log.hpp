#pragma once
#include "../Base.hpp"
#include "./differential.hpp"
#include "./integral.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> log(const FormalPowerSeries<T, MX> &f) {
    assert(f.size() and f[0] == 1);
    return integral(differential(f) / f);
}

} // namespace fps
