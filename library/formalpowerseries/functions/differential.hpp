#pragma once
#include <cstddef>
#include "../Base.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> differential(FormalPowerSeries<T, MX> f) {
    if (f.size() <= 1)
        return FormalPowerSeries<T, MX>{};

    for (size_t i : std::views::iota(0uz, f.size() - 1))
        f[i] = T::raw(i + 1) * f[i + 1];
    f.pop_back();

    return f;
}

} // namespace fps
