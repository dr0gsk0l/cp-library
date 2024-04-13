#define PROBLEM "https://judge.yosupo.jp/problem/pow_of_formal_power_series"
#include <bits/stdc++.h>

#include <library/formalpowerseries/Base.cpp>

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

using FPS = FormalPowerSeries<mint, 500000>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    long long m;
    std::cin >> n >> m;
    FPS f(n);
    for (int i = 0; i < n; i++)
        std::cin >> f[i];
    f = f.pow(m);
    for (int i = 0; i < n; i++)
        std::cout << (i < f.size() ? f[i] : 0) << "\n "[i + 1 < n];
}