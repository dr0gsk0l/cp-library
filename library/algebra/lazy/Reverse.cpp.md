---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/tree/TreeLazy.cpp
    title: library/tree/TreeLazy.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/Reverse.cpp\"\ntemplate<typename Algebra>\n\
    struct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n  static\
    \ constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static constexpr\
    \ void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 3 \"library/algebra/lazy/Reverse.cpp\"\
    \ntemplate<typename Lazy>\nstruct LazyReverse:Lazy{\n  using MX=AlgebraReverse<typename\
    \ Lazy::MX>;\n};\n"
  code: "#pragma once\n#include \"library/algebra/Reverse.cpp\"\ntemplate<typename\
    \ Lazy>\nstruct LazyReverse:Lazy{\n  using MX=AlgebraReverse<typename Lazy::MX>;\n\
    };\n"
  dependsOn:
  - library/algebra/Reverse.cpp
  isVerificationFile: false
  path: library/algebra/lazy/Reverse.cpp
  requiredBy:
  - library/tree/TreeLazy.cpp
  timestamp: '2023-11-25 17:03:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/algebra/lazy/Reverse.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/Reverse.cpp
- /library/library/algebra/lazy/Reverse.cpp.html
title: library/algebra/lazy/Reverse.cpp
---
