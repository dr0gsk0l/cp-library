#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <bits/stdc++.h>

#include "library/algebra/lazy/AddMin.hpp"
#include "library/segtree/DualSegmentTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    DualSegmentTree<LazyAddMin<int>> seg(std::vector<int>(n, 0));
    while (q--) {
        int t;
        std::cin >> t;
        if (t) {
            int x;
            std::cin >> x;
            x--;
            std::cout << seg[x] << "\n";
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        }
    }
}
