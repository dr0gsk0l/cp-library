---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/util/Compress.hpp
    title: library/util/Compress.hpp
  - icon: ':heavy_check_mark:'
    path: library/util/InversionNumber.hpp
    title: library/util/InversionNumber.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \    }\n    return res;\n}\n#line 3 \"library/util/BubbleNumber.hpp\"\ntemplate\
    \ <typename T>\nlong long bubble_number(const std::vector<T> &v, const std::vector<T>\
    \ &w) {\n    int n = v.size();\n    assert(w.size() == n);\n    std::map<T, std::queue<int>>\
    \ mp;\n    for (int i = 0; i < n; i++)\n        mp[w[i]].push(i);\n    std::vector<int>\
    \ idx(n);\n    REP (i, n) {\n        if (!mp[v[i]].size())\n            return\
    \ -1;\n        idx[i] = mp[v[i]].front();\n        mp[v[i]].pop();\n    }\n  \
    \  return inversion_number(idx);\n}\n"
  code: "#pragma once\n#include \"library/util/InversionNumber.hpp\"\ntemplate <typename\
    \ T>\nlong long bubble_number(const std::vector<T> &v, const std::vector<T> &w)\
    \ {\n    int n = v.size();\n    assert(w.size() == n);\n    std::map<T, std::queue<int>>\
    \ mp;\n    for (int i = 0; i < n; i++)\n        mp[w[i]].push(i);\n    std::vector<int>\
    \ idx(n);\n    REP (i, n) {\n        if (!mp[v[i]].size())\n            return\
    \ -1;\n        idx[i] = mp[v[i]].front();\n        mp[v[i]].pop();\n    }\n  \
    \  return inversion_number(idx);\n}"
  dependsOn:
  - library/util/InversionNumber.hpp
  - library/util/Compress.hpp
  isVerificationFile: false
  path: library/util/BubbleNumber.hpp
  requiredBy: []
  timestamp: '2025-11-09 21:16:52+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/BubbleNumber.hpp
layout: document
redirect_from:
- /library/library/util/BubbleNumber.hpp
- /library/library/util/BubbleNumber.hpp.html
title: library/util/BubbleNumber.hpp
---
