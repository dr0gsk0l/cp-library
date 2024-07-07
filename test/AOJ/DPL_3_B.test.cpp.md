---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/tree/CartesianTree.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/tree/CartesianTree.cpp\"\n\n\
    void chmax(int &a, int b) { a = std::max(a, b); }\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int h, w;\n    std::cin >> h >> w;\n\n    int\
    \ ans = 0;\n    std::vector<int> v(w, 0);\n    while (h--) {\n        for (int\
    \ &p : v) {\n            int a;\n            std::cin >> a;\n            if (a)\n\
    \                p = 0;\n            else\n                p++;\n        }\n \
    \       auto T = cartesian_tree(v);\n        chmax(ans, v[T.root] * w);\n    \
    \    for (int i = 0; i < w; i++)\n            for (const auto &e : T.son(i)) {\n\
    \                const auto &[L, R] = e.weight;\n                chmax(ans, v[e.to]\
    \ * (R - L));\n            }\n    }\n    std::cout << ans << std::endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/DPL_3_B.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DPL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_3_B.test.cpp
- /verify/test/AOJ/DPL_3_B.test.cpp.html
title: test/AOJ/DPL_3_B.test.cpp
---
