#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>

#include "library/datastructure/CumulativeSum.hpp"

int main() {
    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    auto wa = CumulativeSum(v);
    while (q--) {
        int l, r;
        std::cin >> l >> r;
        std::cout << wa.sum(l, r) << '\n';
    }
}