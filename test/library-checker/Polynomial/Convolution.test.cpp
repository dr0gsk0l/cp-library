#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <bits/stdc++.h>

#include "library/convolution/NTT.cpp"
#include "library/mod/Modint.cpp"

using mint = Mint<long long, 998244353>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<mint> f(n), g(m);
    for (mint &p : f)
        std::cin >> p;
    for (mint &p : g)
        std::cin >> p;
    auto h = convolution(f, g);
    for (mint &p : h)
        std::cout << p << " ";
    std::cout << std::endl;
}