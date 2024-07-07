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
    \ FPS> std::pair<FPS, FPS> div_mod(FPS f, FPS g) {\n    f.shrink();\n    g.shrink();\n\
    \    assert(g.size());\n    if (f.size() < g.size())\n        return {FPS(0),\
    \ f};\n    std::ranges::reverse(f);\n    std::ranges::reverse(g);\n    int d =\
    \ f.size() - g.size() + 1;\n    FPS q = (f.pre(d) * g.inv(d)).pre(d);\n    if\
    \ (q.size() < d)\n        q.resize(d, 0);\n    std::ranges::reverse(q);\n    std::ranges::reverse(f);\n\
    \    std::ranges::reverse(g);\n    return {q, f - q * g};\n}\n#undef REVERSE_"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/DivMod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/DivMod.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/DivMod.hpp
- /library/library/formalpowerseries/DivMod.hpp.html
title: library/formalpowerseries/DivMod.hpp
---
