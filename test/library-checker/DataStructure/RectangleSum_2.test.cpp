#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/datastructure/CumulativeSum.hpp"
#include "library/datastructure/WaveletMatrix.hpp"
#include "library/r2/Projection.hpp"
#include "library/r2/XY.hpp"

using ll = long long;
using r2 = XY<ll>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<r2> r2s(n);
    std::vector<int> x(n), y(n), w(n);
    REP (i, n) {
        std::cin >> x[i] >> y[i] >> w[i];
        r2s[i] = r2(x[i], y[i]);
    }

    auto P = Projection(r2s);
    std::vector<int> Y(P.size(), 0);
    REP (id, P.size())
        Y[id] = P.r(id).y;
    WaveletMatrix WM(Y);

    int LOG = WM.height();
    std::vector W(LOG, std::vector<ll>(P.size(), 0));
    REP (i, n) {
        int idx = P.id(x[i], y[i]);
        auto idxs = WM.points(idx);
        REP (h, LOG)
            W[h][idxs[h]] += w[i];
    }
    std::vector<CumulativeSum<ll>> C(LOG);
    REP (h, LOG)
        C[h] = CumulativeSum<ll>(W[h]);

    REP (j, q) {
        int l, r, d, u;
        std::cin >> l >> d >> r >> u;
        auto [L, R] = P.interval(l, r);
        ll res = 0;
        auto intervals = WM.intervals(L, R, u);
        for (const auto &[h, l, r] : intervals)
            res += C[h].sum(l, r);
        auto intervals2 = WM.intervals(L, R, d);
        for (const auto &[h, l, r] : intervals2)
            res -= C[h].sum(l, r);
        std::cout << res << "\n";
    }
}