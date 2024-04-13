#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/group/Add.cpp"
#include "library/datastructure/GroupWaveletMatrix.cpp"
#include "library/r2/Projection.cpp"
#include "library/r2/XY.cpp"

using ll = long long;
using r2 = XY<ll>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    std::vector<r2> r2s(n);
    r2s.reserve(n + q);
    std::vector<int> x(n), y(n), w(n), qt(q), l(q), d(q), r(q), u(q);
    REP (i, n) {
        cin >> x[i] >> y[i] >> w[i];
        r2s[i] = r2(x[i], y[i]);
    }
    REP (j, q) {
        cin >> qt[j];
        if (qt[j])
            cin >> l[j] >> d[j] >> r[j] >> u[j];
        else {
            cin >> l[j] >> d[j] >> r[j];
            r2s.emplace_back(l[j], d[j]);
        }
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

    REP (j, q)
        if (qt[j]) {
            auto [L, R] = P.interval(l[j], r[j]);
            std::cout << WM.sum(L, R, d[j], u[j]) << "\n";
        } else {
            int id = P.id(l[j], d[j]);
            WM.add(id, r[j]);
        }
}