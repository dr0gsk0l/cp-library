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
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Min.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Min.hpp
- /library/library/algebra/monoid/Min.hpp.html
title: library/algebra/monoid/Min.hpp
---
