#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"
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
using FPS = FormalPowerSeries<mint, 500000>;
#include "library/formalpowerseries/DivMod.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    FPS f(n), g(m);
    REP (i, n)
        std::cin >> f[i];
    REP (j, m)
        std::cin >> g[j];
    auto [q, r] = div_mod(f, g);
    q.shrink();
    r.shrink();
    std::cout << q.size() << " " << r.size() << std::endl;
    REP (i, q.size())
        std::cout << q[i] << " ";
    std::cout << "\n";
    REP (i, r.size())
        std::cout << r[i] << " ";
    std::cout << "\n";
}