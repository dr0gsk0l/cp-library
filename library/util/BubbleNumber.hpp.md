---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/util/InversionNumber.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/util/InversionNumber.cpp\"\ntemplate <typename\
    \ T>\nlong long bubble_number(const std::vector<T> &v, const std::vector<T> &w)\
    \ {\n    int n = v.size();\n    assert(w.size() == n);\n    std::map<T, std::queue<int>>\
    \ mp;\n    for (int i = 0; i < n; i++)\n        mp[w[i]].push(i);\n    std::vector<int>\
    \ idx(n);\n    REP (i, n) {\n        if (!mp[v[i]].size())\n            return\
    \ -1;\n        idx[i] = mp[v[i]].front();\n        mp[v[i]].pop();\n    }\n  \
    \  return inversion_number(idx);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/BubbleNumber.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/BubbleNumber.hpp
layout: document
redirect_from:
- /library/library/util/BubbleNumber.hpp
- /library/library/util/BubbleNumber.hpp.html
title: library/util/BubbleNumber.hpp
---
