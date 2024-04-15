---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.cpp
    title: library/datastructure/unionfind/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_A.test.cpp
    title: test/AOJ/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/unionfind/UnionFind.cpp\"\nclass UnionFind\
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
    \   int count() const { return num; }\n};\n#line 2 \"library/graph/MinimumSpanningTree.cpp\"\
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
  code: "#include \"library/datastructure/unionfind/UnionFind.cpp\"\ntemplate <typename\
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
  - library/datastructure/unionfind/UnionFind.cpp
  isVerificationFile: false
  path: library/graph/MinimumSpanningTree.cpp
  requiredBy: []
  timestamp: '2024-04-15 12:10:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/GRL_2_A.test.cpp
documentation_of: library/graph/MinimumSpanningTree.cpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningTree.cpp
- /library/library/graph/MinimumSpanningTree.cpp.html
title: library/graph/MinimumSpanningTree.cpp
---
