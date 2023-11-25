---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/ReRooting.cpp\"\ntemplate<typename TREE,typename\
    \ Data>\nclass ReRooting{\n  int n;\n  TREE T;\npublic:\n  ReRooting(const TREE&T):T(T),n(T.n){}\n\
    \n  template<typename F1,typename F2>\n  vector<Data> build(const F1&score,const\
    \ F2&merge,const Data&unit){\n    if(!~T.root)T.build(0);\n    vector<Data> dp1(n,unit),dp2(n);\n\
    \    for(int v:T.DFS)\n      for(const auto&e:T.son(v)){\n        dp2[e.to]=score(dp1[e.to],e);\n\
    \        merge(dp1[v],dp2[e.to]);\n      }\n    vector<Data> top(n,unit),res(n);\n\
    \    for(int v:T.BFS){\n      Data now=(T.root==v?unit:score(top[v],T.parent(v)));\n\
    \      for(int to:T.son(v)){\n        top[to]=now;\n        merge(now,dp2[to]);\n\
    \      }\n      res[v]=now;\n      now=unit;\n      for(int i=T.son(v).size()-1;i>=0;i--){\n\
    \        int to=T.son(v)[i];\n        merge(top[to],now);\n        merge(now,dp2[to]);\n\
    \      }\n    }\n    return res;\n  }\n};\n"
  code: "template<typename TREE,typename Data>\nclass ReRooting{\n  int n;\n  TREE\
    \ T;\npublic:\n  ReRooting(const TREE&T):T(T),n(T.n){}\n\n  template<typename\
    \ F1,typename F2>\n  vector<Data> build(const F1&score,const F2&merge,const Data&unit){\n\
    \    if(!~T.root)T.build(0);\n    vector<Data> dp1(n,unit),dp2(n);\n    for(int\
    \ v:T.DFS)\n      for(const auto&e:T.son(v)){\n        dp2[e.to]=score(dp1[e.to],e);\n\
    \        merge(dp1[v],dp2[e.to]);\n      }\n    vector<Data> top(n,unit),res(n);\n\
    \    for(int v:T.BFS){\n      Data now=(T.root==v?unit:score(top[v],T.parent(v)));\n\
    \      for(int to:T.son(v)){\n        top[to]=now;\n        merge(now,dp2[to]);\n\
    \      }\n      res[v]=now;\n      now=unit;\n      for(int i=T.son(v).size()-1;i>=0;i--){\n\
    \        int to=T.son(v)[i];\n        merge(top[to],now);\n        merge(now,dp2[to]);\n\
    \      }\n    }\n    return res;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/ReRooting.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_A.test.cpp
documentation_of: library/tree/ReRooting.cpp
layout: document
title: ReRooting
---

$n$ 頂点無向グラフ $T$ を入力にとる  
各頂点 $r\in[n]$ に対して $r$ を根とした時の以下の $dp[r]$ を返す

$dp[v] = \oplus_{c\in C(v)} f(dp[c],e_{vc})$
### 補足
$C(v)$ : $v$ の子  
$\oplus$ : 可換 monoid

---
* ```ReRooting<TREE,Data>(const TREE&T)```  
コンストラクタ  
```Data``` は dp の型

* ```vector<Data> build(const F1&score,const F2&merge, const Data&unit)```  
  $\Theta(n)$
  * ```Data score(Data d,Edge e)```  
  $f(d,e)$ を返す
  * ```void merge(Data&d,const Data&add)```  
  $d \leftarrow d\oplus add$
  * ```Data unit```  
  Data の（$\oplus$ での）単位元
