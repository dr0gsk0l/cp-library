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
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':warning:'
    path: library/math/FactorialNumberSystem.cpp
    title: library/math/FactorialNumberSystem.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_B.test.cpp
    title: test/AOJ/DSL_2_B.test.cpp
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
  _verificationStatusIcon: ':question:'
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
  code: "#pragma once\n#include \"library/algebra/group/Add.cpp\"\n#include \"library/algebra/group/Concepts.cpp\"\
    \n\ntemplate <group G = GroupAdd<long long>> class FenwickTree {\n    using T\
    \ = typename G::value_type;\n    int n;\n    std::vector<T> dat, raw;\n\n  public:\n\
    \    FenwickTree() { assert(G::commute); }\n    FenwickTree(int n) : n(n) {\n\
    \        assert(G::commute);\n        dat = raw = std::vector<T>(n, G::unit());\n\
    \    }\n    FenwickTree(const std::vector<T> &v) : n(v.size()), raw(v), dat(v)\
    \ {\n        assert(G::commute);\n        for (int i = 1; i <= n; i++) {\n   \
    \         int j = i + (i & -i);\n            if (j <= n)\n                G::Rchop(dat[j\
    \ - 1], dat[i - 1]);\n        }\n    }\n\n    T operator[](int k) const { return\
    \ raw[k]; }\n    T get(int k) const { return raw[k]; }\n\n    void multiply(int\
    \ k, const T &x) {\n        G::Rchop(raw[k], x);\n        for (++k; k <= n; k\
    \ += k & -k)\n            G::Rchop(dat[k - 1], x);\n    }\n    void add(int k,\
    \ const T &x) { multiply(k, x); }\n    void set(int k, const T &x) { multiply(k,\
    \ G::op(x, G::inverse(raw[k]))); }\n\n    T prod(int k) const {\n        T res\
    \ = G::unit();\n        while (k > 0) {\n            G::Rchop(res, dat[k - 1]);\n\
    \            k -= k & -k;\n        }\n        return res;\n    }\n    T sum(int\
    \ k) const { return prod(k); }\n    T prod(int L, int R) const {\n        T pos\
    \ = G::unit();\n        while (L < R) {\n            G::Rchop(pos, dat[R - 1]);\n\
    \            R -= R & -R;\n        }\n        T neg = G::unit();\n        while\
    \ (R < L) {\n            G::Rchop(neg, dat[L - 1]);\n            L -= L & -L;\n\
    \        }\n        return G::op(pos, G::inverse(neg));\n    }\n    T sum(int\
    \ L, int R) const { return prod(L, R); }\n\n    template <class F> int max_right(const\
    \ F check) const {\n        assert(check(G::unit()));\n        int r = 0;\n  \
    \      T sum = G::unit();\n        int k = 1;\n        while (2 * k <= n)\n  \
    \          k <<= 1;\n        while (k) {\n            if (r + k - 1 < dat.size())\n\
    \                if (check(G::op(sum, dat[r + k - 1]))) {\n                  \
    \  G::Rchop(sum, dat[r + k - 1]);\n                    r += k;\n             \
    \   }\n            k >>= 1;\n        }\n        return r;\n    }\n\n    int kth(T\
    \ k) const {\n        return max_right([&k](T x) { return x <= k; });\n    }\n\
    };"
  dependsOn:
  - library/algebra/group/Add.cpp
  - library/algebra/group/Concepts.cpp
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/datastructure/FenwickTree.cpp
  requiredBy:
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/math/FactorialNumberSystem.cpp
  timestamp: '2024-04-14 23:11:29+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/yukicoder/924.test.cpp
  - test/AOJ/DSL_2_B.test.cpp
documentation_of: library/datastructure/FenwickTree.cpp
layout: document
redirect_from:
- /library/library/datastructure/FenwickTree.cpp
- /library/library/datastructure/FenwickTree.cpp.html
title: library/datastructure/FenwickTree.cpp
---
