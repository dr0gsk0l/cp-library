#define PROBLEM "https://judge.yosupo.jp/problem/rectangle_sum"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/GroupWaveletMatrix.hpp"
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
    std::vector<ll> W(P.size(), 0);
    REP (id, P.size())
        Y[id] = P.r(id).y;
    REP (i, n) {
        int id = P.id(x[i], y[i]);
        W[id] += w[i];
    }

    GroupWaveletMatrix<int, GroupAdd<ll>> WM(Y, W);

    REP (j, q) {
        int l, r, d, u;
        std::cin >> l >> d >> r >> u;
        auto [L, R] = P.interval(l, r);
        std::cout << WM.sum(L, R, d, u) << "\n";
    }
}