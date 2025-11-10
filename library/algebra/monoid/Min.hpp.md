---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddMin.hpp
    title: library/algebra/lazy/AddMin.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetMin.hpp
    title: library/algebra/lazy/SetMin.hpp
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
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Min.hpp\"\ntemplate <typename X>\
    \ struct MonoidMin {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        return std::min(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) {\n        if (x > y)\n            x\
    \ = y;\n    }\n    static constexpr void Lchop(const X &x, X &y) {\n        if\
    \ (y > x)\n            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::max()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n"
  code: "template <typename X> struct MonoidMin {\n    using value_type = X;\n   \
    \ static constexpr X op(const X &x, const X &y) noexcept {\n        return std::min(x,\
    \ y);\n    }\n    static constexpr void Rchop(X &x, const X &y) {\n        if\
    \ (x > y)\n            x = y;\n    }\n    static constexpr void Lchop(const X\
    \ &x, X &y) {\n        if (y > x)\n            y = x;\n    }\n    static constexpr\
    \ X unit() { return std::numeric_limits<X>::max() / 2; }\n    static constexpr\
    \ bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Min.hpp
  requiredBy:
  - library/algebra/lazy/SetMin.hpp
  - library/algebra/lazy/AddMin.hpp
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_H.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_E.test.cpp
  - test/yukicoder/1038.test.cpp
documentation_of: library/algebra/monoid/Min.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Min.hpp
- /library/library/algebra/monoid/Min.hpp.html
title: library/algebra/monoid/Min.hpp
---
