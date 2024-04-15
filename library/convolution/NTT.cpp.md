---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Convolution.test.cpp
    title: test/library-checker/Polynomial/Convolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/convolution/NTT.cpp\"\n#define REP_(i, n) for (int\
    \ i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n)-1; i >= 0; i--)\n\
    \ntemplate <typename MINT>\nstd::vector<MINT> convolution(std::vector<MINT> f,\
    \ std::vector<MINT> g) {\n    int nf = f.size(), ng = g.size();\n    if (!nf or\
    \ !ng)\n        return std::vector<MINT>{};\n    int M = nf + ng - 1;\n\n    if\
    \ (nf <= 60 or ng <= 60) {\n        std::vector<MINT> res(M, 0);\n        REP_(i,\
    \ nf) REP_(j, ng) res[i + j] += f[i] * g[j];\n        return res;\n    }\n\n \
    \   int lg;\n    for (lg = 0; (1 << lg) < M; lg++) {\n    }\n    const int N =\
    \ 1 << lg;\n    f.resize(N, 0);\n    g.resize(N, 0);\n\n    static_assert(MINT::mod\
    \ == 998244353);\n    MINT c = MINT(3).pow((MINT::mod - 1) >> lg);\n    std::vector<MINT>\
    \ cs(N);\n    REP_(i, N) cs[i] = (i ? cs[i - 1] * c : 1);\n\n    std::vector<int>\
    \ x(N, 0);\n    REP_(h, lg)\n    REP_(S, 1 << h)\n    REP_(T, 1 << (lg - h - 1))\
    \ {\n        int l = (S << (lg - h)) | T;\n        int r = l | (1 << (lg - h -\
    \ 1));\n\n        x[l] >>= 1;\n        (x[r] >>= 1) |= 1 << (lg - 1);\n\n    \
    \    MINT a = f[l];\n        f[l] += f[r] * cs[x[l]];\n        (f[r] *= cs[x[r]])\
    \ += a;\n\n        a = g[l];\n        g[l] += g[r] * cs[x[l]];\n        (g[r]\
    \ *= cs[x[r]]) += a;\n    }\n    REP_(i, N) f[i] *= g[i];\n\n    std::ranges::fill(x,\
    \ 0);\n    c = c.inv();\n    REP_(i, N) cs[i] = (i ? cs[i - 1] * c : 1);\n   \
    \ RREP_(h, lg)\n    REP_(S, 1 << h)\n    REP_(T, 1 << (lg - h - 1)) {\n      \
    \  int l = (S << (lg - h)) | T;\n        int r = l | (1 << (lg - h - 1));\n\n\
    \        x[l] >>= 1;\n        (x[r] >>= 1) |= 1 << (lg - 1);\n\n        MINT a\
    \ = f[l];\n        f[l] += f[r] * cs[x[l]];\n        (f[r] *= cs[x[r]]) += a;\n\
    \    }\n    f.resize(M);\n    MINT Ninv = MINT(N).inv();\n    REP_(i, M) f[i]\
    \ *= Ninv;\n    return f;\n}\n#undef REP_\n#undef RREP_\n"
  code: "#pragma once\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n#define RREP_(i,\
    \ n) for (int i = (n)-1; i >= 0; i--)\n\ntemplate <typename MINT>\nstd::vector<MINT>\
    \ convolution(std::vector<MINT> f, std::vector<MINT> g) {\n    int nf = f.size(),\
    \ ng = g.size();\n    if (!nf or !ng)\n        return std::vector<MINT>{};\n \
    \   int M = nf + ng - 1;\n\n    if (nf <= 60 or ng <= 60) {\n        std::vector<MINT>\
    \ res(M, 0);\n        REP_(i, nf) REP_(j, ng) res[i + j] += f[i] * g[j];\n   \
    \     return res;\n    }\n\n    int lg;\n    for (lg = 0; (1 << lg) < M; lg++)\
    \ {\n    }\n    const int N = 1 << lg;\n    f.resize(N, 0);\n    g.resize(N, 0);\n\
    \n    static_assert(MINT::mod == 998244353);\n    MINT c = MINT(3).pow((MINT::mod\
    \ - 1) >> lg);\n    std::vector<MINT> cs(N);\n    REP_(i, N) cs[i] = (i ? cs[i\
    \ - 1] * c : 1);\n\n    std::vector<int> x(N, 0);\n    REP_(h, lg)\n    REP_(S,\
    \ 1 << h)\n    REP_(T, 1 << (lg - h - 1)) {\n        int l = (S << (lg - h)) |\
    \ T;\n        int r = l | (1 << (lg - h - 1));\n\n        x[l] >>= 1;\n      \
    \  (x[r] >>= 1) |= 1 << (lg - 1);\n\n        MINT a = f[l];\n        f[l] += f[r]\
    \ * cs[x[l]];\n        (f[r] *= cs[x[r]]) += a;\n\n        a = g[l];\n       \
    \ g[l] += g[r] * cs[x[l]];\n        (g[r] *= cs[x[r]]) += a;\n    }\n    REP_(i,\
    \ N) f[i] *= g[i];\n\n    std::ranges::fill(x, 0);\n    c = c.inv();\n    REP_(i,\
    \ N) cs[i] = (i ? cs[i - 1] * c : 1);\n    RREP_(h, lg)\n    REP_(S, 1 << h)\n\
    \    REP_(T, 1 << (lg - h - 1)) {\n        int l = (S << (lg - h)) | T;\n    \
    \    int r = l | (1 << (lg - h - 1));\n\n        x[l] >>= 1;\n        (x[r] >>=\
    \ 1) |= 1 << (lg - 1);\n\n        MINT a = f[l];\n        f[l] += f[r] * cs[x[l]];\n\
    \        (f[r] *= cs[x[r]]) += a;\n    }\n    f.resize(M);\n    MINT Ninv = MINT(N).inv();\n\
    \    REP_(i, M) f[i] *= Ninv;\n    return f;\n}\n#undef REP_\n#undef RREP_"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/NTT.cpp
  requiredBy: []
  timestamp: '2024-04-15 09:29:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Polynomial/Convolution.test.cpp
documentation_of: library/convolution/NTT.cpp
layout: document
redirect_from:
- /library/library/convolution/NTT.cpp
- /library/library/convolution/NTT.cpp.html
title: library/convolution/NTT.cpp
---
