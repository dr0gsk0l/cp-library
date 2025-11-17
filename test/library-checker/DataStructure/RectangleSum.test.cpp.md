---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.hpp
    title: library/algebra/group/Add.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Concepts.hpp
    title: library/algebra/group/Concepts.hpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.hpp
    title: library/algebra/monoid/Concepts.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FenwickTree.hpp
    title: library/datastructure/FenwickTree.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FullyIndexableDictionary.hpp
    title: library/datastructure/FullyIndexableDictionary.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/WaveletMatrix.hpp
    title: library/datastructure/WaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: library/r2/Projection.hpp
    title: library/r2/Projection.hpp
  - icon: ':question:'
    path: library/r2/XY.hpp
    title: library/r2/XY.hpp
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.hpp
    title: library/util/Compress.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/rectangle_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.14.0/x64/lib/python3.14/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.hpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/rectangle_sum\"\n#include\
    \ <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\n#include\
    \ \"library/algebra/group/Add.hpp\"\n#include \"library/datastructure/GroupWaveletMatrix.hpp\"\
    \n#include \"library/r2/Projection.hpp\"\n#include \"library/r2/XY.hpp\"\n\nusing\
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
  dependsOn:
  - library/algebra/group/Add.hpp
  - library/datastructure/GroupWaveletMatrix.hpp
  - library/datastructure/FenwickTree.hpp
  - library/algebra/group/Concepts.hpp
  - library/algebra/monoid/Concepts.hpp
  - library/datastructure/WaveletMatrix.hpp
  - library/datastructure/FullyIndexableDictionary.hpp
  - library/util/Compress.hpp
  - library/r2/Projection.hpp
  - library/r2/XY.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/RectangleSum.test.cpp
  requiredBy: []
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/RectangleSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/RectangleSum.test.cpp
- /verify/test/library-checker/DataStructure/RectangleSum.test.cpp.html
title: test/library-checker/DataStructure/RectangleSum.test.cpp
---
