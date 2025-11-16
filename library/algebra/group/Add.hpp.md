---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddMin.hpp
    title: library/algebra/lazy/AddMin.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddSum.hpp
    title: library/algebra/lazy/AddSum.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.hpp
    title: library/datastructure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.hpp
    title: library/math/FactorialNumberSystem.hpp
  - icon: ':heavy_check_mark:'
    path: library/sequence/AhoCorasick.hpp
    title: library/sequence/AhoCorasick.hpp
  - icon: ':heavy_check_mark:'
    path: library/sequence/Trie.hpp
    title: library/sequence/Trie.hpp
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
    path: test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
    title: test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/group/Add.hpp\"\ntemplate<typename X>\n\
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
  path: library/algebra/group/Add.hpp
  requiredBy:
  - library/algebra/lazy/AddSum.hpp
  - library/algebra/lazy/AddMin.hpp
  - library/datastructure/FenwickTree.hpp
  - library/datastructure/GroupWaveletMatrix.hpp
  - library/math/FactorialNumberSystem.hpp
  - library/sequence/AhoCorasick.hpp
  - library/sequence/Trie.hpp
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/DataStructure/UnionfindWithPotential.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/AOJ/1330.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/2207.test.cpp
  - test/AOJ/DSL_1_B.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
  - test/AOJ/2212.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/yukicoder/430_2.test.cpp
  - test/yukicoder/430.test.cpp
  - test/yukicoder/1097.test.cpp
documentation_of: library/algebra/group/Add.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Add.hpp
- /library/library/algebra/group/Add.hpp.html
title: library/algebra/group/Add.hpp
---
