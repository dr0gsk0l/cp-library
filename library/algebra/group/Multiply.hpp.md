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
  bundledCode: "#line 1 \"library/algebra/group/Multiply.hpp\"\ntemplate<typename\
    \ X,bool COMMUTE=true>\nstruct GroupMultiply{\n  using value_type = X;\n  static\
    \ constexpr X op(const X &x, const X &y) noexcept { return x * y; }\n  static\
    \ constexpr void Rchop(X&x, const X&y){ x*=y; }\n  static constexpr void Lchop(const\
    \ X&x, X&y){ \n    if constexpr(COMMUTE){ y*=x; }\n    else{ y=x*y;} \n  }\n \
    \ static constexpr X inverse(const X &x) noexcept { return X(1)/x; }\n  static\
    \ constexpr X power(const X &x, long long n) noexcept { return x.pow(n); }\n \
    \ static constexpr X unit() { return X(1); }\n  static constexpr bool commute\
    \ = COMMUTE;\n};\n"
  code: "template<typename X,bool COMMUTE=true>\nstruct GroupMultiply{\n  using value_type\
    \ = X;\n  static constexpr X op(const X &x, const X &y) noexcept { return x *\
    \ y; }\n  static constexpr void Rchop(X&x, const X&y){ x*=y; }\n  static constexpr\
    \ void Lchop(const X&x, X&y){ \n    if constexpr(COMMUTE){ y*=x; }\n    else{\
    \ y=x*y;} \n  }\n  static constexpr X inverse(const X &x) noexcept { return X(1)/x;\
    \ }\n  static constexpr X power(const X &x, long long n) noexcept { return x.pow(n);\
    \ }\n  static constexpr X unit() { return X(1); }\n  static constexpr bool commute\
    \ = COMMUTE;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/Multiply.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/group/Multiply.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Multiply.hpp
- /library/library/algebra/group/Multiply.hpp.html
title: library/algebra/group/Multiply.hpp
---
