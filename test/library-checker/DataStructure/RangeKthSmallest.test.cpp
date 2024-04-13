#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <bits/stdc++.h>

#include "library/datastructure/WaveletMatrix.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    WaveletMatrix<int> WM(v);
    while (q--) {
        int l, r, k;
        std::cin >> l >> r >> k;
        std::cout << WM.kth_smallest(l, r, k) << "\n";
    }
}
