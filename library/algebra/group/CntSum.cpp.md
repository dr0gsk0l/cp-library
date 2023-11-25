---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AddSum.cpp
    title: library/algebra/lazy/AddSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/AffineSum.cpp
    title: library/algebra/lazy/AffineSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/lazy/SetSum.cpp
    title: library/algebra/lazy/SetSum.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n  return res;\n}\n"
  code: "template<typename X>\nstruct GroupCntSum{\n  using P=pair<X,X>;\n  using\
    \ value_type=P;\n  static constexpr P op(const P &x, const P &y){\n    return\
    \ {x.first + y.first, x.second + y.second};\n  }\n  static constexpr void Rchop(P&x,\
    \ const P&y){\n    x.first+=y.first;\n    x.second+=y.second;\n  }\n  static constexpr\
    \ void Lchop(const P&x, P&y){\n    y.first+=x.first;\n    y.second+=x.second;\n\
    \  }\n  static constexpr P inverse(const P &x){ return {-x.fi, -x.se}; }\n  static\
    \ constexpr P unit() { return {0, 0}; }\n  static constexpr bool commute = true;\n\
    };\ntemplate<typename X>\nvector<pair<X,X>> cnt_init(int n,const X&x){\n  return\
    \ vector<pair<X,X>>(n,{x,1});\n}\ntemplate<typename X>\nvector<pair<X,X>> cnt_init(const\
    \ vector<X>&v){\n  int n=v.size();\n  vector<pair<X,X>> res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n\
    \  return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/CntSum.cpp
  requiredBy:
  - library/algebra/lazy/AffineSum.cpp
  - library/algebra/lazy/AddSum.cpp
  - library/algebra/lazy/SetSum.cpp
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
  - test/AOJ/DSL_2_I.test.cpp
documentation_of: library/algebra/group/CntSum.cpp
layout: document
redirect_from:
- /library/library/algebra/group/CntSum.cpp
- /library/library/algebra/group/CntSum.cpp.html
title: library/algebra/group/CntSum.cpp
---
