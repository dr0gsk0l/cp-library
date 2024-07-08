---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/monoid/Max.hpp\"\ntemplate <typename X>\
    \ struct MonoidMax {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        return std::max(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) {\n        if (x < y)\n            x\
    \ = y;\n    }\n    static constexpr void Lchop(const X &x, X &y) {\n        if\
    \ (y < x)\n            y = x;\n    }\n    static constexpr X unit() { return std::numeric_limits<X>::min()\
    \ / 2; }\n    static constexpr bool commute = true;\n};\n"
  code: "#pragma once\ntemplate <typename X> struct MonoidMax {\n    using value_type\
    \ = X;\n    static constexpr X op(const X &x, const X &y) noexcept {\n       \
    \ return std::max(x, y);\n    }\n    static constexpr void Rchop(X &x, const X\
    \ &y) {\n        if (x < y)\n            x = y;\n    }\n    static constexpr void\
    \ Lchop(const X &x, X &y) {\n        if (y < x)\n            y = x;\n    }\n \
    \   static constexpr X unit() { return std::numeric_limits<X>::min() / 2; }\n\
    \    static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Max.hpp
  requiredBy: []
  timestamp: '2024-07-08 10:24:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Max.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Max.hpp
- /library/library/algebra/monoid/Max.hpp.html
title: library/algebra/monoid/Max.hpp
---
