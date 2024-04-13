#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_E"
#include <bits/stdc++.h>

#include "library/math/ExtraGCD.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int a, b;
    std::cin >> a >> b;
    auto [x, y] = ext_gcd(a, b);
    std::cout << x << " " << y << std::endl;
}