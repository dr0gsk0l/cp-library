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
  bundledCode: "#line 1 \"library/datastructure/unionfind/UndoMonoidUnionFind.cpp\"\
    \ntemplate <typename AbelGroup> class UnionFind {\n    using T = typename AbelGroup::value_type;\n\
    \    int n, num;\n    std::vector<int> sz, parent;\n    std::vector<T> value;\n\
    \    std::stack<std::pair<int, int>> sta;\n\n  public:\n    UnionFind() = default;\n\
    \    UnionFind(int n)\n        : n(n), num(n), sz(n, 1), parent(n), value(n, AbelGroup::unit())\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n    UnionFind(const\
    \ std::vector<T> &v)\n        : n(v.size()), num(n), sz(n, 1), parent(n), value(v)\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int leader(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return (x == parent[x] ? x\
    \ : leader(parent[x]));\n    }\n\n    T sum(int x) { return value[leader(x)];\
    \ }\n\n    void multiply(int x, T a) { AbelGroup::Rchop(value[leader(x)], a);\
    \ }\n\n    bool same(int x, int y) {\n        assert(0 <= x and x < n and 0 <=\
    \ y and y < n);\n        return leader(x) == leader(y);\n    }\n\n    void undo()\
    \ {\n        auto [x, y] = sta.top();\n        sta.pop();\n        sz[x] -= sz[y];\n\
    \        parent[y] = y;\n        AbelGroup::Rchop(value[x], AbelGroup::inverse(value[y]));\n\
    \    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x and x < n and\
    \ 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n       \
    \ if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n       \
    \     std::swap(x, y);\n        sta.emplace(x, y);\n        sz[x] += sz[y];\n\
    \        parent[y] = x;\n        AbelGroup::Rchop(value[x], value[y]);\n     \
    \   num--;\n        return true;\n    }\n\n    int size(const int x) {\n     \
    \   assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int\
    \ count() const { return num; }\n};\n"
  code: "template <typename AbelGroup> class UnionFind {\n    using T = typename AbelGroup::value_type;\n\
    \    int n, num;\n    std::vector<int> sz, parent;\n    std::vector<T> value;\n\
    \    std::stack<std::pair<int, int>> sta;\n\n  public:\n    UnionFind() = default;\n\
    \    UnionFind(int n)\n        : n(n), num(n), sz(n, 1), parent(n), value(n, AbelGroup::unit())\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n    UnionFind(const\
    \ std::vector<T> &v)\n        : n(v.size()), num(n), sz(n, 1), parent(n), value(v)\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    int leader(int\
    \ x) {\n        assert(0 <= x and x < n);\n        return (x == parent[x] ? x\
    \ : leader(parent[x]));\n    }\n\n    T sum(int x) { return value[leader(x)];\
    \ }\n\n    void multiply(int x, T a) { AbelGroup::Rchop(value[leader(x)], a);\
    \ }\n\n    bool same(int x, int y) {\n        assert(0 <= x and x < n and 0 <=\
    \ y and y < n);\n        return leader(x) == leader(y);\n    }\n\n    void undo()\
    \ {\n        auto [x, y] = sta.top();\n        sta.pop();\n        sz[x] -= sz[y];\n\
    \        parent[y] = y;\n        AbelGroup::Rchop(value[x], AbelGroup::inverse(value[y]));\n\
    \    }\n\n    bool merge(int x, int y) {\n        assert(0 <= x and x < n and\
    \ 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n       \
    \ if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n       \
    \     std::swap(x, y);\n        sta.emplace(x, y);\n        sz[x] += sz[y];\n\
    \        parent[y] = x;\n        AbelGroup::Rchop(value[x], value[y]);\n     \
    \   num--;\n        return true;\n    }\n\n    int size(const int x) {\n     \
    \   assert(0 <= x and x < n);\n        return sz[leader(x)];\n    }\n\n    int\
    \ count() const { return num; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/UndoMonoidUnionFind.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/UndoMonoidUnionFind.cpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/UndoMonoidUnionFind.cpp
- /library/library/datastructure/unionfind/UndoMonoidUnionFind.cpp.html
title: library/datastructure/unionfind/UndoMonoidUnionFind.cpp
---
