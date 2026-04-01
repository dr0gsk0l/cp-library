#pragma once
#include <algorithm>
#include "../Base.hpp"

namespace fps {

template <typename T>
FormalPowerSeries<T> integral(FormalPowerSeries<T> f, int n = -1) {
    if (n < 0)
        n = int(f.size()) + 1;
    if (n <= 0)
        return {};
    f.strict(std::max(0, n - 1));
    if (f.size() < size_t(std::max(0, n - 1)))
        f.resize(std::max(0, n - 1), T(0));
    if (f.size() < size_t(n))
        f.resize(n, T(0));

    for (int i = int(f.size()) - 1; i > 0; i--)
        f[i] = f[i - 1] / i;
    f[0] = 0;

    return f;
}

} // namespace fps
