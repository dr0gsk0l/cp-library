---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/graph/MinimumSpanningArborescence.hpp
    title: library/graph/MinimumSpanningArborescence.hpp
  - icon: ':heavy_check_mark:'
    path: library/graph/MinimumSpanningTree.hpp
    title: library/graph/MinimumSpanningTree.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/unionfind.test.cpp
    title: test/library-checker/DataStructure/unionfind.test.cpp
  - icon: ':x:'
    path: test/library-checker/Graph/DirectedMST.test.cpp
    title: test/library-checker/Graph/DirectedMST.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/UnionFind.hpp\"\n#include\
    \ <numeric>\n#include <vector>\n\nclass UnionFind {\n    int n, num;\n    std::vector<int>\
    \ sz, parent;\n\n  public:\n    UnionFind() = default;\n    UnionFind(int n) :\
    \ n(n), num(n), sz(n, 1), parent(n, 0) {\n        std::iota(parent.begin(), parent.end(),\
    \ 0);\n    }\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n \
    \       return (x == parent[x] ? x : parent[x] = leader(parent[x]));\n    }\n\n\
    \    bool same(int x, int y) {\n        assert(0 <= x and x < n and 0 <= y and\
    \ y < n);\n        return leader(x) == leader(y);\n    }\n\n    bool merge(int\
    \ x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n      \
    \  x = leader(x);\n        y = leader(y);\n        if (x == y)\n            return\
    \ false;\n        if (sz[x] < sz[y])\n            std::swap(x, y);\n        sz[x]\
    \ += sz[y];\n        parent[y] = x;\n        num--;\n        return true;\n  \
    \  }\n\n    int size(const int x) {\n        assert(0 <= x and x < n);\n     \
    \   return sz[leader(x)];\n    }\n\n    int count() const { return num; }\n\n\
    \    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(n);\n        for (int i = 0; i < n; i++)\n            res[leader(i)].push_back(i);\n\
    \        std::erase_if(res, [](const auto &vec) { return vec.empty(); });\n  \
    \      return res;\n    }\n};\n"
  code: "#include <numeric>\n#include <vector>\n\nclass UnionFind {\n    int n, num;\n\
    \    std::vector<int> sz, parent;\n\n  public:\n    UnionFind() = default;\n \
    \   UnionFind(int n) : n(n), num(n), sz(n, 1), parent(n, 0) {\n        std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    int leader(int x) {\n        assert(0 <= x and\
    \ x < n);\n        return (x == parent[x] ? x : parent[x] = leader(parent[x]));\n\
    \    }\n\n    bool same(int x, int y) {\n        assert(0 <= x and x < n and 0\
    \ <= y and y < n);\n        return leader(x) == leader(y);\n    }\n\n    bool\
    \ merge(int x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n\
    \        x = leader(x);\n        y = leader(y);\n        if (x == y)\n       \
    \     return false;\n        if (sz[x] < sz[y])\n            std::swap(x, y);\n\
    \        sz[x] += sz[y];\n        parent[y] = x;\n        num--;\n        return\
    \ true;\n    }\n\n    int size(const int x) {\n        assert(0 <= x and x < n);\n\
    \        return sz[leader(x)];\n    }\n\n    int count() const { return num; }\n\
    \n    std::vector<std::vector<int>> groups() {\n        std::vector<std::vector<int>>\
    \ res(n);\n        for (int i = 0; i < n; i++)\n            res[leader(i)].push_back(i);\n\
    \        std::erase_if(res, [](const auto &vec) { return vec.empty(); });\n  \
    \      return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/UnionFind.hpp
  requiredBy:
  - library/graph/MinimumSpanningTree.hpp
  - library/graph/MinimumSpanningArborescence.hpp
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/unionfind.test.cpp
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/AOJ/GRL_2_A.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
  - test/AOJ/2647.test.cpp
documentation_of: library/datastructure/unionfind/UnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/UnionFind.hpp
- /library/library/datastructure/unionfind/UnionFind.hpp.html
title: library/datastructure/unionfind/UnionFind.hpp
---
