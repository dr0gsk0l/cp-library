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
  bundledCode: "#line 1 \"library/algebra/monoid/Lcm.cpp\"\ntemplate <typename X>\
    \ struct MonoidLcm {\n    using value_type = X;\n    static constexpr X op(const\
    \ X &x, const X &y) noexcept {\n        return std::lcm(x, y);\n    }\n    static\
    \ constexpr void Rchop(X &x, const X &y) { x = std::lcm(x, y); }\n    static constexpr\
    \ void Lchop(const X &x, X &y) { y = std::lcm(x, y); }\n    static constexpr X\
    \ unit() { return 1; }\n    static constexpr bool commute = true;\n};\n"
  code: "template <typename X> struct MonoidLcm {\n    using value_type = X;\n   \
    \ static constexpr X op(const X &x, const X &y) noexcept {\n        return std::lcm(x,\
    \ y);\n    }\n    static constexpr void Rchop(X &x, const X &y) { x = std::lcm(x,\
    \ y); }\n    static constexpr void Lchop(const X &x, X &y) { y = std::lcm(x, y);\
    \ }\n    static constexpr X unit() { return 1; }\n    static constexpr bool commute\
    \ = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Lcm.cpp
  requiredBy: []
  timestamp: '2024-04-15 12:10:38+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Lcm.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Lcm.cpp
- /library/library/algebra/monoid/Lcm.cpp.html
title: library/algebra/monoid/Lcm.cpp
---
