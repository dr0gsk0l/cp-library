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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/formalpowerseries/Base.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/formalpowerseries/Base.cpp\"\n#include \"\
    library/formalpowerseries/DivMod.cpp\"\ntemplate <typename FPS, typename T = typename\
    \ FPS::value_type>\nstd::vector<T> multipoint_evaluation(const FPS &f, std::vector<T>\
    \ v) {\n    int m = v.size();\n    int sz;\n    for (sz = 1; sz < m; sz *= 2)\
    \ {\n    }\n    std::vector<FPS> t(sz * 2);\n    for (int i = 0; i < sz; i++)\n\
    \        t[sz + i] = {(i < m ? -v[i] : 0), 1};\n    for (int i = sz - 1; i > 0;\
    \ i--)\n        t[i] = t[2 * i] * t[2 * i + 1];\n\n    t[0] = f;\n    for (int\
    \ i = 1; i < sz + m; i++)\n        t[i] = div_mod(t[i >> 1], t[i]).second;\n\n\
    \    for (int i = 0; i < m; i++)\n        v[i] = t[sz + i][0];\n    return v;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/MultipointEvaluation.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/MultipointEvaluation.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/MultipointEvaluation.hpp
- /library/library/formalpowerseries/MultipointEvaluation.hpp.html
title: library/formalpowerseries/MultipointEvaluation.hpp
---
