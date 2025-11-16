---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Gcd.hpp\"\ntemplate <typename X>\
    \ struct MonoidGcd {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        return std::gcd(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) { x = std::gcd(x, y); }\n    static constexpr\
    \ void Lchop(const X &x, X &y) { y = std::gcd(x, y); }\n    static constexpr X\
    \ unit() { return 0; }\n    static constexpr bool commute = true;\n};\n"
  code: "template <typename X> struct MonoidGcd {\n    using value_type = X;\n   \
    \ static constexpr X op(const X &x, const X &y) noexcept {\n        return std::gcd(x,\
    \ y);\n    }\n    static constexpr void Rchop(X &x, const X &y) { x = std::gcd(x,\
    \ y); }\n    static constexpr void Lchop(const X &x, X &y) { y = std::gcd(x, y);\
    \ }\n    static constexpr X unit() { return 0; }\n    static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Gcd.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1036.test.cpp
documentation_of: library/algebra/monoid/Gcd.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Gcd.hpp
- /library/library/algebra/monoid/Gcd.hpp.html
title: library/algebra/monoid/Gcd.hpp
---
