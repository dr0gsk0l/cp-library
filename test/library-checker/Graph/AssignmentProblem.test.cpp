#define PROBLEM "https://judge.yosupo.jp/problem/assignment"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/graph/matching/WeightedBipartiteMatching.cpp"
using ll = long long;
constexpr ll INF = ll(1e9) + 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    WeightedBipartiteMatching<ll> B(n, n);
    REP (i, n)
        REP (j, n) {
            int a;
            cin >> a;
            B.add_edge(i, j, INF - a);
        }
    auto [sum, vec] = B.solve();

    sum -= n * INF;
    sum = -sum;

    std::vector<int> res(n);
    for (const auto &[from, to, weight] : vec)
        res[from] = to;

    std::cout << sum << "\n";
    REP (i, n)
        std::cout << res[i] << "\n "[i + 1 < n];
}
