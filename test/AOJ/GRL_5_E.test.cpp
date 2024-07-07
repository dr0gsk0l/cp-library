#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_E"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/lazy/AddSum.hpp"
#include "library/tree/Tree.hpp"
#include "library/tree/TreeLazy.hpp"
using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    Tree t(n);
    REP (i, n) {
        int k;
        std::cin >> k;
        REP (_, k) {
            int c;
            std::cin >> c;
            t.add_edge(i, c);
        }
    }
    t.build(0);

    TreeLazy<Tree, LazyAddSum<ll>> TL(t, cnt_init(n, 0LL));
    // 辺の情報は子に持たせる
    // 各頂点 v について、根から 1 移動した点が必要
    // Tree に jump を実装してないので無理くり求める
    std::vector<int> root2(n, -1);
    for (int v : t.BFS) {
        if (v == 0)
            continue;
        int p = t.parent(v).to;
        if (p == 0)
            root2[v] = v;
        else
            root2[v] = root2[p];
    }

    int q;
    std::cin >> q;
    REP (_, q) {
        int c;
        std::cin >> c;
        if (c) {
            int u;
            std::cin >> u;
            std::cout << TL.path_prod(u, root2[u]).first << "\n";
        } else {
            int v, w;
            std::cin >> v >> w;
            TL.path_apply(v, root2[v], w);
        }
    }
}
