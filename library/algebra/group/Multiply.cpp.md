---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2971.test.cpp
    title: test/AOJ/2971.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/group/Multiply.cpp\"\ntemplate<typename\
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
  path: library/algebra/group/Multiply.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/2971.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/algebra/group/Multiply.cpp
layout: document
redirect_from:
- /library/library/algebra/group/Multiply.cpp
- /library/library/algebra/group/Multiply.cpp.html
title: library/algebra/group/Multiply.cpp
---