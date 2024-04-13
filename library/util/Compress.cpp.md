---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/datastructure/GroupWaveletMatrix.cpp
    title: library/datastructure/GroupWaveletMatrix.cpp
  - icon: ':x:'
    path: library/datastructure/WaveletMatrix.cpp
    title: library/datastructure/WaveletMatrix.cpp
  - icon: ':x:'
    path: library/r2/Projection.cpp
    title: library/r2/Projection.cpp
  - icon: ':warning:'
    path: library/util/BubbleNumber.cpp
    title: library/util/BubbleNumber.cpp
  - icon: ':x:'
    path: library/util/InversionNumber.cpp
    title: library/util/InversionNumber.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
    title: test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
    title: test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1332.test.cpp
    title: test/yukicoder/1332.test.cpp
  - icon: ':x:'
    path: test/yukicoder/919.test.cpp
    title: test/yukicoder/919.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/util/Compress.cpp\"\n#define ALL_(v) v.begin(),\
    \ v.end()\ntemplate <typename T, bool Sentinel = false> class Compress {\n   \
    \ std::vector<T> v;\n    bool prepared;\n\n  public:\n    Compress() : prepared(false)\
    \ {\n        if constexpr (Sentinel) {\n            static_assert(std::numeric_limits<T>::is_specialized,\n\
    \                          \"cannot use Sentinel\");\n            v = {numeric_limits<T>::min(),\
    \ numeric_limits<T>::max()};\n        }\n    }\n    Compress(const std::vector<T>\
    \ &w) : v(w), prepared(false) {\n        if constexpr (Sentinel) {\n         \
    \   static_assert(std::numeric_limits<T>::is_specialized,\n                  \
    \        \"cannot use Sentinel\");\n            v.push_back(numeric_limits<T>::min());\n\
    \            v.push_back(numeric_limits<T>::max());\n        }\n        build();\n\
    \    }\n\n    void add(T a) {\n        assert(!prepared);\n        v.push_back(a);\n\
    \    }\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        sort(ALL_(v));\n        v.erase(unique(ALL_(v)), v.end());\n    }\n\n\
    \    bool is_prepared() const { return prepared; }\n\n    int operator[](const\
    \ T &a) const {\n        assert(prepared);\n        auto it = lower_bound(ALL_(v),\
    \ a);\n        assert(*it == a);\n        return distance(v.begin(), it);\n  \
    \  }\n    int geq(const T &a) const {\n        assert(prepared);\n        auto\
    \ it = lower_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n   \
    \ }\n    int gt(const T &a) const {\n        assert(prepared);\n        auto it\
    \ = upper_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    int leq(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ --upper_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    int lt(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ --lower_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    T r(int id) const {\n        assert(prepared);\n        return v[id];\n \
    \   }\n    bool exist(const T &a) const {\n        assert(prepared);\n       \
    \ return (*lower_bound(ALL_(v), a)) == a;\n    }\n    int size() const { return\
    \ v.size(); }\n    T max() const { return v.back(); }\n    T min() const { return\
    \ v[0]; }\n\n    friend std::ostream &operator<<(std::ostream &os, const Compress\
    \ &C) {\n        for (int i = 0; i < C.v.size(); i++)\n            os << C.v[i]\
    \ << \":\" << i << \" \";\n        return os;\n    }\n};\n#undef ALL_\n"
  code: "#pragma once\n#define ALL_(v) v.begin(), v.end()\ntemplate <typename T, bool\
    \ Sentinel = false> class Compress {\n    std::vector<T> v;\n    bool prepared;\n\
    \n  public:\n    Compress() : prepared(false) {\n        if constexpr (Sentinel)\
    \ {\n            static_assert(std::numeric_limits<T>::is_specialized,\n     \
    \                     \"cannot use Sentinel\");\n            v = {numeric_limits<T>::min(),\
    \ numeric_limits<T>::max()};\n        }\n    }\n    Compress(const std::vector<T>\
    \ &w) : v(w), prepared(false) {\n        if constexpr (Sentinel) {\n         \
    \   static_assert(std::numeric_limits<T>::is_specialized,\n                  \
    \        \"cannot use Sentinel\");\n            v.push_back(numeric_limits<T>::min());\n\
    \            v.push_back(numeric_limits<T>::max());\n        }\n        build();\n\
    \    }\n\n    void add(T a) {\n        assert(!prepared);\n        v.push_back(a);\n\
    \    }\n    void build() {\n        assert(!prepared);\n        prepared = true;\n\
    \        sort(ALL_(v));\n        v.erase(unique(ALL_(v)), v.end());\n    }\n\n\
    \    bool is_prepared() const { return prepared; }\n\n    int operator[](const\
    \ T &a) const {\n        assert(prepared);\n        auto it = lower_bound(ALL_(v),\
    \ a);\n        assert(*it == a);\n        return distance(v.begin(), it);\n  \
    \  }\n    int geq(const T &a) const {\n        assert(prepared);\n        auto\
    \ it = lower_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n   \
    \ }\n    int gt(const T &a) const {\n        assert(prepared);\n        auto it\
    \ = upper_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    int leq(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ --upper_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    int lt(const T &a) const {\n        assert(prepared);\n        auto it =\
    \ --lower_bound(ALL_(v), a);\n        return distance(v.begin(), it);\n    }\n\
    \    T r(int id) const {\n        assert(prepared);\n        return v[id];\n \
    \   }\n    bool exist(const T &a) const {\n        assert(prepared);\n       \
    \ return (*lower_bound(ALL_(v), a)) == a;\n    }\n    int size() const { return\
    \ v.size(); }\n    T max() const { return v.back(); }\n    T min() const { return\
    \ v[0]; }\n\n    friend std::ostream &operator<<(std::ostream &os, const Compress\
    \ &C) {\n        for (int i = 0; i < C.v.size(); i++)\n            os << C.v[i]\
    \ << \":\" << i << \" \";\n        return os;\n    }\n};\n#undef ALL_"
  dependsOn: []
  isVerificationFile: false
  path: library/util/Compress.cpp
  requiredBy:
  - library/datastructure/GroupWaveletMatrix.cpp
  - library/datastructure/WaveletMatrix.cpp
  - library/util/InversionNumber.cpp
  - library/util/BubbleNumber.cpp
  - library/r2/Projection.cpp
  timestamp: '2024-04-13 18:08:10+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/RangeKthSmallest.test.cpp
  - test/library-checker/DataStructure/StaticRangeFrequency.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/yukicoder/919.test.cpp
  - test/yukicoder/1332.test.cpp
  - test/yukicoder/924.test.cpp
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: library/util/Compress.cpp
layout: document
redirect_from:
- /library/library/util/Compress.cpp
- /library/library/util/Compress.cpp.html
title: library/util/Compress.cpp
---
