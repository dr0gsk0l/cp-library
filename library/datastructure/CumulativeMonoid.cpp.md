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
  bundledCode: "#line 1 \"library/datastructure/CumulativeMonoid.cpp\"\ntemplate<typename\
    \ Monoid>\nclass CumulativeMonoid{\n  using T=typename Monoid::value_type;\n \
    \ vector<T> pre,suf;\npublic:\n  CumulativeMonoid():pre(1,Monoid::unit()),suf(pre){}\n\
    \  CumulativeMonoid(const vector<T>&v):pre(v.size()+1,Monoid::unit()),suf(pre){\n\
    \    for(int i=0;i<v.size();i++)pre[i+1]=Monoid::op(pre[i],v[i]);\n    for(int\
    \ i=v.size()-1;i>=0;i--)suf[i]=Monoid::op(v[i],suf[i+1]);\n    assert(pre.back()==suf[0]);\n\
    \  }\n  //[0,r)\n  T pre_sum(int r){ return pre[r]; }\n  // [l,n)\n  T suf_sum(int\
    \ l){ return suf[l]; }\n\n  T sum(){ return pre.back(); }\n}\n"
  code: "template<typename Monoid>\nclass CumulativeMonoid{\n  using T=typename Monoid::value_type;\n\
    \  vector<T> pre,suf;\npublic:\n  CumulativeMonoid():pre(1,Monoid::unit()),suf(pre){}\n\
    \  CumulativeMonoid(const vector<T>&v):pre(v.size()+1,Monoid::unit()),suf(pre){\n\
    \    for(int i=0;i<v.size();i++)pre[i+1]=Monoid::op(pre[i],v[i]);\n    for(int\
    \ i=v.size()-1;i>=0;i--)suf[i]=Monoid::op(v[i],suf[i+1]);\n    assert(pre.back()==suf[0]);\n\
    \  }\n  //[0,r)\n  T pre_sum(int r){ return pre[r]; }\n  // [l,n)\n  T suf_sum(int\
    \ l){ return suf[l]; }\n\n  T sum(){ return pre.back(); }\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/CumulativeMonoid.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/CumulativeMonoid.cpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeMonoid.cpp
- /library/library/datastructure/CumulativeMonoid.cpp.html
title: library/datastructure/CumulativeMonoid.cpp
---
