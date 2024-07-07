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
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_C\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/tree/CartesianTree.cpp\"\n\n\
    using ll = long long;\nvoid chmax(ll &a, ll b) { a = std::max(a, b); }\n\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n    std::vector<ll> v(n);\n    for (int i =\
    \ 0; i < n; i++)\n        std::cin >> v[i];\n    auto T = cartesian_tree(v);\n\
    \n    ll ans = 0;\n    chmax(ans, v[T.root] * n);\n    for (int i = 0; i < n;\
    \ i++)\n        for (const auto &e : T.son(i)) {\n            const auto &[L,\
    \ R] = e.weight;\n            chmax(ans, v[e.to] * (R - L));\n        }\n    std::cout\
    \ << ans << std::endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/AOJ/DPL_3_C.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/AOJ/DPL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/DPL_3_C.test.cpp
- /verify/test/AOJ/DPL_3_C.test.cpp.html
title: test/AOJ/DPL_3_C.test.cpp
---
