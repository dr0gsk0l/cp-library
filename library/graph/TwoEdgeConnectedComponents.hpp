#include "datastructure/unionfind/UnionFind.hpp"
#include "graph/LowLink.hpp"

std::vector<std::vector<int>> two_edge_connected_components(const Graph &g) {
    LowLink low_link(g);
    UnionFind uf(g.n);
    for (int i = 0; i < g.n; i++)
        for (int to : g[i]) {
            if (i > to || low_link.is_bridge(i, to))
                continue;
            uf.merge(i, to);
        }
    return uf.groups();
}