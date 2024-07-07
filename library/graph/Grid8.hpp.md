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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/graph/WeightedGraph.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/graph/WeightedGraph.cpp\"\n#define REP_(i,\
    \ n) for (int i = 0; i < (n); i++)\ntemplate <typename T> class Grid8 {\n    const\
    \ int h, w;\n    std::optional<T> ban;\n    // D,DR,R,RU,U,UL,L,LD\n    static\
    \ constexpr std::pair<int, int> d8[8] = {\n        {1, 0}, {1, 1}, {0, 1}, {-1,\
    \ 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};\n    template <typename vecvecT> void\
    \ build(const vecvecT &grid) {\n        REP_(y, h) REP_(x, w) {\n            int\
    \ p = id(y, x);\n            v[p] = grid[y][x];\n            if (ban and v[p]\
    \ == ban.value())\n                continue;\n            REP_(d, 8) {\n     \
    \           int y2 = y + d8[d].first, x2 = x + d8[d].second;\n               \
    \ if (in(y2, x2) and (!ban or ban.value() != grid[y2][x2]))\n                \
    \    G.add_arc(p, id(y2, x2), d);\n            }\n        }\n        G.build();\n\
    \    }\n\n  public:\n    std::vector<T> v;\n    WeightedGraph<int> G;\n    bool\
    \ in(int y, int x) const {\n        return 0 <= y and y < h and 0 <= x and x <\
    \ w;\n    }\n    int id(int y, int x) const {\n        assert(in(y, x));\n   \
    \     return y * w + x;\n    }\n    std::pair<int, int> r2(int a) const {\n  \
    \      assert(0 <= a and a < h * w);\n        return {a / w, a % w};\n    }\n\n\
    \    Grid8(const std::vector<std::vector<T>> &grid,\n          const std::optional<T>\
    \ &ban = std::nullopt)\n        : h(grid.size()), w(grid[0].size()), ban(ban),\
    \ v(h * w), G(h * w) {\n        build(grid);\n    }\n    Grid8(const std::vector<std::string>\
    \ &s,\n          const std::optional<T> &ban = std::nullopt)\n        : h(s.size()),\
    \ w(s[0].size()), ban(ban), v(h * w), G(h * w) {\n        static_assert(std::is_same<T,\
    \ char>::value, \"value_type==char\");\n        build(s);\n    }\n\n    int find(const\
    \ T &c) const {\n        REP_(i, h * w) if (v[i] == c) return i;\n        return\
    \ -1;\n    }\n};\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/graph/Grid8.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/graph/Grid8.hpp
layout: document
redirect_from:
- /library/library/graph/Grid8.hpp
- /library/library/graph/Grid8.hpp.html
title: library/graph/Grid8.hpp
---
