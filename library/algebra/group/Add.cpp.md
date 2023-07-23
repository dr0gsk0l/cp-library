---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddMin.cpp
    title: library/algebra/lazy/AddMin.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddSum.cpp
    title: library/algebra/lazy/AddSum.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':question:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.cpp
    title: library/math/FactorialNumberSystem.cpp
  - icon: ':heavy_check_mark:'
    path: library/sequence/AhoCorasick.cpp
    title: AhoCorasick
  - icon: ':heavy_check_mark:'
    path: library/sequence/Trie.cpp
    title: library/sequence/Trie.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/1330.test.cpp
    title: test/AOJ/1330.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2207.test.cpp
    title: test/AOJ/2207.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_1_B.test.cpp
    title: test/AOJ/DSL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1097.test.cpp
    title: test/yukicoder/1097.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430_2.test.cpp
    title: test/yukicoder/430_2.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename X>\n\
    struct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x, const\
    \ X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n"
  code: "#pragma once\ntemplate<typename X>\nstruct GroupAdd {\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x +\
    \ y; }\n  static constexpr void Rchop(X&x, const X&y){ x+=y; }\n  static constexpr\
    \ void Lchop(const X&x, X&y){ y+=x; }\n  static constexpr X inverse(const X &x)\
    \ noexcept { return -x; }\n  static constexpr X power(const X &x, long long n)\
    \ noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0); }\n\
    \  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/Add.cpp
  requiredBy:
  - library/algebra/lazy/AddMin.cpp
  - library/algebra/lazy/AddSum.cpp
  - library/math/FactorialNumberSystem.cpp
  - library/datastructure/FenwickTree.cpp
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/sequence/AhoCorasick.cpp
  - library/sequence/Trie.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yukicoder/430_2.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/yukicoder/1097.test.cpp
  - test/yukicoder/430.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/DSL_1_B.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/1330.test.cpp
  - test/AOJ/2212.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/2207.test.cpp
documentation_of: library/algebra/group/Add.cpp
layout: document
redirect_from:
- /library/library/algebra/group/Add.cpp
- /library/library/algebra/group/Add.cpp.html
title: library/algebra/group/Add.cpp
---
