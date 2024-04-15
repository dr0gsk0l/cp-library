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
  bundledCode: "#line 1 \"library/local/Distance.cpp\"\ntemplate <typename T> class\
    \ Distance {\n    std::map<T, int> d;\n    std::queue<T> que;\n\n  public:\n \
    \   // s \u304B\u3089\u7D42\u7AEF\u306B\u305F\u3069\u308A\u7740\u304F\u307E\u3067\
    \u306E\u8DDD\u96E2\n    template <typename F> int shortest_path(const F &f, const\
    \ T &s) {\n        if (d.count(s))\n            return d[s];\n        if (!f(s).size())\n\
    \            return d[s] = 0;\n        int res = 1e9;\n        for (const T &to\
    \ : f(s))\n            res = std::min(res, shortest_path(f, to) + 1);\n      \
    \  return d[s] = res;\n    }\n\n    // s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\
    \u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n    template <typename\
    \ F>\n    std::vector<std::vector<T>> from_root(const F &f, const T &s,\n    \
    \                                      int MAX = 10) {\n        std::vector<std::vector<T>>\
    \ level(MAX + 1);\n        d[s] = 0;\n        que.push(s);\n        while (que.size())\
    \ {\n            T v = que.front();\n            que.pop();\n            int D\
    \ = d[v];\n            for (const T &to : f(v)) {\n                if (d.count(to))\n\
    \                    continue;\n                d[to] = D + 1;\n             \
    \   if (D + 1 < MAX)\n                    que.push(to);\n            }\n     \
    \   }\n        for (const auto &[key, val] : d)\n            level[val].push_back(key);\n\
    \        return level;\n    }\n\n    template <typename F>\n    std::vector<std::vector<T>>\
    \ from_root(const F &f, const std::vector<T> &s,\n                           \
    \               int MAX = 10) {\n        std::vector<std::vector<T>> level(MAX\
    \ + 1);\n        for (const T &v : s) {\n            d[v] = 0;\n            que.push(v);\n\
    \        }\n        while (que.size()) {\n            T v = que.front();\n   \
    \         que.pop();\n            int D = d[v];\n            for (const T &to\
    \ : f(v)) {\n                if (d.count(to))\n                    continue;\n\
    \                d[to] = D + 1;\n                if (D + 1 < MAX)\n          \
    \          que.push(to);\n            }\n        }\n        for (const auto &[key,\
    \ val] : d)\n            level[val].push_back(key);\n        return level;\n \
    \   }\n};\n"
  code: "template <typename T> class Distance {\n    std::map<T, int> d;\n    std::queue<T>\
    \ que;\n\n  public:\n    // s \u304B\u3089\u7D42\u7AEF\u306B\u305F\u3069\u308A\
    \u7740\u304F\u307E\u3067\u306E\u8DDD\u96E2\n    template <typename F> int shortest_path(const\
    \ F &f, const T &s) {\n        if (d.count(s))\n            return d[s];\n   \
    \     if (!f(s).size())\n            return d[s] = 0;\n        int res = 1e9;\n\
    \        for (const T &to : f(s))\n            res = std::min(res, shortest_path(f,\
    \ to) + 1);\n        return d[s] = res;\n    }\n\n    // s \u304B\u3089\u306E\u6700\
    \u77ED\u8DDD\u96E2\u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n\
    \    template <typename F>\n    std::vector<std::vector<T>> from_root(const F\
    \ &f, const T &s,\n                                          int MAX = 10) {\n\
    \        std::vector<std::vector<T>> level(MAX + 1);\n        d[s] = 0;\n    \
    \    que.push(s);\n        while (que.size()) {\n            T v = que.front();\n\
    \            que.pop();\n            int D = d[v];\n            for (const T &to\
    \ : f(v)) {\n                if (d.count(to))\n                    continue;\n\
    \                d[to] = D + 1;\n                if (D + 1 < MAX)\n          \
    \          que.push(to);\n            }\n        }\n        for (const auto &[key,\
    \ val] : d)\n            level[val].push_back(key);\n        return level;\n \
    \   }\n\n    template <typename F>\n    std::vector<std::vector<T>> from_root(const\
    \ F &f, const std::vector<T> &s,\n                                          int\
    \ MAX = 10) {\n        std::vector<std::vector<T>> level(MAX + 1);\n        for\
    \ (const T &v : s) {\n            d[v] = 0;\n            que.push(v);\n      \
    \  }\n        while (que.size()) {\n            T v = que.front();\n         \
    \   que.pop();\n            int D = d[v];\n            for (const T &to : f(v))\
    \ {\n                if (d.count(to))\n                    continue;\n       \
    \         d[to] = D + 1;\n                if (D + 1 < MAX)\n                 \
    \   que.push(to);\n            }\n        }\n        for (const auto &[key, val]\
    \ : d)\n            level[val].push_back(key);\n        return level;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/local/Distance.cpp
  requiredBy: []
  timestamp: '2024-04-15 11:27:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/Distance.cpp
layout: document
title: Distance
---

* ```int shortest_path(const F&f,const T&s)```  
$s$ から終端（ $f(t)$ が空であるような頂点 $t$ ）までの最短距離を求める  
一度求めた距離はメモ化され、2回目以降にもその結果が用いられる
実装が BFS でなく DFS であることに注意

* ```vector<vector<T>> from_root(const F&f,const T&s,int MAX=10)```  
$s$ からの距離が $MAX$ 以下の点を BFS で求める  
```result[d]``` には $s$ から距離 $d$ の頂点が辞書順に入ってる  
この関数を呼ぶ場合、（```from_root``` も含めて）他に関数は呼ばない

* ```vector<vector<T>> from_root(const F&f,const std::vector<T>&s,int MAX=10)```  
```from_root``` の多始点版

## 概要
最短手数を求める実験用ライブラリ  
有向辺　$f:T\rightarrow std::vector<T>$ を渡す  

## 例
[AGC059A](https://atcoder.jp/contests/agc059/tasks/agc059_a) の実験コード  
操作を逆向きにして ```from_root``` を呼ぶことで、5手以内で終了する長さ 7 の列を列挙している
```cpp
#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(v) v.begin(),v.end()
using vi=vector<int>;
vi iota(int n){ vi v(n);iota(ALL(v),0);return v; }

auto f=[](vi v){
  std::vector<vi> nxt;
  auto p=iota(3);
  do{
    REP(l,v.size()){
      vi w=v;
      for(int r=l;r<v.size();r++){
        w[r]=p[v[r]];
        nxt.push_back(w);
      }
    }
  }while(next_permutation(ALL(p)));
  return nxt;
};

Distance<vi> D;
auto level=D.from_root(f,{vi(7,0),vi(7,1),vi(7,2)},5);
```
対称性などがあるものに関しては、$f$ で代表元に向かうコードにしても良いし、以下のように出力で省いても良い
```cpp
set<vi> used;
REP(d,level.size()){
  std::cout<<d<<":\n";
  auto p=iota(3);
  for(vi v:level[d]){
    v.erase(unique(ALL(v)),v.end());
    if(used.count(v))continue;
    bool ok=true;
    do{
      auto w=v;
      for(int&a:w)a=p[a];
      if(used.count(w))ok=false;
    }while(next_permutation(ALL(p)));
    if(ok){
      std::cout<<v<<endl;
      used.insert(v);
    }
  }
}
```
