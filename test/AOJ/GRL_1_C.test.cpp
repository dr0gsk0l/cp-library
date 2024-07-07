#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C"
#include <bits/stdc++.h>

#include "library/graph/NegativeCycleFind.hpp"
#include "library/graph/WeightedGraph.hpp"
#include "library/graph/shortest_path/WarshallFloyd.hpp"

using ll = long long;

int main() {
    int n, m;
    std::cin >> n >> m;
    WeightedGraph<ll> g(n, m, true, 0);
    if (negative_cycle_find(g))
        std::cout << "NEGATIVE CYCLE\n";
    else {
        auto d = warshall_floyd(g);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (d[i][j] < 1e10)
                    std::cout << d[i][j] << "\n "[j + 1 < n];
                else
                    std::cout << "INF" << "\n "[j + 1 < n];
    }
}