#define PROBLEM "https://judge.yosupo.jp/problem/scc"
#include <bits/stdc++.h>

#include "library/graph/Graph.cpp"
#include "library/graph/SCC.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    Graph g(n, m, true, 0);
    SCC scc(g);
    int k = scc.DAG.n;
    std::cout << k << "\n";
    for (const auto &ve : scc.component) {
        std::cout << ve.size();
        for (int p : ve)
            std::cout << " " << p;
        std::cout << "\n";
    }
}