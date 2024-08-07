#define PROBLEM "https://yukicoder.me/problems/no/1502"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp"
#include "library/mod/Modint.hpp"
using mint = Mint<long long, 1000'000'007>;

void chmin(int &a, int b) { a = std::min(a, b); }
void chmax(int &a, int b) { a = std::max(a, b); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    IntegerSumRuleUnionFind UF(n);
    REP (_, m) {
        int x, y, z;
        std::cin >> x >> y >> z;
        x--;
        y--;
        if (!UF.merge(x, y, z)) {
            std::cout << 0 << std::endl;
            return 0;
        }
    }

    auto solve = [&](int upper) {
        std::vector<int> low(n, 1), high(n, upper);
        REP (i, n) {
            auto [r, a, b] = UF.from_root(i);
            if (UF.val(r)) {
                int v = UF.val(r).value() * a + b;
                if (v < 1 || upper < v)
                    return mint::raw(0);
                continue;
            }
            // 1 <= ra+b <= upper
            if (a == 1) {
                chmax(low[r], 1 - b);
                chmin(high[r], upper - b);
            } else {
                chmax(low[r], b - upper);
                chmin(high[r], b - 1);
            }
        }
        mint res = 1;
        REP (r, n)
            if (UF.leader(r) == r and !UF.val(r))
                res *= std::max(high[r] - low[r] + 1, 0);
        return res;
    };

    std::cout << solve(k) - solve(k - 1) << std::endl;
}