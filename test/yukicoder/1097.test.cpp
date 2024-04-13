#define PROBLEM "https://yukicoder.me/problems/no/1097"
#include <bits/stdc++.h>

#include "library/algebra/group/Add.cpp"
#include "library/datastructure/Doubling.cpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    Doubling<GroupAdd<ll>, 40> db(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        db.add_arc(i, (i + a) % n, a);
    }

    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        std::cout << db.calc(0, k).second << "\n";
    }
}