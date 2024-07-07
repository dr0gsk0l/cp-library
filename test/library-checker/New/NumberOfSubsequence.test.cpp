#define PROBLEM "https://judge.yosupo.jp/problem/number_of_subsequences"
#include <bits/stdc++.h>

#include "library/mod/Modint.hpp"
#include "library/util/Subsequence.hpp"
using mint = Mint<long long>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    std::cout << sparse_subsequence<mint, int>(v) - 1 << std::endl;
}