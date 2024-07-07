#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/tree/Tree.hpp"
#include "library/tree/TreeMonoid.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    using G = GroupAdd<long long>;

    int n, q;
    std::cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    Tree t(n);
    t.scan_root(0);

    TreeMonoid<Tree, G> TM(t, a);

    while (q--) {
        int c;
        std::cin >> c;
        if (c) {
            int u;
            std::cin >> u;
            std::cout << TM.subtree_prod(u) << "\n";
        } else {
            int u, x;
            std::cin >> u >> x;
            TM.multiply(u, x);
        }
    }
}