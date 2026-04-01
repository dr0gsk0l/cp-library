#pragma once
#include "../Base.hpp"
#include "library/mod/MintUtility.hpp"
#include <ranges>

namespace fps {

// Convert ordinary generating function f to exponential generating function.
// g[i] = f[i] / i!
template <typename T>
FormalPowerSeries<T> to_egf(FormalPowerSeries<T> f) {
    /*
    Return g s.t. g[i] = f[i] / i!
    */

    for (auto &&[i, coef] : f | std::views::enumerate)
        coef *= MintUtility<T>::inv_fact(i);
    return f;
}

template <typename T>
FormalPowerSeries<T> from_egf(FormalPowerSeries<T> g) {
    /*
    Return f s.t. f[i] = i!f[i]
    */

    for (auto &&[i, coef] : g | std::views::enumerate)
        coef *= MintUtility<T>::fact(i);
    return g;
}

} // namespace fps
