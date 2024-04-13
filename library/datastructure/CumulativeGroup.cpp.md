---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Concepts.cpp
    title: library/algebra/group/Concepts.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.cpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#include \"library/algebra/group/Concepts.cpp\"\n\ntemplate <group G> struct\
    \ CumulativeGroup {\n    using T = typename G::value_type;\n    std::vector<T>\
    \ A;\n    CumulativeGroup() : A(1, G::unit()) {}\n    CumulativeGroup(const std::vector<T>\
    \ &v) : A(v.size() + 1, G::unit()) {\n        for (int i = 0; i < v.size(); i++)\n\
    \            A[i + 1] = G::op(A[i], v[i]);\n    }\n    void add(const T &a) {\
    \ A.push_back(G::op(A.back(), a)); }\n    T sum(int l, int r) {\n        assert(0\
    \ <= l and l <= r and r < A.size());\n        return G::op(A[r], Group::inverse(A[l]));\n\
    \    }\n    T sum() { return A.back(); }\n};"
  dependsOn:
  - library/algebra/group/Concepts.cpp
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/datastructure/CumulativeGroup.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:59:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/CumulativeGroup.cpp
layout: document
redirect_from:
- /library/library/datastructure/CumulativeGroup.cpp
- /library/library/datastructure/CumulativeGroup.cpp.html
title: library/datastructure/CumulativeGroup.cpp
---
