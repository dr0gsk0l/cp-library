#define PROBLEM "https://judge.yosupo.jp/problem/cartesian_tree"
#include <bits/stdc++.h>

#include "library/tree/CartesianTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    auto T = cartesian_tree(v);
    for (int i = 0; i < n; i++)
        std::cout << (i == T.root ? i : T.parent(i).to) << "\n "[i + 1 < n];
}