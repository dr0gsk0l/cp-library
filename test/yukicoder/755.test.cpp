#define PROBLEM "https://yukicoder.me/problems/no/755"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP2(i, s, n) for (int i = (s); i < (n); i++)

#include "library/datastructure/2D/CumulativeSum.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector v(m, std::vector<int>(m));
    REP (i, m)
        REP (j, m)
            std::cin >> v[i][j];
    CumulativeSum2D C(v);

    REP (_, n) {
        int y, x;
        std::cin >> y >> x;
        y--;
        x--;
        int ans = 0;
        REP (u, y + 1)
            REP2(d, y + 1, m + 1)
        REP (l, x + 1)
            REP2(r, x + 1, m + 1) ans += !C.sum(u, d, l, r);
        std::cout << ans << "\n";
    }
}