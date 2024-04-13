---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/755.test.cpp
    title: test/yukicoder/755.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/2D/CumulativeSum.cpp\"\ntemplate <typename\
    \ T> class CumulativeSum2D {\n    using U = conditional_t<is_same_v<T, int>, long\
    \ long, T>;\n    int h, w;\n    std::vector<vector<U>> A;\n    bool prepared;\n\
    \n  public:\n    CumulativeSum2D(int h = 0, int w = 0)\n        : h(h), w(w),\
    \ A(h + 1, vector<U>(w + 1, 0)), prepared(false) {}\n    CumulativeSum2D(const\
    \ std::vector<vector<T>> &v)\n        : h(v.size()), w(v[0].size()), A(h + 1,\
    \ vector<U>(w + 1, 0)),\n          prepared(false) {\n        for (int i = 0;\
    \ i < h; i++)\n            for (int j = 0; j < w; j++)\n                A[i +\
    \ 1][j + 1] = v[i][j];\n        build();\n    }\n    void add(int y, int x, const\
    \ T &val = 1) {\n        assert(!prepared);\n        assert(0 <= y and y < h and\
    \ 0 <= x and x < w);\n        A[y + 1][x + 1] += val;\n    }\n    void build()\
    \ {\n        assert(!prepared);\n        prepared = true;\n        for (int i\
    \ = 0; i < h; i++)\n            for (int j = 0; j <= w; j++)\n               \
    \ A[i + 1][j] += A[i][j];\n        for (int i = 0; i <= h; i++)\n            for\
    \ (int j = 0; j < w; j++)\n                A[i][j + 1] += A[i][j];\n    }\n  \
    \  U sum(int u, int d, int l, int r) {\n        assert(prepared);\n        assert(0\
    \ <= u and u <= d and u <= h);\n        assert(0 <= l and l <= r and r <= w);\n\
    \        return A[d][r] - A[d][l] - A[u][r] + A[u][l];\n    }\n    U sum() {\n\
    \        assert(prepared);\n        return A.back().back();\n    }\n};\n"
  code: "template <typename T> class CumulativeSum2D {\n    using U = conditional_t<is_same_v<T,\
    \ int>, long long, T>;\n    int h, w;\n    std::vector<vector<U>> A;\n    bool\
    \ prepared;\n\n  public:\n    CumulativeSum2D(int h = 0, int w = 0)\n        :\
    \ h(h), w(w), A(h + 1, vector<U>(w + 1, 0)), prepared(false) {}\n    CumulativeSum2D(const\
    \ std::vector<vector<T>> &v)\n        : h(v.size()), w(v[0].size()), A(h + 1,\
    \ vector<U>(w + 1, 0)),\n          prepared(false) {\n        for (int i = 0;\
    \ i < h; i++)\n            for (int j = 0; j < w; j++)\n                A[i +\
    \ 1][j + 1] = v[i][j];\n        build();\n    }\n    void add(int y, int x, const\
    \ T &val = 1) {\n        assert(!prepared);\n        assert(0 <= y and y < h and\
    \ 0 <= x and x < w);\n        A[y + 1][x + 1] += val;\n    }\n    void build()\
    \ {\n        assert(!prepared);\n        prepared = true;\n        for (int i\
    \ = 0; i < h; i++)\n            for (int j = 0; j <= w; j++)\n               \
    \ A[i + 1][j] += A[i][j];\n        for (int i = 0; i <= h; i++)\n            for\
    \ (int j = 0; j < w; j++)\n                A[i][j + 1] += A[i][j];\n    }\n  \
    \  U sum(int u, int d, int l, int r) {\n        assert(prepared);\n        assert(0\
    \ <= u and u <= d and u <= h);\n        assert(0 <= l and l <= r and r <= w);\n\
    \        return A[d][r] - A[d][l] - A[u][r] + A[u][l];\n    }\n    U sum() {\n\
    \        assert(prepared);\n        return A.back().back();\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/2D/CumulativeSum.cpp
  requiredBy: []
  timestamp: '2024-04-13 18:46:02+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/755.test.cpp
documentation_of: library/datastructure/2D/CumulativeSum.cpp
layout: document
redirect_from:
- /library/library/datastructure/2D/CumulativeSum.cpp
- /library/library/datastructure/2D/CumulativeSum.cpp.html
title: library/datastructure/2D/CumulativeSum.cpp
---
