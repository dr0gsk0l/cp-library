#pragma once
#include <cassert>
#include <cmath>
#include <cstddef>
#include <vector>
#include "../Base.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> composition(FormalPowerSeries<T, MX> f,
                                     FormalPowerSeries<T, MX> g) {
    const std::size_t n = f.size();
    if (n == 0)
        return {};
    if (n == 1)
        return {f[0]};

    assert(g.size() >= n);
    assert(g[0] == 0);

    g.strict(static_cast<int>(n));

    const std::size_t block = static_cast<std::size_t>(
        std::max(1, static_cast<int>(std::sqrt(static_cast<long double>(n)))));

    std::vector<FormalPowerSeries<T, MX>> small(block + 1);
    small[0] = FormalPowerSeries<T, MX>{1};
    for (std::size_t i = 1; i <= block; i++) {
        small[i] = small[i - 1] * g;
        small[i].strict(static_cast<int>(n));
    }

    FormalPowerSeries<T, MX> res(n, T(0));
    FormalPowerSeries<T, MX> giant = FormalPowerSeries<T, MX>{1};

    for (std::size_t l = 0; l < n; l += block) {
        FormalPowerSeries<T, MX> cur(n, T(0));
        const std::size_t width = std::min(block, n - l);
        for (std::size_t j = 0; j < width; j++) {
            if (f[l + j] == T(0))
                continue;
            cur += small[j] * f[l + j];
        }
        cur.strict(static_cast<int>(n));
        res += cur * giant;
        res.strict(static_cast<int>(n));
        if (l + block < n) {
            giant *= small[block];
            giant.strict(static_cast<int>(n));
        }
    }

    res.strict(static_cast<int>(n));
    if (res.size() < n)
        res.resize(n, T(0));
    return res;
}

} // namespace fps
