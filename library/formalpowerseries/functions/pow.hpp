#pragma once
#include "../Base.hpp"
#include "./exp.hpp"
#include "./log.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> pow(FormalPowerSeries<T, MX> f, long long n) {
    assert(n >= 0);
    if (n == 0) {
        return {1};
    }
    if (n == 1) {
        return f;
    }

    f.shrink();
    if (!f.size()) {
        return f;
    }
    int d = 0;
    while(d < f.size() && f[d] == 0) {
        d++;
    }
    
    if (d > 0 && (unsigned __int128)d * n >= MX) {
        return FormalPowerSeries<T, MX>{};
    }
    f >>= d;
    d *= n;

    if (f[0] == 1) {
        f = exp(n * log(f));
    } else {
        f = exp(log(f) * n);
    }
    f <<= d;
    
    return f;
}

} // namespace fps
