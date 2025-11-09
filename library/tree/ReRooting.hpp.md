---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_A.test.cpp
    title: test/AOJ/GRL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/ReRooting.hpp\"\ntemplate <typename TREE, typename\
    \ Data> class ReRooting {\n    int n;\n    TREE T;\n\n  public:\n    ReRooting(const\
    \ TREE &T) : T(T), n(T.n) {}\n\n    template <typename F1, typename F2>\n    std::vector<Data>\
    \ build(const F1 &score, const F2 &merge,\n                            const Data\
    \ &unit) {\n        if (!~T.root)\n            T.build(0);\n        std::vector<Data>\
    \ dp1(n, unit), dp2(n);\n        for (int v : T.DFS)\n            for (const auto\
    \ &e : T.son(v)) {\n                dp2[e.to] = score(dp1[e.to], e);\n       \
    \         merge(dp1[v], dp2[e.to]);\n            }\n        std::vector<Data>\
    \ top(n, unit), res(n);\n        for (int v : T.BFS) {\n            Data now =\
    \ (T.root == v ? unit : score(top[v], T.parent(v)));\n            for (int to\
    \ : T.son(v)) {\n                top[to] = now;\n                merge(now, dp2[to]);\n\
    \            }\n            res[v] = now;\n            now = unit;\n         \
    \   for (int i = T.son(v).size() - 1; i >= 0; i--) {\n                int to =\
    \ T.son(v)[i];\n                merge(top[to], now);\n                merge(now,\
    \ dp2[to]);\n            }\n        }\n        return res;\n    }\n};\n"
  code: "template <typename TREE, typename Data> class ReRooting {\n    int n;\n \
    \   TREE T;\n\n  public:\n    ReRooting(const TREE &T) : T(T), n(T.n) {}\n\n \
    \   template <typename F1, typename F2>\n    std::vector<Data> build(const F1\
    \ &score, const F2 &merge,\n                            const Data &unit) {\n\
    \        if (!~T.root)\n            T.build(0);\n        std::vector<Data> dp1(n,\
    \ unit), dp2(n);\n        for (int v : T.DFS)\n            for (const auto &e\
    \ : T.son(v)) {\n                dp2[e.to] = score(dp1[e.to], e);\n          \
    \      merge(dp1[v], dp2[e.to]);\n            }\n        std::vector<Data> top(n,\
    \ unit), res(n);\n        for (int v : T.BFS) {\n            Data now = (T.root\
    \ == v ? unit : score(top[v], T.parent(v)));\n            for (int to : T.son(v))\
    \ {\n                top[to] = now;\n                merge(now, dp2[to]);\n  \
    \          }\n            res[v] = now;\n            now = unit;\n           \
    \ for (int i = T.son(v).size() - 1; i >= 0; i--) {\n                int to = T.son(v)[i];\n\
    \                merge(top[to], now);\n                merge(now, dp2[to]);\n\
    \            }\n        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/ReRooting.hpp
  requiredBy: []
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_5_A.test.cpp
documentation_of: library/tree/ReRooting.hpp
layout: document
redirect_from:
- /library/library/tree/ReRooting.hpp
- /library/library/tree/ReRooting.hpp.html
title: library/tree/ReRooting.hpp
---
