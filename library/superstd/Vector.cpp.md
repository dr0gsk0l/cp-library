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
  bundledCode: "#line 2 \"library/superstd/Vector.cpp\"\ntemplate<typename T>\nclass\
    \ Vector{\n  int m;\n  vector<T> v;\n\n  Vector()=default;\n  Vector(int n,T x={}):v(n,x),m(0){}\n\
    \  Vector(int L,int R,T x):v(L+R,x),m(L){}\n};\n"
  code: "#pragma once\ntemplate<typename T>\nclass Vector{\n  int m;\n  vector<T>\
    \ v;\n\n  Vector()=default;\n  Vector(int n,T x={}):v(n,x),m(0){}\n  Vector(int\
    \ L,int R,T x):v(L+R,x),m(L){}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Vector.cpp
  requiredBy: []
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/superstd/Vector.cpp
layout: document
redirect_from:
- /library/library/superstd/Vector.cpp
- /library/library/superstd/Vector.cpp.html
title: library/superstd/Vector.cpp
---