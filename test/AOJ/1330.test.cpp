#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1330"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/unionfind/PotentialUnionFind.hpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    while (std::cin >> n >> m, n) {
        PotentialUnionFind<GroupAdd<ll>> uf(n);
        while (m--) {
            char c;
            int a, b;
            std::cin >> c >> a >> b;
            a--;
            b--;
            if (c == '!') {
                ll w;
                std::cin >> w;
                assert(uf.merge(a, b, w));
            } else {
                auto ans = uf.diff(a, b);
                if (ans)
                    std::cout << ans.value() << "\n";
                else
                    std::cout << "UNKNOWN\n";
            }
        }
    }
}
