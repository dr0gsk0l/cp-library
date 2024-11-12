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
  bundledCode: "#line 1 \"library/algebra/monoid/Lcm.hpp\"\ntemplate <typename X>\
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
  path: library/algebra/monoid/Lcm.hpp
  requiredBy: []
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/Lcm.hpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Lcm.hpp
- /library/library/algebra/monoid/Lcm.hpp.html
title: library/algebra/monoid/Lcm.hpp
---
