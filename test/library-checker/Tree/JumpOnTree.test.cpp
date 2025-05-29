#define PROBLEM "https://judge.yosupo.jp/problem/jump_on_tree"
#include <bits/stdc++.h>

#include "library/tree/Tree.hpp"
#include "library/tree/HLD.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Tree T(n);
    T.scan(0);

    HLD hld(T);
    hld.build();

    int q;
    std::cin >> q;
    while(q--){
        int u, v, k;
        std::cin >> u >> v >> k;
        std::cout << hld.jump(u, v, k) << "\n";
    }
}