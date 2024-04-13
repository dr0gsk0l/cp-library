#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"

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
    t.scan(0);

    TreeMonoid<Tree, G> TM(t, a);

    while (q--) {
        int c;
        std::cin >> c;
        if (c) {
            int u, v;
            std::cin >> u >> v;
            std::cout << TM.path_prod(u, v) << "\n";
        } else {
            int p, x;
            std::cin >> p >> x;
            TM.multiply(p, x);
        }
    }
}