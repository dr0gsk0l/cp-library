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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/linearalgebra/Matrix.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include\
    \ <bits/stdc++.h>\n\n#include \"library/linearalgebra/Matrix.cpp\"\n#include \"\
    library/mod/Modint.cpp\"\n\nusing mint = Mint<long long, 998244353>;\nusing M\
    \ = Matrix<mint>;\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    M A(n, n);\n    std::cin >> A;\n    auto\
    \ B = A.inv();\n    if (B.has_value())\n        REP (i, n)\n            REP (j,\
    \ n)\n                std::cout << B.value()[i][j] << \"\\n \"[j + 1 < n];\n \
    \   else\n        std::cout << -1 << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Matrix/Inverse.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Matrix/Inverse.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Matrix/Inverse.test.cpp
- /verify/test/library-checker/Matrix/Inverse.test.cpp.html
title: test/library-checker/Matrix/Inverse.test.cpp
---
