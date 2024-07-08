---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/query/OfflineDynamicConnectivity.hpp
    title: library/query/OfflineDynamicConnectivity.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/UndoUnionFind.hpp\"\n#include\
    \ <cassert>\n#include <stack>\n#include <vector>\n\nclass UndoUnionFind {\n  \
    \  size_t n, num;\n    std::vector<size_t> sz, parent;\n    std::stack<std::pair<size_t,\
    \ size_t>> sta;\n\n  public:\n    UndoUnionFind() = default;\n    UndoUnionFind(size_t\
    \ n) : n(n), num(n), sz(n, 1), parent(n) {\n        std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    size_t leader(size_t x) const {\n        assert(0\
    \ <= x and x < n);\n        return (x == parent[x] ? x : leader(parent[x]));\n\
    \    }\n\n    bool same(size_t x, size_t y) const {\n        assert(0 <= x and\
    \ x < n and 0 <= y and y < n);\n        return leader(x) == leader(y);\n    }\n\
    \n    bool merge(size_t x, size_t y) {\n        assert(0 <= x and x < n and 0\
    \ <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n        if\
    \ (x == y)\n            return false;\n        if (sz[x] < sz[y])\n          \
    \  std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n       \
    \ num--;\n        sta.emplace(x, y);\n        return true;\n    }\n\n    void\
    \ undo() {\n        if (!sta.size())\n            return;\n        auto [x, y]\
    \ = sta.top();\n        sta.pop();\n        sz[x] -= sz[y];\n        parent[y]\
    \ = y;\n        num++;\n    }\n\n    size_t size(const size_t x) const {\n   \
    \     assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    size_t\
    \ count() const { return num; }\n};\n"
  code: "#include <cassert>\n#include <stack>\n#include <vector>\n\nclass UndoUnionFind\
    \ {\n    size_t n, num;\n    std::vector<size_t> sz, parent;\n    std::stack<std::pair<size_t,\
    \ size_t>> sta;\n\n  public:\n    UndoUnionFind() = default;\n    UndoUnionFind(size_t\
    \ n) : n(n), num(n), sz(n, 1), parent(n) {\n        std::iota(parent.begin(),\
    \ parent.end(), 0);\n    }\n\n    size_t leader(size_t x) const {\n        assert(0\
    \ <= x and x < n);\n        return (x == parent[x] ? x : leader(parent[x]));\n\
    \    }\n\n    bool same(size_t x, size_t y) const {\n        assert(0 <= x and\
    \ x < n and 0 <= y and y < n);\n        return leader(x) == leader(y);\n    }\n\
    \n    bool merge(size_t x, size_t y) {\n        assert(0 <= x and x < n and 0\
    \ <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n        if\
    \ (x == y)\n            return false;\n        if (sz[x] < sz[y])\n          \
    \  std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n       \
    \ num--;\n        sta.emplace(x, y);\n        return true;\n    }\n\n    void\
    \ undo() {\n        if (!sta.size())\n            return;\n        auto [x, y]\
    \ = sta.top();\n        sta.pop();\n        sz[x] -= sz[y];\n        parent[y]\
    \ = y;\n        num++;\n    }\n\n    size_t size(const size_t x) const {\n   \
    \     assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    size_t\
    \ count() const { return num; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/UndoUnionFind.hpp
  requiredBy:
  - library/query/OfflineDynamicConnectivity.hpp
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/UndoUnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/UndoUnionFind.hpp
- /library/library/datastructure/unionfind/UndoUnionFind.hpp.html
title: library/datastructure/unionfind/UndoUnionFind.hpp
---
