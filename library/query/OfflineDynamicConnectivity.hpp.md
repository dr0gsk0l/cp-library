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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/datastructure/unionfind/UndoUnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#include \"library/datastructure/unionfind/UndoUnionFind.cpp\"\n\nclass OfflineDynamicConnectivity\
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
  dependsOn: []
  isVerificationFile: false
  path: library/query/OfflineDynamicConnectivity.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/query/OfflineDynamicConnectivity.hpp
layout: document
redirect_from:
- /library/library/query/OfflineDynamicConnectivity.hpp
- /library/library/query/OfflineDynamicConnectivity.hpp.html
title: library/query/OfflineDynamicConnectivity.hpp
---
