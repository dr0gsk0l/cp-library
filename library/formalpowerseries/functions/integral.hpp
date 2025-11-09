#pragma once
#include "../Base.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> integral(FormalPowerSeries<T, MX> f) {
    if (f.size() < MX) {
        f.resize(f.size() + 1);
    }
    for (int i = f.size() - 1; i > 0; i--) {
        f[i] = f[i - 1] / i;
    }
    f[0] = 0;
    return f;
}

} // namespace fps
