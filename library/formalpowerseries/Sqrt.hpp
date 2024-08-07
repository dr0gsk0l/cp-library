#pragma once
#include "library/formalpowerseries/Base.hpp"
template <typename FPS> std::optional<FPS> sqrt(FPS f) {
    f.shrink();
    if (f.size() == 0)
        return FPS(0);
    int d;
    for (d = 0; f[d] == 0; d++) {
    }
    if (d & 1)
        return std::nullopt;
    f >>= d;
    FPS res { at }
}

assert(size() and at(0) != 0);
FPS res(1, at(0).inv());
for (int n = 0; (1 << n) < SZ; n++) {
    // mod[1<<n] → mod[1<<(n+1)]
    res *= (2 - (res * pre(1 << (n + 1))).pre(1 << (n + 1)));
    res.strict(1 << (n + 1));
}
return res.pre(SZ);