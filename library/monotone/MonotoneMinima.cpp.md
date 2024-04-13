---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/monotone/MonotoneMinima.cpp\"\ntemplate <typename\
    \ F>\nstd::vector<int> internal_monotone_minima(int u, int d, int l, int r,\n\
    \                                          const F &argmin) {\n    if (u == d)\n\
    \        return {};\n    std::vector<int> ret(d - u);\n    int m = (u + d) >>\
    \ 1;\n    ret[m - u] = argmin(m, l, r);\n    auto v1 = internal_monotone_minima(u,\
    \ m, l, ret[m - u] + 1, argmin);\n    std::ranges::copy(v1, ret.begin());\n  \
    \  auto v2 = internal_monotone_minima(m + 1, d, ret[m - u], r, argmin);\n    std::ranges::copy(v2,\
    \ ret.begin() + m - u + 1);\n    return ret;\n}\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    return internal_monotone_minima(0,\
    \ n, 0, m, argmin);\n}\n"
  code: "template <typename F>\nstd::vector<int> internal_monotone_minima(int u, int\
    \ d, int l, int r,\n                                          const F &argmin)\
    \ {\n    if (u == d)\n        return {};\n    std::vector<int> ret(d - u);\n \
    \   int m = (u + d) >> 1;\n    ret[m - u] = argmin(m, l, r);\n    auto v1 = internal_monotone_minima(u,\
    \ m, l, ret[m - u] + 1, argmin);\n    std::ranges::copy(v1, ret.begin());\n  \
    \  auto v2 = internal_monotone_minima(m + 1, d, ret[m - u], r, argmin);\n    std::ranges::copy(v2,\
    \ ret.begin() + m - u + 1);\n    return ret;\n}\n\ntemplate <typename F>\nstd::vector<int>\
    \ monotone_minima(int n, int m, const F &argmin) {\n    return internal_monotone_minima(0,\
    \ n, 0, m, argmin);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/monotone/MonotoneMinima.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:59:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
docs: https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu
documentation_of: library/monotone/MonotoneMinima.cpp
layout: document
title: monotone_minima
---
# monotone
$N\times M$ 行列 $A$ に対し $b_i \coloneqq \arg\min_{j\in[m]} A_{i,j}$ とする．

$b$ が広義単調増加であるような行列を monotone と呼ぶ．
# monotone_minima
monotone 行列に対して $b$ を $O(N+M\log M)$ で求めるアルゴリズム．  
最初に $b[\lfloor N/2\rfloor]$ を $O(M)$ で求めて再帰的に解くだけ．
# 使い方
* ```std::vector<int> monotone_minima(n, m, argmin)```
monotone 行列に対して $b$ を求める．  
計算時間 $O(N+M\log M)$.  
ただし $\arg\min(i,l,r)$ を$O(r-l)$ で$\arg\min_{j\in[l,r)} A_{i,j}$ を返す関数とする．