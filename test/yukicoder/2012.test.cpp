#define PROBLEM "https://yukicoder.me/problems/no/2012"
#include <bits/stdc++.h>

#include "library/linearalgebra/ConvexHullTrick.cpp"
#include "library/r2/XY.cpp"
using ll = long long;
using ld = long double;
void chmax(ld &a, ld b) {
    if (a < b)
        a = b;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<XY<ld>> xy(n);
    for (int i = 0; i < n; i++)
        std::cin >> xy[i];
    sort(xy.begin(), xy.end());

    MinConvexHullTrick<ld> CHT1;
    MaxConvexHullTrick<ld> CHT2;

    ld ans = 0;

    for (const auto &v : xy) {
        if (v.x == 0) {
            chmax(ans, abs(xy[0].x * v.y));
            chmax(ans, abs(xy.back().x * v.y));
            continue;
        }
        if (CHT1.size()) {
            chmax(ans, abs(CHT1.query(v.y / v.x) * v.x));
            chmax(ans, abs(CHT2.query(v.y / v.x) * v.x));
        }
        Line<ld> f(v.x, -v.y);
        CHT1.add(f);
        CHT2.add(f);
    }
    std::cout << ll(round(ans)) << '\n';
}