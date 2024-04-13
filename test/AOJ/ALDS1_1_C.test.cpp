#define PROBLEM                                                                \
    "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include <bits/stdc++.h>

#include "library/util/PrimeUtil.cpp"
PrimeUtil<1000000> PU;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    while (n--) {
        int a;
        cin >> a;
        ans += PU.is_prime(a);
    }
    std::cout << ans << std::endl;
}