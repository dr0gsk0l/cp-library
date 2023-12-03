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
  bundledCode: "#line 2 \"library/datastructure/unionfind/ApplyUnionFind.cpp\"\n//\
    \ \u3042\u308B\u9023\u7D50\u6210\u5206\u306E\u5404\u9802\u70B9\u306B\u52A0\u7B97\
    \u51FA\u6765\u308B\ntemplate<typename AbelGroup>\nclass ApplyUnionFind{\n  using\
    \ T=typename AbelGroup::value_type;\n  int n,num;\n  vector<int> sz,parent;\n\
    \  vector<T> value;\npublic:\n  ApplyUnionFind()=default;\n  ApplyUnionFind(int\
    \ n):n(n),num(n),sz(n,1),parent(n),value(n,AbelGroup::unit()){\n    iota(parent.begin(),parent.end(),0);\n\
    \  }\n  ApplyUnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  \n  int leader(int x){ \n  \
    \  assert(0<=x and x<n);\n    if(parent[x]==x)return x;\n    if(parent[parent[x]]==parent[x])return\
    \ parent[x];\n    stack<int> sta;\n    while(parent[x]!=x){\n      sta.push(x);\n\
    \      x=parent[x];\n    }\n    T sum=AbelGroup::unit();\n    while(sta.size()){\n\
    \      int v=sta.top();sta.pop();\n      AbelGroup::Rchop(sum,value[v]);\n   \
    \   value[v]=sum;\n      parent[v]=x;\n    }\n    return x;\n  }\n\n  T get(int\
    \ x){\n    if(x==leader(x))return value[x];\n    return AbelGroup::op(value[x],value[parent[x]]);\n\
    \  }\n\n  // x \u3068\u9023\u7D50\u306A\u9802\u70B9\u5168\u4F53\u306B *=a\n  void\
    \ multiply(int x,T a){\n    x=leader(x);\n    AbelGroup::Rchop(value[x],a);\n\
    \  }\n  \n  bool same(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    return leader(x)==leader(y); \n  }\n  \n  bool merge(int x,int y){\n    assert(0<=x\
    \ and x<n and 0<=y and y<n);\n    x=leader(x);y=leader(y);\n    if(x==y)return\
    \ false;\n    if(sz[x]<sz[y])swap(x,y);\n    sz[x]+=sz[y];\n    parent[y]=x;\n\
    \    AbelGroup::Rchop(value[y],AbelGroup::inverse(value[x]));\n    num--;\n  \
    \  return true;\n  }\n  \n  int size(const int x){\n    assert(0<=x and x<n);\n\
    \    return sz[leader(x)];\n  }\n  \n  int count()const{\n    return num;\n  }\n\
    };\n"
  code: "#pragma once\n// \u3042\u308B\u9023\u7D50\u6210\u5206\u306E\u5404\u9802\u70B9\
    \u306B\u52A0\u7B97\u51FA\u6765\u308B\ntemplate<typename AbelGroup>\nclass ApplyUnionFind{\n\
    \  using T=typename AbelGroup::value_type;\n  int n,num;\n  vector<int> sz,parent;\n\
    \  vector<T> value;\npublic:\n  ApplyUnionFind()=default;\n  ApplyUnionFind(int\
    \ n):n(n),num(n),sz(n,1),parent(n),value(n,AbelGroup::unit()){\n    iota(parent.begin(),parent.end(),0);\n\
    \  }\n  ApplyUnionFind(const vector<T>&v):n(v.size()),num(n),sz(n,1),parent(n),value(v){\n\
    \    iota(parent.begin(),parent.end(),0);\n  }\n  \n  int leader(int x){ \n  \
    \  assert(0<=x and x<n);\n    if(parent[x]==x)return x;\n    if(parent[parent[x]]==parent[x])return\
    \ parent[x];\n    stack<int> sta;\n    while(parent[x]!=x){\n      sta.push(x);\n\
    \      x=parent[x];\n    }\n    T sum=AbelGroup::unit();\n    while(sta.size()){\n\
    \      int v=sta.top();sta.pop();\n      AbelGroup::Rchop(sum,value[v]);\n   \
    \   value[v]=sum;\n      parent[v]=x;\n    }\n    return x;\n  }\n\n  T get(int\
    \ x){\n    if(x==leader(x))return value[x];\n    return AbelGroup::op(value[x],value[parent[x]]);\n\
    \  }\n\n  // x \u3068\u9023\u7D50\u306A\u9802\u70B9\u5168\u4F53\u306B *=a\n  void\
    \ multiply(int x,T a){\n    x=leader(x);\n    AbelGroup::Rchop(value[x],a);\n\
    \  }\n  \n  bool same(int x,int y){\n    assert(0<=x and x<n and 0<=y and y<n);\n\
    \    return leader(x)==leader(y); \n  }\n  \n  bool merge(int x,int y){\n    assert(0<=x\
    \ and x<n and 0<=y and y<n);\n    x=leader(x);y=leader(y);\n    if(x==y)return\
    \ false;\n    if(sz[x]<sz[y])swap(x,y);\n    sz[x]+=sz[y];\n    parent[y]=x;\n\
    \    AbelGroup::Rchop(value[y],AbelGroup::inverse(value[x]));\n    num--;\n  \
    \  return true;\n  }\n  \n  int size(const int x){\n    assert(0<=x and x<n);\n\
    \    return sz[leader(x)];\n  }\n  \n  int count()const{\n    return num;\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/ApplyUnionFind.cpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/ApplyUnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/ApplyUnionFind.cpp
- /library/library/datastructure/unionfind/ApplyUnionFind.cpp.html
title: library/datastructure/unionfind/ApplyUnionFind.cpp
---
