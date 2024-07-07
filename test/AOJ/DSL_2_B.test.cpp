#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_B"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/FenwickTree.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    FenwickTree<GroupAdd<int>> ft(n);
    while (q--) {
        int c, s, t;
        std::cin >> c >> s >> t;
        s--;
        if (c) {
            assert(s <= t);
            std::cout << ft.prod(s, t) << "\n";
        } else
            ft.multiply(s, t);
    }
}