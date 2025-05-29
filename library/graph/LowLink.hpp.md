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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/Graph.hpp:\
    \ line -1: no such header\n"
  code: "#include <numeric>\n#include <ranges>\n#include <utility>\n#include <vector>\n\
    \n#include \"graph/Graph.hpp\"\n\nclass LowLink {\n    Graph g;\n    std::vector<int>\
    \ ord, low_link;\n    int cnt;\n\n    static inline void chmin(int &a, int b)\
    \ { a = std::min(a, b); }\n\n    void dfs(int p, int v) {\n        ord[v] = cnt++;\n\
    \        for (int to : g[v])\n            if (~ord[to]) {\n                if\
    \ (to != p)\n                    chmin(low_link[v], to);\n            } else {\n\
    \                dfs(v, to);\n                chmin(low_link[v], low_link[to]);\n\
    \            }\n    }\n\n  public:\n    LowLink(const Graph &g) : g(g), ord(g.n,\
    \ -1), low_link(g.n), cnt(0) {\n        std::iota(low_link.begin(), low_link.end(),\
    \ 0);\n        assert(g.is_prepared());\n        for (int v = 0; v < g.n; v++)\n\
    \            if (ord[v] < 0)\n                dfs(-1, v);\n    }\n\n    int get_ord(int\
    \ v) const { return ord[v]; }\n    int get_low_link(int v) const { return low_link[v];\
    \ }\n    bool is_bridge(int u, int v) const {\n        if (ord[u] > ord[v])\n\
    \            std::swap(u, v);\n        return ord[u] < low_link[v];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/LowLink.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/LowLink.hpp
layout: document
redirect_from:
- /library/library/graph/LowLink.hpp
- /library/library/graph/LowLink.hpp.html
title: library/graph/LowLink.hpp
---
