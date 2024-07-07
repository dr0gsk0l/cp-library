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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/linearalgebra/Linear.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/linearalgebra/Linear.cpp\"\ntemplate<typename\
    \ T>\nstruct GroupAffine{\n  using L = Line<T>;\n  using value_type = L;\n  static\
    \ constexpr L op(const L&f, const L&g)noexcept{ return f(g); }\n  static constexpr\
    \ void Rchop(L&f, const L&g){\n    f.b += f.a*g.b;\n    f.a *= g.a;\n  }\n  static\
    \ constexpr void Lchop(const L&f, L&g){\n    (g.b *= f.a) += f.b;\n    g.a *=\
    \ f.a;\n  }\n  static constexpr L inverse(const L&f){ return f.inv(); }\n  /*\n\
    \  static constexpr L power(const L& f,long long n) noexcept {\n    if(a==1)return\
    \ {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n  }\n  */\n\
    \  static constexpr L unit(){ return L(1,0); }\n  static constexpr bool commute\
    \ = false;\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/Affine.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/group/Affine.hpp
layout: document
redirect_from:
- /library/library/algebra/group/Affine.hpp
- /library/library/algebra/group/Affine.hpp.html
title: library/algebra/group/Affine.hpp
---
