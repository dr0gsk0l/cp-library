---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bitwise/Ranked.cpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include <atcoder/modint>\n\
    #include <atcoder/convolution>\nusing namespace atcoder;\nusing mint = modint998244353;\n\
    namespace atcoder\n{\n  ostream &operator<<(ostream &os, mint a)\n  {\n    os\
    \ << a.val();\n    return os;\n  }\n  istream &operator>>(istream &is, mint &a)\n\
    \  {\n    long long b;\n    is >> b;\n    a = b;\n    return is;\n  }\n}\n\n#include\
    \ \"library/setpowerseries/Compose.cpp\"\nusing SPS = SetPowerSeries<mint>;\n\n\
    int main()\n{\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n;\n\
    \  std::cin >> n;\n\n  SPS b(1 << n);\n  for (auto &x : b)\n    std::cin >> x;\n\
    \n  SPS c = exp(b);\n  for (auto &x : c)\n    std::cout << x << \" \";\n  std::cout\
    \ << endl;\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
- /verify/test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp.html
title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
---
