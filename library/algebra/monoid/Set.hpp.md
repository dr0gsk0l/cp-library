---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetMin.hpp
    title: library/algebra/lazy/SetMin.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetSum.hpp
    title: library/algebra/lazy/SetSum.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Set.hpp\"\n// \u5408\u6210\u306E\u9806\
    \u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\ntemplate <typename X>\
    \ struct MonoidSet {\n    using O = std::optional<X>;\n    using value_type =\
    \ O;\n    static constexpr O op(const O &x, const O &y) noexcept {\n        return\
    \ (x.has_value() ? x : y);\n    }\n    static constexpr void Rchop(O &x, const\
    \ O &y) {\n        if (!x)\n            x = y;\n    }\n    static constexpr void\
    \ Lchop(const O &x, O &y) {\n        if (x)\n            y = x;\n    }\n    static\
    \ constexpr O unit() noexcept { return std::nullopt; }\n    static constexpr bool\
    \ commute = false;\n};\n"
  code: "#pragma once\n// \u5408\u6210\u306E\u9806\u756A\u306F\u95A2\u6570\u3068\u4E00\
    \u7DD2\u3060\u3088\ntemplate <typename X> struct MonoidSet {\n    using O = std::optional<X>;\n\
    \    using value_type = O;\n    static constexpr O op(const O &x, const O &y)\
    \ noexcept {\n        return (x.has_value() ? x : y);\n    }\n    static constexpr\
    \ void Rchop(O &x, const O &y) {\n        if (!x)\n            x = y;\n    }\n\
    \    static constexpr void Lchop(const O &x, O &y) {\n        if (x)\n       \
    \     y = x;\n    }\n    static constexpr O unit() noexcept { return std::nullopt;\
    \ }\n    static constexpr bool commute = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Set.hpp
  requiredBy:
  - library/algebra/lazy/SetMin.hpp
  - library/algebra/lazy/SetSum.hpp
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_D.test.cpp
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
documentation_of: library/algebra/monoid/Set.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Set.hpp
- /library/library/algebra/monoid/Set.hpp.html
title: library/algebra/monoid/Set.hpp
---
