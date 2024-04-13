#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=3297"
#include <bits/stdc++.h>

#include "library/flow/NondecreasingMCF.cpp"

using ll = long long;
const __int128 LINF = 1e20;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    while (cin >> n >> m >> k, n) {
        NondecreasingMCF<__int128> fl(n);
        for (int i = 0; i < m; i++) {
            ll s, t, c, d;
            std::cin >> s >> t >> c >> d;
            s--;
            t--;
            fl.add_arc(s, t, k,
                       [c, d](int x) { return c + (x ? x * d : -LINF); });
        }
        auto [ans, ok] = fl.flow(0, n - 1, k);
        ans += LINF * m;
        std::cout << (ans < LINF ? ll(ans) : -1LL) << "\n";
    }
}