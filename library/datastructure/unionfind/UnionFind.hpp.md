---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/UnionFind.hpp\"\nclass UnionFind\
    \ {\n    int n, num;\n    std::vector<int> sz, parent;\n\n  public:\n    UnionFind()\
    \ = default;\n    UnionFind(int n) : n(n), num(n), sz(n, 1), parent(n, 0) {\n\
    \        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int leader(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return (x == parent[x] ? x\
    \ : parent[x] = leader(parent[x]));\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x)\
    \ == leader(y);\n    }\n\n    bool merge(int x, int y) {\n        assert(0 <=\
    \ x and x < n and 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n\
    \            std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n\
    \        num--;\n        return true;\n    }\n\n    int size(const int x) {\n\
    \        assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n \
    \   int count() const { return num; }\n};\n"
  code: "class UnionFind {\n    int n, num;\n    std::vector<int> sz, parent;\n\n\
    \  public:\n    UnionFind() = default;\n    UnionFind(int n) : n(n), num(n), sz(n,\
    \ 1), parent(n, 0) {\n        std::iota(parent.begin(), parent.end(), 0);\n  \
    \  }\n\n    int leader(int x) {\n        assert(0 <= x and x < n);\n        return\
    \ (x == parent[x] ? x : parent[x] = leader(parent[x]));\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n      \
    \  return leader(x) == leader(y);\n    }\n\n    bool merge(int x, int y) {\n \
    \       assert(0 <= x and x < n and 0 <= y and y < n);\n        x = leader(x);\n\
    \        y = leader(y);\n        if (x == y)\n            return false;\n    \
    \    if (sz[x] < sz[y])\n            std::swap(x, y);\n        sz[x] += sz[y];\n\
    \        parent[y] = x;\n        num--;\n        return true;\n    }\n\n    int\
    \ size(const int x) {\n        assert(0 <= x and x < n);\n        return sz[leader(x)];\n\
    \    }\n\n    int count() const { return num; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/UnionFind.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/UnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/UnionFind.hpp
- /library/library/datastructure/unionfind/UnionFind.hpp.html
title: library/datastructure/unionfind/UnionFind.hpp
---
