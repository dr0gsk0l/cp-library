#define PROBLEM "https://yukicoder.me/problems/no/1038"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/algebra/lazy/AddMin.cpp"
#include "library/segtree/DualSegmentTree.cpp"
#include "library/tree/CentroidDecomposition.cpp"
#include "library/tree/Tree.cpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    Tree T(n);
    T.scan(1);

    std::vector<std::tuple<int, int, int>> query(q);
    std::vector<std::vector<int>> query_at(n);
    REP (i, q) {
        auto &[x, y, z] = query[i];
        std::cin >> x >> y >> z;
        x--;
        query_at[x].push_back(i);
    }

    std::vector<ll> ans(q, 0);
    DualSegmentTree<LazyAddMin<ll>> seg(std::vector<ll>(n, 0));
    std::vector<int> D(n), events;
    int root;

    auto next_val = [&](int d, const auto &e) {
        for (int id : query_at[e.to])
            events.push_back(id);
        return D[e.to] = d + 1;
    };
    auto action = [&](int d, bool add) {
        if (d == 0)
            next_val(-1, Edge{root, root});
    };
    auto finish = [&](bool add) {
        sort(events.begin(), events.end());
        for (int id : events) {
            const auto &[x, y, z] = query[id];
            int d = D[x];
            if (add)
                ans[id] += seg[d];
            else
                ans[id] -= seg[d];
            if (d <= y)
                seg.apply(0, y - d + 1, z);
        }
        for (int id : events) {
            const auto &[x, y, z] = query[id];
            int d = D[x];
            if (d <= y)
                seg.apply(0, y - d + 1, -z);
        }
        events.resize(0);
    };

    CentroidDecomposition CD(T);
    for (root = 0; root < n; root++)
        CD.calc(root, 0, next_val, action, finish);

    REP (i, q)
        std::cout << ans[i] << "\n";
}