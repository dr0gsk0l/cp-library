#pragma once
#include "../Base.hpp"
#include "./differential.hpp"
#include "./pow.hpp"

namespace fps {

template <typename T, int MX>
FormalPowerSeries<T, MX> composition(const FormalPowerSeries<T, MX>& f, FormalPowerSeries<T, MX> g) {
    using FPS = FormalPowerSeries<T, MX>;
    // f(g(x)) をブロック分割＋テイラー展開で計算する
    assert(!g.size() or g[0] == 0);
    switch (f.size()) {
        case 0:
            return f;
        case 1:
            return {f[0]};
        case 2:
            return f[0] + f[1] * g;
        default:
            break;
    }

    int m = sqrt(MX / 20);
    // g(x) = g1(x) + x^m g2(x) に分割
    FPS g1 = g;
    FPS g2 = g1.separate(m);
    
    if (g1 == FPS(0)) {
        // f(g) = f(x^m g2(x))
        FPS res(0), g2pow = FPS::unit();
        for (int i = 0; i * m < MX and i < f.size(); i++, g2pow *= g2)
            res += f[i] * g2pow << (i * m);
        return res;
    }

    // f を二分しつつ g1 の累乗をまとめて掛ける再帰
    auto rec = [&](auto rec, int l, int d) -> FPS {
        if (d == 0 or l >= f.size()) {
            return {};
        }
        if (d == 1) {
            return {f[l]};
        }
        if (d == 2) {
            return f[l] + (l + 1 < f.size() ? f[l + 1] * g1 : FPS{});
        }
        FPS f1 = rec(rec, l, d >> 1);
        FPS f2 = rec(rec, l + (d >> 1), d - (d >> 1));
        f2 *= fps::pow(g1, d >> 1);
        return f1 + f2;
    };
    FPS res = rec(rec, 0, f.size()); // まず g1 を代入した分を計算

    FPS dfg = res; // d^k f(g1) を順に更新するための一時変数
    FPS g1_diff = fps::differential(g);
    g1_diff >>= (g1.order() - 1);
    FPS g1inv = g1_diff.inv();
    FPS g2pow = {1};
    T factinv = 1;

    // g2 によるテイラー展開の各項を足し込む
    for (int i = 1; i * m < MX; i++) {
        dfg = (fps::differential(dfg) >> g1.order()) * g1inv;
        dfg.strict(MX - m * i);
        (g2pow *= g2).strict(MX - m * i);
        factinv /= i;
        res += factinv * (dfg * g2pow) << (m * i);
    }
    return res;
}

} // namespace fps
