#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"
#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (n); i++)

#include "library/bitwise/And.cpp"
#include "library/mod/Modint.cpp"

using mint = Mint<long long>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    cin >> n;
    int N = 1 << n;
    std::vector<mint> a(N), b(N);
    REP (i, N)
        cin >> a[i];
    REP (i, N)
        cin >> b[i];
    auto c = BitwiseAnd::convolution(a, b);
    REP (i, N)
        std::cout << c[i] << "\n "[i + 1 < N];
}