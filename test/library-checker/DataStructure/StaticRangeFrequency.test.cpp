#define PROBLEM "https://judge.yosupo.jp/problem/static_range_frequency"
#include <bits/stdc++.h>

#include "library/datastructure/WaveletMatrix.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    WaveletMatrix WM(v);

    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        std::cout << WM.rank(l, r, x) << "\n";
    }
}