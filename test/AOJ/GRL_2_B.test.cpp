#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_B"
#include <bits/stdc++.h>

#include "library/graph/MinimumSpanningArborescence.cpp"
#include "library/graph/WeightedGraph.cpp"

int main() {
    int n, m, r;
    cin >> n >> m >> r;
    WeightedGraph<int> g(n, m, true, 0);
    auto ans = minimum_spanning_arborescence(g, r);
    assert(ans.has_value());
    std::cout << ans.value().first << std::endl;
}