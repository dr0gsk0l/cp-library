#define PROBLEM                                                                \
    "https://judge.yosupo.jp/problem/double_ended_std::priority_queue"
#include <bits/stdc++.h>

#include "library/superstd/Multiset.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q;
    std::cin >> n >> q;
    Multiset<int> s;
    s.scan(n);
    while (q--) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int x;
            std::cin >> x;
            s.insert(x);
        }
        if (t == 1) {
            int a = s.pick_mn();
            std::cout << a << "\n";
        }
        if (t == 2) {
            int a = s.pick_mx();
            std::cout << a << "\n";
        }
    }
}
