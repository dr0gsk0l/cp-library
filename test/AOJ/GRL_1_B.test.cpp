#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_B"
#include <bits/stdc++.h>

#include "library/graph/WeightedGraph.hpp"
#include "library/graph/shortest_path/BellmanFord.hpp"

using ll = long long;

int main() {
    int n, m, s;
    std::cin >> n >> m >> s;
    WeightedGraph<ll> g(n, m, true, 0);
    auto [d, pre] = bellman_ford(g, s);
    for (const auto &p : d)
        if (!p) {
            std::cout << "NEGATIVE CYCLE\n";
            return 0;
        }
    for (int i = 0; i < n; i++)
        if (~pre[i] || i == s)
            std::cout << d[i].value() << "\n";
        else
            std::cout << "INF\n";
}