#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"
#include <bits/stdc++.h>

#include "library/graph/matching/BipartiteMatching.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int l, r, m;
    std::cin >> l >> r >> m;

    BipartiteMatching BM(l, r);
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        BM.add_edge(a, b);
    }
    auto ans = BM.solve();
    std::cout << ans.size() << "\n";
    for (const auto &[u, v] : ans)
        std::cout << u << " " << v << "\n";
}