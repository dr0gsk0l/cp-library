---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/datastructure/unionfind/UndoUnionFind.hpp
    title: library/datastructure/unionfind/UndoUnionFind.hpp
  _extendedRequiredBy: []
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
    \ count() const { return num; }\n};\n#line 2 \"library/query/OfflineDynamicConnectivity.hpp\"\
    \n\nclass OfflineDynamicConnectivity {\n    using edge = std::pair<int, int>;\n\
    \n    UnionFindUndo uf;\n    int V, Q, segsz;\n    std::vector<std::vector<edge>>\
    \ seg;\n    int comp;\n\n    std::vector<std::pair<std::pair<int, int>, edge>>\
    \ pend;\n    std::map<edge, int> cnt, appear;\n\n    OfflineDynamicConnectivity(int\
    \ V, int Q) : uf(V), V(V), Q(Q), comp(V) {\n        segsz = 1;\n        while\
    \ (segsz < Q)\n            segsz <<= 1;\n        seg.resize(2 * segsz - 1);\n\
    \    }\n\n    void insert(int idx, int s, int t) {\n        auto e = std::minmax(s,\
    \ t);\n        if (cnt[e]++ == 0)\n            appear[e] = idx;\n    }\n\n   \
    \ void erase(int idx, int s, int t) {\n        auto e = std::minmax(s, t);\n \
    \       if (--cnt[e] == 0)\n            pend.emplace_back(std::make_pair(appear[e],\
    \ idx), e);\n    }\n\n    void add(int a, int b, const edge &e, int k, int l,\
    \ int r) {\n        if (r <= a || b <= l)\n            return;\n        if (a\
    \ <= l && r <= b) {\n            seg[k].emplace_back(e);\n            return;\n\
    \        }\n        add(a, b, e, 2 * k + 1, l, (l + r) >> 1);\n        add(a,\
    \ b, e, 2 * k + 2, (l + r) >> 1, r);\n    }\n\n    void add(int a, int b, const\
    \ edge &e) { add(a, b, e, 0, 0, segsz); }\n\n    void build() {\n        for (auto\
    \ &p : cnt) {\n            if (p.second > 0)\n                pend.emplace_back(std::make_pair(appear[p.first],\
    \ Q), p.first);\n        }\n        for (auto &s : pend) {\n            add(s.first.first,\
    \ s.first.second, s.second);\n        }\n    }\n\n    int run(const function<void(int)>\
    \ &f, int k = 0) {\n        int add = 0;\n        for (auto &e : seg[k]) {\n \
    \           add += uf.unite(e.first, e.second);\n        }\n        comp -= add;\n\
    \        if (k < segsz - 1) {\n            run(f, 2 * k + 1);\n            run(f,\
    \ 2 * k + 2);\n        } else if (k - (segsz - 1) < Q) {\n            int query_index\
    \ = k - (segsz - 1);\n            f(query_index);\n        }\n        for (auto\
    \ &e : seg[k]) {\n            uf.undo();\n        }\n        comp += add;\n  \
    \  }\n};\n"
  code: "#include \"library/datastructure/unionfind/UndoUnionFind.hpp\"\n\nclass OfflineDynamicConnectivity\
    \ {\n    using edge = std::pair<int, int>;\n\n    UnionFindUndo uf;\n    int V,\
    \ Q, segsz;\n    std::vector<std::vector<edge>> seg;\n    int comp;\n\n    std::vector<std::pair<std::pair<int,\
    \ int>, edge>> pend;\n    std::map<edge, int> cnt, appear;\n\n    OfflineDynamicConnectivity(int\
    \ V, int Q) : uf(V), V(V), Q(Q), comp(V) {\n        segsz = 1;\n        while\
    \ (segsz < Q)\n            segsz <<= 1;\n        seg.resize(2 * segsz - 1);\n\
    \    }\n\n    void insert(int idx, int s, int t) {\n        auto e = std::minmax(s,\
    \ t);\n        if (cnt[e]++ == 0)\n            appear[e] = idx;\n    }\n\n   \
    \ void erase(int idx, int s, int t) {\n        auto e = std::minmax(s, t);\n \
    \       if (--cnt[e] == 0)\n            pend.emplace_back(std::make_pair(appear[e],\
    \ idx), e);\n    }\n\n    void add(int a, int b, const edge &e, int k, int l,\
    \ int r) {\n        if (r <= a || b <= l)\n            return;\n        if (a\
    \ <= l && r <= b) {\n            seg[k].emplace_back(e);\n            return;\n\
    \        }\n        add(a, b, e, 2 * k + 1, l, (l + r) >> 1);\n        add(a,\
    \ b, e, 2 * k + 2, (l + r) >> 1, r);\n    }\n\n    void add(int a, int b, const\
    \ edge &e) { add(a, b, e, 0, 0, segsz); }\n\n    void build() {\n        for (auto\
    \ &p : cnt) {\n            if (p.second > 0)\n                pend.emplace_back(std::make_pair(appear[p.first],\
    \ Q), p.first);\n        }\n        for (auto &s : pend) {\n            add(s.first.first,\
    \ s.first.second, s.second);\n        }\n    }\n\n    int run(const function<void(int)>\
    \ &f, int k = 0) {\n        int add = 0;\n        for (auto &e : seg[k]) {\n \
    \           add += uf.unite(e.first, e.second);\n        }\n        comp -= add;\n\
    \        if (k < segsz - 1) {\n            run(f, 2 * k + 1);\n            run(f,\
    \ 2 * k + 2);\n        } else if (k - (segsz - 1) < Q) {\n            int query_index\
    \ = k - (segsz - 1);\n            f(query_index);\n        }\n        for (auto\
    \ &e : seg[k]) {\n            uf.undo();\n        }\n        comp += add;\n  \
    \  }\n};\n"
  dependsOn:
  - library/datastructure/unionfind/UndoUnionFind.hpp
  isVerificationFile: false
  path: library/query/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/query/OfflineDynamicConnectivity.hpp
layout: document
redirect_from:
- /library/library/query/OfflineDynamicConnectivity.hpp
- /library/library/query/OfflineDynamicConnectivity.hpp.html
title: library/query/OfflineDynamicConnectivity.hpp
---
