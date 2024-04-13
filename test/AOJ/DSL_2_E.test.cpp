#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_E"
#include <bits/stdc++.h>

#include "library/algebra/lazy/AddMin.cpp"
#include "library/segtree/DualSegmentTree.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    DualSegmentTree<LazyAddMin<int>> seg(vector<int>(n, 0));
    while (q--) {
        int t;
        cin >> t;
        if (t) {
            int x;
            cin >> x;
            x--;
            std::cout << seg[x] << "\n";
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            l--;
            seg.apply(l, r, x);
        }
    }
}
