---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: bitwise/Ranked.cpp:\
    \ line -1: no such header\n"
  code: "// https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90\n\
    #include <vector>\n#include \"library/setpowerseries/Base.cpp\"\n\ntemplate <typename\
    \ SPS, typename T = typename SPS::value_type>\nSPS SPS_exp_comp(const std::vector<T>\
    \ &f, const SPS &a)\n{\n  int N = a.size();\n  int n = bitwise::log2(N);\n\n \
    \ std::vector<SPS> ret(n + 1);\n  for (int d = n; d >= 0; d--)\n  {\n    ret[d].resize(1\
    \ << (n - d));\n    ret[d][0] = f[d];\n    for (int m = 0; m < n - d; m++)\n \
    \   {\n      // ret[d] \u306E [2^m, 2^{m+1}] \u3092\u6C42\u3081\u308B\n      SPS\
    \ pre(ret[d + 1].begin(), ret[d + 1].begin() + (1 << m));\n      SPS a2(a.begin()\
    \ + (1 << m), a.begin() + (1 << (m + 1)));\n      pre *= a2;\n      std::copy(pre.begin(),\
    \ pre.end(), ret[d].begin() + (1 << m));\n    }\n  }\n  return ret[0];\n}\n\n\
    // sum_k f_k a^k\ntemplate <typename SPS, typename T = typename SPS::value_type>\n\
    SPS SPS_composition(const std::vector<T> &f, SPS a)\n{\n  int N = a.size();\n\
    \  int n = bitwise::log2(N);\n\n  std::vector<T> c_pow(f.size() + 1, 1);\n  for\
    \ (int i = 1; i <= f.size(); i++)\n    c_pow[i] = c_pow[i - 1] * a[0];\n\n  std::vector<T>\
    \ f2(n + 1, 0);\n  for (int i = 0; i < f.size(); i++)\n  {\n    T now = f[i];\n\
    \    for (int k = 0; k <= std::min(i, n); k++)\n    {\n      f2[k] += now * c_pow[i\
    \ - k];\n      now *= i - k;\n    }\n  }\n  a[0] = 0;\n  return SPS_exp_comp(f2,\
    \ a);\n}\n\ntemplate <typename SPS, typename T = typename SPS::value_type>\nSPS\
    \ exp(SPS a)\n{\n  int N = a.size();\n  int n = bitwise::log2(N);\n\n  SPS ret(N,\
    \ 1);\n  for (int d = n - 1; d >= 0; d--)\n  {\n    const int M = 1 << (n - d\
    \ - 1);\n    SPS pre(ret.begin(), ret.begin() + M);\n    SPS a2(a.begin() + M,\
    \ a.begin() + 2 * M);\n    pre *= a2;\n    std::copy(pre.begin(), pre.end(), ret.begin()\
    \ + M);\n  }\n  return ret;\n}\n\ntemplate <typename SPS, typename T = typename\
    \ SPS::value_type>\nSPS log(SPS a)\n{\n  int n = bitwise::log2(a.size());\n  assert((1\
    \ << n) == a.size() and a[0] == 1);\n  std::vector<T> lg(n + 1, 0);\n  for (int\
    \ k = 1; k <= n; k++)\n    lg[k] = T(-1) / k;\n  return SPS_composition(lg, SPS(1,\
    \ 1) - a);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: library/setpowerseries/Compose.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/setpowerseries/Compose.cpp
layout: document
redirect_from:
- /library/library/setpowerseries/Compose.cpp
- /library/library/setpowerseries/Compose.cpp.html
title: library/setpowerseries/Compose.cpp
---
