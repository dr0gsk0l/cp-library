#define PROBLEM "https://judge.yosupo.jp/problem/polynomial_taylor_shift"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
std::ostream &operator<<(std::ostream &os, mint a) {
    os << a.val();
    return os;
}
std::istream &operator>>(std::istream &is, mint &a) {
    long long b;
    is >> b;
    a = b;
    return is;
}

#include "library/formalpowerseries/Base.hpp"
#include "library/formalpowerseries/functions/taylor_shift.hpp"
using FPS = FormalPowerSeries<mint, 524288>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, c;
    std::cin >> n >> c;
    FPS f(n);
    REP (i, n)
        std::cin >> f[i];
    fps::taylor_shift(f, mint(c));
    REP (i, n)
        std::cout << (i < f.size() ? f[i] : 0) << "\n "[i + 1 < n];
}
