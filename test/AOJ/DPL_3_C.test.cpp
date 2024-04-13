#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C"
#include <bits/stdc++.h>

#include "library/tree/CartesianTree.cpp"

using ll = long long;
void chmax(ll &a, ll b) { a = std::max(a, b); }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<ll> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    auto T = cartesian_tree(v);

    ll ans = 0;
    chmax(ans, v[T.root] * n);
    for (int i = 0; i < n; i++)
        for (const auto &e : T.son(i)) {
            const auto &[L, R] = e.weight;
            chmax(ans, v[e.to] * (R - L));
        }
    std::cout << ans << std::endl;
}