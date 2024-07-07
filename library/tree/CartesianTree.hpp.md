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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/tree/WeightedTree.cpp:\
    \ line -1: no such header\n"
  code: "#include <stack>\n#include <utility>\n#include <vector>\n\n#include \"library/tree/WeightedTree.cpp\"\
    \n\n// \u6700\u5C0F\u5024\u3067\u5206\u5272 \u6839\u4ED8\u304D\u6728\u3092\u6E21\
    \u3059 \u6839\u304C\u6700\u5C0F\u5024\u306Eindex\n// \u7B49\u3057\u3044\u5024\u306B\
    \u95A2\u3057\u3066\u306F index \u306E\u5927\u5C0F\u3092\u6BD4\u8F03\u3059\u308B\
    \n// \u8FBA\u306E\u91CD\u307F\u306F\u5B50\u306E\u90E8\u5206\u6728\u304C\u62C5\u5F53\
    \u3059\u308B\u534A\u958B\u533A\u9593\ntemplate <typename T>\nWeightedTree<std::pair<int,\
    \ int>> cartesian_tree(const std::vector<T> &v) {\n    int n = v.size();\n   \
    \ std::vector<std::pair<int, int>> lr(n, {0, n});\n    std::stack<int> sta;\n\
    \    for (int i = 0; i < n; i++) {\n        while (sta.size() and v[i] < v[sta.top()])\
    \ {\n            lr[sta.top()].second = i;\n            sta.pop();\n        }\n\
    \        if (sta.size())\n            lr[i].first = sta.top() + 1;\n        sta.push(i);\n\
    \    }\n    WeightedTree<std::pair<int, int>> t(n);\n    int root;\n    for (int\
    \ i = 0; i < n; i++) {\n        const auto &[l, r] = lr[i];\n        if (l ==\
    \ 0 and r == n)\n            root = i;\n        else {\n            if (l == 0)\n\
    \                t.add_edge(r, i, lr[i]);\n            if (r == n)\n         \
    \       t.add_edge(l - 1, i, lr[i]);\n            if (l != 0 and r != n)\n   \
    \             if (v[l - 1] > v[r])\n                    t.add_edge(l - 1, i, lr[i]);\n\
    \                else\n                    t.add_edge(r, i, lr[i]);\n        }\n\
    \    }\n    t.build(root);\n    return t;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/CartesianTree.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/CartesianTree.hpp
layout: document
redirect_from:
- /library/library/tree/CartesianTree.hpp
- /library/library/tree/CartesianTree.hpp.html
title: library/tree/CartesianTree.hpp
---
