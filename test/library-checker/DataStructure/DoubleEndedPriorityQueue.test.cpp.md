---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/superstd/Multiset.hpp
    title: library/superstd/Multiset.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/double_ended_std::priority_queue
    links:
    - https://judge.yosupo.jp/problem/double_ended_std::priority_queue
  bundledCode: "#line 1 \"test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/double_ended_std::priority_queue\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/superstd/Multiset.hpp\"\ntemplate\
    \ <typename T> class Multiset {\n    using u32 = std::uint32_t;\n    u32 size_;\n\
    \n  public:\n    std::map<T, u32> m;\n\n    Multiset() : size_(0) {}\n\n    void\
    \ banpei() {\n        insert(std::numeric_limits<T>::max() / 2);\n        insert(std::numeric_limits<T>::min()\
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
    };\n#line 6 \"test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    Multistd::set<int> s;\n    s.scan(n);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int x;\n            std::cin >> x;\n            s.insert(x);\n\
    \        }\n        if (t == 1) {\n            int a = s.pick_mn();\n        \
    \    std::cout << a << \"\\n\";\n        }\n        if (t == 2) {\n          \
    \  int a = s.pick_mx();\n            std::cout << a << \"\\n\";\n        }\n \
    \   }\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/double_ended_std::priority_queue\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/superstd/Multiset.hpp\"\n\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    Multistd::set<int> s;\n    s.scan(n);\n\
    \    while (q--) {\n        int t;\n        std::cin >> t;\n        if (t == 0)\
    \ {\n            int x;\n            std::cin >> x;\n            s.insert(x);\n\
    \        }\n        if (t == 1) {\n            int a = s.pick_mn();\n        \
    \    std::cout << a << \"\\n\";\n        }\n        if (t == 2) {\n          \
    \  int a = s.pick_mx();\n            std::cout << a << \"\\n\";\n        }\n \
    \   }\n}"
  dependsOn:
  - library/superstd/Multiset.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
  requiredBy: []
  timestamp: '2025-11-11 01:03:47+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
- /verify/test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp.html
title: test/library-checker/DataStructure/DoubleEndedPriorityQueue.test.cpp
---
