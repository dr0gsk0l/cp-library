---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/Reverse.cpp
    title: library/algebra/lazy/Reverse.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.cpp
    title: library/tree/TreeLazy.cpp
  - icon: ':x:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/Reverse.cpp\"\ntemplate<typename Algebra>\n\
    struct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n  static\
    \ constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static constexpr\
    \ void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n"
  code: "#pragma once\ntemplate<typename Algebra>\nstruct AlgebraReverse:Algebra{\n\
    \  using X=typename Algebra::value_type;\n  static constexpr X op(const X& x,\
    \ const X& y){ return Algebra::op(y,x); }\n  static constexpr void Rchop(X&x,const\
    \ X&y){ Algebra::Lchop(y,x); }\n  static constexpr void Lchop(const X&x,X&y){\
    \ Algebra::Rchop(y,x); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/Reverse.cpp
  requiredBy:
  - library/tree/TreeLazy.cpp
  - library/tree/TreeMonoid.cpp
  - library/algebra/lazy/Reverse.cpp
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/algebra/Reverse.cpp
layout: document
redirect_from:
- /library/library/algebra/Reverse.cpp
- /library/library/algebra/Reverse.cpp.html
title: library/algebra/Reverse.cpp
---
