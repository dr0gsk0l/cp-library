#define PROBLEM "https://judge.yosupo.jp/problem/matrix_product"
#include <bits/stdc++.h>

#include "library/linearalgebra/Matrix.hpp"
#include "library/mod/Modint.hpp"

using mint = Mint<long long, 998244353>;
using M = Matrix<mint>;

#define REP(i, n) for (int i = 0; i < (n); i++)

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    M A(n, m), B(m, k);
    std::cin >> A >> B;
    M C = A * B;
    REP (i, n)
        REP (j, k)
            std::cout << C[i][j] << "\n "[j + 1 < k];
}