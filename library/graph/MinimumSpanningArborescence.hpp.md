---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/datastructure/unionfind/UnionFind.hpp
    title: library/datastructure/unionfind/UnionFind.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2647.test.cpp
    title: test/AOJ/2647.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_2_B.test.cpp
    title: test/AOJ/GRL_2_B.test.cpp
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
    \      return res;\n    }\n};\n#line 3 \"library/graph/MinimumSpanningArborescence.hpp\"\
    \ntemplate <typename WG, typename W = typename WG::weight_type>\nstd::optional<std::pair<W,\
    \ std::vector<int>>>\nminimum_spanning_arborescence(WG g, int r = 0) {\n    int\
    \ n = g.n;\n    W res = 0;\n    std::vector<W> new_add(n, 0);\n    std::vector<int>\
    \ tree(n), pre(n), state(n, 0);\n    UnionFind uf(n);\n    state[r] = 2;\n\n \
    \   auto compare = [&](const int &a, const int &b) {\n        return g.edges[a].weight\
    \ > g.edges[b].weight;\n    };\n    using PQ = std::priority_queue<int, std::vector<int>,\
    \ decltype(compare)>;\n    std::vector<std::pair<PQ, W>> pq_add(n, {PQ{compare},\
    \ 0});\n    for (int i = 0; i < g.edges.size(); i++)\n        pq_add[g.edges[i].to].first.push(i);\n\
    \    std::vector<int> pq_id(n);\n    std::iota(pq_id.begin(), pq_id.end(), 0);\n\
    \n    auto merge = [&](int u, int v) {\n        u = uf.leader(u);\n        v =\
    \ uf.leader(v);\n        if (u == v)\n            return;\n        uf.merge(u,\
    \ v);\n        auto &[pq1, add1] = pq_add[pq_id[u]];\n        auto &[pq2, add2]\
    \ = pq_add[pq_id[v]];\n        if (pq1.size() > pq2.size()) {\n            while\
    \ (pq2.size()) {\n                int edge_id = pq2.top();\n                pq2.pop();\n\
    \                g.edges[edge_id].weight -= add2 - add1;\n                pq1.push(edge_id);\n\
    \            }\n            pq_id[uf.leader(v)] = pq_id[u];\n        } else {\n\
    \            while (pq1.size()) {\n                int edge_id = pq1.top();\n\
    \                pq1.pop();\n                g.edges[edge_id].weight -= add1 -\
    \ add2;\n                pq2.push(edge_id);\n            }\n            pq_id[uf.leader(v)]\
    \ = pq_id[v];\n        }\n    };\n\n    for (int i = 0; i < n; i++) {\n      \
    \  int now = uf.leader(i);\n        if (state[now])\n            continue;\n \
    \       std::vector<int> processing;\n        while (state[now] != 2) {\n    \
    \        processing.push_back(now);\n            state[now] = 1;\n           \
    \ auto &[pq, add] = pq_add[pq_id[now]];\n            if (!pq.size())\n       \
    \         return std::nullopt;\n            int edge_id = pq.top();\n        \
    \    pq.pop();\n            auto &e = g.edges[edge_id];\n            res += e.weight\
    \ - add;\n            tree[e.to] = edge_id;\n            pre[now] = uf.leader(e.from);\n\
    \            new_add[now] = e.weight;\n            if (state[pre[now]] == 1) {\n\
    \                int v = now;\n                do {\n                    pq_add[pq_id[v]].second\
    \ = new_add[v];\n                    merge(v, now);\n                    v = uf.leader(pre[v]);\n\
    \                } while (!uf.same(v, now));\n                now = uf.leader(now);\n\
    \            } else\n                now = uf.leader(pre[now]);\n        }\n \
    \       for (int v : processing)\n            state[v] = 2;\n    }\n    tree.erase(tree.begin()\
    \ + r);\n    return std::make_pair(res, tree);\n}\n"
  code: "#pragma once\n#include \"library/datastructure/unionfind/UnionFind.hpp\"\n\
    template <typename WG, typename W = typename WG::weight_type>\nstd::optional<std::pair<W,\
    \ std::vector<int>>>\nminimum_spanning_arborescence(WG g, int r = 0) {\n    int\
    \ n = g.n;\n    W res = 0;\n    std::vector<W> new_add(n, 0);\n    std::vector<int>\
    \ tree(n), pre(n), state(n, 0);\n    UnionFind uf(n);\n    state[r] = 2;\n\n \
    \   auto compare = [&](const int &a, const int &b) {\n        return g.edges[a].weight\
    \ > g.edges[b].weight;\n    };\n    using PQ = std::priority_queue<int, std::vector<int>,\
    \ decltype(compare)>;\n    std::vector<std::pair<PQ, W>> pq_add(n, {PQ{compare},\
    \ 0});\n    for (int i = 0; i < g.edges.size(); i++)\n        pq_add[g.edges[i].to].first.push(i);\n\
    \    std::vector<int> pq_id(n);\n    std::iota(pq_id.begin(), pq_id.end(), 0);\n\
    \n    auto merge = [&](int u, int v) {\n        u = uf.leader(u);\n        v =\
    \ uf.leader(v);\n        if (u == v)\n            return;\n        uf.merge(u,\
    \ v);\n        auto &[pq1, add1] = pq_add[pq_id[u]];\n        auto &[pq2, add2]\
    \ = pq_add[pq_id[v]];\n        if (pq1.size() > pq2.size()) {\n            while\
    \ (pq2.size()) {\n                int edge_id = pq2.top();\n                pq2.pop();\n\
    \                g.edges[edge_id].weight -= add2 - add1;\n                pq1.push(edge_id);\n\
    \            }\n            pq_id[uf.leader(v)] = pq_id[u];\n        } else {\n\
    \            while (pq1.size()) {\n                int edge_id = pq1.top();\n\
    \                pq1.pop();\n                g.edges[edge_id].weight -= add1 -\
    \ add2;\n                pq2.push(edge_id);\n            }\n            pq_id[uf.leader(v)]\
    \ = pq_id[v];\n        }\n    };\n\n    for (int i = 0; i < n; i++) {\n      \
    \  int now = uf.leader(i);\n        if (state[now])\n            continue;\n \
    \       std::vector<int> processing;\n        while (state[now] != 2) {\n    \
    \        processing.push_back(now);\n            state[now] = 1;\n           \
    \ auto &[pq, add] = pq_add[pq_id[now]];\n            if (!pq.size())\n       \
    \         return std::nullopt;\n            int edge_id = pq.top();\n        \
    \    pq.pop();\n            auto &e = g.edges[edge_id];\n            res += e.weight\
    \ - add;\n            tree[e.to] = edge_id;\n            pre[now] = uf.leader(e.from);\n\
    \            new_add[now] = e.weight;\n            if (state[pre[now]] == 1) {\n\
    \                int v = now;\n                do {\n                    pq_add[pq_id[v]].second\
    \ = new_add[v];\n                    merge(v, now);\n                    v = uf.leader(pre[v]);\n\
    \                } while (!uf.same(v, now));\n                now = uf.leader(now);\n\
    \            } else\n                now = uf.leader(pre[now]);\n        }\n \
    \       for (int v : processing)\n            state[v] = 2;\n    }\n    tree.erase(tree.begin()\
    \ + r);\n    return std::make_pair(res, tree);\n}\n"
  dependsOn:
  - library/datastructure/unionfind/UnionFind.hpp
  isVerificationFile: false
  path: library/graph/MinimumSpanningArborescence.hpp
  requiredBy: []
  timestamp: '2024-07-08 10:24:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/Graph/DirectedMST.test.cpp
  - test/AOJ/2647.test.cpp
  - test/AOJ/GRL_2_B.test.cpp
documentation_of: library/graph/MinimumSpanningArborescence.hpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningArborescence.hpp
- /library/library/graph/MinimumSpanningArborescence.hpp.html
title: library/graph/MinimumSpanningArborescence.hpp
---
