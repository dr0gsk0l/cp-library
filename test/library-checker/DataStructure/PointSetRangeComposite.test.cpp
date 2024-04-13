#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"
#include <bits/stdc++.h>

#include "library/algebra/Reverse.cpp"
#include "library/algebra/group/Affine.cpp"
#include "library/mod/Modint.cpp"
#include "library/segtree/SegmentTree.cpp"

using ll = long long;
using mint = Mint<ll>;
using G_ = GroupAffine<mint>;
using G = AlgebraReverse<G_>;
using F = G::value_type;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<F> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    SegmentTree<G> seg(v);
    while (q--) {
        int t, l, r, x;
        std::cin >> t >> l >> r >> x;
        if (t) {
            F f = seg.prod(l, r);
            std::cout << f(x) << "\n";
        } else
            seg.set(l, F(r, x));
    }
}