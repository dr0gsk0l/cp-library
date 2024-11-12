---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/datastructure/FullyIndexableDictionary.hpp
    title: library/datastructure/FullyIndexableDictionary.hpp
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.hpp
    title: library/util/Compress.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
    title: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
    title: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/FullyIndexableDictionary.hpp\"\n#include\
    \ <cassert>\n#include <vector>\nclass FullyIndexableDictionary {\n    int n,\n\
    \        block; // 64\u500B\u4E8B\u306B\u533A\u5207\u3063\u305F\u30D6\u30ED\u30C3\
    \u30AF\u306E\u500B\u6570\n    std::vector<unsigned long long> bit;\n    std::vector<unsigned\
    \ int> sum; // \u30D6\u30ED\u30C3\u30AF\u6BCE\u306E\u7D2F\u7A4D\u548C\n    bool\
    \ prepared;\n\n  public:\n    FullyIndexableDictionary() {}\n    FullyIndexableDictionary(int\
    \ n)\n        : n(n), block((n + 63) >> 6), bit(block, 0), sum(block + 1, 0),\n\
    \          prepared(false) {}\n\n    bool is_prepared() { return prepared; }\n\
    \n    void set(int k) {\n        bit[k >> 6] |= 1ull << (k & 63);\n        sum[(k\
    \ >> 6) + 1]++;\n    }\n    void build() {\n        assert(!prepared);\n     \
    \   prepared = true;\n        for (int i = 0; i < block; i++)\n            sum[i\
    \ + 1] += sum[i];\n    }\n\n    bool operator[](int k) const { return bool((bit[k\
    \ >> 6] >> (k & 63)) & 1); }\n\n    // [0,j) \u306E\u5408\u8A08\n    int rank(int\
    \ j, bool f = 1) {\n        assert(prepared);\n        int a = sum[j >> 6] +\n\
    \                __builtin_popcountll(bit[j >> 6] & ((1ull << (j & 63)) - 1));\n\
    \        return (f ? a : j - a);\n    }\n    // 0-indexed \u3067 k \u756A\u76EE\
    \u306E f \u306E\u5834\u6240\n    int select(int k, bool f = 1) {\n        assert(prepared);\n\
    \        if (k < 0 or rank(n, f) <= k)\n            return -1;\n        int l\
    \ = 0, r = n;\n        while (r - l > 1) {\n            int m = (l + r) >> 1;\n\
    \            (rank(m, f) >= k + 1 ? r : l) = m;\n        }\n        return r -\
    \ 1;\n    }\n    // l\u4EE5\u4E0A\u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\
    \n    int select(int k, bool f, int l) { return select(rank(l, f) + k, f); }\n\
    };\n#line 2 \"library/util/Compress.hpp\"\ntemplate <typename T, bool Sentinel\
    \ = false> class Compress {\n    std::vector<T> v;\n    bool prepared;\n\n  public:\n\
    \    Compress() : prepared(false) {\n        if constexpr (Sentinel) {\n     \
    \       static_assert(std::numeric_limits<T>::is_specialized,\n              \
    \            \"cannot use Sentinel\");\n            v = {std::numeric_limits<T>::min(),\
    \ std::numeric_limits<T>::max()};\n        }\n    }\n    Compress(const std::vector<T>\
    \ &w) : v(w), prepared(false) {\n        if constexpr (Sentinel) {\n         \
    \   static_assert(std::numeric_limits<T>::is_specialized,\n                  \
    \        \"cannot use Sentinel\");\n            v.push_back(std::numeric_limits<T>::min());\n\
    \            v.push_back(std::numeric_limits<T>::max());\n        }\n        build();\n\
    \    }\n\n    void add(T a) {\n        assert(!prepared);\n        v.push_back(a);\n\
    \    }\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        std::ranges::sort(v);\n        auto result = std::ranges::unique(v);\n\
    \        v.erase(result.begin(), result.end());\n    }\n\n    bool is_prepared()\
    \ const { return prepared; }\n\n    int operator[](const T &a) const {\n     \
    \   assert(prepared);\n        auto it = std::ranges::lower_bound(v, a);\n   \
    \     assert(*it == a);\n        return std::distance(v.begin(), it);\n    }\n\
    \    int geq(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(), it);\n\
    \    }\n    int gt(const T &a) const {\n        assert(prepared);\n        auto\
    \ it = std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int leq(const T &a) const {\n        assert(prepared);\n  \
    \      auto it = --std::ranges::upper_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    int lt(const T &a) const {\n        assert(prepared);\n   \
    \     auto it = --std::ranges::lower_bound(v, a);\n        return std::distance(v.begin(),\
    \ it);\n    }\n    T r(int id) const {\n        assert(prepared);\n        return\
    \ v[id];\n    }\n    bool exist(const T &a) const {\n        assert(prepared);\n\
    \        return (*std::ranges::lower_bound(v, a)) == a;\n    }\n    int size()\
    \ const { return v.size(); }\n    T max() const { return v.back(); }\n    T min()\
    \ const { return v[0]; }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const Compress &C) {\n        for (int i = 0; i < C.v.size(); i++)\n       \
    \     os << C.v[i] << \":\" << i << \" \";\n        return os;\n    }\n};\n#line\
    \ 4 \"library/datastructure/WaveletMatrix.hpp\"\n#define REP_(i, n) for (int i\
    \ = 0; i < (n); i++)\ntemplate <typename T, bool COMPRESS = true> class WaveletMatrix\
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
    \ r, r - l - k - 1);\n    }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/datastructure/FullyIndexableDictionary.hpp\"\
    \n#include \"library/util/Compress.hpp\"\n#define REP_(i, n) for (int i = 0; i\
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
  dependsOn:
  - library/datastructure/FullyIndexableDictionary.hpp
  - library/util/Compress.hpp
  isVerificationFile: false
  path: library/datastructure/WaveletMatrix.hpp
  requiredBy:
  - library/datastructure/GroupWaveletMatrix.hpp
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/yukicoder/919.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1332.test.cpp
documentation_of: library/datastructure/WaveletMatrix.hpp
layout: document
redirect_from:
- /library/library/datastructure/WaveletMatrix.hpp
- /library/library/datastructure/WaveletMatrix.hpp.html
title: library/datastructure/WaveletMatrix.hpp
---
