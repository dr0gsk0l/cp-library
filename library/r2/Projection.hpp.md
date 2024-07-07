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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/r2/XY.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/r2/XY.cpp\"\n#include \"library/util/Compress.cpp\"\
    \ntemplate <typename T> class Projection {\n    using r2 = XY<T>;\n    Compress<r2>\
    \ C;\n\n  public:\n    Projection(const std::vector<r2> &v) : C(v) {}\n    int\
    \ size() { return C.size(); }\n    int id(r2 xy) { return C[xy]; }\n    int id(int\
    \ x, int y) { return C[r2(x, y)]; }\n    r2 r(int id) { return C.r(id); }\n  \
    \  //[l,r) \u3092\u8FD4\u3059\n    std::pair<int, int> interval(const T &l, const\
    \ T &r) {\n        if (C.max().x < l or r <= C.min().x)\n            return std::make_pair(0,\
    \ 0);\n        T mn = std::numeric_limits<T>::min();\n        int L = C.geq(r2(l,\
    \ mn));\n        int R = C.geq(r2(r, mn));\n        return std::make_pair(L, R);\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/r2/Projection.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/r2/Projection.hpp
layout: document
redirect_from:
- /library/library/r2/Projection.hpp
- /library/library/r2/Projection.hpp.html
title: library/r2/Projection.hpp
---
