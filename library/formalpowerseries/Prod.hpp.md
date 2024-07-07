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
    \ FPS> class FPSProd {\n    std::queue<FPS> que;\n\n  public:\n    void add(const\
    \ FPS &f) { que.push(f); }\n    FPS prod() {\n        if (!que.size())\n     \
    \       return FPS::unit();\n        while (que.size() > 1) {\n            FPS\
    \ f = que.front();\n            que.pop();\n            FPS g = que.front();\n\
    \            que.pop();\n            que.push(f * g);\n        }\n        FPS\
    \ res = que.front();\n        que.pop();\n        return res;\n    }\n};\n\ntemplate\
    \ <typename FPS> class FPSProdDiversity {\n    static constexpr auto cmp = [](const\
    \ FPS &f, const FPS &g) {\n        return f.size() > g.size();\n    };\n    std::priority_queue<FPS,\
    \ std::vector<FPS>, decltype(cmp)> que{cmp};\n\n  public:\n    void add(const\
    \ FPS &f) { que.push(f); }\n    FPS prod() {\n        if (!que.size())\n     \
    \       return FPS::unit();\n        while (que.size() > 1) {\n            FPS\
    \ f = que.top();\n            que.pop();\n            FPS g = que.top();\n   \
    \         que.pop();\n            que.push(f * g);\n        }\n        FPS res\
    \ = que.top();\n        que.pop();\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/Prod.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/Prod.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/Prod.hpp
- /library/library/formalpowerseries/Prod.hpp.html
title: library/formalpowerseries/Prod.hpp
---
