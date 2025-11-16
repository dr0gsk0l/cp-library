---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Det.test.cpp
    title: test/library-checker/Matrix/Det.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Inverse.test.cpp
    title: test/library-checker/Matrix/Inverse.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Matrix/Product.test.cpp
    title: test/library-checker/Matrix/Product.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Matrix.hpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define REP2_(i, s, n) for (int i = (s); i < (n);\
    \ i++)\ntemplate <typename K> struct Matrix {\n    using value_type = K;\n   \
    \ using vec = std::vector<K>;\n    using mat = std::vector<vec>;\n    size_t r,\
    \ c;\n    mat M;\n\n    Matrix(size_t r, size_t c) : r(r), c(c), M(r, vec(c, K()))\
    \ {}\n    Matrix(mat A) : M(A), r(A.size()), c(A[0].size()) {}\n\n    vec &operator[](size_t\
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
    \    return is;\n    }\n};\n#undef REP_\n#undef REP2_\n"
  code: "#pragma once\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n#define REP2_(i,\
    \ s, n) for (int i = (s); i < (n); i++)\ntemplate <typename K> struct Matrix {\n\
    \    using value_type = K;\n    using vec = std::vector<K>;\n    using mat = std::vector<vec>;\n\
    \    size_t r, c;\n    mat M;\n\n    Matrix(size_t r, size_t c) : r(r), c(c),\
    \ M(r, vec(c, K())) {}\n    Matrix(mat A) : M(A), r(A.size()), c(A[0].size())\
    \ {}\n\n    vec &operator[](size_t k) { return M[k]; }\n    const vec &operator[](size_t\
    \ k) const { return M[k]; }\n\n    Matrix &operator+=(const Matrix &A) {\n   \
    \     assert(r == A.r && c == A.c);\n        REP_(i, r) REP_(j, c) M[i][j] +=\
    \ A[i][j];\n        return *this;\n    }\n    Matrix &operator-=(const Matrix\
    \ &A) {\n        assert(r == A.r && c == A.c);\n        REP_(i, r) REP_(j, c)\
    \ M[i][j] -= A[i][j];\n        return *this;\n    }\n    Matrix operator+(const\
    \ Matrix &A) { return Matrix(M) += A; }\n    Matrix operator-(const Matrix &A)\
    \ { return Matrix(M) -= A; }\n\n    friend Matrix operator*(const Matrix &A, const\
    \ Matrix &B) {\n        assert(A.c == B.r);\n        Matrix res(A.r, B.c);\n \
    \       REP_(i, A.r) REP_(k, A.c) REP_(j, B.c) res[i][j] += A[i][k] * B[k][j];\n\
    \        return res;\n    }\n    Matrix &operator*=(const Matrix &A) {\n     \
    \   M = ((*this) * A).M;\n        return *this;\n    }\n\n    bool operator==(const\
    \ Matrix &A) {\n        if (r != A.r || c != A.c)\n            return false;\n\
    \        REP_(i, r) REP_(j, c) if (M[i][j] != A[i][j]) return false;\n       \
    \ return true;\n    }\n    bool operator!=(const Matrix &A) { return !((*this)\
    \ == A); }\n\n    static Matrix I(size_t n) {\n        Matrix res(n, n);\n   \
    \     REP_(i, n) res[i][i] = K(1);\n        return res;\n    }\n\n    Matrix pow(long\
    \ long n) const {\n        assert(n >= 0 && r == c);\n        Matrix A(M), res\
    \ = I(r);\n        while (n) {\n            if (n & 1)\n                res *=\
    \ A;\n            A *= A;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n\n    std::pair<int, int> GaussJordan() {\n        int rnk = 0, cnt =\
    \ 0;\n        REP_(k, c) {\n            if (M[rnk][k] == 0)\n                REP2_(i,\
    \ rnk + 1, r)\n            if (M[i][k] != 0) {\n                std::swap(M[i],\
    \ M[rnk]);\n                cnt ^= 1;\n                break;\n            }\n\
    \            if (M[rnk][k] == 0)\n                continue;\n            REP_(i,\
    \ r) if (i != rnk) {\n                K x = M[i][k] / M[rnk][k];\n           \
    \     REP_(j, c) M[i][j] -= M[rnk][j] * x;\n            }\n            if (++rnk\
    \ == r)\n                break;\n        }\n        return {rnk, cnt};\n    }\n\
    \n    K det() const {\n        assert(r == c);\n        Matrix A(M);\n       \
    \ const auto &[rnk, cnt] = A.GaussJordan();\n        if (rnk != r)\n         \
    \   return 0;\n        K res = 1;\n        REP_(i, r) res *= A[i][i];\n      \
    \  return (cnt ? -res : res);\n    }\n\n    std::optional<Matrix> inv() const\
    \ {\n        assert(r == c);\n        Matrix A(r, c + c);\n        REP_(i, r)\
    \ REP_(j, c) A[i][j] = M[i][j];\n        REP_(i, r) REP_(j, c) A[i][c + j] = K(i\
    \ == j);\n        A.GaussJordan();\n        REP_(i, r) if (A[i][i] == 0) return\
    \ std::nullopt;\n        Matrix res(r, c);\n        REP_(i, r) REP_(j, c) res[i][j]\
    \ = A[i][c + j] / A[i][i];\n        return res;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Matrix &M) {\n        os << M.M;\n     \
    \   return os;\n    }\n    friend std::istream &operator>>(std::istream &is, Matrix\
    \ &M) {\n        REP_(i, M.r) REP_(j, M.c) is >> M.M[i][j];\n        return is;\n\
    \    }\n};\n#undef REP_\n#undef REP2_\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/Matrix.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Matrix/Det.test.cpp
  - test/library-checker/Matrix/Product.test.cpp
  - test/library-checker/Matrix/Inverse.test.cpp
documentation_of: library/linearalgebra/Matrix.hpp
layout: document
redirect_from:
- /library/library/linearalgebra/Matrix.hpp
- /library/library/linearalgebra/Matrix.hpp.html
title: library/linearalgebra/Matrix.hpp
---
