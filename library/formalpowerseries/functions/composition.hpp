#pragma once
#include "../Base.hpp"
#include "./differential.hpp"
#include "./pow.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> composition(const FormalPowerSeries<T, MX>& f, FormalPowerSeries<T, MX> g) {
    assert(!g.size() or g[0] == 0);
    if (f.size() == 0) {
        return f;
    }
    if (f.size() == 1) {
        return {f[0]};
    }
    if (f.size() == 2) {
        return f[0] + f[1] * g;
    }

    int m = sqrt(MX / 20);
    FormalPowerSeries<T, MX> g1 = g;
    FormalPowerSeries<T, MX> g2 = g1.separate(m);

    int z;
    for (z = 1; z < g1.size() and g1[z] == 0; z++) {
    }
    if (z == g1.size()) {
        FormalPowerSeries<T, MX> res(0);
        FormalPowerSeries<T, MX> g2pow = {1};
        for (int i = 0; i * m < MX and i < f.size(); i++, g2pow *= g2) {
            res += f[i] * g2pow << (i * m);
        }
        return res;
    }

    auto rec = [&](auto rec, int l, int d) -> FormalPowerSeries<T, MX> {
        if (d == 0 or l >= f.size()) {
            return {};
        }
        if (d == 1) {
            return {f[l]};
        }
        if (d == 2) {
            return f[l] + (l + 1 < f.size() ? f[l + 1] * g1 : FormalPowerSeries<T, MX>{});
        }
        FormalPowerSeries<T, MX> f1 = rec(rec, l, d >> 1);
        FormalPowerSeries<T, MX> f2 = rec(rec, l + (d >> 1), d - (d >> 1));
        f2 *= fps::pow(g1, d >> 1);
        return f1 + f2;
    };
    FormalPowerSeries<T, MX> res = rec(rec, 0, f.size());

    FormalPowerSeries<T, MX> dfg = res;
    FormalPowerSeries<T, MX> g1_diff = fps::differential(g);
    g1_diff >>= (z-1);
    FormalPowerSeries<T, MX> g1inv = g1_diff.inv();
    FormalPowerSeries<T, MX> g2pow = {1};
    T factinv = 1;

    for (int i = 1; i * m < MX; i++) {
        dfg = (fps::differential(dfg) >> z) * g1inv;
        dfg.strict(MX - m * i);
        (g2pow *= g2).strict(MX - m * i);
        factinv /= i;
        res += factinv * (dfg * g2pow) << (m * i);
    }
    return res;
}

} // namespace fps
