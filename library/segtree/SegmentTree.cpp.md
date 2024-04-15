---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Concepts.cpp
    title: library/algebra/monoid/Concepts.cpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/tree/TreeMonoid.cpp
    title: library/tree/TreeMonoid.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_path_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
    title: test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links:
    - https://codeforces.com/contest/1401/problem/F
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/segtree/SegmentTree.cpp: line 3: #pragma once found in a non-first line\n"
  code: "#include \"library/algebra/monoid/Concepts.cpp\"\n\n#pragma once\ntemplate\
    \ <monoid M> class SegmentTree {\n    using X = typename M::value_type;\n    std::vector<X>\
    \ dat;\n    int n, log, size;\n\n    void update(int i) { dat[i] = M::op(dat[2\
    \ * i], dat[2 * i + 1]); }\n\n  public:\n    SegmentTree() : SegmentTree(0) {}\n\
    \    SegmentTree(int n) : SegmentTree(std::vector<X>(n, M::unit())) {}\n    SegmentTree(std::vector<X>\
    \ v) : n(v.size()) {\n        for (log = 1; (1 << log) < n; log++) {\n       \
    \ }\n        size = 1 << log;\n        dat.assign(size << 1, M::unit());\n   \
    \     for (int i = 0; i < n; ++i)\n            dat[size + i] = v[i];\n       \
    \ for (int i = size - 1; i >= 1; --i)\n            update(i);\n    }\n\n    X\
    \ operator[](int i) const { return dat[size + i]; }\n\n    void set(int i, const\
    \ X &x) {\n        assert(0 <= i and i < n);\n        dat[i += size] = x;\n  \
    \      while (i >>= 1)\n            update(i);\n    }\n    void multiply(int i,\
    \ const X &x) { set(i, M::op(dat[i + size], x)); }\n\n    X prod(int L, int R)\
    \ const {\n        assert(0 <= L and L <= R and R <= n);\n        X vl = M::unit(),\
    \ vr = M::unit();\n        L += size, R += size;\n        while (L < R) {\n  \
    \          if (L & 1)\n                M::Rchop(vl, dat[L++]);\n            if\
    \ (R & 1)\n                M::Lchop(dat[--R], vr);\n            L >>= 1, R >>=\
    \ 1;\n        }\n        return M::op(vl, vr);\n    }\n    X prod_all() const\
    \ { return dat[1]; }\n\n    template <class F> int max_right(F &check, int L)\
    \ {\n        assert(0 <= L && L <= n && check(M::unit()));\n        if (L == n)\n\
    \            return n;\n        L += size;\n        X sm = M::unit();\n      \
    \  do {\n            while (L % 2 == 0)\n                L >>= 1;\n          \
    \  if (!check(M::op(sm, dat[L]))) {\n                while (L < size) {\n    \
    \                L <<= 1;\n                    if (check(M::op(sm, dat[L])))\n\
    \                        M::Rchop(sm, dat[L++]);\n                }\n        \
    \        return L - size;\n            }\n            M::Rchop(sm, dat[L++]);\n\
    \        } while ((L & -L) != L);\n        return n;\n    }\n\n    template <class\
    \ F> int min_left(F &check, int R) {\n        assert(0 <= R && R <= n && check(M::unit()));\n\
    \        if (R == 0)\n            return 0;\n        R += size;\n        X sm\
    \ = M::unit();\n        do {\n            --R;\n            while (R > 1 && (R\
    \ % 2))\n                R >>= 1;\n            if (!check(M::op(dat[R], sm)))\
    \ {\n                while (R < size) {\n                    (R <<= 1)++;\n  \
    \                  if (check(M::op(dat[R], sm)))\n                        M::Lchop(dat[R--],\
    \ sm);\n                }\n                return R + 1 - size;\n            }\n\
    \            M::Lchop(dat[R], sm);\n        } while ((R & -R) != R);\n       \
    \ return 0;\n    }\n\n    // \u30E2\u30CE\u30A4\u30C9\u304C\u53EF\u63DB\u306A\u3089\
    \u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\u53EF\u80FD\n    // https://codeforces.com/contest/1401/problem/F\n\
    \    X Xor_prod(int l, int r, int xor_val) {\n        assert(M::commute);\n  \
    \      X x = M::unit();\n        for (int k = 0; k < log + 1; ++k) {\n       \
    \     if (l >= r)\n                break;\n            if (l & 1) {\n        \
    \        M::Rchop(x, dat[(size >> k) + ((l++) ^ xor_val)]);\n            }\n \
    \           if (r & 1) {\n                M::Rchop(x, dat[(size >> k) + ((--r)\
    \ ^ xor_val)]);\n            }\n            l /= 2, r /= 2, xor_val /= 2;\n  \
    \      }\n        return x;\n    }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const SegmentTree &seg) {\n        os << \"(\";\n        for (int L = 1;\
    \ L <= seg.size; L <<= 1) {\n            os << \"[\";\n            for (int j\
    \ = L; j < (L << 1); j++) {\n                os << seg.dat[j];\n             \
    \   if (j + 1 < (L << 1))\n                    os << \",\";\n            }\n \
    \           os << \"]\";\n        }\n        os << \")\";\n        return os;\n\
    \    }\n};"
  dependsOn:
  - library/algebra/monoid/Concepts.cpp
  isVerificationFile: false
  path: library/segtree/SegmentTree.cpp
  requiredBy:
  - library/tree/TreeMonoid.cpp
  timestamp: '2024-04-15 10:07:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  - test/library-checker/Tree/vertex_add_subtree_sum.test.cpp
  - test/library-checker/Tree/vertex_add_path_sum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/yukicoder/650.test.cpp
documentation_of: library/segtree/SegmentTree.cpp
layout: document
redirect_from:
- /library/library/segtree/SegmentTree.cpp
- /library/library/segtree/SegmentTree.cpp.html
title: library/segtree/SegmentTree.cpp
---
