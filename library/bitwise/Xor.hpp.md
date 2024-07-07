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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/bitwise/Util.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/bitwise/Util.cpp\"\n#define REP_(i, n) for\
    \ (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n)-1; i >= 0; i--)\n\
    struct BitwiseXor {\n    template <typename T> static void zeta(std::vector<T>\
    \ &A) {\n        const int n = bitwise::log2(A.size());\n        REP_(i, n)\n\
    \        REP_(S, 1 << n) {\n            if (bitwise::in(S, i))\n             \
    \   continue;\n            T x = A[S], y = A[S | (1 << i)];\n            A[S]\
    \ -= y;\n            A[S | (1 << i)] += x;\n        }\n    }\n    template <typename\
    \ T> static void mobius(std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n\
    \        RREP_(i, n)\n        REP_(S, 1 << n) {\n            if (bitwise::in(S,\
    \ i))\n                continue;\n            T x = A[S], y = A[S | (1 << i)];\n\
    \            A[S] += y;\n            A[S | (1 << i)] -= x;\n        }\n      \
    \  T inv = T(1) / (1 << n);\n        REP (S, 1 << n)\n            A[S] *= inv;\n\
    \    }\n    template <typename T>\n    static std::vector<T> convolution(std::vector<T>\
    \ A, std::vector<T> B) {\n        zeta(A);\n        zeta(B);\n        REP (S,\
    \ A.size())\n            A[S] *= B[S];\n        mobius(A);\n        return A;\n\
    \    }\n};\n#undef REP_\n#undef RREP_"
  dependsOn: []
  isVerificationFile: false
  path: library/bitwise/Xor.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/bitwise/Xor.hpp
layout: document
redirect_from:
- /library/library/bitwise/Xor.hpp
- /library/library/bitwise/Xor.hpp.html
title: library/bitwise/Xor.hpp
---
