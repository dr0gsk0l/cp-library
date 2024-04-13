#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_D"
#include <bits/stdc++.h>

#include "library/algebra/lazy/SetMin.cpp"
#include "library/segtree/DualSegmentTree.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    DualSegmentTree<LazySetMin<int>> seg(vector<int>(n, (1LL << 31) - 1));
    while (q--) {
        int t;
        cin >> t;
        if (t) {
            int i;
            cin >> i;
            std::cout << seg[i] << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            r++;
            seg.apply(l, r, x);
        }
    }
}