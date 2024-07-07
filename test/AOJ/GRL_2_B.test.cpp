#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"
#include <bits/stdc++.h>

#include "library/graph/MinimumSpanningArborescence.hpp"
#include "library/graph/WeightedGraph.hpp"

int main() {
    int n, m, r;
    std::cin >> n >> m >> r;
    WeightedGraph<int> g(n, m, true, 0);
    auto ans = minimum_spanning_arborescence(g, r);
    assert(ans.has_value());
    std::cout << ans.value().first << std::endl;
}