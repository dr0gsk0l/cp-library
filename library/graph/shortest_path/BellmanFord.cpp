// s からの最短距離が定まるなら最短距離, 無限に小さく出来るなら std::nullopt
// そもそも到達出来ない場合は pre が -1 になっている
template <typename WG, typename T = typename WG::weight_type>
std::pair<std::vector<std::optional<T>>, std::vector<int>>
bellman_ford(const WG &g, int s = 0) {
    assert(g.is_prepared());
    int n = g.n;
    static constexpr T INF = std::numeric_limits<T>::max() / 2;
    std::vector<T> d(n, INF);
    std::vector<int> pre(n, -1);
    d[s] = 0;
    for (int _ = 0; _ < n; _++) {
        bool update = false;
        for (int v = 0; v < n; v++)
            if (d[v] < INF)
                for (const auto &e : g[v])
                    if (d[e.to] > d[v] + e.weight) {
                        d[e.to] = d[v] + e.weight;
                        pre[e.to] = v;
                        update = true;
                    }
        if (!update) {
            std::vector<std::optional<T>> d_(n);
            for (int i = 0; i < n; i++)
                d_[i] = d[i];
            return {d_, pre};
        }
    }
    auto now_d = d;
    for (int v = 0; v < n; v++)
        if (d[v] < INF)
            for (const auto &e : g[v])
                if (d[e.to] > d[v] + e.weight)
                    d[e.to] = d[v] + e.weight;
    for (int _ = 1; _ < n; _++)
        for (int v = 0; v < n; v++)
            if (d[v] < now_d[v])
                for (const auto &e : g[v])
                    if (d[e.to] > d[v] + e.weight)
                        d[e.to] = d[v] + e.weight;
    std::vector<std::optional<T>> res(n);
    for (int v = 0; v < n; v++)
        if (now_d[v] == d[v])
            res[v] = d[v];
        else
            res[v] = std::nullopt;
    return {res, pre};
}
