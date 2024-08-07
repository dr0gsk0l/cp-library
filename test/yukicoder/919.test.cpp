#define PROBLEM "https://yukicoder.me/problems/no/919"
#include <bits/stdc++.h>

#include "library/datastructure/WaveletMatrix.hpp"

using ll = long long;
const int INF = 1000'000'000;

void chmax(ll &a, ll b) { a = std::max(a, b); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        v[i] += INF;
    }

    WaveletMatrix<int> WM(v);
    ll ans = 0;
    for (int k = 1; k <= n; k++) {
        std::vector<ll> pre{0};
        for (int i = 0; i + k <= n; i += k) {
            ll b = WM.kth_smallest(i, i + k, (k - 1) / 2);
            pre.push_back(pre.back() + (b - INF) * k);
        }
        for (int i = 1; i < pre.size(); i++)
            chmax(pre[i], pre[i - 1]);
        chmax(ans, pre.back());
        ll sum = 0;
        for (int r = n, id = pre.size() - 2; r - k >= 0; r -= k, id--) {
            ll b = WM.kth_smallest(r - k, r, (k - 1) / 2);
            sum += (b - INF) * k;
            chmax(ans, pre[id] + sum);
        }
    }
    std::cout << ans << std::endl;
}