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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/datastructure/unionfind/UnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/datastructure/unionfind/UnionFind.cpp\"\n\
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
  dependsOn: []
  isVerificationFile: false
  path: library/graph/MinimumSpanningArborescence.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/MinimumSpanningArborescence.hpp
layout: document
redirect_from:
- /library/library/graph/MinimumSpanningArborescence.hpp
- /library/library/graph/MinimumSpanningArborescence.hpp.html
title: library/graph/MinimumSpanningArborescence.hpp
---
