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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/algebra/monoid/Concepts.cpp:\
    \ line -1: no such header\n"
  code: "#include \"library/algebra/monoid/Concepts.cpp\"\n\ntemplate <monoid M> class\
    \ CumulativeMonoid {\n    using T = typename M::value_type;\n    std::vector<T>\
    \ pre, suf;\n\n  public:\n    CumulativeMonoid() : pre(1, M::unit()), suf(pre)\
    \ {}\n    CumulativeMonoid(const std::vector<T> &v)\n        : pre(v.size() +\
    \ 1, M::unit()), suf(pre) {\n        for (int i = 0; i < v.size(); i++)\n    \
    \        pre[i + 1] = M::op(pre[i], v[i]);\n        for (int i = v.size() - 1;\
    \ i >= 0; i--)\n            suf[i] = M::op(v[i], suf[i + 1]);\n        assert(pre.back()\
    \ == suf[0]);\n    }\n    //[0,r)\n    T pre_sum(int r) { return pre[r]; }\n \
    \   // [l,n)\n    T suf_sum(int l) { return suf[l]; }\n\n    T sum() { return\
    \ pre.back(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/CumulativeMonoid.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/CumulativeMonoid.hpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeMonoid.hpp
- /library/library/datastructure/CumulativeMonoid.hpp.html
title: library/datastructure/CumulativeMonoid.hpp
---
