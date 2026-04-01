#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"
#include <bits/stdc++.h>

#include "library/datastructure/unionfind/UnionFind.hpp"
#include "library/graph/Graph.hpp"
#include "library/graph/LowLink.hpp"

std::vector<std::vector<int>> two_edge_connected_components_impl(const Graph &g) {
    LowLink low_link(g);
    UnionFind uf(g.n);
    for (int i = 0; i < g.n; i++) {
        for (int to : g[i]) {
            if (i > to || low_link.is_bridge(i, to))
                continue;
            uf.merge(i, to);
        }
    }
    return uf.groups();
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    Graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        std::cin >> u >> v;
        g.add_edge(u, v);
    }
    g.build();

    auto comps = two_edge_connected_components_impl(g);
    std::cout << comps.size() << '\n';
    for (const auto &c : comps) {
        std::cout << c.size();
        for (int v : c)
            std::cout << ' ' << v;
        std::cout << '\n';
    }
}
