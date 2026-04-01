#include <numeric>
#include <ranges>
#include <utility>
#include <vector>
#include <algorithm>
#include <cassert>

#include "library/graph/Graph.hpp"

class LowLink {
    Graph g;
    std::vector<int> ord, low_link;
    int cnt;

    static inline void chmin(int &a, int b) { a = std::min(a, b); }

    void dfs(int p, int v) {
        ord[v] = low_link[v] = cnt++;
        bool used_parent_edge = false;
        for (int to : g[v]) {
            if (to == p && !used_parent_edge) {
                used_parent_edge = true;
                continue;
            }
            if (ord[to] < 0) {
                dfs(v, to);
                chmin(low_link[v], low_link[to]);
            } else {
                chmin(low_link[v], ord[to]);
            }
        }
    }

  public:
    LowLink(const Graph &g) : g(g), ord(g.n, -1), low_link(g.n), cnt(0) {
        assert(g.is_prepared());
        for (int v = 0; v < g.n; v++)
            if (ord[v] < 0)
                dfs(-1, v);
    }

    int get_ord(int v) const { return ord[v]; }
    int get_low_link(int v) const { return low_link[v]; }
    bool is_bridge(int u, int v) const {
        if (ord[u] > ord[v])
            std::swap(u, v);
        return ord[u] < low_link[v];
    }
};
