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
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/group/Xor.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Xor.hpp
- /library/library/algebra/group/Xor.hpp.html
title: library/algebra/group/Xor.hpp
---
