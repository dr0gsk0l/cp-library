#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_H"
#include <bits/stdc++.h>

#include "library/algebra/lazy/AddMin.cpp"
#include "library/segtree/LazySegmentTree.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    LazySegmentTree<LazyAddMin<int>> seg(vector<int>(n, 0));
    while (q--) {
        int t, l, r;
        std::cin >> t >> l >> r;
        r++;
        if (t)
            std::cout << seg.prod(l, r) << "\n";
        else {
            int x;
            std::cin >> x;
            seg.apply(l, r, x);
        }
    }
}
