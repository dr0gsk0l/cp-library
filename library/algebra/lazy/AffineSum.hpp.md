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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/group/Affine.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/algebra/group/Affine.cpp\"\n#include \"\
    library/algebra/group/CntSum.cpp\"\ntemplate <typename X> struct LazyAffineSum\
    \ {\n    using MX = GroupCntSum<X>;\n    using MF = GroupAffine<X>;\n    using\
    \ P = typename MX::value_type;\n    using F = typename MF::value_type;\n    static\
    \ constexpr P mapping(const F &f, const P &x) {\n        return {f.a * x.first\
    \ + f.b * x.second, x.second};\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/lazy/AffineSum.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/lazy/AffineSum.hpp
layout: document
redirect_from:
- /library/library/algebra/lazy/AffineSum.hpp
- /library/library/algebra/lazy/AffineSum.hpp.html
title: library/algebra/lazy/AffineSum.hpp
---
