---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeLazy.cpp
    title: library/tree/TreeLazy.cpp
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/LowestCommonAncestor.test.cpp
    title: test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/tree/HLD.cpp\"\ntemplate <typename TREE> struct\
    \ HLD {\n    int n;\n    TREE T;\n    std::vector<int> sz, head, id, id2;\n  \
    \  bool prepared;\n    HLD(TREE T_)\n        : T(T_), n(T_.n), sz(n), head(n),\
    \ id(n), id2(n), prepared(false) {}\n    HLD() = default;\n\n  private:\n    void\
    \ dfs_sz(int v) {\n        sz[v] = 1;\n        for (auto &e : T.son(v)) {\n  \
    \          dfs_sz(e.to);\n            sz[v] += sz[e.to];\n            if (sz[e.to]\
    \ > sz[T.son(v)[0].to])\n                std::swap(e, T.son(v)[0]);\n        }\n\
    \    }\n    void dfs_hld(int v, int &k) {\n        id[v] = k++;\n        for (int\
    \ i = 0; i < T.son(v).size(); i++) {\n            int to = T.son(v)[i];\n    \
    \        head[to] = (i ? to : head[v]);\n            dfs_hld(to, k);\n       \
    \ }\n        id2[v] = k;\n    }\n\n  public:\n    std::vector<int> build(int r\
    \ = 0) {\n        assert(!prepared);\n        prepared = true;\n        if (~T.root)\n\
    \            assert(T.root == r);\n        else\n            T.build(r);\n   \
    \     head[r] = r;\n        dfs_sz(r);\n        int k = 0;\n        dfs_hld(r,\
    \ k);\n        return id;\n    }\n\n    int lca(int u, int v) {\n        assert(prepared);\n\
    \        while (head[u] != head[v])\n            if (T.depth[head[u]] > T.depth[head[v]])\n\
    \                u = T.parent(head[u]);\n            else\n                v =\
    \ T.parent(head[v]);\n        return (T.depth[u] < T.depth[v] ? u : v);\n    }\n\
    \    int distance(int u, int v) {\n        int w = lca(u, v);\n        return\
    \ T.depth[u] + T.depth[v] - T.depth[w] * 2;\n    }\n\n    // l=lca(u,v) \u3068\
    \u3057\u305F\u6642\u3001[u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\u30B9 \u3092\u9589\
    \u533A\u9593\u306E\u7D44\u307F\u3067\u8FD4\u3059\n    using path_t = std::vector<std::pair<int,\
    \ int>>;\n    std::pair<path_t, path_t> path(int u, int v) {\n        assert(prepared);\n\
    \        path_t path_u, path_v;\n        while (u != v) {\n            if (head[u]\
    \ == head[v]) {\n                if (T.depth[u] < T.depth[v])\n              \
    \      path_v.emplace_back(id[v], id[u]);\n                else\n            \
    \        path_u.emplace_back(id[u], id[v]);\n                break;\n        \
    \    }\n            if (T.depth[head[u]] < T.depth[head[v]]) {\n             \
    \   path_v.emplace_back(id[v], id[head[v]]);\n                v = T.parent(head[v]);\n\
    \            } else {\n                path_u.emplace_back(id[u], id[head[u]]);\n\
    \                u = T.parent(head[u]);\n            }\n        }\n        if\
    \ (u == v)\n            path_u.emplace_back(id[u], id[u]);\n        return {path_u,\
    \ path_v};\n    }\n\n    // [l,r) \u304C v \u306E\u90E8\u5206\u6728\n    std::pair<int,\
    \ int> subtree(int v) {\n        assert(prepared);\n        return {id[v], id2[v]};\n\
    \    }\n};\n"
  code: "#pragma once\ntemplate <typename TREE> struct HLD {\n    int n;\n    TREE\
    \ T;\n    std::vector<int> sz, head, id, id2;\n    bool prepared;\n    HLD(TREE\
    \ T_)\n        : T(T_), n(T_.n), sz(n), head(n), id(n), id2(n), prepared(false)\
    \ {}\n    HLD() = default;\n\n  private:\n    void dfs_sz(int v) {\n        sz[v]\
    \ = 1;\n        for (auto &e : T.son(v)) {\n            dfs_sz(e.to);\n      \
    \      sz[v] += sz[e.to];\n            if (sz[e.to] > sz[T.son(v)[0].to])\n  \
    \              std::swap(e, T.son(v)[0]);\n        }\n    }\n    void dfs_hld(int\
    \ v, int &k) {\n        id[v] = k++;\n        for (int i = 0; i < T.son(v).size();\
    \ i++) {\n            int to = T.son(v)[i];\n            head[to] = (i ? to :\
    \ head[v]);\n            dfs_hld(to, k);\n        }\n        id2[v] = k;\n   \
    \ }\n\n  public:\n    std::vector<int> build(int r = 0) {\n        assert(!prepared);\n\
    \        prepared = true;\n        if (~T.root)\n            assert(T.root ==\
    \ r);\n        else\n            T.build(r);\n        head[r] = r;\n        dfs_sz(r);\n\
    \        int k = 0;\n        dfs_hld(r, k);\n        return id;\n    }\n\n   \
    \ int lca(int u, int v) {\n        assert(prepared);\n        while (head[u] !=\
    \ head[v])\n            if (T.depth[head[u]] > T.depth[head[v]])\n           \
    \     u = T.parent(head[u]);\n            else\n                v = T.parent(head[v]);\n\
    \        return (T.depth[u] < T.depth[v] ? u : v);\n    }\n    int distance(int\
    \ u, int v) {\n        int w = lca(u, v);\n        return T.depth[u] + T.depth[v]\
    \ - T.depth[w] * 2;\n    }\n\n    // l=lca(u,v) \u3068\u3057\u305F\u6642\u3001\
    [u,l] \u30D1\u30B9\u3068 [v,l] \u30D1\u30B9 \u3092\u9589\u533A\u9593\u306E\u7D44\
    \u307F\u3067\u8FD4\u3059\n    using path_t = std::vector<std::pair<int, int>>;\n\
    \    std::pair<path_t, path_t> path(int u, int v) {\n        assert(prepared);\n\
    \        path_t path_u, path_v;\n        while (u != v) {\n            if (head[u]\
    \ == head[v]) {\n                if (T.depth[u] < T.depth[v])\n              \
    \      path_v.emplace_back(id[v], id[u]);\n                else\n            \
    \        path_u.emplace_back(id[u], id[v]);\n                break;\n        \
    \    }\n            if (T.depth[head[u]] < T.depth[head[v]]) {\n             \
    \   path_v.emplace_back(id[v], id[head[v]]);\n                v = T.parent(head[v]);\n\
    \            } else {\n                path_u.emplace_back(id[u], id[head[u]]);\n\
    \                u = T.parent(head[u]);\n            }\n        }\n        if\
    \ (u == v)\n            path_u.emplace_back(id[u], id[u]);\n        return {path_u,\
    \ path_v};\n    }\n\n    // [l,r) \u304C v \u306E\u90E8\u5206\u6728\n    std::pair<int,\
    \ int> subtree(int v) {\n        assert(prepared);\n        return {id[v], id2[v]};\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/HLD.cpp
  requiredBy:
  - library/tree/TreeMonoid.cpp
  - library/tree/TreeLazy.cpp
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/LowestCommonAncestor.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/yukicoder/650.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/tree/HLD.cpp
layout: document
redirect_from:
- /library/library/tree/HLD.cpp
- /library/library/tree/HLD.cpp.html
title: library/tree/HLD.cpp
---