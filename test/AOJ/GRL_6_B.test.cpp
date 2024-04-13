#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_B"
#include <bits/stdc++.h>

#include "library/flow/MCF.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, f;
    cin >> n >> m >> f;
    MCF<int, int> fl(n);
    while (m--) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        fl.add_arc(u, v, c, d);
    }
    auto [ans, ok] = fl.flow(f);
    std::cout << (ok ? ans : -1) << std::endl;
}