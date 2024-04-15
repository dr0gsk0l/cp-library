---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Max.cpp\"\ntemplate <typename X>\
    \ struct MonoidMax {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        returnstd::max(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) {\n        if (x < y)\n            x\
    \ = y;\n    }\n    static constexpr void Lchop(const X &x, X &y) {\n        if\
    \ (y < x)\n            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::min()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n"
  code: "#pragma once\ntemplate <typename X> struct MonoidMax {\n    using value_type\
    \ = X;\n    static constexpr X op(const X &x, const X &y) noexcept {\n       \
    \ returnstd::max(x, y);\n    }\n    static constexpr void Rchop(X &x, const X\
    \ &y) {\n        if (x < y)\n            x = y;\n    }\n    static constexpr void\
    \ Lchop(const X &x, X &y) {\n        if (y < x)\n            y = x;\n    }\n \
    \   static constexpr X unit() { return std::numeric_limits<X>::min() / 2; }\n\
    \    static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Max.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Max.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Max.cpp
- /library/library/algebra/monoid/Max.cpp.html
title: library/algebra/monoid/Max.cpp
---
