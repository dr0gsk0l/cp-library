#define PROBLEM "https://yukicoder.me/problems/no/416"
#include <bits/stdc++.h>

#include "library/datastructure/unionfind/PartialPersistentUnionFind.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, q;
    std::cin >> n >> m >> q;
    PartialPersistentUnionFind uf(n);

    std::set<std::pair<int, int>> edge;
    while (m--) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        edge.insert(std::minmax(a, b));
    }

    std::vector<std::pair<int, int>> query(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        std::cin >> a >> b;
        a--;
        b--;
        edge.erase(std::minmax(a, b));
        query[i] = std::minmax(a, b);
    }

    for (const auto &[a, b] : edge)
        uf.merge(a, b);

    std::map<int, int> time;
    while (q--) {
        auto [a, b] = query[q];
        int now = uf.merge(a, b);
        time[now] = q + 1;
    }

    for (int i = 1; i < n; i++) {
        int t = uf.when_same(0, i);
        if (t == -1)
            std::cout << 0 << "\n";
        else if (!time.count(t))
            std::cout << -1 << "\n";
        else
            std::cout << time[t] << "\n";
    }
}