#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/composition_of_formal_power_series"
#include <bits/stdc++.h>

#include "library/formalpowerseries/Base.hpp"

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

using FPS = FormalPowerSeries<mint, 8000>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    FPS f(n), g(n);
    for (int i = 0; i < n; i++)
        std::cin >> f[i];
    for (int i = 0; i < n; i++)
        std::cin >> g[i];
    f = f(g);
    for (int i = 0; i < n; i++)
        std::cout << f[i] << "\n "[i + 1 < n];
}