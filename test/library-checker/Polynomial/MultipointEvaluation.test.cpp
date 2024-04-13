#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"
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
#include "library/formalpowerseries/Base.cpp"
using FPS = FormalPowerSeries<mint, (1 << 17) + 1>;
#include "library/formalpowerseries/MultipointEvaluation.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    FPS f(n);
    REP (i, n)
        std::cin >> f[i];
    std::vector<mint> p(m);
    REP (j, m)
        std::cin >> p[j];

    std::vector<mint> ans = multipoint_evaluation(f, p);
    REP (j, m)
        std::cout << ans[j] << "\n "[j + 1 < m];
}