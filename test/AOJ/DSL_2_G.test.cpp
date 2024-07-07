#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_G"
#include <bits/stdc++.h>

#include "library/algebra/lazy/AddSum.hpp"
#include "library/segtree/LazySegmentTree.hpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    LazySegmentTree<LazyAddSum<ll>> seg(cnt_init(n, 0LL));

    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        l--;
        if (t)
            std::cout << seg.prod(l, r).first << "\n";
        else {
            int x;
            std::cin >> x;
            seg.apply(l, r, x);
        }
    }
}