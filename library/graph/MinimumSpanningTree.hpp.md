---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.hpp
    title: library/datastructure/unionfind/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \      return res;\n    }\n};\n#line 2 \"library/graph/MinimumSpanningTree.hpp\"\
    \ntemplate <typename WG, typename W = typename WG::weight_type>\nstd::pair<W,\
    \ std::vector<int>> minimum_spanning_tree(const WG &g) {\n    assert(g.is_prepared());\n\
    \    int n = g.n, m = g.edges.size();\n    UnionFind uf(n);\n    std::vector<int>\
    \ id(m);\n    std::iota(id.begin(), id.end(), 0);\n    std::ranges::sort(id, [&](const\
    \ int i, const int j) {\n        return g.edges[i].weight < g.edges[j].weight;\n\
    \    });\n    W res = 0;\n    std::vector<int> tree;\n    tree.reserve(n - 1);\n\
    \    for (int i : id) {\n        const auto &[from, to, weight] = g.edges[i];\n\
    \        if (uf.same(from, to))\n            continue;\n        tree.push_back(i);\n\
    \        uf.merge(from, to);\n        res += weight;\n    }\n    assert(uf.count()\
    \ == 1);\n    return {res, tree};\n}\n"
  code: "#include \"library/datastructure/unionfind/UnionFind.hpp\"\ntemplate <typename\
    \ WG, typename W = typename WG::weight_type>\nstd::pair<W, std::vector<int>> minimum_spanning_tree(const\
    \ WG &g) {\n    assert(g.is_prepared());\n    int n = g.n, m = g.edges.size();\n\
    \    UnionFind uf(n);\n    std::vector<int> id(m);\n    std::iota(id.begin(),\
    \ id.end(), 0);\n    std::ranges::sort(id, [&](const int i, const int j) {\n \
    \       return g.edges[i].weight < g.edges[j].weight;\n    });\n    W res = 0;\n\
    \    std::vector<int> tree;\n    tree.reserve(n - 1);\n    for (int i : id) {\n\
    \        const auto &[from, to, weight] = g.edges[i];\n        if (uf.same(from,\
    \ to))\n            continue;\n        tree.push_back(i);\n        uf.merge(from,\
    \ to);\n        res += weight;\n    }\n    assert(uf.count() == 1);\n    return\
    \ {res, tree};\n}"
  dependsOn:
  - library/datastructure/unionfind/UnionFind.hpp
  isVerificationFile: false
  path: library/graph/MinimumSpanningTree.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: library/graph/MinimumSpanningTree.hpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningTree.hpp
- /library/library/graph/MinimumSpanningTree.hpp.html
title: library/graph/MinimumSpanningTree.hpp
---
