#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"
#include <bits/stdc++.h>

#include "library/algebra/lazy/AffineSum.cpp"
#include "library/mod/Modint.cpp"
#include "library/segtree/LazySegmentTree.cpp"

using mint = Mint<long long>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    std::vector<mint> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    LazySegmentTree<LazyAffineSum<mint>> seg(cnt_init(v));

    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        if (t)
            std::cout << seg.prod(l, r).first << '\n';
        else {
            Line<mint> f;
            cin >> f;
            seg.apply(l, r, f);
        }
    }
}