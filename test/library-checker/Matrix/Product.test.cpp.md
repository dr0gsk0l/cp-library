---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/linearalgebra/Matrix.hpp
    title: library/linearalgebra/Matrix.hpp
  - icon: ':question:'
    path: library/math/ExtraGCD.hpp
    title: library/math/ExtraGCD.hpp
  - icon: ':question:'
    path: library/mod/Modint.hpp
    title: library/mod/Modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_product
    links:
    - https://judge.yosupo.jp/problem/matrix_product
  bundledCode: "#line 1 \"test/library-checker/Matrix/Product.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include <bits/stdc++.h>\n\
    \n#line 2 \"library/linearalgebra/Matrix.hpp\"\n#define REP_(i, n) for (int i\
    \ = 0; i < (n); i++)\n#define REP2_(i, s, n) for (int i = (s); i < (n); i++)\n\
    template <typename K> struct Matrix {\n    using value_type = K;\n    using vec\
    \ = std::vector<K>;\n    using mat = std::vector<vec>;\n    size_t r, c;\n   \
    \ mat M;\n\n    Matrix(size_t r, size_t c) : r(r), c(c), M(r, vec(c, K())) {}\n\
    \    Matrix(mat A) : M(A), r(A.size()), c(A[0].size()) {}\n\n    vec &operator[](size_t\
    \ k) { return M[k]; }\n    const vec &operator[](size_t k) const { return M[k];\
    \ }\n\n    Matrix &operator+=(const Matrix &A) {\n        assert(r == A.r && c\
    \ == A.c);\n        REP_(i, r) REP_(j, c) M[i][j] += A[i][j];\n        return\
    \ *this;\n    }\n    Matrix &operator-=(const Matrix &A) {\n        assert(r ==\
    \ A.r && c == A.c);\n        REP_(i, r) REP_(j, c) M[i][j] -= A[i][j];\n     \
    \   return *this;\n    }\n    Matrix operator+(const Matrix &A) { return Matrix(M)\
    \ += A; }\n    Matrix operator-(const Matrix &A) { return Matrix(M) -= A; }\n\n\
    \    friend Matrix operator*(const Matrix &A, const Matrix &B) {\n        assert(A.c\
    \ == B.r);\n        Matrix res(A.r, B.c);\n        REP_(i, A.r) REP_(k, A.c) REP_(j,\
    \ B.c) res[i][j] += A[i][k] * B[k][j];\n        return res;\n    }\n    Matrix\
    \ &operator*=(const Matrix &A) {\n        M = ((*this) * A).M;\n        return\
    \ *this;\n    }\n\n    bool operator==(const Matrix &A) {\n        if (r != A.r\
    \ || c != A.c)\n            return false;\n        REP_(i, r) REP_(j, c) if (M[i][j]\
    \ != A[i][j]) return false;\n        return true;\n    }\n    bool operator!=(const\
    \ Matrix &A) { return !((*this) == A); }\n\n    static Matrix I(size_t n) {\n\
    \        Matrix res(n, n);\n        REP_(i, n) res[i][i] = K(1);\n        return\
    \ res;\n    }\n\n    Matrix pow(long long n) const {\n        assert(n >= 0 &&\
    \ r == c);\n        Matrix A(M), res = I(r);\n        while (n) {\n          \
    \  if (n & 1)\n                res *= A;\n            A *= A;\n            n >>=\
    \ 1;\n        }\n        return res;\n    }\n\n    std::pair<int, int> GaussJordan()\
    \ {\n        int rnk = 0, cnt = 0;\n        REP_(k, c) {\n            if (M[rnk][k]\
    \ == 0)\n                REP2_(i, rnk + 1, r)\n            if (M[i][k] != 0) {\n\
    \                std::swap(M[i], M[rnk]);\n                cnt ^= 1;\n       \
    \         break;\n            }\n            if (M[rnk][k] == 0)\n           \
    \     continue;\n            REP_(i, r) if (i != rnk) {\n                K x =\
    \ M[i][k] / M[rnk][k];\n                REP_(j, c) M[i][j] -= M[rnk][j] * x;\n\
    \            }\n            if (++rnk == r)\n                break;\n        }\n\
    \        return {rnk, cnt};\n    }\n\n    K det() const {\n        assert(r ==\
    \ c);\n        Matrix A(M);\n        const auto &[rnk, cnt] = A.GaussJordan();\n\
    \        if (rnk != r)\n            return 0;\n        K res = 1;\n        REP_(i,\
    \ r) res *= A[i][i];\n        return (cnt ? -res : res);\n    }\n\n    std::optional<Matrix>\
    \ inv() const {\n        assert(r == c);\n        Matrix A(r, c + c);\n      \
    \  REP_(i, r) REP_(j, c) A[i][j] = M[i][j];\n        REP_(i, r) REP_(j, c) A[i][c\
    \ + j] = K(i == j);\n        A.GaussJordan();\n        REP_(i, r) if (A[i][i]\
    \ == 0) return std::nullopt;\n        Matrix res(r, c);\n        REP_(i, r) REP_(j,\
    \ c) res[i][j] = A[i][c + j] / A[i][i];\n        return res;\n    }\n\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Matrix &M) {\n        os <<\
    \ M.M;\n        return os;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, Matrix &M) {\n        REP_(i, M.r) REP_(j, M.c) is >> M.M[i][j];\n    \
    \    return is;\n    }\n};\n#undef REP_\n#undef REP2_\n#line 2 \"library/math/ExtraGCD.hpp\"\
    \nusing ll = long long;\nstd::pair<ll, ll> ext_gcd(ll a, ll b) {\n    if (b ==\
    \ 0)\n        return {1, 0};\n    auto [X, Y] = ext_gcd(b, a % b);\n    // bX\
    \ + (a%b)Y = gcd(a,b)\n    // a%b = a - b(a/b)\n    // \u2234 aY + b(X-(a/b)Y)\
    \ = gcd(a,b)\n    ll x = Y, y = X - (a / b) * Y;\n    return {x, y};\n}\n#line\
    \ 3 \"library/mod/Modint.hpp\"\ntemplate <typename T, T MOD = 998244353> struct\
    \ Mint {\n    inline static constexpr T mod = MOD;\n    T v;\n    Mint() : v(0)\
    \ {}\n    Mint(signed v) : v(v) {}\n    Mint(long long t) {\n        v = t % MOD;\n\
    \        if (v < 0)\n            v += MOD;\n    }\n\n    static Mint raw(int v)\
    \ {\n        Mint x;\n        x.v = v;\n        return x;\n    }\n\n    Mint pow(long\
    \ long k) const {\n        Mint res(1), tmp(v);\n        while (k) {\n       \
    \     if (k & 1)\n                res *= tmp;\n            tmp *= tmp;\n     \
    \       k >>= 1;\n        }\n        return res;\n    }\n\n    static Mint add_identity()\
    \ { return Mint(0); }\n    static Mint mul_identity() { return Mint(1); }\n\n\
    \    // Mint inv()const{return pow(MOD-2);}\n    Mint inv() const { return Mint(ext_gcd(v,\
    \ mod).first); }\n\n    Mint &operator+=(Mint a) {\n        v += a.v;\n      \
    \  if (v >= MOD)\n            v -= MOD;\n        return *this;\n    }\n    Mint\
    \ &operator-=(Mint a) {\n        v += MOD - a.v;\n        if (v >= MOD)\n    \
    \        v -= MOD;\n        return *this;\n    }\n    Mint &operator*=(Mint a)\
    \ {\n        v = 1LL * v * a.v % MOD;\n        return *this;\n    }\n    Mint\
    \ &operator/=(Mint a) { return (*this) *= a.inv(); }\n\n    Mint operator+(Mint\
    \ a) const { return Mint(v) += a; }\n    Mint operator-(Mint a) const { return\
    \ Mint(v) -= a; }\n    Mint operator*(Mint a) const { return Mint(v) *= a; }\n\
    \    Mint operator/(Mint a) const { return Mint(v) /= a; }\n#define FRIEND(op)\
    \                                                             \\\n    friend Mint\
    \ operator op(int a, Mint b) { return Mint(a) op b; }\n    FRIEND(+);\n    FRIEND(-);\n\
    \    FRIEND(*);\n    FRIEND(/);\n#undef FRIEND\n    Mint operator+() const { return\
    \ *this; }\n    Mint operator-() const { return v ? Mint(MOD - v) : Mint(v); }\n\
    \n    bool operator==(const Mint a) const { return v == a.v; }\n    bool operator!=(const\
    \ Mint a) const { return v != a.v; }\n\n    static Mint comb(long long n, int\
    \ k) {\n        Mint num(1), dom(1);\n        for (int i = 0; i < k; i++) {\n\
    \            num *= Mint(n - i);\n            dom *= Mint(i + 1);\n        }\n\
    \        return num / dom;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Mint &m) {\n        os << m.v;\n        return os;\n    }\n    friend\
    \ std::istream &operator>>(std::istream &is, Mint &m) {\n        is >> m.v;\n\
    \        m.v %= MOD;\n        if (m.v < 0)\n            m.v += MOD;\n        return\
    \ is;\n    }\n};\n#line 6 \"test/library-checker/Matrix/Product.test.cpp\"\n\n\
    using mint = Mint<long long, 998244353>;\nusing M = Matrix<mint>;\n\n#define REP(i,\
    \ n) for (int i = 0; i < (n); i++)\n\nint main() {\n    int n, m, k;\n    std::cin\
    \ >> n >> m >> k;\n    M A(n, m), B(m, k);\n    std::cin >> A >> B;\n    M C =\
    \ A * B;\n    REP (i, n)\n        REP (j, k)\n            std::cout << C[i][j]\
    \ << \"\\n \"[j + 1 < k];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_product\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/linearalgebra/Matrix.hpp\"\n#include \"\
    library/mod/Modint.hpp\"\n\nusing mint = Mint<long long, 998244353>;\nusing M\
    \ = Matrix<mint>;\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\nint main()\
    \ {\n    int n, m, k;\n    std::cin >> n >> m >> k;\n    M A(n, m), B(m, k);\n\
    \    std::cin >> A >> B;\n    M C = A * B;\n    REP (i, n)\n        REP (j, k)\n\
    \            std::cout << C[i][j] << \"\\n \"[j + 1 < k];\n}"
  dependsOn:
  - library/linearalgebra/Matrix.hpp
  - library/mod/Modint.hpp
  - library/math/ExtraGCD.hpp
  isVerificationFile: true
  path: test/library-checker/Matrix/Product.test.cpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Matrix/Product.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Matrix/Product.test.cpp
- /verify/test/library-checker/Matrix/Product.test.cpp.html
title: test/library-checker/Matrix/Product.test.cpp
---
