#define PROBLEM "https://judge.yosupo.jp/problem/predecessor_problem"
#include <bits/stdc++.h>

#include "library/datastructure/BinaryTrie.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;

    BinaryTrie<30> bt;
    for (int i = 0; i < n; i++) {
        char c;
        std::cin >> c;
        if (c == '1')
            bt.add(i);
    }

    while (q--) {
        int type, k;
        std::cin >> type >> k;
        if (type == 0) {
            if (bt.count(k) == 0)
                bt.add(k);
        }
        if (type == 1) {
            if (bt.count(k) == 1)
                bt.add(k, -1);
        }
        if (type == 2)
            std::cout << bt.count(k) << "\n";
        if (type == 3) {
            int rank = bt.count_ranges(0u, static_cast<unsigned int>(k));
            if (rank == bt.size())
                std::cout << -1 << "\n";
            else
                std::cout << bt.k_th(rank) << "\n";
        }
        if (type == 4) {
            int rank = bt.count_ranges(0u, static_cast<unsigned int>(k) + 1);
            if (rank == 0)
                std::cout << -1 << "\n";
            else
                std::cout << bt.k_th(rank - 1) << "\n";
        }
    }
}
