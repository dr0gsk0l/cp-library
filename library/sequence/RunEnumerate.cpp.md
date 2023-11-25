---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/String/RunEnumerate.test.cpp
    title: test/library-checker/String/RunEnumerate.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/RunEnumerate.cpp\"\n#include <atcoder/string>\n\
    using namespace atcoder;\n\n#define SIZE_(s) int(s.size())\n\nstruct RunEnumerate{\n\
    \  string s;\n  RunEnumerate(const string&s):s(s){ build(); }\n\n  struct Run{\n\
    \    int t,l,r;\n    Run()=default;\n    Run(int t,int l,int r):t(t),l(l),r(r){}\n\
    \  };\n  vector<Run> ans;\n\n  queue<pair<int,int>> que;\n  string REV(string\
    \ s){ reverse(s.begin(),s.end()); return s; }\n  void solve(int l,int r){\n  \
    \  int m=(l+r)>>1;\n    que.emplace(l,m);que.emplace(m,r);\n    string left_s=s.substr(l,m-l),\
    \ right_s=s.substr(m,r-m), all_s=s.substr(l,r-l);\n    {\n      // \u5404 k \u306B\
    \u5BFE\u3057\u3001left_s \u306E suffix t \u6587\u5B57\u3092\u5468\u671F\u3068\u3059\
    \u308B run \u3092\u63A2\u3059\n      auto Z_left_rev = z_algorithm( REV(left_s)\
    \ );\n      auto Left = [&](int t)->int{\n        // [*,m) \u304C\u5468\u671F\
    \ t\n        if(t==SIZE_(left_s))return l;\n        return m-t-Z_left_rev[t];\n\
    \      };\n      auto Z_right = z_algorithm( right_s+\"#\"+all_s );\n      auto\
    \ Right = [&](int t)->int{\n        // [m,*)\n        return m+Z_right[r-l-t+1];\n\
    \      };\n      for(int t=1;t<=m-l;t++){\n        int L=Left(t),R=Right(t);\n\
    \        if(R-L>=2*t)ans.emplace_back(t,L,R);\n      }\n    }\n    {\n      //\
    \ [m,r) \u306E prefix t \u6587\u5B57\n      auto Z_right = z_algorithm( right_s\
    \ );\n      auto Right = [&](int t)->int{\n        if(t==SIZE_(right_s))return\
    \ r;\n        return m+t+Z_right[t];\n      };\n      auto Z_left = z_algorithm(\
    \ REV(left_s)+\"#\"+REV(all_s) );\n      auto Left = [&](int t)->int{\n      \
    \  return m-Z_left[ SIZE_(Z_left)-SIZE_(left_s)-t ];\n      };\n      for(int\
    \ t=1;t<=r-m;t++){\n        int L=Left(t),R=Right(t);\n        if(R-L>=2*t)ans.emplace_back(t,L,R);\n\
    \      }\n    }\n  }\n\n  void arrangement(){\n    vector<Run> fans;\n    sort(ans.begin(),ans.end(),[](Run\
    \ a,Run b){\n      if(a.t!=b.t)return a.t<b.t;\n      if(a.l!=b.l)return a.l<b.l;\n\
    \      return a.r>b.r;\n    });\n    set<pair<int,int>> already;\n    int pret=-1,mx;\n\
    \    for(const auto&[t,l,r]:ans){\n      if(pret!=t)pret=t,mx=-1;\n      if(already.count({l,r})||mx>=r)continue;\n\
    \      if( (r<SIZE_(s) and s[r]==s[r-t]) or (l-1>=0 and s[l-1]==s[l-1+t]) )continue;\n\
    \      fans.emplace_back(t,l,r);\n      already.emplace(l,r);\n      mx=r;\n \
    \   }\n    ans=fans;\n  }\n\n  void build(){\n    que.emplace(0,int(s.size()));\n\
    \    while(que.size()){\n      auto[l,r]=que.front();que.pop();\n      if(l+1==r)continue;\n\
    \      solve(l,r);\n    }\n    arrangement();\n  }\n};\n#undef SIZE_\n"
  code: "#pragma once\n#include <atcoder/string>\nusing namespace atcoder;\n\n#define\
    \ SIZE_(s) int(s.size())\n\nstruct RunEnumerate{\n  string s;\n  RunEnumerate(const\
    \ string&s):s(s){ build(); }\n\n  struct Run{\n    int t,l,r;\n    Run()=default;\n\
    \    Run(int t,int l,int r):t(t),l(l),r(r){}\n  };\n  vector<Run> ans;\n\n  queue<pair<int,int>>\
    \ que;\n  string REV(string s){ reverse(s.begin(),s.end()); return s; }\n  void\
    \ solve(int l,int r){\n    int m=(l+r)>>1;\n    que.emplace(l,m);que.emplace(m,r);\n\
    \    string left_s=s.substr(l,m-l), right_s=s.substr(m,r-m), all_s=s.substr(l,r-l);\n\
    \    {\n      // \u5404 k \u306B\u5BFE\u3057\u3001left_s \u306E suffix t \u6587\
    \u5B57\u3092\u5468\u671F\u3068\u3059\u308B run \u3092\u63A2\u3059\n      auto\
    \ Z_left_rev = z_algorithm( REV(left_s) );\n      auto Left = [&](int t)->int{\n\
    \        // [*,m) \u304C\u5468\u671F t\n        if(t==SIZE_(left_s))return l;\n\
    \        return m-t-Z_left_rev[t];\n      };\n      auto Z_right = z_algorithm(\
    \ right_s+\"#\"+all_s );\n      auto Right = [&](int t)->int{\n        // [m,*)\n\
    \        return m+Z_right[r-l-t+1];\n      };\n      for(int t=1;t<=m-l;t++){\n\
    \        int L=Left(t),R=Right(t);\n        if(R-L>=2*t)ans.emplace_back(t,L,R);\n\
    \      }\n    }\n    {\n      // [m,r) \u306E prefix t \u6587\u5B57\n      auto\
    \ Z_right = z_algorithm( right_s );\n      auto Right = [&](int t)->int{\n   \
    \     if(t==SIZE_(right_s))return r;\n        return m+t+Z_right[t];\n      };\n\
    \      auto Z_left = z_algorithm( REV(left_s)+\"#\"+REV(all_s) );\n      auto\
    \ Left = [&](int t)->int{\n        return m-Z_left[ SIZE_(Z_left)-SIZE_(left_s)-t\
    \ ];\n      };\n      for(int t=1;t<=r-m;t++){\n        int L=Left(t),R=Right(t);\n\
    \        if(R-L>=2*t)ans.emplace_back(t,L,R);\n      }\n    }\n  }\n\n  void arrangement(){\n\
    \    vector<Run> fans;\n    sort(ans.begin(),ans.end(),[](Run a,Run b){\n    \
    \  if(a.t!=b.t)return a.t<b.t;\n      if(a.l!=b.l)return a.l<b.l;\n      return\
    \ a.r>b.r;\n    });\n    set<pair<int,int>> already;\n    int pret=-1,mx;\n  \
    \  for(const auto&[t,l,r]:ans){\n      if(pret!=t)pret=t,mx=-1;\n      if(already.count({l,r})||mx>=r)continue;\n\
    \      if( (r<SIZE_(s) and s[r]==s[r-t]) or (l-1>=0 and s[l-1]==s[l-1+t]) )continue;\n\
    \      fans.emplace_back(t,l,r);\n      already.emplace(l,r);\n      mx=r;\n \
    \   }\n    ans=fans;\n  }\n\n  void build(){\n    que.emplace(0,int(s.size()));\n\
    \    while(que.size()){\n      auto[l,r]=que.front();que.pop();\n      if(l+1==r)continue;\n\
    \      solve(l,r);\n    }\n    arrangement();\n  }\n};\n#undef SIZE_"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/RunEnumerate.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:03:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/String/RunEnumerate.test.cpp
documentation_of: library/sequence/RunEnumerate.cpp
layout: document
redirect_from:
- /library/library/sequence/RunEnumerate.cpp
- /library/library/sequence/RunEnumerate.cpp.html
title: library/sequence/RunEnumerate.cpp
---
