#define PROBLEM "https://judge.yosupo.jp/problem/unionfind_with_potential"

#include <atcoder/modint>
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/unionfind/PotentialUnionFind.hpp"

using mint = atcoder::modint998244353;

int main() {
    int n, q;
    std::cin >> n >> q;

    PotentialUnionFind<GroupAdd<mint>> uf(n);
    while (q--) {
        int t, u, v;
        std::cin >> t >> u >> v;
        if (t == 0) {
            int x;
            std::cin >> x;

            std::cout << uf.merge(u, v, mint::raw(x)) << std::endl;
        } else {
            auto d = uf.diff(u, v);
            if (d.has_value())
                std::cout << d.value().val() << std::endl;
            else
                std::cout << -1 << std::endl;
        }
    }
}