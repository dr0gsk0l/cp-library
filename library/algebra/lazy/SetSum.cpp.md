---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Set.cpp
    title: library/algebra/monoid/Set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
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
    \ res(n);\n  for(int i=0;i<n;i++)res[i]={v[i],1};\n  return res;\n}\n#line 2 \"\
    library/algebra/monoid/Set.cpp\"\n// \u5408\u6210\u306E\u9806\u756A\u306F\u95A2\
    \u6570\u3068\u4E00\u7DD2\u3060\u3088\ntemplate<typename X>\nstruct MonoidSet{\n\
    \  using O=optional<X>;\n  using value_type=O;\n  static constexpr O op(const\
    \ O &x,const O &y)noexcept{ return (x.has_value()?x:y); }\n  static constexpr\
    \ void Rchop(O&x, const O&y){ if(!x)x=y; }\n  static constexpr void Lchop(const\
    \ O&x, O&y){ if(x)y=x; } \n  static constexpr O unit()noexcept{ return nullopt;\
    \ }\n  static constexpr bool commute=false;\n};\n#line 4 \"library/algebra/lazy/SetSum.cpp\"\
    \ntemplate<typename X>\nstruct LazySetSum{\n  using MX=GroupCntSum<X>;\n  using\
    \ MF=MonoidSet<X>;\n  using P=typename MX::value_type;\n  using F=typename MF::value_type;\n\
    \  static constexpr P mapping(const F&f,const P&x){\n    if(f.has_value())return\
    \ {f.value()*x.second,x.second};\n    return x;\n  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/CntSum.cpp\"\n#include \"\
    library/algebra/monoid/Set.cpp\"\ntemplate<typename X>\nstruct LazySetSum{\n \
    \ using MX=GroupCntSum<X>;\n  using MF=MonoidSet<X>;\n  using P=typename MX::value_type;\n\
    \  using F=typename MF::value_type;\n  static constexpr P mapping(const F&f,const\
    \ P&x){\n    if(f.has_value())return {f.value()*x.second,x.second};\n    return\
    \ x;\n  }\n};"
  dependsOn:
  - library/algebra/group/CntSum.cpp
  - library/algebra/monoid/Set.cpp
  isVerificationFile: false
  path: library/algebra/lazy/SetSum.cpp
  requiredBy: []
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_I.test.cpp
documentation_of: library/algebra/lazy/SetSum.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/SetSum.cpp
- /library/library/algebra/lazy/SetSum.cpp.html
title: library/algebra/lazy/SetSum.cpp
---
