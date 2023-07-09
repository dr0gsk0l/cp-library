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
  bundledCode: "#line 1 \"library/datastructure/CumulativeGroup.cpp\"\ntemplate<typename\
    \ Group>\nstruct CumulativeGroup{\n  using T=typename Group::value_type;\n  vector<T>\
    \ A;\n  CumulativeGroup():A(1,Group::unit()){}\n  CumulativeGroup(const vector<T>&v):A(v.size()+1,Group::unit()){\n\
    \    for(int i=0;i<v.size();i++)A[i+1]=Group::op(A[i],v[i]);\n  }\n  void add(const\
    \ T&a){ A.push_back(Group::op(A.back()+a)); }\n  U sum(int l,int r){\n    assert(0<=l\
    \ and l<=r and r<A.size());\n    return Group::op(A[r],Group::inverse(A[l]));\
    \ \n  }\n  U sum(){ return A.back(); }\n};\n"
  code: "template<typename Group>\nstruct CumulativeGroup{\n  using T=typename Group::value_type;\n\
    \  vector<T> A;\n  CumulativeGroup():A(1,Group::unit()){}\n  CumulativeGroup(const\
    \ vector<T>&v):A(v.size()+1,Group::unit()){\n    for(int i=0;i<v.size();i++)A[i+1]=Group::op(A[i],v[i]);\n\
    \  }\n  void add(const T&a){ A.push_back(Group::op(A.back()+a)); }\n  U sum(int\
    \ l,int r){\n    assert(0<=l and l<=r and r<A.size());\n    return Group::op(A[r],Group::inverse(A[l]));\
    \ \n  }\n  U sum(){ return A.back(); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/CumulativeGroup.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/CumulativeGroup.cpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeGroup.cpp
- /library/library/datastructure/CumulativeGroup.cpp.html
title: library/datastructure/CumulativeGroup.cpp
---
