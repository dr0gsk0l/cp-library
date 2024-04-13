#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <bits/stdc++.h>

#include "library/tree/HLD.cpp"
#include "library/tree/Tree.cpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    Tree t(n);
    t.scan_root(0);
    HLD hld(t);
    hld.build();
    while (q--) {
        int u, v;
        std::cin >> u >> v;
        std::cout << hld.lca(u, v) << "\n";
    }
}