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
  bundledCode: "#line 1 \"library/local/Distance.cpp\"\ntemplate<typename T>\nclass\
    \ Distance{\n  map<T,int> d;\n  queue<T> que;\npublic:\n  // s \u304B\u3089\u7D42\
    \u7AEF\u306B\u305F\u3069\u308A\u7740\u304F\u307E\u3067\u306E\u8DDD\u96E2\n  template<typename\
    \ F>\n  int shortest_path(const F&f,const T&s){\n    if(d.count(s))return d[s];\n\
    \    if(!f(s).size())return d[s]=0;\n    int res=1e9;\n    for(const T&to:f(s))res=min(res,shortest_path(f,to)+1);\n\
    \    return d[s]=res;\n  }\n\n  // s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\
    \u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n  template<typename\
    \ F>\n  vector<vector<T>> from_root(const F&f,const T&s,int MAX=10){\n    vector<vector<T>>\
    \ level(MAX+1);\n    d[s]=0;\n    que.push(s);\n    while(que.size()){\n     \
    \ T v=que.front();que.pop();\n      int D=d[v];\n      for(const T&to:f(v)){\n\
    \        if(d.count(to))continue;\n        d[to]=D+1;\n        if(D+1<MAX)que.push(to);\n\
    \      }\n    }\n    for(const auto&[key,val]:d)level[val].push_back(key);\n \
    \   return level;\n  }\n\n  template<typename F>\n  vector<vector<T>> from_root(const\
    \ F&f,const vector<T>&s,int MAX=10){\n    vector<vector<T>> level(MAX+1);\n  \
    \  for(const T&v:s){\n      d[v]=0;\n      que.push(v);\n    }\n    while(que.size()){\n\
    \      T v=que.front();que.pop();\n      int D=d[v];\n      for(const T&to:f(v)){\n\
    \        if(d.count(to))continue;\n        d[to]=D+1;\n        if(D+1<MAX)que.push(to);\n\
    \      }\n    }\n    for(const auto&[key,val]:d)level[val].push_back(key);\n \
    \   return level;\n  }\n};\n"
  code: "template<typename T>\nclass Distance{\n  map<T,int> d;\n  queue<T> que;\n\
    public:\n  // s \u304B\u3089\u7D42\u7AEF\u306B\u305F\u3069\u308A\u7740\u304F\u307E\
    \u3067\u306E\u8DDD\u96E2\n  template<typename F>\n  int shortest_path(const F&f,const\
    \ T&s){\n    if(d.count(s))return d[s];\n    if(!f(s).size())return d[s]=0;\n\
    \    int res=1e9;\n    for(const T&to:f(s))res=min(res,shortest_path(f,to)+1);\n\
    \    return d[s]=res;\n  }\n\n  // s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\
    \u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n  template<typename\
    \ F>\n  vector<vector<T>> from_root(const F&f,const T&s,int MAX=10){\n    vector<vector<T>>\
    \ level(MAX+1);\n    d[s]=0;\n    que.push(s);\n    while(que.size()){\n     \
    \ T v=que.front();que.pop();\n      int D=d[v];\n      for(const T&to:f(v)){\n\
    \        if(d.count(to))continue;\n        d[to]=D+1;\n        if(D+1<MAX)que.push(to);\n\
    \      }\n    }\n    for(const auto&[key,val]:d)level[val].push_back(key);\n \
    \   return level;\n  }\n\n  template<typename F>\n  vector<vector<T>> from_root(const\
    \ F&f,const vector<T>&s,int MAX=10){\n    vector<vector<T>> level(MAX+1);\n  \
    \  for(const T&v:s){\n      d[v]=0;\n      que.push(v);\n    }\n    while(que.size()){\n\
    \      T v=que.front();que.pop();\n      int D=d[v];\n      for(const T&to:f(v)){\n\
    \        if(d.count(to))continue;\n        d[to]=D+1;\n        if(D+1<MAX)que.push(to);\n\
    \      }\n    }\n    for(const auto&[key,val]:d)level[val].push_back(key);\n \
    \   return level;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/local/Distance.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/Distance.cpp
layout: document
redirect_from:
- /library/library/local/Distance.cpp
- /library/library/local/Distance.cpp.html
title: library/local/Distance.cpp
---
