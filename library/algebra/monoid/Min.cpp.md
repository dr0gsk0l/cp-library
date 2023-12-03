---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/algebra/lazy/AddMin.cpp
    title: library/algebra/lazy/AddMin.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetMin.cpp
    title: library/algebra/lazy/SetMin.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Min.cpp\"\ntemplate<typename X>\n\
    struct MonoidMin{\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x,y); }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ if(x>y)x=y; }\n  static constexpr void Lchop(const X&x, X&y){ if(y>x)y=x;\
    \ }\n  static constexpr X unit() { return numeric_limits<X>::max()/2; }\n  static\
    \ constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct MonoidMin{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return min(x,y); }\n  static\
    \ constexpr void Rchop(X&x, const X&y){ if(x>y)x=y; }\n  static constexpr void\
    \ Lchop(const X&x, X&y){ if(y>x)y=x; }\n  static constexpr X unit() { return numeric_limits<X>::max()/2;\
    \ }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Min.cpp
  requiredBy:
  - library/algebra/lazy/AddMin.cpp
  - library/algebra/lazy/SetMin.cpp
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/yukicoder/1038.test.cpp
documentation_of: library/algebra/monoid/Min.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Min.cpp
- /library/library/algebra/monoid/Min.cpp.html
title: library/algebra/monoid/Min.cpp
---
