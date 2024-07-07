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
    library/formalpowerseries/RationalSum.cpp\"\n// f(e^x)\ntemplate<typename FPS>\n\
    void compose_exp(FPS&f){\n  f.shrink();\n  if(f.size()<=1)return;\n  RationalSum<FPS>\
    \ RS;\n  for(int n=0;n<f.size();n++)\n    RS.add(FPS{f[n]},FPS{1,-n});\n  f=RS.sum();\n\
    \  typename FPS::value_type fact=1;\n  for(int n=1;n<f.size();fact*=++n)\n   \
    \ f[n]/=fact;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/ComposeEXP.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/formalpowerseries/ComposeEXP.hpp
layout: document
redirect_from:
- /library/library/formalpowerseries/ComposeEXP.hpp
- /library/library/formalpowerseries/ComposeEXP.hpp.html
title: library/formalpowerseries/ComposeEXP.hpp
---
