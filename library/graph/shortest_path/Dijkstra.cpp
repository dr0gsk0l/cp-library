template <typename WG, typename T = typename WG::weight_type>
std::pair<std::vector<T>, std::vector<int>> dijkstra(const WG &g, int s = 0) {
    assert(g.is_prepared());
    std::vector<T> d(g.n, -1);
    std::vector<int> pre(g.n, -1);
    std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>,
                        greater<std::pair<T, int>>>
        que;
    d[s] = 0;
    que.emplace(0, s);
    while (que.size()) {
        auto [now, id] = que.top();
        que.pop();
        if (d[id] < now)
            continue;
        for (const auto &e : g[id])
            if (d[e.to] == -1 || d[e.to] > now + e.weight) {
                d[e.to] = now + e.weight;
                pre[e.to] = id;
                que.emplace(d[e.to], e.to);
            }
    }
    return {d, pre};
}