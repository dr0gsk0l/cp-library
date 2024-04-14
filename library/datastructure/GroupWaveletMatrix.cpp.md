---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/algebra/group/Concepts.cpp
    title: library/algebra/group/Concepts.cpp
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':x:'
    path: library/datastructure/FullyIndexableDictionary.cpp
    title: library/datastructure/FullyIndexableDictionary.cpp
  - icon: ':x:'
    path: library/datastructure/WaveletMatrix.cpp
    title: library/datastructure/WaveletMatrix.cpp
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
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
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/algebra/group/Concepts.cpp: line 3: #pragma once found in a non-first\
    \ line\n"
  code: "#pragma once\n#include \"library/datastructure/FenwickTree.cpp\"\n#include\
    \ \"library/datastructure/WaveletMatrix.cpp\"\n#define REP_(i, n) for (int i =\
    \ 0; i < (n); i++)\ntemplate <typename T, group G>\nclass GroupWaveletMatrix :\
    \ WaveletMatrix<T, true> {\n    using super = WaveletMatrix<T, true>;\n    using\
    \ super::log, super::n, super::nxt, super::comp, super::data,\n        super::high_bit,\
    \ super::mat, super::zero_cnt;\n    using U = typename super::U;\n    using FT\
    \ = FenwickTree<G>;\n    using S = typename G::value_type;\n    std::vector<FT>\
    \ ft;\n\n  public:\n    using super::rank, super::select, super::kth_largest,\
    \ super::kth_smallest,\n        super::range_freq, super::lt, super::leq, super::gt,\
    \ super::geq;\n    GroupWaveletMatrix(std::vector<T> v) : super::WaveletMatrix(v)\
    \ {\n        ft.resize(log);\n        for (auto &p : ft)\n            p = FT(n);\n\
    \    }\n    GroupWaveletMatrix(std::vector<T> v, const std::vector<S> &w)\n  \
    \      : GroupWaveletMatrix(v) {\n        for (int i = 0; i < n; i++)\n      \
    \      add(i, w[i]);\n    }\n    void add(int idx, const S &val) {\n        U\
    \ a = comp(data[idx]);\n        REP_(h, log) {\n            idx = nxt(idx, h,\
    \ a);\n            ft[h].add(idx, val);\n        }\n    }\n    S sum(int l, int\
    \ r, const T &upper) {\n        U a = comp(upper);\n        S res = G::unit();\n\
    \        REP_(h, log) {\n            if (high_bit(a, h)) {\n                int\
    \ L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);\n                G::Rchop(res,\
    \ ft[h].sum(L, R));\n            }\n            l = nxt(l, h, a);\n          \
    \  r = nxt(r, h, a);\n        }\n        return res;\n    }\n    S sum(int l,\
    \ int r, const T &lower, const T &upper) {\n        return G::op(sum(l, r, upper),\
    \ G::inverse(sum(l, r, lower)));\n    }\n    S kth_largest_sum(int l, int r, int\
    \ k) {\n        assert(0 <= k and k < r - l);\n        S res = G::unit();\n  \
    \      REP_(h, log) {\n            int L = mat[h].rank(l);\n            int R\
    \ = mat[h].rank(r);\n            if (R - L > k) {\n                l = L + zero_cnt[h];\n\
    \                r = R + zero_cnt[h];\n            } else {\n                G::Rchop(res,\
    \ ft[h].sum(L + zero_cnt[h], R + zero_cnt[h]));\n                k -= R - L;\n\
    \                l -= L;\n                r -= R;\n            }\n        }\n\
    \        return res;\n    }\n};\n#undef REP_\n"
  dependsOn:
  - library/datastructure/FenwickTree.cpp
  - library/algebra/group/Add.cpp
  - library/algebra/group/Concepts.cpp
  - library/algebra/monoid/Concepts.cpp
  - library/datastructure/WaveletMatrix.cpp
  - library/datastructure/FullyIndexableDictionary.cpp
  - library/util/Compress.cpp
  isVerificationFile: false
  path: library/datastructure/GroupWaveletMatrix.cpp
  requiredBy: []
  timestamp: '2024-04-14 23:11:29+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: library/datastructure/GroupWaveletMatrix.cpp
layout: document
redirect_from:
- /library/library/datastructure/GroupWaveletMatrix.cpp
- /library/library/datastructure/GroupWaveletMatrix.cpp.html
title: library/datastructure/GroupWaveletMatrix.cpp
---
