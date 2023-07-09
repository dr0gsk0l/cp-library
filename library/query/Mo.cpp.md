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
  bundledCode: "#line 1 \"library/query/Mo.cpp\"\nclass Mo{\n  int n;\n  vector<pair<int,int>>\
    \ lr;\npublic:\n  Mo()=default;\n  Mo(const vector<pair<int,int>>&lr):lr(lr){\n\
    \    for(const auto&[l,r]:lr){\n      assert(0<=l and l<=r);\n      n=max(n,r);\n\
    \    }\n  }\n  void add(int l,int r){\n    assert(0<=l and l<=r);\n    lr.emplace_back(l,r);\n\
    \    n=max(n,r);\n  }\n\n  template<typename AL,typename AR,typename EL,typename\
    \ ER,typename F>\n  void calc(const AL&add_left,const AR&add_right,const EL&erase_left,const\
    \ ER&erase_right,const F&f){\n    int q=lr.size();\n    int B=max(1,n/int(sqrt(q)));\n\
    \    vector<int> ord(q);\n    iota(ord.begin(),ord.end(),0);\n    sort(ord.begin(),ord.end(),[&](int\
    \ a,int b)->bool{\n      int Ba=lr[a].first/B, Bb=lr[b].first/B;\n      if(Ba!=Bb)return\
    \ Ba<Bb;\n      return (Ba&1) ^ (lr[a].second<lr[b].second);\n    });\n    int\
    \ l=0,r=0;\n    for(int idx:ord){\n      while(l > lr[idx].first) add_left(--l);\n\
    \      while(r < lr[idx].second) add_right(r++);\n      while(l < lr[idx].first)\
    \ erase_left(l++);\n      while(r > lr[idx].second) erase_right(--r);\n      f(idx);\n\
    \    }\n  }\n\n  template< typename A,typename E,typename F>\n  void calc(const\
    \ A&add,const E&erase,const F&f) {\n    calc(add,add,erase,erase,f);\n  }\n};\n"
  code: "class Mo{\n  int n;\n  vector<pair<int,int>> lr;\npublic:\n  Mo()=default;\n\
    \  Mo(const vector<pair<int,int>>&lr):lr(lr){\n    for(const auto&[l,r]:lr){\n\
    \      assert(0<=l and l<=r);\n      n=max(n,r);\n    }\n  }\n  void add(int l,int\
    \ r){\n    assert(0<=l and l<=r);\n    lr.emplace_back(l,r);\n    n=max(n,r);\n\
    \  }\n\n  template<typename AL,typename AR,typename EL,typename ER,typename F>\n\
    \  void calc(const AL&add_left,const AR&add_right,const EL&erase_left,const ER&erase_right,const\
    \ F&f){\n    int q=lr.size();\n    int B=max(1,n/int(sqrt(q)));\n    vector<int>\
    \ ord(q);\n    iota(ord.begin(),ord.end(),0);\n    sort(ord.begin(),ord.end(),[&](int\
    \ a,int b)->bool{\n      int Ba=lr[a].first/B, Bb=lr[b].first/B;\n      if(Ba!=Bb)return\
    \ Ba<Bb;\n      return (Ba&1) ^ (lr[a].second<lr[b].second);\n    });\n    int\
    \ l=0,r=0;\n    for(int idx:ord){\n      while(l > lr[idx].first) add_left(--l);\n\
    \      while(r < lr[idx].second) add_right(r++);\n      while(l < lr[idx].first)\
    \ erase_left(l++);\n      while(r > lr[idx].second) erase_right(--r);\n      f(idx);\n\
    \    }\n  }\n\n  template< typename A,typename E,typename F>\n  void calc(const\
    \ A&add,const E&erase,const F&f) {\n    calc(add,add,erase,erase,f);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/query/Mo.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/query/Mo.cpp
layout: document
redirect_from:
- /library/library/query/Mo.cpp
- /library/library/query/Mo.cpp.html
title: library/query/Mo.cpp
---
