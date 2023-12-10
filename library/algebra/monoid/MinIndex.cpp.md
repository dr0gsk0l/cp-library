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
  bundledCode: "#line 2 \"library/algebra/monoid/MinIndex.cpp\"\ntemplate<typename\
    \ X>\nstruct MonoidMinIndex{\n  using P = pair<X,int>;\n  using value_type = P;\n\
    \  static constexpr P op(const P &x, const P &y) noexcept { return min(x,y); }\n\
    \  static constexpr void Rchop(P&x, const P&y){ if(x>y)x=y; }\n  static constexpr\
    \ void Lchop(const P&x, P&y){ if(y>x)y=x; }\n  static constexpr P unit() { return\
    \ P(numeric_limits<X>::max()/2,-1); }\n  static constexpr bool commute = true;\n\
    \  static constexpr vector<P> arrange(const vector<X>&v){\n    vector<P> w(v.size());\n\
    \    for(int i=0;i<v.size();i++)w[i]=P(v[i],i);\n    return w;\n  }\n};\n"
  code: "#pragma once\ntemplate<typename X>\nstruct MonoidMinIndex{\n  using P = pair<X,int>;\n\
    \  using value_type = P;\n  static constexpr P op(const P &x, const P &y) noexcept\
    \ { return min(x,y); }\n  static constexpr void Rchop(P&x, const P&y){ if(x>y)x=y;\
    \ }\n  static constexpr void Lchop(const P&x, P&y){ if(y>x)y=x; }\n  static constexpr\
    \ P unit() { return P(numeric_limits<X>::max()/2,-1); }\n  static constexpr bool\
    \ commute = true;\n  static constexpr vector<P> arrange(const vector<X>&v){\n\
    \    vector<P> w(v.size());\n    for(int i=0;i<v.size();i++)w[i]=P(v[i],i);\n\
    \    return w;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/monoid/MinIndex.cpp
  requiredBy: []
  timestamp: '2023-12-10 20:25:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/monoid/MinIndex.cpp
layout: document
redirect_from:
- /library/library/algebra/monoid/MinIndex.cpp
- /library/library/algebra/monoid/MinIndex.cpp.html
title: library/algebra/monoid/MinIndex.cpp
---
