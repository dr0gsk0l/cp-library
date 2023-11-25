---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':x:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':x:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/group/CntSum.cpp\"\ntemplate<typename X>\n\
    struct GroupCntSum{\n  using P=pair<X,X>;\n  using value_type=P;\n  static constexpr\
    \ P op(const P &x, const P &y){\n    return {x.first + y.first, x.second + y.second};\n\
    \  }\n  static constexpr void Rchop(P&x, const P&y){\n    x.first+=y.first;\n\
    \    x.second+=y.second;\n  }\n  static constexpr void Lchop(const P&x, P&y){\n\
    \    y.first+=x.first;\n    y.second+=x.second;\n  }\n  static constexpr P inverse(const\
    \ P &x){ return {-x.fi, -x.se}; }\n  static constexpr P unit() { return {0, 0};\
    \ }\n  static constexpr bool commute = true;\n};\ntemplate<typename X>\nvector<pair<X,X>>\
    \ cnt_init(int n,const X&x){\n  return vector<pair<X,X>>(n,{x,1});\n}\ntemplate<typename\
    \ X>\nvector<pair<X,X>> cnt_init(const vector<X>&v){\n  int n=v.size();\n  vector<pair<X,X>>\
    \ res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n  return res;\n}\n#line 2 \"\
    library/algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct GroupAdd {\n  using\
    \ value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept {\
    \ return x + y; }\n  static constexpr void Rchop(X&x, const X&y){ x+=y; }\n  static\
    \ constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static constexpr X inverse(const\
    \ X &x) noexcept { return -x; }\n  static constexpr X power(const X &x, long long\
    \ n) noexcept { return X(n) * x; }\n  static constexpr X unit() { return X(0);\
    \ }\n  static constexpr bool commute = true;\n};\n#line 4 \"library/algebra/lazy/AddSum.cpp\"\
    \ntemplate<typename X>\nstruct LazyAddSum{\n  using MX=GroupCntSum<X>;\n  using\
    \ MF=GroupAdd<X>;\n  using S=typename MX::value_type;\n  static constexpr S mapping(const\
    \ X&f,const S&x){\n    return {x.first+f*x.second,x.second};\n  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/CntSum.cpp\"\n#include \"\
    library/algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct LazyAddSum{\n  using\
    \ MX=GroupCntSum<X>;\n  using MF=GroupAdd<X>;\n  using S=typename MX::value_type;\n\
    \  static constexpr S mapping(const X&f,const S&x){\n    return {x.first+f*x.second,x.second};\n\
    \  }\n};"
  dependsOn:
  - library/algebra/group/CntSum.cpp
  - library/algebra/group/Add.cpp
  isVerificationFile: false
  path: library/algebra/lazy/AddSum.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/algebra/lazy/AddSum.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/AddSum.cpp
- /library/library/algebra/lazy/AddSum.cpp.html
title: library/algebra/lazy/AddSum.cpp
---
