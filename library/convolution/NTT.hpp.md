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
  bundledCode: "#line 2 \"library/convolution/NTT.hpp\"\n#define REP_(i, n) for (int\
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
  path: library/convolution/NTT.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/convolution/NTT.hpp
layout: document
redirect_from:
- /library/library/convolution/NTT.hpp
- /library/library/convolution/NTT.hpp.html
title: library/convolution/NTT.hpp
---
