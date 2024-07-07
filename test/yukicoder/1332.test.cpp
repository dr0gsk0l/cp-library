#define PROBLEM "https://yukicoder.me/problems/no/1332"
#include <bits/stdc++.h>

#include "library/datastructure/WaveletMatrix.hpp"
const int INF = 1e9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    WaveletMatrix WM(v);

    int q;
    std::cin >> q;
    while (q--) {
        int l, r, x;
        std::cin >> l >> r >> x;
        l--;
        std::cout << std::min(x - (WM.leq(l, r, x)).value_or(-INF),
                              (WM.geq(l, r, x)).value_or(2 * INF) - x)
                  << "\n";
    }
}