#define PROBLEM "https://judge.yosupo.jp/problem/inverse_matrix"
#include <bits/stdc++.h>

#include "library/linearalgebra/Matrix.hpp"
#include "library/mod/Modint.hpp"

using mint = Mint<long long, 998244353>;
using M = Matrix<mint>;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n;
    std::cin >> n;
    M A(n, n);
    std::cin >> A;
    auto B = A.inv();
    if (B.has_value())
        REP (i, n)
            REP (j, n)
                std::cout << B.value()[i][j] << "\n "[j + 1 < n];
    else
        std::cout << -1 << "\n";
}