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
  code: "#pragma once\n#include \"library/formalpowerseries/Base.cpp\"\ntemplate <typename\
    \ FPS> std::optional<FPS> sqrt(FPS f) {\n    f.shrink();\n    if (f.size() ==\
    \ 0)\n        return FPS(0);\n    int d;\n    for (d = 0; f[d] == 0; d++) {\n\
    \    }\n    if (d & 1)\n        return std::nullopt;\n    f >>= d;\n    FPS res\
    \ { at }\n}\n\nassert(size() and at(0) != 0);\nFPS res(1, at(0).inv());\nfor (int\
    \ n = 0; (1 << n) < SZ; n++) {\n    // mod[1<<n] \u2192 mod[1<<(n+1)]\n    res\
    \ *= (2 - (res * pre(1 << (n + 1))).pre(1 << (n + 1)));\n    res.strict(1 << (n\
    \ + 1));\n}\nreturn res.pre(SZ);"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/Sqrt.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/Sqrt.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/Sqrt.hpp
- /library/library/formalpowerseries/Sqrt.hpp.html
title: library/formalpowerseries/Sqrt.hpp
---
