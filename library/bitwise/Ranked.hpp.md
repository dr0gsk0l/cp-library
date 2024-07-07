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
    class BitwiseRanked {\n    static int popcount(int S) { return __builtin_popcount(S);\
    \ }\n\n  public:\n    template <typename T>\n    static std::vector<std::vector<T>>\
    \ zeta(const std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n\
    \        std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));\n \
    \       REP_(S, 1 << n) RA[S][popcount(S)] = A[S];\n        REP_(i, n)\n     \
    \   REP_(S, 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n +\
    \ 1) RA[S | (1 << i)][d] += RA[S][d];\n        return RA;\n    }\n    template\
    \ <typename T>\n    static std::vector<T> mobius(std::vector<std::vector<T>> RA)\
    \ {\n        const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n   \
    \     REP_(S, 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n\
    \ + 1) RA[S | (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n \
    \       REP_(S, 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n\
    \    template <typename T>\n    static std::vector<T> convolution(const std::vector<T>\
    \ &A,\n                                      const std::vector<T> &B) {\n    \
    \    const int n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n    \
    \    auto RB = zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S],\
    \ rb = RB[S];\n            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n\
    \                REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n     \
    \   }\n        return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_"
  dependsOn: []
  isVerificationFile: false
  path: library/bitwise/Ranked.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/bitwise/Ranked.hpp
layout: document
redirect_from:
- /library/library/bitwise/Ranked.hpp
- /library/library/bitwise/Ranked.hpp.html
title: library/bitwise/Ranked.hpp
---
