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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/formalpowerseries/Base.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/division_of_polynomials\"\
    \n#include <bits/stdc++.h>\n\n#define REP(i, n) for (int i = 0; i < (n); i++)\n\
    \n#include <atcoder/convolution>\n#include <atcoder/modint>\nusing namespace atcoder;\n\
    using mint = modint998244353;\nstd::ostream &operator<<(std::ostream &os, mint\
    \ a) {\n    os << a.val();\n    return os;\n}\nstd::istream &operator>>(std::istream\
    \ &is, mint &a) {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n\
    }\n\n#include \"library/formalpowerseries/Base.cpp\"\nusing FPS = FormalPowerSeries<mint,\
    \ 500000>;\n#include \"library/formalpowerseries/DivMod.cpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n    int\
    \ n, m;\n    std::cin >> n >> m;\n    FPS f(n), g(m);\n    REP (i, n)\n      \
    \  std::cin >> f[i];\n    REP (j, m)\n        std::cin >> g[j];\n    auto [q,\
    \ r] = div_mod(f, g);\n    q.shrink();\n    r.shrink();\n    std::cout << q.size()\
    \ << \" \" << r.size() << std::endl;\n    REP (i, q.size())\n        std::cout\
    \ << q[i] << \" \";\n    std::cout << \"\\n\";\n    REP (i, r.size())\n      \
    \  std::cout << r[i] << \" \";\n    std::cout << \"\\n\";\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
- /verify/test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp.html
title: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
---
