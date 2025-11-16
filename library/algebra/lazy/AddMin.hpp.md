---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.hpp
    title: library/algebra/group/Add.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Min.hpp
    title: library/algebra/monoid/Min.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_E.test.cpp
    title: test/AOJ/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_H.test.cpp
    title: test/AOJ/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
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
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"library/algebra/monoid/Min.hpp\"\ntemplate <typename X> struct MonoidMin\
    \ {\n    using value_type = X;\n    static constexpr X op(const X &x, const X\
    \ &y) noexcept {\n        return std::min(x, y);\n    }\n    static constexpr\
    \ void Rchop(X &x, const X &y) {\n        if (x > y)\n            x = y;\n   \
    \ }\n    static constexpr void Lchop(const X &x, X &y) {\n        if (y > x)\n\
    \            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::max()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n#line 4 \"library/algebra/lazy/AddMin.hpp\"\
    \ntemplate <typename X> struct LazyAddMin {\n    using MX = MonoidMin<X>;\n  \
    \  using MF = GroupAdd<X>;\n    static constexpr X mapping(const X &f, const X\
    \ &x) { return f + x; }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/Add.hpp\"\n#include \"library/algebra/monoid/Min.hpp\"\
    \ntemplate <typename X> struct LazyAddMin {\n    using MX = MonoidMin<X>;\n  \
    \  using MF = GroupAdd<X>;\n    static constexpr X mapping(const X &f, const X\
    \ &x) { return f + x; }\n};"
  dependsOn:
  - library/algebra/group/Add.hpp
  - library/algebra/monoid/Min.hpp
  isVerificationFile: false
  path: library/algebra/lazy/AddMin.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/yukicoder/1038.test.cpp
documentation_of: library/algebra/lazy/AddMin.hpp
layout: document
redirect_from:
- /library/library/algebra/lazy/AddMin.hpp
- /library/library/algebra/lazy/AddMin.hpp.html
title: library/algebra/lazy/AddMin.hpp
---
