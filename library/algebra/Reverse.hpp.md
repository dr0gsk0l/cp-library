---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/Reverse.hpp
    title: library/algebra/lazy/Reverse.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.hpp
    title: library/tree/TreeLazy.hpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.hpp
    title: library/tree/TreeMonoid.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/Reverse.hpp\"\ntemplate<typename Algebra>\n\
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
  path: library/algebra/Reverse.hpp
  requiredBy:
  - library/algebra/lazy/Reverse.hpp
  - library/tree/TreeLazy.hpp
  - library/tree/TreeMonoid.hpp
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/algebra/Reverse.hpp
layout: document
redirect_from:
- /library/library/algebra/Reverse.hpp
- /library/library/algebra/Reverse.hpp.html
title: library/algebra/Reverse.hpp
---
