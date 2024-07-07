#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_12_B"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/graph/WeightedGraph.hpp"
#include "library/graph/shortest_path/Dial.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    WeightedGraph<int> G(n);
    REP (_, n) {
        int u, k;
        std::cin >> u >> k;
        REP (_, k) {
            int v, c;
            std::cin >> v >> c;
            G.add_arc(u, v, c);
        }
    }
    G.build();
    auto [d, pre] = dial(G);
    REP (i, n)
        std::cout << i << " " << d[i] << "\n";
}