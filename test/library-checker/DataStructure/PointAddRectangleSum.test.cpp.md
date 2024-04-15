---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Concepts.cpp
    title: library/algebra/group/Concepts.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FullyIndexableDictionary.cpp
    title: library/datastructure/FullyIndexableDictionary.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/WaveletMatrix.cpp
    title: library/datastructure/WaveletMatrix.cpp
  - icon: ':heavy_check_mark:'
    path: library/r2/Projection.cpp
    title: library/r2/Projection.cpp
  - icon: ':question:'
    path: library/r2/XY.cpp
    title: library/r2/XY.cpp
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.cpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include \"library/algebra/group/Add.cpp\"\n#include \"library/datastructure/GroupWaveletMatrix.cpp\"\
    \n#include \"library/r2/Projection.cpp\"\n#include \"library/r2/XY.cpp\"\n\nusing\
    \ ll = long long;\nusing r2 = XY<ll>;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n, q;\n    std::cin >> n >> q;\n    std::vector<r2>\
    \ r2s(n);\n    r2s.reserve(n + q);\n    std::vector<int> x(n), y(n), w(n), qt(q),\
    \ l(q), d(q), r(q), u(q);\n    REP (i, n) {\n        std::cin >> x[i] >> y[i]\
    \ >> w[i];\n        r2s[i] = r2(x[i], y[i]);\n    }\n    REP (j, q) {\n      \
    \  std::cin >> qt[j];\n        if (qt[j])\n            std::cin >> l[j] >> d[j]\
    \ >> r[j] >> u[j];\n        else {\n            std::cin >> l[j] >> d[j] >> r[j];\n\
    \            r2s.emplace_back(l[j], d[j]);\n        }\n    }\n\n    auto P = Projection(r2s);\n\
    \    std::vector<int> Y(P.size(), 0);\n    std::vector<ll> W(P.size(), 0);\n \
    \   REP (id, P.size())\n        Y[id] = P.r(id).y;\n    REP (i, n) {\n       \
    \ int id = P.id(x[i], y[i]);\n        W[id] += w[i];\n    }\n\n    GroupWaveletMatrix<int,\
    \ GroupAdd<ll>> WM(Y, W);\n\n    REP (j, q)\n        if (qt[j]) {\n          \
    \  auto [L, R] = P.interval(l[j], r[j]);\n            std::cout << WM.sum(L, R,\
    \ d[j], u[j]) << \"\\n\";\n        } else {\n            int id = P.id(l[j], d[j]);\n\
    \            WM.add(id, r[j]);\n        }\n}"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/datastructure/FenwickTree.cpp
  - library/algebra/group/Concepts.cpp
  - library/algebra/monoid/Concepts.cpp
  - library/datastructure/WaveletMatrix.cpp
  - library/datastructure/FullyIndexableDictionary.cpp
  - library/util/Compress.cpp
  - library/r2/Projection.cpp
  - library/r2/XY.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
- /verify/test/library-checker/DataStructure/PointAddRectangleSum.test.cpp.html
title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
---
