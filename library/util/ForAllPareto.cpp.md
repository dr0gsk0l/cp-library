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
  bundledCode: "#line 1 \"library/util/ForAllPareto.cpp\"\ntemplate<typename F>\n\
    void for_all_pareto(const vector<int>&v, const F&f){\n  int n=v.size();\n  vector<int>\
    \ a(n,0);\n  while(true){\n    f(a);\n    int idx=0;\n    while(idx<n and a[idx]==v[idx])a[idx++]=0;\n\
    \    if(idx==n)break;\n    a[idx]++;\n  }\n}\n"
  code: "template<typename F>\nvoid for_all_pareto(const vector<int>&v, const F&f){\n\
    \  int n=v.size();\n  vector<int> a(n,0);\n  while(true){\n    f(a);\n    int\
    \ idx=0;\n    while(idx<n and a[idx]==v[idx])a[idx++]=0;\n    if(idx==n)break;\n\
    \    a[idx]++;\n  }\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/ForAllPareto.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/ForAllPareto.cpp
layout: document
redirect_from:
- /library/library/util/ForAllPareto.cpp
- /library/library/util/ForAllPareto.cpp.html
title: library/util/ForAllPareto.cpp
---
