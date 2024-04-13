#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification"
#include <bits/stdc++.h>

#include "library/tree/RootedTreeIsomorphism.cpp"
#include "library/tree/Tree.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    Tree t(n);
    t.scan_root(0);

    auto [k, hsh] = rooted_tree_isomorphism(t);
    std::cout << k << "\n";
    for (int p : hsh)
        std::cout << p << " ";
    std::cout << "\n";
}