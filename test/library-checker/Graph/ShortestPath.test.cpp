#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"
#include <bits/stdc++.h>

#include "library/graph/WeightedGraph.cpp"
#include "library/graph/shortest_path/Dijkstra.cpp"

using ll = long long;

int main() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    WeightedGraph<ll> g(n, m, true, 0);
    auto [d, pre] = dijkstra(g, s);

    std::cout << d[t];
    if (d[t] < 0) {
        std::cout << "\n";
        return 0;
    }

    std::vector<pair<int, int>> ans;
    while (t != s) {
        ans.emplace_back(pre[t], t);
        t = pre[t];
    }
    reverse(ans.begin(), ans.end());
    std::cout << " " << ans.size() << "\n";
    for (const auto &[from, to] : ans)
        std::cout << from << " " << to << "\n";
}