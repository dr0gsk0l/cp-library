#define PROBLEM "https://judge.yosupo.jp/problem/std::set_xor_min"
#include <bits/stdc++.h>

#include "library/datastructure/BinaryTrie.cpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    BinaryTrie<30, int> BT;
    int q;
    std::cin >> q;
    while (q--) {
        int t, x;
        std::cin >> t >> x;
        if (t <= 1) {
            int c = BT.count(x);
            if (t == 0 and c == 0)
                BT.add(x, +1);
            if (t == 1 and c == 1)
                BT.add(x, -1);
        } else
            std::cout << BT.min(x) << "\n";
    }
}
