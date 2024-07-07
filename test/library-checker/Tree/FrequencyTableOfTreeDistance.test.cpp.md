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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/tree/CentroidDecomposition.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/frequency_table_of_tree_distance\"\
    \n#include <bits/stdc++.h>\n\n#include <atcoder/convolution>\nusing namespace\
    \ atcoder;\n\n#include \"library/tree/CentroidDecomposition.cpp\"\n#include \"\
    library/tree/Tree.cpp\"\n\nusing ll = long long;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    Tree T(n);\n\
    \    T.scan(0);\n\n    CentroidDecomposition CD(T);\n\n    std::vector<ll> ans(n,\
    \ 0), D{0};\n\n    auto next_val = [&](int d, auto &e) { return d + 1; };\n  \
    \  auto action = [&](int d, bool add) {\n        if (D.size() <= d)\n        \
    \    D.push_back(0);\n        D[d]++;\n    };\n    auto finish = [&](bool add)\
    \ {\n        auto D2 = convolution_ll(D, D);\n        for (int i = 0; i < D2.size()\
    \ and i < n; i++)\n            if (add)\n                ans[i] += D2[i];\n  \
    \          else\n                ans[i] -= D2[i];\n        D = std::vector<ll>{0};\n\
    \    };\n\n    CD.all_calc(0, next_val, action, finish);\n\n    for (int i = 1;\
    \ i < n; i++)\n        std::cout << ans[i] / 2 << \"\\n \"[i + 1 < n];\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
- /verify/test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp.html
title: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
---
