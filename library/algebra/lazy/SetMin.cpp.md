---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Min.cpp
    title: library/algebra/monoid/Min.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Set.cpp
    title: library/algebra/monoid/Set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Min.cpp\"\ntemplate <typename X>\
    \ struct MonoidMin {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        return std::min(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) {\n        if (x > y)\n            x\
    \ = y;\n    }\n    static constexpr void Lchop(const X &x, X &y) {\n        if\
    \ (y > x)\n            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::max()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n#line 2 \"library/algebra/monoid/Set.cpp\"\
    \n// \u5408\u6210\u306E\u9806\u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\
    \ntemplate <typename X> struct MonoidSet {\n    using O = std::optional<X>;\n\
    \    using value_type = O;\n    static constexpr O op(const O &x, const O &y)\
    \ noexcept {\n        return (x.has_value() ? x : y);\n    }\n    static constexpr\
    \ void Rchop(O &x, const O &y) {\n        if (!x)\n            x = y;\n    }\n\
    \    static constexpr void Lchop(const O &x, O &y) {\n        if (x)\n       \
    \     y = x;\n    }\n    static constexpr O unit() noexcept { return std::nullopt;\
    \ }\n    static constexpr bool commute = false;\n};\n#line 4 \"library/algebra/lazy/SetMin.cpp\"\
    \ntemplate <typename X> struct LazySetMin {\n    using MX = MonoidMin<X>;\n  \
    \  using MF = MonoidSet<X>;\n    using F = typename MF::value_type;\n    static\
    \ constexpr X mapping(const F &f, const X &x) { return f.value_or(x); }\n};\n"
  code: "#pragma once\n#include \"library/algebra/monoid/Min.cpp\"\n#include \"library/algebra/monoid/Set.cpp\"\
    \ntemplate <typename X> struct LazySetMin {\n    using MX = MonoidMin<X>;\n  \
    \  using MF = MonoidSet<X>;\n    using F = typename MF::value_type;\n    static\
    \ constexpr X mapping(const F &f, const X &x) { return f.value_or(x); }\n};"
  dependsOn:
  - library/algebra/monoid/Min.cpp
  - library/algebra/monoid/Set.cpp
  isVerificationFile: false
  path: library/algebra/lazy/SetMin.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
documentation_of: library/algebra/lazy/SetMin.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/SetMin.cpp
- /library/library/algebra/lazy/SetMin.cpp.html
title: library/algebra/lazy/SetMin.cpp
---