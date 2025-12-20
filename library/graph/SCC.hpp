#pragma once
#include <cassert>
#include <cstdint>
#include <ranges>
#include <vector>
#include <algorithm>
#include "library/graph/Graph.hpp"
#include "library/graph/ReverseGraph.hpp"
template <typename DirectedGraph> class SCC {
    int n;
    DirectedGraph G, R;
    std::vector<int> visit, belong;
    std::vector<uint8_t> used;
    void dfs(int v) {
        used[v] = true;
        for (int to : G[v])
            if (!used[to])
                dfs(to);
        visit.push_back(v);
    }
    void rdfs(int v, int k) {
        used[v] = true;
        belong[v] = k;
        for (int to : R[v])
            if (!used[to])
                rdfs(to, k);
    }

  public:
    Graph DAG;
    std::vector<std::vector<int>> component;
    SCC(const DirectedGraph &G) : n(G.n), G(G), belong(n), used(n, false) {
        assert(G.is_prepared());
        visit.reserve(n);
        R = reverse_graph(G);
        for (int v : std::views::iota(0, n))
            if (!used[v])
                dfs(v);
        std::ranges::fill(used, false);
        std::ranges::reverse(visit);
        int k = 0;
        for (const int &v : visit)
            if (!used[v])
                rdfs(v, k++);
        std::vector<std::vector<int>> edges(k);
        component.resize(k);
        for (int v : std::views::iota(0, n)) {
            component[belong[v]].push_back(v);
            for (int to : G[v])
                if (belong[v] != belong[to])
                    edges[belong[v]].push_back(belong[to]);
        }
        DAG = Graph(k);
        for (int from : std::views::iota(0, k)) {
            std::ranges::sort(edges[from]);
            bool first = true;
            int prev = -1;
            for (int to : edges[from]) {
                if (first || to != prev)
                    DAG.add_arc(from, to);
                first = false;
                prev = to;
            }
        }
    }
    int operator[](int k) { return belong[k]; }
};
