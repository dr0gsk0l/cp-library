---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.hpp
    title: library/util/Compress.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/util/BubbleNumber.hpp
    title: library/util/BubbleNumber.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_5_D.test.cpp
    title: test/AOJ/ALDS1_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/InversionNumber.hpp\"\n#include <atcoder/fenwicktree>\n\
    using namespace atcoder;\n\n#line 2 \"library/util/Compress.hpp\"\ntemplate <typename\
    \ T, bool Sentinel = false> class Compress {\n    std::vector<T> v;\n    bool\
    \ prepared;\n\n  public:\n    Compress() : prepared(false) {\n        if constexpr\
    \ (Sentinel) {\n            static_assert(std::numeric_limits<T>::is_specialized,\n\
    \                          \"cannot use Sentinel\");\n            v = {std::numeric_limits<T>::min(),\
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
    \ 5 \"library/util/InversionNumber.hpp\"\n\ntemplate <typename T> long long inversion_number(const\
    \ std::vector<T> &v) {\n    Compress cmp(v);\n    fenwick_tree<int> ft(cmp.size());\n\
    \    long long res = 0;\n    for (int i = int(v.size()) - 1; i >= 0; i--) {\n\
    \        int j = cmp[v[i]];\n        res += ft.sum(0, j);\n        ft.add(j, 1);\n\
    \    }\n    return res;\n}\n"
  code: "#include <atcoder/fenwicktree>\nusing namespace atcoder;\n\n#include \"library/util/Compress.hpp\"\
    \n\ntemplate <typename T> long long inversion_number(const std::vector<T> &v)\
    \ {\n    Compress cmp(v);\n    fenwick_tree<int> ft(cmp.size());\n    long long\
    \ res = 0;\n    for (int i = int(v.size()) - 1; i >= 0; i--) {\n        int j\
    \ = cmp[v[i]];\n        res += ft.sum(0, j);\n        ft.add(j, 1);\n    }\n \
    \   return res;\n}"
  dependsOn:
  - library/util/Compress.hpp
  isVerificationFile: false
  path: library/util/InversionNumber.hpp
  requiredBy:
  - library/util/BubbleNumber.hpp
  timestamp: '2025-11-09 20:16:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_5_D.test.cpp
documentation_of: library/util/InversionNumber.hpp
layout: document
redirect_from:
- /library/library/util/InversionNumber.hpp
- /library/library/util/InversionNumber.hpp.html
title: library/util/InversionNumber.hpp
---
