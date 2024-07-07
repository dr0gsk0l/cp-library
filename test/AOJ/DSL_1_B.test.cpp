#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_B"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/unionfind/PotentialUnionFind.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    PotentialUnionFind<GroupAdd<int>> PUF(n);
    while (q--) {
        int t, x, y;
        std::cin >> t >> x >> y;
        if (t) {
            auto diff = PUF.diff(x, y);
            if (diff)
                std::cout << diff.value() << "\n";
            else
                std::cout << "?\n";
        } else {
            int d;
            std::cin >> d;
            assert(PUF.merge(x, y, d));
        }
    }
}