#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include <bits/stdc++.h>

#include "library/algebra/monoid/Gcd.cpp"
#include "library/datastructure/SWAG.cpp"

using ll = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    SWAG<MonoidGcd<ll>> S;

    ll ans = ll(n) * ll(n + 1) / 2;
    while (n--) {
        ll a;
        std::cin >> a;
        S.push_back(a);
        while (S.prod() == 1)
            S.pop_front();
        ans -= S.size();
    }
    std::cout << ans << std::endl;
}
