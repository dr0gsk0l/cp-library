#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>

#include "library/algebra/lazy/SetMin.hpp"
#include "library/segtree/DualSegmentTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    DualSegmentTree<LazySetMin<int>> seg(std::vector<int>(n, (1LL << 31) - 1));
    while (q--) {
        int t;
        std::cin >> t;
        if (t) {
            int i;
            std::cin >> i;
            std::cout << seg[i] << "\n";
        } else {
            int l, r, x;
            std::cin >> l >> r >> x;
            r++;
            seg.apply(l, r, x);
        }
    }
}