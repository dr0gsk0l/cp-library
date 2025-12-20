#pragma once
#include <cmath>
#include <cstddef>
#include <ranges>
#include "../Base.hpp"
#include "./egf.hpp"
#include "./exp.hpp"
#include <algorithm>

namespace fps {

template <typename T, int MX>
void taylor_shift(FormalPowerSeries<T, MX> &f, T c) {
    f.shrink();
    if (f.size() <= 1 || c == 0)
        return;

    const size_t n = f.size();

    f = from_egf(f);

    std::ranges::reverse(f);
    f *= exp<T, MX>(c).pre(n);
    f.strict(n);
    std::ranges::reverse(f);

    f = to_egf(f);
}

} // namespace fps
