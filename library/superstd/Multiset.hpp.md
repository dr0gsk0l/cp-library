---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
    title: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/superstd/Multiset.hpp\"\ntemplate <typename T> class\
    \ Multiset {\n    using u32 = std::uint32_t;\n    u32 size_;\n\n  public:\n  \
    \  std::map<T, u32> m;\n\n    Multiset() : size_(0) {}\n\n    void banpei() {\n\
    \        insert(std::numeric_limits<T>::max() / 2);\n        insert(std::numeric_limits<T>::min()\
    \ / 2);\n        size_ -= 2;\n    }\n\n    bool contains(const T &a) const { return\
    \ m.contains(a); }\n    u32 count(const T &a) { return contains(a) ? m[a] : 0;\
    \ }\n    u32 size() const { return size_; }\n    void clear() {\n        m.clear();\n\
    \        size_ = 0;\n    }\n\n    void insert(const T &a, u32 k = 1) {\n     \
    \   if (!k)\n            return;\n        m[a] += k;\n        size_ += k;\n  \
    \  }\n\n    void erase(const T &a) {\n        size_ -= count(a);\n        m.erase(a);\n\
    \    }\n    void erase_k(const T &a, u32 k = 1) {\n        if (count(a) <= k)\
    \ {\n            size_ -= count(a);\n            erase(a);\n        } else {\n\
    \            m[a] -= k;\n            size_ -= k;\n        }\n    }\n\n    T min_value()\
    \ const {\n        assert(size());\n        return m.begin()->first;\n    }\n\
    \    T max_value() const { // MaxValu\n        assert(size());\n        return\
    \ m.rbegin()->first;\n    }\n\n    T pick_min() { // \u30D4\u30AF\u30DF\u30F3\n\
    \        T res = min_value();\n        erase1(res);\n        return res;\n   \
    \ }\n    T pick_max() {\n        T res = max_value();\n        erase1(res);\n\
    \        return res;\n    }\n\n    T lt(const T &a) const {\n        assert(min_value()\
    \ < a);\n        return (--m.lower_bound(a))->first;\n    }\n    T leq(const T\
    \ &a) const {\n        assert(min_value() <= a);\n        return (--m.upper_bound(a))->first;\n\
    \    }\n    T gt(const T &a) const {\n        assert(max_value() > a);\n     \
    \   return upper_bound(a)->first;\n    }\n    T geq(const T &a) const {\n    \
    \    assert(max_value() >= a);\n        return lower_bound(a)->first;\n    }\n\
    };\n"
  code: "template <typename T> class Multiset {\n    using u32 = std::uint32_t;\n\
    \    u32 size_;\n\n  public:\n    std::map<T, u32> m;\n\n    Multiset() : size_(0)\
    \ {}\n\n    void banpei() {\n        insert(std::numeric_limits<T>::max() / 2);\n\
    \        insert(std::numeric_limits<T>::min() / 2);\n        size_ -= 2;\n   \
    \ }\n\n    bool contains(const T &a) const { return m.contains(a); }\n    u32\
    \ count(const T &a) { return contains(a) ? m[a] : 0; }\n    u32 size() const {\
    \ return size_; }\n    void clear() {\n        m.clear();\n        size_ = 0;\n\
    \    }\n\n    void insert(const T &a, u32 k = 1) {\n        if (!k)\n        \
    \    return;\n        m[a] += k;\n        size_ += k;\n    }\n\n    void erase(const\
    \ T &a) {\n        size_ -= count(a);\n        m.erase(a);\n    }\n    void erase_k(const\
    \ T &a, u32 k = 1) {\n        if (count(a) <= k) {\n            size_ -= count(a);\n\
    \            erase(a);\n        } else {\n            m[a] -= k;\n           \
    \ size_ -= k;\n        }\n    }\n\n    T min_value() const {\n        assert(size());\n\
    \        return m.begin()->first;\n    }\n    T max_value() const { // MaxValu\n\
    \        assert(size());\n        return m.rbegin()->first;\n    }\n\n    T pick_min()\
    \ { // \u30D4\u30AF\u30DF\u30F3\n        T res = min_value();\n        erase1(res);\n\
    \        return res;\n    }\n    T pick_max() {\n        T res = max_value();\n\
    \        erase1(res);\n        return res;\n    }\n\n    T lt(const T &a) const\
    \ {\n        assert(min_value() < a);\n        return (--m.lower_bound(a))->first;\n\
    \    }\n    T leq(const T &a) const {\n        assert(min_value() <= a);\n   \
    \     return (--m.upper_bound(a))->first;\n    }\n    T gt(const T &a) const {\n\
    \        assert(max_value() > a);\n        return upper_bound(a)->first;\n   \
    \ }\n    T geq(const T &a) const {\n        assert(max_value() >= a);\n      \
    \  return lower_bound(a)->first;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/superstd/Multiset.hpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
documentation_of: library/superstd/Multiset.hpp
layout: document
redirect_from:
- /library/library/superstd/Multiset.hpp
- /library/library/superstd/Multiset.hpp.html
title: library/superstd/Multiset.hpp
---
