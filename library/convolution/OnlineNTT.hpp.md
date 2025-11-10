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
  bundledCode: "#line 2 \"library/convolution/OnlineNTT.hpp\"\n#define REP_(i, n)\
    \ for (int i = 0; i < (n); i++)\n#define RREP_(i, n) for (int i = (n)-1; i >=\
    \ 0; i--)\ntemplate <typename MINT> class OnlineNTT {\n    static_assert(MINT::mod\
    \ == 998244353);\n    int d;\n    std::vector<MINT> f, g, fg, change_f, change_g,\
    \ tmp;\n    std::vector<std::vector<MINT>> F, G;\n    // F[i] : \u5E45 1<<i \u306E\
    \ DFT \u7D50\u679C\n    std::vector<std::vector<MINT>> cs, cs_inv;\n    std::vector<int>\
    \ x, fst, lst;\n    std::vector<MINT> inv;\n    int d_lst, lg;\n\n    void DFT(std::vector<MINT>\
    \ &f, std::vector<MINT> &g, const int lg) {\n        // 1<<lg \u306E DFT \u3092\
    \u884C\u3046\n        const int n = 1 << lg;\n        // f[n/2,n) , g[n/2,n) =\
    \ 0 \u304C\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\n        std::fill(x.begin(),\
    \ x.begin() + n, 0);\n        REP_(h, lg)\n        REP_(S, 1 << h)\n        REP_(T,\
    \ 1 << (lg - h - 1)) {\n            int l = (S << (lg - h)) | T;\n           \
    \ int r = l | (1 << (lg - h - 1));\n\n            x[l] >>= 1;\n            (x[r]\
    \ >>= 1) |= 1 << (lg - 1);\n\n            MINT a = f[l];\n            f[l] +=\
    \ f[r] * cs[lg][x[l]];\n            (f[r] *= cs[lg][x[r]]) += a;\n\n         \
    \   a = g[l];\n            g[l] += g[r] * cs[lg][x[l]];\n            (g[r] *=\
    \ cs[lg][x[r]]) += a;\n        }\n    }\n\n    void IDFT(std::vector<MINT> &f,\
    \ const int lg) {\n        const int n = 1 << lg;\n        std::fill(x.begin(),\
    \ x.begin() + n, 0);\n        RREP_(h, lg)\n        REP_(S, 1 << h)\n        REP_(T,\
    \ 1 << (lg - h - 1)) {\n            int l = (S << (lg - h)) | T;\n           \
    \ int r = l | (1 << (lg - h - 1));\n\n            x[l] >>= 1;\n            (x[r]\
    \ >>= 1) |= 1 << (lg - 1);\n\n            MINT a = f[l];\n            f[l] +=\
    \ f[r] * cs_inv[lg][x[l]];\n            (f[r] *= cs_inv[lg][x[r]]) += a;\n   \
    \     }\n        REP_(i, n) f[i] *= inv[lg];\n    }\n\n    void IDFT(std::vector<MINT>\
    \ &f, std::vector<MINT> &g, const int lg) {\n        const int n = 1 << lg;\n\
    \        std::fill(x.begin(), x.begin() + n, 0);\n        RREP_(h, lg)\n     \
    \   REP_(S, 1 << h)\n        REP_(T, 1 << (lg - h - 1)) {\n            int l =\
    \ (S << (lg - h)) | T;\n            int r = l | (1 << (lg - h - 1));\n\n     \
    \       x[l] >>= 1;\n            (x[r] >>= 1) |= 1 << (lg - 1);\n\n          \
    \  MINT a = f[l];\n            f[l] += f[r] * cs_inv[lg][x[l]];\n            (f[r]\
    \ *= cs_inv[lg][x[r]]) += a;\n            a = g[l];\n            g[l] += g[r]\
    \ * cs_inv[lg][x[l]];\n            (g[r] *= cs_inv[lg][x[r]]) += a;\n        }\n\
    \        REP_(i, n) {\n            f[i] *= inv[lg];\n            g[i] *= inv[lg];\n\
    \        }\n    }\n\n  public:\n    OnlineNTT(int n, int m)\n        : d(0), d_lst(-1),\
    \ lg(0), cs(1), cs_inv(1), inv(1), fg(n + m - 1) {}\n\n    MINT query(MINT f_i,\
    \ MINT g_i) {\n        f.push_back(f_i);\n        g.push_back(g_i);\n\n      \
    \  std::ranges::fill(change_f, 0);\n        std::ranges::fill(change_g, 0);\n\n\
    \        REP_(h, F.size()) {\n            if (lst[h] + (1 << h) != d)\n      \
    \          continue;\n            REP (i, 1 << h) {\n                change_f[i]\
    \ = f[d - (1 << h) + 1 + i];\n                change_g[i] = g[d - (1 << h) + 1\
    \ + i];\n            }\n            DFT(change_f, change_g, h + 1);\n        \
    \    REP (i, 1 << (h + 1)) {\n                change_f[i] *= G[h][i];\n      \
    \          change_g[i] *= F[h][i];\n            }\n            IDFT(change_f,\
    \ change_g, h + 1);\n            REP (i, (1 << (h + 1)) - 1) {\n             \
    \   if (fst[h] + lst[h] + 1 + i >= fg.size())\n                    break;\n  \
    \              fg[fst[h] + lst[h] + 1 + i] += change_f[i] + change_g[i];\n   \
    \         }\n            lst[h] = d;\n        }\n\n        if (d_lst + (1 << lg)\
    \ == d) {\n            // \u30B5\u30A4\u30BA 1<<lg \u304C\u5B8C\u6210\uFF08DFT\
    \ \u5F8C\u306E\u30B5\u30A4\u30BA\u306F 1<<(lg+1))\n            const int N = 1\
    \ << (lg + 1);\n            F.emplace_back(std::vector<MINT>(N, 0));\n       \
    \     G.emplace_back(std::vector<MINT>(N, 0));\n            REP_(i, 1 << lg) {\n\
    \                F.back()[i] = f[d - (1 << lg) + 1 + i];\n                G.back()[i]\
    \ = g[d - (1 << lg) + 1 + i];\n            }\n\n            x.resize(N);\n   \
    \         MINT c = MINT(3).pow((MINT::mod - 1) >> (lg + 1));\n            cs.emplace_back(std::vector<MINT>(N));\n\
    \            REP_(i, N) cs.back()[i] = (i ? cs.back()[i - 1] * c : 1);\n     \
    \       DFT(F.back(), G.back(), lg + 1);\n\n            tmp.resize(N);\n     \
    \       REP_(i, N) tmp[i] = F.back()[i] * G.back()[i];\n\n            c = c.inv();\n\
    \            cs_inv.emplace_back(std::vector<MINT>(N));\n            REP_(i, N)\
    \ cs_inv.back()[i] = (i ? cs_inv.back()[i - 1] * c : 1);\n            inv.push_back(MINT(N).inv());\n\
    \            IDFT(tmp, lg + 1);\n\n            REP_(i, N - 1) {\n            \
    \    if ((d_lst + 1) * 2 + i >= fg.size())\n                    break;\n     \
    \           fg[(d_lst + 1) * 2 + i] += tmp[i];\n            }\n\n            change_f.resize(N);\n\
    \            change_g.resize(N);\n\n            fst.push_back(d - (1 << lg) +\
    \ 1);\n            lst.push_back(d);\n            d_lst = d;\n            lg++;\n\
    \        }\n\n        return fg[d++];\n    }\n};\n#undef REP_\n#undef RREP_\n"
  code: "#pragma once\n#define REP_(i, n) for (int i = 0; i < (n); i++)\n#define RREP_(i,\
    \ n) for (int i = (n)-1; i >= 0; i--)\ntemplate <typename MINT> class OnlineNTT\
    \ {\n    static_assert(MINT::mod == 998244353);\n    int d;\n    std::vector<MINT>\
    \ f, g, fg, change_f, change_g, tmp;\n    std::vector<std::vector<MINT>> F, G;\n\
    \    // F[i] : \u5E45 1<<i \u306E DFT \u7D50\u679C\n    std::vector<std::vector<MINT>>\
    \ cs, cs_inv;\n    std::vector<int> x, fst, lst;\n    std::vector<MINT> inv;\n\
    \    int d_lst, lg;\n\n    void DFT(std::vector<MINT> &f, std::vector<MINT> &g,\
    \ const int lg) {\n        // 1<<lg \u306E DFT \u3092\u884C\u3046\n        const\
    \ int n = 1 << lg;\n        // f[n/2,n) , g[n/2,n) = 0 \u304C\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\n        std::fill(x.begin(), x.begin() + n, 0);\n  \
    \      REP_(h, lg)\n        REP_(S, 1 << h)\n        REP_(T, 1 << (lg - h - 1))\
    \ {\n            int l = (S << (lg - h)) | T;\n            int r = l | (1 << (lg\
    \ - h - 1));\n\n            x[l] >>= 1;\n            (x[r] >>= 1) |= 1 << (lg\
    \ - 1);\n\n            MINT a = f[l];\n            f[l] += f[r] * cs[lg][x[l]];\n\
    \            (f[r] *= cs[lg][x[r]]) += a;\n\n            a = g[l];\n         \
    \   g[l] += g[r] * cs[lg][x[l]];\n            (g[r] *= cs[lg][x[r]]) += a;\n \
    \       }\n    }\n\n    void IDFT(std::vector<MINT> &f, const int lg) {\n    \
    \    const int n = 1 << lg;\n        std::fill(x.begin(), x.begin() + n, 0);\n\
    \        RREP_(h, lg)\n        REP_(S, 1 << h)\n        REP_(T, 1 << (lg - h -\
    \ 1)) {\n            int l = (S << (lg - h)) | T;\n            int r = l | (1\
    \ << (lg - h - 1));\n\n            x[l] >>= 1;\n            (x[r] >>= 1) |= 1\
    \ << (lg - 1);\n\n            MINT a = f[l];\n            f[l] += f[r] * cs_inv[lg][x[l]];\n\
    \            (f[r] *= cs_inv[lg][x[r]]) += a;\n        }\n        REP_(i, n) f[i]\
    \ *= inv[lg];\n    }\n\n    void IDFT(std::vector<MINT> &f, std::vector<MINT>\
    \ &g, const int lg) {\n        const int n = 1 << lg;\n        std::fill(x.begin(),\
    \ x.begin() + n, 0);\n        RREP_(h, lg)\n        REP_(S, 1 << h)\n        REP_(T,\
    \ 1 << (lg - h - 1)) {\n            int l = (S << (lg - h)) | T;\n           \
    \ int r = l | (1 << (lg - h - 1));\n\n            x[l] >>= 1;\n            (x[r]\
    \ >>= 1) |= 1 << (lg - 1);\n\n            MINT a = f[l];\n            f[l] +=\
    \ f[r] * cs_inv[lg][x[l]];\n            (f[r] *= cs_inv[lg][x[r]]) += a;\n   \
    \         a = g[l];\n            g[l] += g[r] * cs_inv[lg][x[l]];\n          \
    \  (g[r] *= cs_inv[lg][x[r]]) += a;\n        }\n        REP_(i, n) {\n       \
    \     f[i] *= inv[lg];\n            g[i] *= inv[lg];\n        }\n    }\n\n  public:\n\
    \    OnlineNTT(int n, int m)\n        : d(0), d_lst(-1), lg(0), cs(1), cs_inv(1),\
    \ inv(1), fg(n + m - 1) {}\n\n    MINT query(MINT f_i, MINT g_i) {\n        f.push_back(f_i);\n\
    \        g.push_back(g_i);\n\n        std::ranges::fill(change_f, 0);\n      \
    \  std::ranges::fill(change_g, 0);\n\n        REP_(h, F.size()) {\n          \
    \  if (lst[h] + (1 << h) != d)\n                continue;\n            REP (i,\
    \ 1 << h) {\n                change_f[i] = f[d - (1 << h) + 1 + i];\n        \
    \        change_g[i] = g[d - (1 << h) + 1 + i];\n            }\n            DFT(change_f,\
    \ change_g, h + 1);\n            REP (i, 1 << (h + 1)) {\n                change_f[i]\
    \ *= G[h][i];\n                change_g[i] *= F[h][i];\n            }\n      \
    \      IDFT(change_f, change_g, h + 1);\n            REP (i, (1 << (h + 1)) -\
    \ 1) {\n                if (fst[h] + lst[h] + 1 + i >= fg.size())\n          \
    \          break;\n                fg[fst[h] + lst[h] + 1 + i] += change_f[i]\
    \ + change_g[i];\n            }\n            lst[h] = d;\n        }\n\n      \
    \  if (d_lst + (1 << lg) == d) {\n            // \u30B5\u30A4\u30BA 1<<lg \u304C\
    \u5B8C\u6210\uFF08DFT \u5F8C\u306E\u30B5\u30A4\u30BA\u306F 1<<(lg+1))\n      \
    \      const int N = 1 << (lg + 1);\n            F.emplace_back(std::vector<MINT>(N,\
    \ 0));\n            G.emplace_back(std::vector<MINT>(N, 0));\n            REP_(i,\
    \ 1 << lg) {\n                F.back()[i] = f[d - (1 << lg) + 1 + i];\n      \
    \          G.back()[i] = g[d - (1 << lg) + 1 + i];\n            }\n\n        \
    \    x.resize(N);\n            MINT c = MINT(3).pow((MINT::mod - 1) >> (lg + 1));\n\
    \            cs.emplace_back(std::vector<MINT>(N));\n            REP_(i, N) cs.back()[i]\
    \ = (i ? cs.back()[i - 1] * c : 1);\n            DFT(F.back(), G.back(), lg +\
    \ 1);\n\n            tmp.resize(N);\n            REP_(i, N) tmp[i] = F.back()[i]\
    \ * G.back()[i];\n\n            c = c.inv();\n            cs_inv.emplace_back(std::vector<MINT>(N));\n\
    \            REP_(i, N) cs_inv.back()[i] = (i ? cs_inv.back()[i - 1] * c : 1);\n\
    \            inv.push_back(MINT(N).inv());\n            IDFT(tmp, lg + 1);\n\n\
    \            REP_(i, N - 1) {\n                if ((d_lst + 1) * 2 + i >= fg.size())\n\
    \                    break;\n                fg[(d_lst + 1) * 2 + i] += tmp[i];\n\
    \            }\n\n            change_f.resize(N);\n            change_g.resize(N);\n\
    \n            fst.push_back(d - (1 << lg) + 1);\n            lst.push_back(d);\n\
    \            d_lst = d;\n            lg++;\n        }\n\n        return fg[d++];\n\
    \    }\n};\n#undef REP_\n#undef RREP_"
  dependsOn: []
  isVerificationFile: false
  path: library/convolution/OnlineNTT.hpp
  requiredBy: []
  timestamp: '2025-11-10 09:08:40+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/convolution/OnlineNTT.hpp
layout: document
redirect_from:
- /library/library/convolution/OnlineNTT.hpp
- /library/library/convolution/OnlineNTT.hpp.html
title: library/convolution/OnlineNTT.hpp
---
