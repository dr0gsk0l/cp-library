#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>

#include "library/graph/MinimumSpanningTree.cpp"
#include "library/graph/WeightedGraph.cpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    WeightedGraph<int> g(n, m, false, 0);
    auto [sum, tree] = minimum_spanning_tree(g);
    std::cout << sum << std::endl;
}