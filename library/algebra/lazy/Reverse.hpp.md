---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.hpp
    title: library/algebra/Reverse.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.hpp
    title: library/tree/TreeLazy.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/Reverse.hpp\"\ntemplate<typename Algebra>\n\
    struct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n  static\
    \ constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n  static\
    \ constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static constexpr\
    \ void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 3 \"library/algebra/lazy/Reverse.hpp\"\
    \ntemplate <typename Lazy> struct LazyReverse : Lazy {\n    using MX = AlgebraReverse<typename\
    \ Lazy::MX>;\n};\n"
  code: "#pragma once\n#include \"library/algebra/Reverse.hpp\"\ntemplate <typename\
    \ Lazy> struct LazyReverse : Lazy {\n    using MX = AlgebraReverse<typename Lazy::MX>;\n\
    };\n"
  dependsOn:
  - library/algebra/Reverse.hpp
  isVerificationFile: false
  path: library/algebra/lazy/Reverse.hpp
  requiredBy:
  - library/tree/TreeLazy.hpp
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/algebra/lazy/Reverse.hpp
layout: document
redirect_from:
- /library/library/algebra/lazy/Reverse.hpp
- /library/library/algebra/lazy/Reverse.hpp.html
title: library/algebra/lazy/Reverse.hpp
---
