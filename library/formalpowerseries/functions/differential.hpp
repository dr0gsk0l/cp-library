#pragma once
#include "../Base.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> differential(FormalPowerSeries<T, MX> f) {
    if (f.size() <= 1) {
        return FormalPowerSeries<T, MX>{};
    }
    for (std::size_t i = 0; i < f.size() - 1; i++) {
        f[i] = (i + 1) * f[i + 1];
    }
    f.pop_back();
    return f;
}

} // namespace fps
