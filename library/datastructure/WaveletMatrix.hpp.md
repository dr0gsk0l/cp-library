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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/datastructure/FullyIndexableDictionary.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/datastructure/FullyIndexableDictionary.cpp\"\
    \n#include \"library/util/Compress.cpp\"\n#define REP_(i, n) for (int i = 0; i\
    \ < (n); i++)\ntemplate <typename T, bool COMPRESS = true> class WaveletMatrix\
    \ {\n  protected:\n    using U = std::conditional_t<COMPRESS, int, T>;\n    static_assert(std::is_integral_v<U>,\
    \ \"Wavelet Matrix is only for integer\");\n    int n, memo, log;\n    std::vector<FullyIndexableDictionary>\
    \ mat;\n    std::vector<int> zero_cnt;\n    Compress<T, true> C;\n    std::vector<T>\
    \ data;\n\n    constexpr U comp(const T &x) const {\n        if constexpr (COMPRESS)\
    \ {\n            return C.geq(x);\n        } else {\n            return x;\n \
    \       }\n    }\n    constexpr T uncomp(const U &a) {\n        if constexpr (COMPRESS)\
    \ {\n            return C.r(a);\n        } else {\n            return a;\n   \
    \     }\n    }\n\n    // 0-indexed \u3067\u4E0B\u304B\u3089 i bit \u76EE\n   \
    \ inline bool low_bit(const U &a, int i) const { return (a >> i) & 1; }\n    //\
    \ 0-indexed \u3067\u4E0A\u304B\u3089 i bit \u76EE\n    inline bool high_bit(const\
    \ U &a, int i) const {\n        return low_bit(a, log - i - 1);\n    }\n\n   \
    \ int nxt(int idx, int h, const U &a) {\n        // idx \u306E\u4F4D\u7F6E\u306B\
    \ a \u304C\u3042\u3063\u305F\u5834\u5408\u4E0A\u304B\u3089 h bit \u76EE\u3067\u3069\
    \u3053\u306B\u884C\u304F\u304B\n        bool bit = high_bit(a, h);\n        return\
    \ mat[h].rank(idx, bit) + (bit ? zero_cnt[h] : 0);\n    }\n\n  public:\n    WaveletMatrix(std::vector<T>\
    \ v, int log_ = 0)\n        : n(v.size()), data(v), log(log_) {\n        std::vector<U>\
    \ cv(n);\n        if constexpr (COMPRESS) {\n            C = Compress<T, true>(v);\n\
    \            for (int i = 0; i < n; i++)\n                cv[i] = C[v[i]];\n \
    \           while (C.size() >= (1ull << log))\n                log++;\n      \
    \  } else {\n            cv = v;\n            T mx = 0;\n            for (const\
    \ T &a : v) {\n                assert(a >= 0);\n                if (mx < a)\n\
    \                    mx = a;\n            }\n            while (mx >= (1ull <<\
    \ log))\n                log++;\n        }\n        mat.resize(log);\n       \
    \ zero_cnt.resize(log);\n        std::vector<U> lv(n), rv(n);\n        REP_(h,\
    \ log) {\n            mat[h] = FullyIndexableDictionary(n);\n            int l\
    \ = 0, r = 0;\n            REP_(i, n)\n            if (high_bit(cv[i], h)) {\n\
    \                rv[r++] = cv[i];\n                mat[h].set(i);\n          \
    \  } else\n                lv[l++] = cv[i];\n            zero_cnt[h] = l;\n  \
    \          mat[h].build();\n            std::swap(lv, cv);\n            REP_(i,\
    \ r) cv[l + i] = rv[i];\n        }\n    }\n\n    // [l,r) \u306E x \u306E\u500B\
    \u6570\n    int rank(int l, int r, const T &x) {\n        if constexpr (COMPRESS)\
    \ {\n            if (!C.exist(x))\n                return 0;\n        }\n    \
    \    U a = comp(x);\n        REP_(h, log) {\n            l = nxt(l, h, a);\n \
    \           r = nxt(r, h, a);\n        }\n        memo = l;\n        return r\
    \ - l;\n    }\n    int rank(int r, const T &x) { return rank(x, 0, r); }\n\n \
    \   // k \u756A\u76EE\u306E x \u306E index\n    int select(int k, const T &x)\
    \ {\n        U a = comp(x);\n        if (rank(a, n) < k)\n            return -1;\n\
    \        k += memo;\n        for (int h = log - 1; h >= 0; h--) {\n          \
    \  bool bit = high_bit(a, h);\n            if (bit)\n                k -= zero_cnt[h];\n\
    \            k = mat[h].select(k, bit);\n        }\n        return k;\n    }\n\
    \n    // [l,r) \u3067 0-indexed k \u756A\u76EE\u306B\u5927\u304D\u3044\u5024\n\
    \    T kth_largest(int l, int r, int k) {\n        if (k < 0 or r - l <= k)\n\
    \            return -1;\n        U res = 0;\n        REP_(h, log) {\n        \
    \    int L = mat[h].rank(l);\n            int R = mat[h].rank(r);\n          \
    \  res <<= 1;\n            if (R - L > k) {\n                l = L + zero_cnt[h];\n\
    \                r = R + zero_cnt[h];\n                res++;\n            } else\
    \ {\n                k -= R - L;\n                l -= L;\n                r -=\
    \ R;\n            }\n        }\n        return uncomp(res);\n    }\n    T kth_smallest(int\
    \ l, int r, int k) {\n        return kth_largest(l, r, r - l - k - 1);\n    }\n\
    \n    // [l,r) \u3067 x \u672A\u6E80\u306E\u500B\u6570\n    int range_freq(int\
    \ l, int r, const T &upper) {\n        U a = comp(upper);\n        int res = 0;\n\
    \        REP_(h, log) {\n            if (high_bit(a, h)) {\n                int\
    \ L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);\n                res += R - L;\n\
    \            }\n            l = nxt(l, h, a);\n            r = nxt(r, h, a);\n\
    \        }\n        return res;\n    }\n    // [l,r) \u3067 [lower,upper) \u306E\
    \u500B\u6570\n    int range_freq(int l, int r, const T &lower, const T &upper)\
    \ {\n        return range_freq(l, r, upper) - range_freq(l, r, lower);\n    }\n\
    \n    std::optional<T> lt(int l, int r, const T &x) {\n        int cnt = range_freq(l,\
    \ r, x);\n        if (cnt)\n            return kth_smallest(l, r, cnt - 1);\n\
    \        return std::nullopt;\n    }\n    std::optional<T> leq(int l, int r, const\
    \ T &x) {\n        if (rank(l, r, x))\n            return x;\n        return lt(l,\
    \ r, x);\n    }\n    std::optional<T> geq(int l, int r, const T &x) {\n      \
    \  int cnt = r - l - range_freq(l, r, x);\n        if (cnt)\n            return\
    \ kth_largest(l, r, cnt - 1);\n        return std::nullopt;\n    }\n    std::optional<T>\
    \ gt(int l, int r, const T &x) {\n        T y;\n        if constexpr (COMPRESS)\
    \ {\n            y = C.r(C.gt(x));\n        } else {\n            y = x + 1;\n\
    \        }\n        return geq(l, r, y);\n    }\n\n    // \u30BB\u30B0\u6728\u306A\
    \u3069\u3092\u8F09\u305B\u308B\u6642\u7528\n    // BIT \u306F\u5C02\u7528\u306E\
    \u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u4F5C\u3063\u3066\u3042\u308B\u304C\u3001\
    \u4E00\u5FDC\u62BD\u8C61\u5316\u3082\u6301\u3063\u3066\u304A\u304F\n    // \u69CB\
    \u7BC9\u3057\u305F\u3082\u306E\u3092\u8FD4\u3057\u3066\u308B\u306E\u3067\u9045\
    \u305D\u3046\n    int height() const { return log; }\n    std::vector<int> points(int\
    \ idx) {\n        std::vector<int> res(log);\n        U a = comp(data[idx]);\n\
    \        REP_(h, log) {\n            idx = nxt(idx, h, a);\n            res[h]\
    \ = idx;\n        }\n        return res;\n    }\n    std::vector<std::tuple<int,\
    \ int, int>> intervals(int l, int r,\n                                       \
    \              const T &upper) {\n        std::vector<std::tuple<int, int, int>>\
    \ res;\n        U a = comp(upper);\n        REP_(h, log) {\n            if (high_bit(a,\
    \ h)) {\n                int L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);\n \
    \               res.emplace_back(h, L, R);\n            }\n            l = nxt(l,\
    \ h, a);\n            r = nxt(r, h, a);\n        }\n        return res;\n    }\n\
    \    std::vector<std::tuple<int, int, int>> kth_largest_intervals(int l, int r,\n\
    \                                                                 int k) {\n \
    \       assert(0 <= k and k < r - l);\n        std::vector<std::tuple<int, int,\
    \ int>> res;\n        REP_(h, log) {\n            int L = mat[h].rank(l);\n  \
    \          int R = mat[h].rank(r);\n            if (R - L > k) {\n           \
    \     l = L + zero_cnt[h];\n                r = R + zero_cnt[h];\n           \
    \ } else {\n                res.emplace_back(h, L + zero_cnt[h], R + zero_cnt[h]);\n\
    \                k -= R - L;\n                l -= L;\n                r -= R;\n\
    \            }\n        }\n        return res;\n    }\n    std::vector<std::tuple<int,\
    \ int, int>> kth_smallest_intervals(int l, int r,\n                          \
    \                                        int k) {\n        return kth_largest_intervals(l,\
    \ r, r - l - k - 1);\n    }\n};\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/WaveletMatrix.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/datastructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/library/datastructure/WaveletMatrix.hpp
- /library/library/datastructure/WaveletMatrix.hpp.html
title: library/datastructure/WaveletMatrix.hpp
---
