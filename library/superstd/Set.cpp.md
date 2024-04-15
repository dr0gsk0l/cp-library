---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PredecessorProblem.test.cpp
    title: test/library-checker/DataStructure/PredecessorProblem.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/superstd/Set.cpp\"\ntemplate <typename T> struct\
    \ Set : std::set<T> {\n    using std::set<T>::size;\n    using std::set<T>::begin;\n\
    \    using std::set<T>::rbegin;\n    using std::set<T>::insert;\n    using std::set<T>::erase;\n\
    \    using std::set<T>::lower_bound;\n    using std::set<T>::upper_bound;\n\n\
    \    T mn() const {\n        assert(size());\n        return *begin();\n    }\n\
    \    T mx() const {\n        assert(size());\n        return *rbegin();\n    }\n\
    \n    T pop_front() {\n        assert(size());\n        T mn = *begin();\n   \
    \     erase(begin());\n        return mn;\n    }\n    T pop_back() {\n       \
    \ assert(size());\n        T mx = *rbegin();\n        erase(mx);\n        return\
    \ mx;\n    }\n\n    T lt(const T &a) const {\n        assert(mn() < a);\n    \
    \    if (mx() < a)\n            return mx();\n        return *--lower_bound(a);\n\
    \    }\n    T leq(const T &a) const {\n        assert(mn() <= a);\n        if\
    \ (mx() <= a)\n            return mx();\n        return *--upper_bound(a);\n \
    \   }\n    T gt(const T &a) const {\n        assert(mx() > a);\n        return\
    \ *upper_bound(a);\n    }\n    T geq(const T &a) {\n        assert(mx() >= a);\n\
    \        return *lower_bound(a);\n    }\n\n    Set() = default;\n    Set(const\
    \ std::vector<T> &v) {\n        for (const auto &p : v)\n            insert(p);\n\
    \    }\n\n    void scan(int n) {\n        while (n--) {\n            T a;\n  \
    \          std::cin >> a;\n            insert(a);\n        }\n    }\n\n    void\
    \ banpei() {\n        insert(std::numeric_limits<T>::max() / 2);\n        insert(std::numeric_limits<T>::min()\
    \ / 2);\n    }\n};\n"
  code: "template <typename T> struct Set : std::set<T> {\n    using std::set<T>::size;\n\
    \    using std::set<T>::begin;\n    using std::set<T>::rbegin;\n    using std::set<T>::insert;\n\
    \    using std::set<T>::erase;\n    using std::set<T>::lower_bound;\n    using\
    \ std::set<T>::upper_bound;\n\n    T mn() const {\n        assert(size());\n \
    \       return *begin();\n    }\n    T mx() const {\n        assert(size());\n\
    \        return *rbegin();\n    }\n\n    T pop_front() {\n        assert(size());\n\
    \        T mn = *begin();\n        erase(begin());\n        return mn;\n    }\n\
    \    T pop_back() {\n        assert(size());\n        T mx = *rbegin();\n    \
    \    erase(mx);\n        return mx;\n    }\n\n    T lt(const T &a) const {\n \
    \       assert(mn() < a);\n        if (mx() < a)\n            return mx();\n \
    \       return *--lower_bound(a);\n    }\n    T leq(const T &a) const {\n    \
    \    assert(mn() <= a);\n        if (mx() <= a)\n            return mx();\n  \
    \      return *--upper_bound(a);\n    }\n    T gt(const T &a) const {\n      \
    \  assert(mx() > a);\n        return *upper_bound(a);\n    }\n    T geq(const\
    \ T &a) {\n        assert(mx() >= a);\n        return *lower_bound(a);\n    }\n\
    \n    Set() = default;\n    Set(const std::vector<T> &v) {\n        for (const\
    \ auto &p : v)\n            insert(p);\n    }\n\n    void scan(int n) {\n    \
    \    while (n--) {\n            T a;\n            std::cin >> a;\n           \
    \ insert(a);\n        }\n    }\n\n    void banpei() {\n        insert(std::numeric_limits<T>::max()\
    \ / 2);\n        insert(std::numeric_limits<T>::min() / 2);\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Set.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PredecessorProblem.test.cpp
documentation_of: library/superstd/Set.cpp
layout: document
redirect_from:
- /library/library/superstd/Set.cpp
- /library/library/superstd/Set.cpp.html
title: library/superstd/Set.cpp
---
