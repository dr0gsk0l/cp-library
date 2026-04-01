#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <bits/stdc++.h>

#include "library/algebra/monoid/Min.hpp"
#include "library/segtree/SegmentTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];

    SegmentTree<MonoidMin<int>> seg(a);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << seg.prod(l, r) << '\n';
    }
}
