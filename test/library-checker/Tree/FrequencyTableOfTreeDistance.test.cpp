#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/frequency_table_of_tree_distance"
#include <bits/stdc++.h>

#include <atcoder/convolution>
using namespace atcoder;

#include "library/tree/CentroidDecomposition.cpp"
#include "library/tree/Tree.cpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Tree T(n);
    T.scan(0);

    CentroidDecomposition CD(T);

    std::vector<ll> ans(n, 0), D{0};

    auto next_val = [&](int d, auto &e) { return d + 1; };
    auto action = [&](int d, bool add) {
        if (D.size() <= d)
            D.push_back(0);
        D[d]++;
    };
    auto finish = [&](bool add) {
        auto D2 = convolution_ll(D, D);
        for (int i = 0; i < D2.size() and i < n; i++)
            if (add)
                ans[i] += D2[i];
            else
                ans[i] -= D2[i];
        D = std::vector<ll>{0};
    };

    CD.all_calc(0, next_val, action, finish);

    for (int i = 1; i < n; i++)
        std::cout << ans[i] / 2 << "\n "[i + 1 < n];
}