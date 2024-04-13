#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <bits/stdc++.h>

#include "library/algebra/group/Affine.cpp"
#include "library/mod/Modint.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"
using mint = Mint<long long>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    using G = AlgebraReverse<GroupAffine<mint>>;
    using F = G::value_type;

    int n, q;
    cin >> n >> q;

    std::vector<F> f(n);
    for (int i = 0; i < n; i++)
        cin >> f[i];

    Tree t(n);
    t.scan(0);

    TreeMonoid<Tree, G> TM(t, f);

    while (q--) {
        int c;
        cin >> c;
        if (c) {
            int u, v, x;
            cin >> u >> v >> x;
            F g = TM.path_prod(u, v);
            std::cout << g(x) << std::endl;
        } else {
            int p;
            cin >> p;
            F f;
            cin >> f;
            TM.set(p, f);
        }
    }
}