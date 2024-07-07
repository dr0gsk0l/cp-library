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
    \ FPS> class RationalSum {\n    std::queue<std::pair<FPS, FPS>> que;\n\n  public:\n\
    \    void add(const FPS &f, const FPS &g) { que.emplace(f, g); }\n    FPS sum()\
    \ {\n        if (!que.size())\n            return FPS(0);\n        while (que.size()\
    \ > 1) {\n            auto [a1, b1] = que.front();\n            que.pop();\n \
    \           auto [a2, b2] = que.front();\n            que.pop();\n           \
    \ que.emplace(a1 * b2 + a2 * b1, b1 * b2);\n        }\n        auto [a, b] = que.front();\n\
    \        que.pop();\n        return a / b;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/RationalSum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/RationalSum.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/RationalSum.hpp
- /library/library/formalpowerseries/RationalSum.hpp.html
title: library/formalpowerseries/RationalSum.hpp
---
