#pragma once

#include "library/tree/HLD.hpp"
#include "library/tree/Tree.hpp"
#include "library/tree/WeightedTree.hpp"
#include "library/util/Compress.hpp"

template <typename TREE>
std::pair<WeightedTree<int>, std::vector<int>>
auxiliary_tree(const HLD<TREE> &hld, std::vector<int> vs) {
    assert(hld.prepared);
    std::ranges::sort(vs, [&](int u, int v) { return hld.id[u] < hld.id[v]; });

    std::vector<std::pair<int, int>> edges;
    std::stack<int> sta;
    sta.push(vs[0]);

    for (int i = 0; i + 1 < vs.size(); i++) {
        int w = hld.lca(vs[i], vs[i + 1]);
        if (w != vs[i]) {
            int l = sta.top();
            sta.pop();
            while (sta.size() and hld.T.depth[w] < hld.T.depth[sta.top()]) {
                edges.emplace_back(sta.top(), l);
                l = sta.top();
                sta.pop();
            }
            if (sta.empty() or sta.top() != w)
                sta.push(w);
            edges.emplace_back(w, l);
        }
        sta.push(vs[i + 1]);
    }
    while (sta.size() > 1) {
        int c = sta.top();
        sta.pop();
        edges.emplace_back(c, sta.top());
    }

    Compress<int> C;
    for (const auto &[u, v] : edges)
        C.add(u), C.add(v);

    C.build();

    WeightedTree<int> t(C.size());
    for (const auto &[u, v] : edges)
        t.add_edge(C[u], C[v], abs(hld.T.depth[u] - hld.T.depth[v]));
    t.build();

    std::vector<int> pre_vertex(C.size());
    for (int i = 0; i < C.size(); i++)
        pre_vertex[i] = C.r(i);
    return std::make_pair(t, pre_vertex);
}
