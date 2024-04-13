#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
ostream &operator<<(ostream &os, mint a) {
    os << a.val();
    return os;
}
istream &operator>>(istream &is, mint &a) {
    long long b;
    is >> b;
    a = b;
    return is;
}

#include "library/formalpowerseries/Base.cpp"
using FPS = FormalPowerSeries<mint, 500001>;
#include "library/formalpowerseries/Prod.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    FPSProdDiversity<FPS> P;

    int n;
    cin >> n;
    REP (_, n) {
        int d;
        cin >> d;
        FPS f(d + 1);
        REP (i, d + 1)
            cin >> f[i];
        P.add(f);
    }
    FPS f = P.prod();
    REP (i, f.size())
        std::cout << f[i] << "\n "[i + 1 < f.size()];
}