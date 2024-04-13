---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.cpp
    title: library/tree/TreeLazy.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
  timestamp: '2024-04-13 19:59:47+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/algebra/lazy/Reverse.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/Reverse.cpp
- /library/library/algebra/lazy/Reverse.cpp.html
title: library/algebra/lazy/Reverse.cpp
---
