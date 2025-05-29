---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1420.test.cpp
    title: test/yukicoder/1420.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/group/Xor.hpp\"\ntemplate<typename X>\n\
    struct GroupXor {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x ^ y; }\n  static constexpr void Rchop(X&x, const\
    \ X&y){ x^=y; }\n  static constexpr void Lchop(const X&x, X&y){ y^=x; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return x; }\n  static constexpr X\
    \ power(const X &x, long long n) noexcept { return (n&1?x:0); }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n"
  code: "template<typename X>\nstruct GroupXor {\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x ^ y; }\n  static\
    \ constexpr void Rchop(X&x, const X&y){ x^=y; }\n  static constexpr void Lchop(const\
    \ X&x, X&y){ y^=x; }\n  static constexpr X inverse(const X &x) noexcept { return\
    \ x; }\n  static constexpr X power(const X &x, long long n) noexcept { return\
    \ (n&1?x:0); }\n  static constexpr X unit() { return X(0); }\n  static constexpr\
    \ bool commute = true;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/Xor.hpp
  requiredBy: []
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1420.test.cpp
documentation_of: library/algebra/group/Xor.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Xor.hpp
- /library/library/algebra/group/Xor.hpp.html
title: library/algebra/group/Xor.hpp
---
