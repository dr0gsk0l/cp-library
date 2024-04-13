#define PROBLEM "https://judge.yosupo.jp/problem/matrix_det"
#include <bits/stdc++.h>

#include "library/linearalgebra/Matrix.cpp"
#include "library/mod/Modint.cpp"

using mint = Mint<long long, 998244353>;
using M = Matrix<mint>;

int main() {
    int n;
    std::cin >> n;
    M A(n, n);
    std::cin >> A;
    std::cout << A.det() << std::endl;
}