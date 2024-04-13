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
  bundledCode: "#line 2 \"library/algebra/monoid/MaxIndex.cpp\"\ntemplate <typename\
    \ X> struct MonoidMaxIndex {\n    using P = pair<X, int>;\n    using value_type\
    \ = P;\n    static constexpr P op(const P &x, const P &y) noexcept { return max(x,\
    \ y); }\n    static constexpr void Rchop(P &x, const P &y) {\n        if (x <\
    \ y)\n            x = y;\n    }\n    static constexpr void Lchop(const P &x, P\
    \ &y) {\n        if (y < x)\n            y = x;\n    }\n    static constexpr P\
    \ unit() { return P(numeric_limits<X>::min() / 2, -1); }\n    static constexpr\
    \ bool commute = true;\n    static constexpr std::vector<P> arrange(const std::vector<X>\
    \ &v) {\n        std::vector<P> w(v.size());\n        for (int i = 0; i < v.size();\
    \ i++)\n            w[i] = P(v[i], i);\n        return w;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename X> struct MonoidMaxIndex {\n    using P\
    \ = pair<X, int>;\n    using value_type = P;\n    static constexpr P op(const\
    \ P &x, const P &y) noexcept { return max(x, y); }\n    static constexpr void\
    \ Rchop(P &x, const P &y) {\n        if (x < y)\n            x = y;\n    }\n \
    \   static constexpr void Lchop(const P &x, P &y) {\n        if (y < x)\n    \
    \        y = x;\n    }\n    static constexpr P unit() { return P(numeric_limits<X>::min()\
    \ / 2, -1); }\n    static constexpr bool commute = true;\n    static constexpr\
    \ std::vector<P> arrange(const std::vector<X> &v) {\n        std::vector<P> w(v.size());\n\
    \        for (int i = 0; i < v.size(); i++)\n            w[i] = P(v[i], i);\n\
    \        return w;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/MaxIndex.cpp
  requiredBy: []
  timestamp: '2024-04-13 17:39:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/MaxIndex.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/MaxIndex.cpp
- /library/library/algebra/monoid/MaxIndex.cpp.html
title: library/algebra/monoid/MaxIndex.cpp
---
