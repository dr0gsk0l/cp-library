#define PROBLEM "https://judge.yosupo.jp/problem/static_range_sum"
#include <bits/stdc++.h>

#include "library/datastructure/CumulativeSum.cpp"

int main() {
    int n, q;
    cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    auto wa = CumulativeSum(v);
    while (q--) {
        int l, r;
        cin >> l >> r;
        std::cout << wa.sum(l, r) << '\n';
    }
}