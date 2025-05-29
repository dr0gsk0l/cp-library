#include <numeric>
#include <ranges>
#include <utility>
#include <vector>

#include "library/graph/Graph.hpp"

class LowLink {
    Graph g;
    std::vector<int> ord, low_link;
    int cnt;

    static inline void chmin(int &a, int b) { a = std::min(a, b); }

    void dfs(int p, int v) {
        ord[v] = cnt++;
        for (int to : g[v])
            if (~ord[to]) {
                if (to != p)
                    chmin(low_link[v], to);
            } else {
                dfs(v, to);
                chmin(low_link[v], low_link[to]);
            }
    }

  public:
    LowLink(const Graph &g) : g(g), ord(g.n, -1), low_link(g.n), cnt(0) {
        std::iota(low_link.begin(), low_link.end(), 0);
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