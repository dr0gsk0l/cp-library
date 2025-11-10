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
  bundledCode: "#line 1 \"library/datastructure/unionfind/ApplyUndoUnionFind.hpp\"\
    \n#include <bits/stdc++.h>\n\ntemplate <typename AbelGroup> class UndoUnionFind\
    \ {\n    using T = typename AbelGroup::value_type;\n    size_t n, num;\n    std::vector<size_t>\
    \ sz, parent;\n    std::stack<std::pair<size_t, size_t>> sta;\n    std::vector<T>\
    \ value;\n\n  public:\n    UndoUnionFind() = default;\n    UndoUnionFind(size_t\
    \ n)\n        : n(n), num(n), sz(n, 1), parent(n, 0), value(n, AbelGroup::unit())\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    size_t\
    \ leader(size_t x) const {\n        assert(0 <= x and x < n);\n        return\
    \ (x == parent[x] ? x : leader(parent[x]));\n    }\n\n    T get(size_t x) const\
    \ {\n        assert(0 <= x and x < n);\n        if (x == parent[x])\n        \
    \    return value[x];\n        T ret = value[x];\n        while (x != parent[x])\
    \ {\n            x = parent[x];\n            AbelGroup::Rchop(ret, value[x]);\n\
    \        }\n        return ret;\n    }\n\n    bool same(size_t x, size_t y) const\
    \ {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x)\
    \ == leader(y);\n    }\n\n    bool merge(size_t x, size_t y) {\n        assert(0\
    \ <= x and x < n and 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n\
    \            std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n\
    \        AbelGroup::Rchop(value[y], AbelGroup::inverse(value[x]));\n        num--;\n\
    \        sta.emplace(x, y);\n        return true;\n    }\n\n    void undo() {\n\
    \        if (!sta.size())\n            return;\n        auto [x, y] = sta.top();\n\
    \        sta.pop();\n        sz[x] -= sz[y];\n        parent[y] = y;\n       \
    \ AbelGroup::Rchop(value[y], value[x]);\n        num++;\n    }\n\n    size_t size(const\
    \ size_t x) const {\n        assert(0 <= x and x < n);\n        return sz[leader(x)];\n\
    \    }\n\n    size_t count() const { return num; }\n};\n"
  code: "#include <bits/stdc++.h>\n\ntemplate <typename AbelGroup> class UndoUnionFind\
    \ {\n    using T = typename AbelGroup::value_type;\n    size_t n, num;\n    std::vector<size_t>\
    \ sz, parent;\n    std::stack<std::pair<size_t, size_t>> sta;\n    std::vector<T>\
    \ value;\n\n  public:\n    UndoUnionFind() = default;\n    UndoUnionFind(size_t\
    \ n)\n        : n(n), num(n), sz(n, 1), parent(n, 0), value(n, AbelGroup::unit())\
    \ {\n        std::iota(parent.begin(), parent.end(), 0);\n    }\n\n    size_t\
    \ leader(size_t x) const {\n        assert(0 <= x and x < n);\n        return\
    \ (x == parent[x] ? x : leader(parent[x]));\n    }\n\n    T get(size_t x) const\
    \ {\n        assert(0 <= x and x < n);\n        if (x == parent[x])\n        \
    \    return value[x];\n        T ret = value[x];\n        while (x != parent[x])\
    \ {\n            x = parent[x];\n            AbelGroup::Rchop(ret, value[x]);\n\
    \        }\n        return ret;\n    }\n\n    bool same(size_t x, size_t y) const\
    \ {\n        assert(0 <= x and x < n and 0 <= y and y < n);\n        return leader(x)\
    \ == leader(y);\n    }\n\n    bool merge(size_t x, size_t y) {\n        assert(0\
    \ <= x and x < n and 0 <= y and y < n);\n        x = leader(x);\n        y = leader(y);\n\
    \        if (x == y)\n            return false;\n        if (sz[x] < sz[y])\n\
    \            std::swap(x, y);\n        sz[x] += sz[y];\n        parent[y] = x;\n\
    \        AbelGroup::Rchop(value[y], AbelGroup::inverse(value[x]));\n        num--;\n\
    \        sta.emplace(x, y);\n        return true;\n    }\n\n    void undo() {\n\
    \        if (!sta.size())\n            return;\n        auto [x, y] = sta.top();\n\
    \        sta.pop();\n        sz[x] -= sz[y];\n        parent[y] = y;\n       \
    \ AbelGroup::Rchop(value[y], value[x]);\n        num++;\n    }\n\n    size_t size(const\
    \ size_t x) const {\n        assert(0 <= x and x < n);\n        return sz[leader(x)];\n\
    \    }\n\n    size_t count() const { return num; }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/unionfind/ApplyUndoUnionFind.hpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/unionfind/ApplyUndoUnionFind.hpp
layout: document
redirect_from:
- /library/library/datastructure/unionfind/ApplyUndoUnionFind.hpp
- /library/library/datastructure/unionfind/ApplyUndoUnionFind.hpp.html
title: library/datastructure/unionfind/ApplyUndoUnionFind.hpp
---
