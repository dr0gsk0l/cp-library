#pragma once
#include "../Base.hpp"
#include "./exp.hpp"
#include <algorithm>

namespace fps {

template <typename T, int MX>
void taylor_shift(FormalPowerSeries<T, MX>& f, T c) {
    f.shrink();
    if (f.size() <= 1 || c == 0) {
        return;
    }
    int n = f.size();
    T fact = 1;
    for (int i = 0; i < n; i++) {
        if (i) {
            fact *= i;
        }
        f[i] *= fact;
    }
    std::reverse(f.begin(), f.end());
    f *= exp<T, MX>(c).pre(n);
    f.strict(n);
    std::reverse(f.begin(), f.end());
    T finv = fact.inv();
    for (int i = n - 1; i >= 0; i--) {
        f[i] *= finv;
        if (i) finv *= i;
    }
}

} // namespace fps
