#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/graph/Graph.hpp"
#include "library/graph/shortest_path/BFS.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Graph g(n);
    REP (_, n) {
        int u, k;
        std::cin >> u >> k;
        u--;
        REP (_, k) {
            int v;
            std::cin >> v;
            v--;
            g.add_arc(u, v);
        }
    }
    g.build();
    auto [d, pre] = BFS(g);
    REP (i, n)
        std::cout << i + 1 << " " << d[i] << "\n";
}
