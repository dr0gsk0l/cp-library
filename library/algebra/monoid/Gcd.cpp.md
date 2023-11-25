---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1036.test.cpp
    title: test/yukicoder/1036.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Gcd.cpp\"\ntemplate<typename X>\n\
    struct MonoidGcd{\n  using value_type = X;\n  static constexpr X op(const X&x,\
    \ const X&y) noexcept { return gcd(x,y); }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ x=gcd(x,y); }\n  static constexpr void Lchop(const X&x, X&y){ y=gcd(x,y);\
    \ }\n  static constexpr X unit() { return 0; }\n  static constexpr bool commute\
    \ = true;\n};\n"
  code: "template<typename X>\nstruct MonoidGcd{\n  using value_type = X;\n  static\
    \ constexpr X op(const X&x, const X&y) noexcept { return gcd(x,y); }\n  static\
    \ constexpr void Rchop(X&x, const X&y){ x=gcd(x,y); }\n  static constexpr void\
    \ Lchop(const X&x, X&y){ y=gcd(x,y); }\n  static constexpr X unit() { return 0;\
    \ }\n  static constexpr bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/Gcd.cpp
  requiredBy: []
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1036.test.cpp
documentation_of: library/algebra/monoid/Gcd.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/Gcd.cpp
- /library/library/algebra/monoid/Gcd.cpp.html
title: library/algebra/monoid/Gcd.cpp
---
