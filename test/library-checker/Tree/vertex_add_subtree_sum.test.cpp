#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    using G = GroupAdd<long long>;

    int n, q;
    cin >> n >> q;
    std::vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    Tree t(n);
    t.scan_root(0);

    TreeMonoid<Tree, G> TM(t, a);

    while (q--) {
        int c;
        cin >> c;
        if (c) {
            int u;
            cin >> u;
            std::cout << TM.subtree_prod(u) << "\n";
        } else {
            int u, x;
            cin >> u >> x;
            TM.multiply(u, x);
        }
    }
}