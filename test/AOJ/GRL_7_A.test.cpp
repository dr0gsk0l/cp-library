#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_7_A"
#include <bits/stdc++.h>

#include "library/graph/matching/BipartiteMatching.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int x, y, m;
    std::cin >> x >> y >> m;

    BipartiteMatching BM(x, y);
    while (m--) {
        int u, v;
        std::cin >> u >> v;
        BM.add_edge(u, v);
    }
    std::cout << BM.solve().size() << std::endl;
}