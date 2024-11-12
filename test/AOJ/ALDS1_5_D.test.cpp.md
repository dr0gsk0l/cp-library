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
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D
  bundledCode: "#line 1 \"test/AOJ/ALDS1_5_D.test.cpp\"\n#define PROBLEM         \
    \                                                       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/util/InversionNumber.hpp\"\n#include\
    \ <atcoder/fenwicktree>\nusing namespace atcoder;\n\n#line 2 \"library/util/Compress.hpp\"\
    \ntemplate <typename T, bool Sentinel = false> class Compress {\n    std::vector<T>\
    \ v;\n    bool prepared;\n\n  public:\n    Compress() : prepared(false) {\n  \
    \      if constexpr (Sentinel) {\n            static_assert(std::numeric_limits<T>::is_specialized,\n\
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
    \    }\n    return res;\n}\n#line 6 \"test/AOJ/ALDS1_5_D.test.cpp\"\n\nint main()\
    \ {\n    int n;\n    std::cin >> n;\n    std::vector<int> v(n);\n    for (int\
    \ i = 0; i < n; i++)\n        std::cin >> v[i];\n    std::cout << inversion_number(v)\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_5_D\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/util/InversionNumber.hpp\"\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n    std::vector<int> v(n);\n   \
    \ for (int i = 0; i < n; i++)\n        std::cin >> v[i];\n    std::cout << inversion_number(v)\
    \ << std::endl;\n}"
  dependsOn:
  - library/util/InversionNumber.hpp
  - library/util/Compress.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_5_D.test.cpp
  requiredBy: []
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_5_D.test.cpp
- /verify/test/AOJ/ALDS1_5_D.test.cpp.html
title: test/AOJ/ALDS1_5_D.test.cpp
---
