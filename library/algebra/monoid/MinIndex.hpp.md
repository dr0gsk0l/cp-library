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
  bundledCode: "#line 2 \"library/algebra/monoid/MinIndex.hpp\"\ntemplate <typename\
    \ X> struct MonoidMinIndex {\n    using P = std::pair<X, int>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x, const P &y) noexcept {\n       \
    \ returnstd::min(x, y);\n    }\n    static constexpr void Rchop(P &x, const P\
    \ &y) {\n        if (x > y)\n            x = y;\n    }\n    static constexpr void\
    \ Lchop(const P &x, P &y) {\n        if (y > x)\n            y = x;\n    }\n \
    \   static constexpr P unit() {\n        return P(std::numeric_limits<X>::max()\
    \ / 2, -1);\n    }\n    static constexpr bool commute = true;\n    static constexpr\
    \ std::vector<P> arrange(const std::vector<X> &v) {\n        std::vector<P> w(v.size());\n\
    \        for (int i = 0; i < v.size(); i++)\n            w[i] = P(v[i], i);\n\
    \        return w;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename X> struct MonoidMinIndex {\n    using P\
    \ = std::pair<X, int>;\n    using value_type = P;\n    static constexpr P op(const\
    \ P &x, const P &y) noexcept {\n        returnstd::min(x, y);\n    }\n    static\
    \ constexpr void Rchop(P &x, const P &y) {\n        if (x > y)\n            x\
    \ = y;\n    }\n    static constexpr void Lchop(const P &x, P &y) {\n        if\
    \ (y > x)\n            y = x;\n    }\n    static constexpr P unit() {\n      \
    \  return P(std::numeric_limits<X>::max() / 2, -1);\n    }\n    static constexpr\
    \ bool commute = true;\n    static constexpr std::vector<P> arrange(const std::vector<X>\
    \ &v) {\n        std::vector<P> w(v.size());\n        for (int i = 0; i < v.size();\
    \ i++)\n            w[i] = P(v[i], i);\n        return w;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/MinIndex.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/MinIndex.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/MinIndex.hpp
- /library/library/algebra/monoid/MinIndex.hpp.html
title: library/algebra/monoid/MinIndex.hpp
---
