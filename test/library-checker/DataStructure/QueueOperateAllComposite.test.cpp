#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/std::queue_operate_all_composite"
#include <bits/stdc++.h>

#include "library/algebra/Reverse.hpp"
#include "library/algebra/group/Affine.hpp"
#include "library/datastructure/SWAG.hpp"
#include "library/mod/Modint.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    using mint = Mint<long long>;
    using G = AlgebraReverse<GroupAffine<mint>>;
    using F = G::value_type;

    SWAG<G> S;

    int q;
    std::cin >> q;
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            F f;
            std::cin >> f;
            S.push_back(f);
        }
        if (t == 1)
            S.pop_front();
        if (t == 2) {
            int x;
            std::cin >> x;
            F f = S.prod();
            std::cout << f(x) << "\n";
        }
    }
}