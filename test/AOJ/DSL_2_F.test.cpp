#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F"
#include <bits/stdc++.h>

#include "library/algebra/lazy/SetMin.cpp"
#include "library/segtree/LazySegmentTree.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    LazySegmentTree<LazySetMin<long long>> seg(
        std::vector<long long>(n, (1LL << 31) - 1));
    while (q--) {
        int t, l, r;
        cin >> t >> l >> r;
        r++;
        if (t)
            std::cout << seg.prod(l, r) << "\n";
        else {
            int x;
            cin >> x;
            seg.apply(l, r, x);
        }
    }
}