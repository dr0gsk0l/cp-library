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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/tree/Tree.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/tree/Tree.cpp\"\nclass EdgeVertex{\n  int\
    \ n,m;\n  Tree T;\npublic:\n  EdgeVertex(int n):n(n),m(0),T(n*2-1){}\n\n  int\
    \ add_edge(int u,int v){\n    assert(0<=u and u<n);\n    assert(0<=v and v<n);\n\
    \    int w=n+(m++);\n    assert(w<T.n);\n    T.add_edge(u,w);\n    T.add_edge(w,v);\n\
    \    return w;\n  }\n\n  Tree build(int root=0){\n    assert(m==n-1);\n    T.build(root);\n\
    \    return T;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/EdgeVertex.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/tree/EdgeVertex.hpp
layout: document
redirect_from:
- /library/library/tree/EdgeVertex.hpp
- /library/library/tree/EdgeVertex.hpp.html
title: library/tree/EdgeVertex.hpp
---
