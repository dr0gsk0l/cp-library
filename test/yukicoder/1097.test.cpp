#define PROBLEM "https://yukicoder.me/problems/no/1097"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.hpp"
#include "library/datastructure/Doubling.hpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    Doubling<GroupAdd<ll>, 40> db(n);

    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        db.add_arc(i, (i + a) % n, a);
    }

    int q;
    std::cin >> q;
    while (q--) {
        ll k;
        std::cin >> k;
        std::cout << db.calc(0, k).second << "\n";
    }
}