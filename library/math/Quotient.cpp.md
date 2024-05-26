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
  bundledCode: "#line 2 \"library/math/Quotient.cpp\"\nstruct Quotient{\n  // f(l,r,k)\
    \ : {x\\in[l,r] | floor(n/x)=k} \u306B\u3064\u3044\u3066\u306E\u64CD\u4F5C\n \
    \ template<typename T,typename F>\n  static void enum_quotient(T n,const F&f){\n\
    \    T l,r;\n    for(l=1; l*l<=n; l++){\n      T k = n/(double)l;\n      f(l,l,k);\n\
    \    }\n    for(T k = n/(double)l; k; l=r+1,k--){\n      r = n/(double)k;\n  \
    \    f(l,r,k);\n    }\n  }\n};\n"
  code: "#pragma once\nstruct Quotient{\n  // f(l,r,k) : {x\\in[l,r] | floor(n/x)=k}\
    \ \u306B\u3064\u3044\u3066\u306E\u64CD\u4F5C\n  template<typename T,typename F>\n\
    \  static void enum_quotient(T n,const F&f){\n    T l,r;\n    for(l=1; l*l<=n;\
    \ l++){\n      T k = n/(double)l;\n      f(l,l,k);\n    }\n    for(T k = n/(double)l;\
    \ k; l=r+1,k--){\n      r = n/(double)k;\n      f(l,r,k);\n    }\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/Quotient.cpp
  requiredBy: []
  timestamp: '2024-05-26 19:55:08+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/Quotient.cpp
layout: document
redirect_from:
- /library/library/math/Quotient.cpp
- /library/library/math/Quotient.cpp.html
title: library/math/Quotient.cpp
---
