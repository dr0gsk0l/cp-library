#define PROBLEM "https://yukicoder.me/problems/no/924"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/GroupWaveletMatrix.hpp"

using ll = long long;
constexpr ll LINF = 1e18;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    std::vector<ll> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    GroupWaveletMatrix<ll, GroupAdd<ll>> WM(v, v);

    while (q--) {
        int l, r;
        std::cin >> l >> r;
        l--;
        int k = (r - l) / 2; // 0-indexed 小さい方から k 番目の値を x にする
        ll x = WM.kth_smallest(l, r, k);
        ll res = 0;
        // x 未満
        ll cnt1 = WM.range_freq(l, r, x);
        res += x * cnt1 - WM.sum(l, r, x);
        // x 以上
        ll cnt2 = WM.range_freq(l, r, x, LINF);
        res += WM.sum(l, r, x, LINF) - x * cnt2;

        std::cout << res << "\n";
    }
}