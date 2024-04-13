#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"
#include <bits/stdc++.h>

#include "library/algebra/Reverse.cpp"
#include "library/algebra/group/Affine.cpp"
#include "library/datastructure/SWAG.cpp"
#include "library/mod/Modint.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    using mint = Mint<long long>;
    using G = AlgebraReverse<GroupAffine<mint>>;
    using F = G::value_type;

    SWAG<G> S;

    int q;
    cin >> q;
    while (q--) {
        int t;
        cin >> t;
        if (t == 0) {
            F f;
            cin >> f;
            S.push_back(f);
        }
        if (t == 1)
            S.pop_front();
        if (t == 2) {
            int x;
            cin >> x;
            F f = S.prod();
            std::cout << f(x) << "\n";
        }
    }
}