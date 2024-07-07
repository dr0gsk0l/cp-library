#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B"
#include <bits/stdc++.h>

#include "library/tree/CartesianTree.hpp"

void chmax(int &a, int b) { a = std::max(a, b); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int h, w;
    std::cin >> h >> w;

    int ans = 0;
    std::vector<int> v(w, 0);
    while (h--) {
        for (int &p : v) {
            int a;
            std::cin >> a;
            if (a)
                p = 0;
            else
                p++;
        }
        auto T = cartesian_tree(v);
        chmax(ans, v[T.root] * w);
        for (int i = 0; i < w; i++)
            for (const auto &e : T.son(i)) {
                const auto &[L, R] = e.weight;
                chmax(ans, v[e.to] * (R - L));
            }
    }
    std::cout << ans << std::endl;
}