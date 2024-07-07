#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include <bits/stdc++.h>

#include "library/flow/Dinic.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;
    Dinic<int> fl(n, 0, n - 1);
    while (m--) {
        int u, v, c;
        std::cin >> u >> v >> c;
        fl.add_arc(u, v, c);
    }
    std::cout << fl.flow() << std::endl;
}