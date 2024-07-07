#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/segtree/SegmentTree.hpp"

using ll = long long;
using G = GroupAdd<ll>;

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<ll> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    SegmentTree<G> seg(v);
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        if (t)
            std::cout << seg.prod(l, r) << "\n";
        else
            seg.multiply(l, r);
    }
}