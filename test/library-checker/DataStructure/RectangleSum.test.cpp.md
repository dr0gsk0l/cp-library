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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/group/Add.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n#include\
    \ \"library/algebra/group/Add.cpp\"\n#include \"library/datastructure/GroupWaveletMatrix.cpp\"\
    \n#include \"library/r2/Projection.cpp\"\n#include \"library/r2/XY.cpp\"\n\nusing\
    \ ll = long long;\nusing r2 = XY<ll>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<r2>\
    \ r2s(n);\n    std::vector<int> x(n), y(n), w(n);\n    REP (i, n) {\n        std::cin\
    \ >> x[i] >> y[i] >> w[i];\n        r2s[i] = r2(x[i], y[i]);\n    }\n\n    auto\
    \ P = Projection(r2s);\n    std::vector<int> Y(P.size(), 0);\n    std::vector<ll>\
    \ W(P.size(), 0);\n    REP (id, P.size())\n        Y[id] = P.r(id).y;\n    REP\
    \ (i, n) {\n        int id = P.id(x[i], y[i]);\n        W[id] += w[i];\n    }\n\
    \n    GroupWaveletMatrix<int, GroupAdd<ll>> WM(Y, W);\n\n    REP (j, q) {\n  \
    \      int l, r, d, u;\n        std::cin >> l >> d >> r >> u;\n        auto [L,\
    \ R] = P.interval(l, r);\n        std::cout << WM.sum(L, R, d, u) << \"\\n\";\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/DataStructure/RectangleSum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/RectangleSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/RectangleSum.test.cpp
- /verify/test/library-checker/DataStructure/RectangleSum.test.cpp.html
title: test/library-checker/DataStructure/RectangleSum.test.cpp
---
