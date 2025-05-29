---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/superstd/Set.hpp
    title: library/superstd/Set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PredecessorProblem.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n#include\
    \ <bits/stdc++.h>\n\n#line 1 \"library/superstd/Set.hpp\"\ntemplate <typename\
    \ T> struct Set : std::set<T> {\n    using std::set<T>::size;\n    using std::set<T>::begin;\n\
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
    \ / 2);\n    }\n};\n#line 5 \"test/library-checker/DataStructure/PredecessorProblem.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n, q;\n    std::cin >> n >> q;\n    Set<int> se;\n    se.banpei();\n\
    \n    for (int i = 0; i < n; i++) {\n        char c;\n        std::cin >> c;\n\
    \        if (c == '1')\n            se.insert(i);\n    }\n\n    while (q--) {\n\
    \        int c, k;\n        std::cin >> c >> k;\n        if (c == 0)\n       \
    \     se.insert(k);\n        if (c == 1)\n            se.erase(k);\n        if\
    \ (c == 2)\n            std::cout << se.count(k) << \"\\n\";\n        if (c ==\
    \ 3) {\n            int x = se.geq(k);\n            std::cout << (x < n ? x :\
    \ -1) << \"\\n\";\n        }\n        if (c == 4) {\n            int x = se.leq(k);\n\
    \            std::cout << (x >= 0 ? x : -1) << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include <bits/stdc++.h>\n\n#include \"library/superstd/Set.hpp\"\n\nint main()\
    \ {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\n   \
    \ int n, q;\n    std::cin >> n >> q;\n    Set<int> se;\n    se.banpei();\n\n \
    \   for (int i = 0; i < n; i++) {\n        char c;\n        std::cin >> c;\n \
    \       if (c == '1')\n            se.insert(i);\n    }\n\n    while (q--) {\n\
    \        int c, k;\n        std::cin >> c >> k;\n        if (c == 0)\n       \
    \     se.insert(k);\n        if (c == 1)\n            se.erase(k);\n        if\
    \ (c == 2)\n            std::cout << se.count(k) << \"\\n\";\n        if (c ==\
    \ 3) {\n            int x = se.geq(k);\n            std::cout << (x < n ? x :\
    \ -1) << \"\\n\";\n        }\n        if (c == 4) {\n            int x = se.leq(k);\n\
    \            std::cout << (x >= 0 ? x : -1) << \"\\n\";\n        }\n    }\n}"
  dependsOn:
  - library/superstd/Set.hpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PredecessorProblem.test.cpp
  requiredBy: []
  timestamp: '2025-05-29 20:57:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PredecessorProblem.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp
- /verify/test/library-checker/DataStructure/PredecessorProblem.test.cpp.html
title: test/library-checker/DataStructure/PredecessorProblem.test.cpp
---
