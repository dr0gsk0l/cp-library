#define PROBLEM "https://judge.yosupo.jp/problem/minimum_spanning_tree"
#include <bits/stdc++.h>

#include "library/graph/MinimumSpanningTree.hpp"
#include "library/graph/WeightedGraph.hpp"

using ll = long long;

struct Weight {
    ll cost;
    int id;
    bool operator<(const Weight &other) const { return cost < other.cost; }
    operator ll() const { return cost; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    WeightedGraph<Weight> g(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        ll c;
        std::cin >> u >> v >> c;
        g.add_edge(u, v, Weight{c, i});
    }
    g.build();

    auto [cost, tree] = minimum_spanning_tree<WeightedGraph<Weight>, ll>(g);
    std::cout << cost << "\n";
    for (int i = 0; i < n - 1; i++) {
        if (i)
            std::cout << ' ';
        std::cout << g.edges[tree[i]].weight.id;
    }
    std::cout << '\n';
}
