---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1077.test.cpp
    title: test/yukicoder/1077.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - "https://maspypy.com/slope-trick-1-\u89E3\u8AAC\u7DE8"
  bundledCode: "#line 1 \"library/datastructure/SlopeTrick.hpp\"\n// reference:https://maspypy.com/slope-trick-1-\u89E3\
    \u8AAC\u7DE8\ntemplate <typename T> class SlopeTrick {\n    static constexpr T\
    \ MIN = std::numeric_limits<T>::lowest() / 2;\n    static constexpr T MAX = std::numeric_limits<T>::max()\
    \ / 2;\n    std::priority_queue<T> L;\n    std::priority_queue<T, std::vector<T>,\
    \ std::greater<T>> R;\n    T add_l, add_r;\n\n    T L0() const { return L.size()\
    \ ? L.top() + add_l : MIN; }\n    T R0() const { return R.size() ? R.top() + add_r\
    \ : MAX; }\n    void push_L(T a) { L.push(a - add_l); }\n    void push_R(T a)\
    \ { R.push(a - add_r); }\n\n  public:\n    T min_f;\n    SlopeTrick() : add_l(0),\
    \ add_r(0), min_f(0) {}\n\n    int size() const { return L.size() + R.size();\
    \ }\n\n    std::tuple<T, T, T> get_min_range() const { return {L0(), R0(), min_f};\
    \ }\n\n    void operator+=(const T &a) { min_f += a; }\n\n    // (x-a)+\n    void\
    \ add_x_minus_a(T a) {\n        if (a < L0()) {\n            min_f += L0() - a;\n\
    \            push_R(L0());\n            L.pop();\n            push_L(a);\n   \
    \     } else\n            push_R(a);\n    }\n\n    // (a-x)+\n    void add_a_minus_x(T\
    \ a) {\n        if (a > R0()) {\n            min_f += a - R0();\n            push_L(R0());\n\
    \            R.pop();\n            push_R(a);\n        } else\n            push_L(a);\n\
    \    }\n\n    // |x-a|\n    void add_abs(T a) {\n        add_x_minus_a(a);\n \
    \       add_a_minus_x(a);\n    }\n\n    // \u5897\u52A0\u5074\u3092\u6D88\u3057\
    \u3066\u3001\u6E1B\u5C11\u5074\u306E\u307F\u306B\u3059\u308B\n    void clear_inc()\
    \ { R = {}; }\n    // \u6E1B\u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\
    \u5074\u306E\u307F\u306B\u3059\u308B\n    void clear_dec() { L = {}; }\n\n   \
    \ // g(x) = min_{x-b <= y <= x-a} f(y)\n    void sliding_window_minimum(const\
    \ T &a, const T &b) {\n        add_l += a;\n        add_r += b;\n    }\n\n   \
    \ void shift(const T &a) { sliding_window_minimum(a, a); }\n\n    // O(nlogn)\
    \ n=size\n    T operator()(T x) const {\n        T y = min_f;\n        if (x <\
    \ L0()) {\n            auto L_cpy = L;\n            while (L_cpy.size()) {\n \
    \               T a = L_cpy.top() + add_l;\n                L_cpy.pop();\n   \
    \             if (a <= x)\n                    break;\n                y += a\
    \ - x;\n            }\n        }\n        if (x > R0()) {\n            auto R_cpy\
    \ = R;\n            while (R_cpy.size()) {\n                T a = R_cpy.top()\
    \ + add_r;\n                R_cpy.pop();\n                if (x <= a)\n      \
    \              break;\n                y += x - a;\n            }\n        }\n\
    \        return y;\n    }\n\n    // O(mlog(n+m)) n=size,m=g.size()\n    SlopeTrick\
    \ &operator+=(SlopeTrick g) {\n        min_f += g.min_f;\n        while (g.L.size())\
    \ {\n            T a = g.L0();\n            g.L.pop();\n            add_a_minus_x(a);\n\
    \        }\n        while (g.R.size()) {\n            T a = g.R0();\n        \
    \    g.R.pop();\n            add_x_minus_a(a);\n        }\n        return *this;\n\
    \    }\n\n    SlopeTrick operator+(SlopeTrick g) const {\n        if (size() <\
    \ g.size())\n            return g += *this;\n        return (*this) += g;\n  \
    \  }\n};\n"
  code: "// reference:https://maspypy.com/slope-trick-1-\u89E3\u8AAC\u7DE8\ntemplate\
    \ <typename T> class SlopeTrick {\n    static constexpr T MIN = std::numeric_limits<T>::lowest()\
    \ / 2;\n    static constexpr T MAX = std::numeric_limits<T>::max() / 2;\n    std::priority_queue<T>\
    \ L;\n    std::priority_queue<T, std::vector<T>, std::greater<T>> R;\n    T add_l,\
    \ add_r;\n\n    T L0() const { return L.size() ? L.top() + add_l : MIN; }\n  \
    \  T R0() const { return R.size() ? R.top() + add_r : MAX; }\n    void push_L(T\
    \ a) { L.push(a - add_l); }\n    void push_R(T a) { R.push(a - add_r); }\n\n \
    \ public:\n    T min_f;\n    SlopeTrick() : add_l(0), add_r(0), min_f(0) {}\n\n\
    \    int size() const { return L.size() + R.size(); }\n\n    std::tuple<T, T,\
    \ T> get_min_range() const { return {L0(), R0(), min_f}; }\n\n    void operator+=(const\
    \ T &a) { min_f += a; }\n\n    // (x-a)+\n    void add_x_minus_a(T a) {\n    \
    \    if (a < L0()) {\n            min_f += L0() - a;\n            push_R(L0());\n\
    \            L.pop();\n            push_L(a);\n        } else\n            push_R(a);\n\
    \    }\n\n    // (a-x)+\n    void add_a_minus_x(T a) {\n        if (a > R0())\
    \ {\n            min_f += a - R0();\n            push_L(R0());\n            R.pop();\n\
    \            push_R(a);\n        } else\n            push_L(a);\n    }\n\n   \
    \ // |x-a|\n    void add_abs(T a) {\n        add_x_minus_a(a);\n        add_a_minus_x(a);\n\
    \    }\n\n    // \u5897\u52A0\u5074\u3092\u6D88\u3057\u3066\u3001\u6E1B\u5C11\u5074\
    \u306E\u307F\u306B\u3059\u308B\n    void clear_inc() { R = {}; }\n    // \u6E1B\
    \u5C11\u5074\u3092\u6D88\u3057\u3066\u3001\u5897\u52A0\u5074\u306E\u307F\u306B\
    \u3059\u308B\n    void clear_dec() { L = {}; }\n\n    // g(x) = min_{x-b <= y\
    \ <= x-a} f(y)\n    void sliding_window_minimum(const T &a, const T &b) {\n  \
    \      add_l += a;\n        add_r += b;\n    }\n\n    void shift(const T &a) {\
    \ sliding_window_minimum(a, a); }\n\n    // O(nlogn) n=size\n    T operator()(T\
    \ x) const {\n        T y = min_f;\n        if (x < L0()) {\n            auto\
    \ L_cpy = L;\n            while (L_cpy.size()) {\n                T a = L_cpy.top()\
    \ + add_l;\n                L_cpy.pop();\n                if (a <= x)\n      \
    \              break;\n                y += a - x;\n            }\n        }\n\
    \        if (x > R0()) {\n            auto R_cpy = R;\n            while (R_cpy.size())\
    \ {\n                T a = R_cpy.top() + add_r;\n                R_cpy.pop();\n\
    \                if (x <= a)\n                    break;\n                y +=\
    \ x - a;\n            }\n        }\n        return y;\n    }\n\n    // O(mlog(n+m))\
    \ n=size,m=g.size()\n    SlopeTrick &operator+=(SlopeTrick g) {\n        min_f\
    \ += g.min_f;\n        while (g.L.size()) {\n            T a = g.L0();\n     \
    \       g.L.pop();\n            add_a_minus_x(a);\n        }\n        while (g.R.size())\
    \ {\n            T a = g.R0();\n            g.R.pop();\n            add_x_minus_a(a);\n\
    \        }\n        return *this;\n    }\n\n    SlopeTrick operator+(SlopeTrick\
    \ g) const {\n        if (size() < g.size())\n            return g += *this;\n\
    \        return (*this) += g;\n    }\n};"
  dependsOn:
  - build/pch/stdc++.hpp
  isVerificationFile: false
  path: library/datastructure/SlopeTrick.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1077.test.cpp
documentation_of: library/datastructure/SlopeTrick.hpp
layout: document
redirect_from:
- /library/library/datastructure/SlopeTrick.hpp
- /library/library/datastructure/SlopeTrick.hpp.html
title: library/datastructure/SlopeTrick.hpp
---
