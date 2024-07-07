#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include <bits/stdc++.h>

#include "library/tree/RootedTreeIsomorphism.hpp"
#include "library/tree/Tree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Tree t(n);
    t.scan_root(0);

    auto [k, hsh] = rooted_tree_isomorphism(t);
    std::cout << k << "\n";
    for (int p : hsh)
        std::cout << p << " ";
    std::cout << "\n";
}