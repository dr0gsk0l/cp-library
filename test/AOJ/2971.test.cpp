#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2971"
#include <bits/stdc++.h>

#include "library/algebra/group/Multiply.cpp"
#include "library/datastructure/unionfind/PotentialUnionFind.cpp"
#include "library/mod/Modint.cpp"
using ll = long long;
using mint1 = Mint<ll, 998244341>;
using mint2 = Mint<ll, 998244389>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    PotentialUnionFind<GroupMultiply<mint1>> uf1(n);
    PotentialUnionFind<GroupMultiply<mint2>> uf2(n);

    while (m--) {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        if (!uf1.merge(a, b, c) || !uf2.merge(a, b, c)) {
            std::cout << "No\n";
            return 0;
        }
    }
    std::cout << "Yes\n";
}