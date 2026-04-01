#pragma once
#include <cmath>
#include <cstddef>
#include <ranges>
#include "../Base.hpp"
#include "./egf.hpp"
#include "./exp.hpp"
#include <algorithm>

namespace fps {

template <typename T>
void taylor_shift(FormalPowerSeries<T> &f, T c) {
    if (f.size() <= 1 || c == 0)
        return;

    const size_t n = f.size();

    f = from_egf(f);

    std::ranges::reverse(f);
    f *= exp(c, int(n));
    f.strict(n);
    std::ranges::reverse(f);

    f = to_egf(f);
}

} // namespace fps
