---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  - icon: ':x:'
    path: library/util/InversionNumber.cpp
    title: library/util/InversionNumber.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/InversionNumber.cpp\"\n#include <atcoder/fenwicktree>\n\
    using namespace atcoder;\n\n#line 2 \"library/util/Compress.cpp\"\n#define ALL_(v)\
    \ v.begin(),v.end()\ntemplate<typename T,bool Sentinel=false>\nclass Compress{\n\
    \  vector<T> v;\n  bool prepared;\npublic:\n  Compress():prepared(false){\n  \
    \  if constexpr(Sentinel){\n      static_assert(std::numeric_limits<T>::is_specialized,\"\
    cannot use Sentinel\");\n      v={numeric_limits<T>::min(),numeric_limits<T>::max()};\n\
    \    }\n  }\n  Compress(const vector<T>&w):v(w),prepared(false){\n    if constexpr(Sentinel){\n\
    \      static_assert(std::numeric_limits<T>::is_specialized,\"cannot use Sentinel\"\
    );\n      v.push_back(numeric_limits<T>::min());\n      v.push_back(numeric_limits<T>::max());\n\
    \    }\n    build();\n  }\n  \n  void add(T a){ \n    assert(!prepared);\n   \
    \ v.push_back(a); \n  }\n  void build(){\n    assert(!prepared);\n    prepared=true;\n\
    \    sort(ALL_(v));\n    v.erase(unique(ALL_(v)),v.end());\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  int operator[](const T&a)const{\n    assert(prepared);\n\
    \    auto it=lower_bound(ALL_(v),a);\n    assert(*it==a);\n    return distance(v.begin(),it);\n\
    \  }\n  int geq(const T&a)const{\n    assert(prepared);\n    auto it=lower_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int gt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=upper_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n  }\n\
    \  int leq(const T&a)const{\n    assert(prepared);\n    auto it=--upper_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int lt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=--lower_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n \
    \ }\n  T r(int id)const{\n    assert(prepared);\n    return v[id];\n  }\n  bool\
    \ exist(const T&a)const{\n    assert(prepared);\n    return (*lower_bound(ALL_(v),a))==a;\n\
    \  }\n  int size()const{return v.size();}\n  T max()const{ return v.back(); }\n\
    \  T min()const{ return v[0]; }\n\n  friend ostream&operator<<(ostream&os, const\
    \ Compress&C){ \n    for(int i=0;i<C.v.size();i++)os<<C.v[i]<<\":\"<<i<<\" \"\
    ;\n    return os;\n  }\n};\n#undef ALL_\n#line 5 \"library/util/InversionNumber.cpp\"\
    \n\ntemplate <typename T>\nlong long inversion_number(const vector<T> &v){\n \
    \ Compress cmp(v);\n  fenwick_tree<int> ft(cmp.size());\n  long long res=0;\n\
    \  for(int i=int(v.size())-1;i>=0;i--){\n    int j=cmp[v[i]];\n    res+=ft.sum(0,j);\n\
    \    ft.add(j,1);\n  }\n  return res;\n}\n#line 3 \"library/util/BubbleNumber.cpp\"\
    \ntemplate<typename T>\nlong long bubble_number(const vector<T>&v,const vector<T>&w){\n\
    \  int n=v.size();\n  assert(w.size()==n);\n  map<T,queue<int>> mp;\n  for(int\
    \ i=0;i<n;i++)mp[w[i]].push(i);\n  vector<int> idx(n);\n  REP(i,n){\n    if(!mp[v[i]].size())return\
    \ -1;\n    idx[i]=mp[v[i]].front();mp[v[i]].pop();\n  }\n  return inversion_number(idx);\n\
    }\n"
  code: "#pragma once\n#include \"library/util/InversionNumber.cpp\"\ntemplate<typename\
    \ T>\nlong long bubble_number(const vector<T>&v,const vector<T>&w){\n  int n=v.size();\n\
    \  assert(w.size()==n);\n  map<T,queue<int>> mp;\n  for(int i=0;i<n;i++)mp[w[i]].push(i);\n\
    \  vector<int> idx(n);\n  REP(i,n){\n    if(!mp[v[i]].size())return -1;\n    idx[i]=mp[v[i]].front();mp[v[i]].pop();\n\
    \  }\n  return inversion_number(idx);\n}"
  dependsOn:
  - library/util/InversionNumber.cpp
  - library/util/Compress.cpp
  isVerificationFile: false
  path: library/util/BubbleNumber.cpp
  requiredBy: []
  timestamp: '2023-07-11 07:06:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/BubbleNumber.cpp
layout: document
redirect_from:
- /library/library/util/BubbleNumber.cpp
- /library/library/util/BubbleNumber.cpp.html
title: library/util/BubbleNumber.cpp
---
