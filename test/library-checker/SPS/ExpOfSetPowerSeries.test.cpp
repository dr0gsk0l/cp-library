#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"
#include <bits/stdc++.h>

#include <atcoder/convolution>
#include <atcoder/modint>
using namespace atcoder;
using mint = modint998244353;
namespace atcoder {
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
} // namespace atcoder

#include "library/setpowerseries/Compose.cpp"
using SPS = SetPowerSeries<mint>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    SPS b(1 << n);
    for (auto &x : b)
        std::cin >> x;

    SPS c = exp(b);
    for (auto &x : c)
        std::cout << x << " ";
    std::cout << std::endl;
}