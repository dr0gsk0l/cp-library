---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/datastructure/GroupWaveletMatrix.hpp
    title: library/datastructure/GroupWaveletMatrix.hpp
  - icon: ':heavy_check_mark:'
    path: library/datastructure/WaveletMatrix.hpp
    title: library/datastructure/WaveletMatrix.hpp
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
    };\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\nclass FullyIndexableDictionary\
    \ {\n    int n,\n        block; // 64\u500B\u4E8B\u306B\u533A\u5207\u3063\u305F\
    \u30D6\u30ED\u30C3\u30AF\u306E\u500B\u6570\n    std::vector<unsigned long long>\
    \ bit;\n    std::vector<unsigned int> sum; // \u30D6\u30ED\u30C3\u30AF\u6BCE\u306E\
    \u7D2F\u7A4D\u548C\n    bool prepared;\n\n  public:\n    FullyIndexableDictionary()\
    \ {}\n    FullyIndexableDictionary(int n)\n        : n(n), block((n + 63) >> 6),\
    \ bit(block, 0), sum(block + 1, 0),\n          prepared(false) {}\n\n    bool\
    \ is_prepared() { return prepared; }\n\n    void set(int k) {\n        bit[k >>\
    \ 6] |= 1ull << (k & 63);\n        sum[(k >> 6) + 1]++;\n    }\n    void build()\
    \ {\n        assert(!prepared);\n        prepared = true;\n        for (int i\
    \ = 0; i < block; i++)\n            sum[i + 1] += sum[i];\n    }\n\n    bool operator[](int\
    \ k) const { return bool((bit[k >> 6] >> (k & 63)) & 1); }\n\n    // [0,j) \u306E\
    \u5408\u8A08\n    int rank(int j, bool f = 1) {\n        assert(prepared);\n \
    \       int a = sum[j >> 6] +\n                __builtin_popcountll(bit[j >> 6]\
    \ & ((1ull << (j & 63)) - 1));\n        return (f ? a : j - a);\n    }\n    //\
    \ 0-indexed \u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\n    int select(int\
    \ k, bool f = 1) {\n        assert(prepared);\n        if (k < 0 or rank(n, f)\
    \ <= k)\n            return -1;\n        int l = 0, r = n;\n        while (r -\
    \ l > 1) {\n            int m = (l + r) >> 1;\n            (rank(m, f) >= k +\
    \ 1 ? r : l) = m;\n        }\n        return r - 1;\n    }\n    // l\u4EE5\u4E0A\
    \u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\n    int select(int k, bool f,\
    \ int l) { return select(rank(l, f) + k, f); }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/FullyIndexableDictionary.hpp
  requiredBy:
  - library/datastructure/WaveletMatrix.hpp
  - library/datastructure/GroupWaveletMatrix.hpp
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - test/yukicoder/924.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/919.test.cpp
documentation_of: library/datastructure/FullyIndexableDictionary.hpp
layout: document
redirect_from:
- /library/library/datastructure/FullyIndexableDictionary.hpp
- /library/library/datastructure/FullyIndexableDictionary.hpp.html
title: library/datastructure/FullyIndexableDictionary.hpp
---
