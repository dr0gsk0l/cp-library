---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: build/pch/stdc++.hpp
    title: build/pch/stdc++.hpp
  - icon: ':warning:'
    path: library/template/base.hpp
    title: library/template/base.hpp
  - icon: ':warning:'
    path: library/template/macro.hpp
    title: library/template/macro.hpp
  - icon: ':warning:'
    path: library/template/type.hpp
    title: library/template/type.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/template/base.hpp\"\n#pragma GCC optimize(\"Ofast\"\
    )\n#include <bits/stdc++.h>\n#line 1 \"library/template/base.hpp\"\n#pragma GCC\
    \ optimize(\"Ofast\")\n#line 2 \"library/template/macro.hpp\"\n\n#define overload2(a,\
    \ b, c, ...) c\n#define overload3(a, b, c, d, ...) d\n#define overload4(a, b,\
    \ c, d, e, ...) e\n#define overload5(a, b, c, d, e, f, ...) f\n\n#define REP4(i,\
    \ s, n, d) for (int i = (s); i < (n); i += (d))\n#define REP3(i, s, n) REP4(i,\
    \ s, n, 1)\n#define REP2(i, n) REP3(i, 0, n)\n#define REP1(n) REP2(tomato, n)\n\
    #define REP(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)\n\
    \n#define RREP4(i, n, s, d) for (int i = (n)-1; i >= (s); i -= (d))\n#define RREP3(i,\
    \ n, s) RREP4(i, n, s, 1)\n#define RREP2(i, n) RREP3(i, n, 0)\n#define RREP1(n)\
    \ RREP2(tomato, n)\n#define RREP(...) overload4(__VA_ARGS__, RREP4, RREP3, RREP2,\
    \ RREP1)(__VA_ARGS__)\n\n#define FOR4(a, b, c, d, v) for (auto [a, b, c, d] :\
    \ v)\n#define FOR3(a, b, c, v) for (auto [a, b, c] : v)\n#define FOR2(a, b, v)\
    \ for (auto [a, b] : v)\n#define FOR1(a, v) for (auto a : v)\n#define FOR(...)\
    \ overload5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)\n\n#define AFOR4(a,\
    \ b, c, d, v) for (auto &[a, b, c, d] : v)\n#define AFOR3(a, b, c, v) for (auto\
    \ &[a, b, c] : v)\n#define AFOR2(a, b, v) for (auto &[a, b] : v)\n#define AFOR1(a,\
    \ v) for (auto &a : v)\n#define AFOR(...) overload5(__VA_ARGS__, AFOR4, AFOR3,\
    \ AFOR2, AFOR1)(__VA_ARGS__)\n\n#define CFOR4(a, b, c, d, v) for (const auto &[a,\
    \ b, c, d] : v)\n#define CFOR3(a, b, c, v) for (const auto &[a, b, c] : v)\n#define\
    \ CFOR2(a, b, v) for (const auto &[a, b] : v)\n#define CFOR1(a, v) for (const\
    \ auto &a : v)\n#define CFOR(...) overload5(__VA_ARGS__, CFOR4, CFOR3, CFOR2,\
    \ CFOR1)(__VA_ARGS__)\n\n#define ALL(v) v.begin(), v.end()\n#define RALL(v) v.rbegin(),\
    \ v.rend()\n#define SORT(v) std::sort(ALL(v))\n#define RSORT(v) std::sort(RALL(v))\n\
    #define REVERSE(v) std::reverse(ALL(v))\n#define UNIQUE(v) SORT(v), v.erase(std::unique(ALL(v)),\
    \ v.end())\n\n#define PFOR(v) for (bool f = true; (f ? std::exchange(f, false)\
    \ : std::next_permutation(ALL(v)));)\n#line 1 \"library/template/base.hpp\"\n\
    #pragma GCC optimize(\"Ofast\")\n#line 2 \"library/template/type.hpp\"\n\n#define\
    \ TYPE1(T) template <class T>\n#define TYPE2(T, U) template <class T, class U>\n\
    #define TYPE3(T, U, V) template <class T, class U, class V>\n#define TYPE4(T,\
    \ U, V, W) template <class T, class U, class V, class W>\n#define TYPE5(T, U,\
    \ V, W, X)                                                   \\\n    template\
    \ <class T, class U, class V, class W, class X>\n#define TYPE(...)           \
    \                                                   \\\n    overload5(__VA_ARGS__,\
    \ TYPE5, TYPE4, TYPE3, TYPE2, TYPE1)(__VA_ARGS__)\n#define TYPES1(T) template\
    \ <class... T>\n#define TYPES2(H, T) template <class H, class... T>\n#define TYPES(...)\
    \ overload2(__VA_ARGS__, TYPES2, TYPES1)(__VA_ARGS__)\n\nTYPE(T)\nusing vec<T>\
    \ = std::vector<T>;\nTYPE(T)\nusing vvec<T> = vec<vec<T>>;\nTYPE(T)\nusing vvvec<T>\
    \ = vec<vvec<T>>;\nTYPE(T)\nusing vvvvec<T> = vec<vvvec<T>>;\nTYPE(T)\nusing ptt<T>\
    \ = std::pair<T, T>;\nusing ll = long long;\nusing ld = long double;\nusing vi\
    \ = vec<int>;\nusing vvi = vvec<int>;\nusing vvvi = vvvec<int>;\nusing vvvvi =\
    \ vvvvec<int>;\nusing vll = vec<ll>;\nusing vvll = vvec<ll>;\nusing vvvll = vvvec<ll>;\n\
    using vvvvll = vvvvec<ll>;\nusing vs = vec<std::string>;\nusing pi = ptt<int>;\n\
    using pll = ptt<ll>;\n\nTYPE(T)\nusing pq = std::priority_queue<T>;\nTYPE(T)\n\
    using pqg = std::priority_queue<T, vec<T>, std::greater<T>>;\n#line 4 \"library/template/input.hpp\"\
    \n\nTYPES(T)\nvoid input(T &...a) { (std::cin >> ... >> a); }\n\n#define INPUT(T,\
    \ ...)                                                          \\\n    T __VA_ARGS__;\
    \                                                             \\\n    input(__VA_ARGS__);\n\
    \n#define INT(...) INPUT(int, __VA_ARGS__)\n#define STR(...) INPUT(std::string,\
    \ __VA_ARGS__)\n#define LL(...) INPUT(long long, __VA_ARGS__)\n#define CHR(...)\
    \ INPUT(char, __VA_ARGS__)\n#define DBL(...) INPUT(double, __VA_ARGS__)\n\n#define\
    \ VI2(n, v)                                                              \\\n\
    \    vi v(n);                                                                \
    \   \\\n    input(v);\n#define VI3(n, v, w)                                  \
    \                         \\\n    vi v(n), w(n);                             \
    \                                \\\n    input(v, w);\n#define VI4(n, v, w, x)\
    \                                                        \\\n    vi v(n), w(n),\
    \ x(n);                                                       \\\n    input(v,\
    \ w, x);\n#define VI(...) overload5(__VA_ARGS__, VI4, VI3, VI2)(__VA_ARGS__)\n\
    \n#define VLL2(n, v)                                                         \
    \    \\\n    vll v(n);                                                       \
    \           \\\n    input(v);\n#define VLL3(n, v, w)                         \
    \                                 \\\n    vll v(n), w(n);                    \
    \                                        \\\n    input(v, w);\n#define VLL4(n,\
    \ v, w, x)                                                       \\\n    vll v(n),\
    \ w(n), x(n);                                                      \\\n    input(v,\
    \ w, x);\n#define VLL(...) overload5(__VA_ARGS__, VLL4, VLL3, VLL2)(__VA_ARGS__)\n\
    \n#define VS2(n, v)                                                          \
    \    \\\n    vs v(n);                                                        \
    \           \\\n    input(v);\n#define VS3(n, v, w)                          \
    \                                 \\\n    vs v(n), w(n);                     \
    \                                        \\\n    input(v, w);\n#define VS4(n,\
    \ v, w, x)                                                        \\\n    vs v(n),\
    \ w(n), x(n);                                                       \\\n    input(v,\
    \ w, x);\n#define VS(...) overload5(__VA_ARGS__, VS4, VS3, VS2)(__VA_ARGS__)\n\
    \n#define VVI(n, m, v)                                                       \
    \    \\\n    vvi v(n, vi(m));                                                \
    \           \\\n    input(v);\n\n#define VVLL(n, m, v)                       \
    \                                   \\\n    vvll v(n, vll(m));               \
    \                                          \\\n    input(v);\n"
  code: "#include \"library/template/base.hpp\"\n#include \"library/template/macro.hpp\"\
    \n#include \"library/template/type.hpp\"\n\nTYPES(T)\nvoid input(T &...a) { (std::cin\
    \ >> ... >> a); }\n\n#define INPUT(T, ...)                                   \
    \                       \\\n    T __VA_ARGS__;                               \
    \                              \\\n    input(__VA_ARGS__);\n\n#define INT(...)\
    \ INPUT(int, __VA_ARGS__)\n#define STR(...) INPUT(std::string, __VA_ARGS__)\n\
    #define LL(...) INPUT(long long, __VA_ARGS__)\n#define CHR(...) INPUT(char, __VA_ARGS__)\n\
    #define DBL(...) INPUT(double, __VA_ARGS__)\n\n#define VI2(n, v)             \
    \                                                 \\\n    vi v(n);           \
    \                                                        \\\n    input(v);\n#define\
    \ VI3(n, v, w)                                                           \\\n\
    \    vi v(n), w(n);                                                          \
    \   \\\n    input(v, w);\n#define VI4(n, v, w, x)                            \
    \                            \\\n    vi v(n), w(n), x(n);                    \
    \                                   \\\n    input(v, w, x);\n#define VI(...) overload5(__VA_ARGS__,\
    \ VI4, VI3, VI2)(__VA_ARGS__)\n\n#define VLL2(n, v)                          \
    \                                   \\\n    vll v(n);                        \
    \                                          \\\n    input(v);\n#define VLL3(n,\
    \ v, w)                                                          \\\n    vll v(n),\
    \ w(n);                                                            \\\n    input(v,\
    \ w);\n#define VLL4(n, v, w, x)                                              \
    \         \\\n    vll v(n), w(n), x(n);                                      \
    \                \\\n    input(v, w, x);\n#define VLL(...) overload5(__VA_ARGS__,\
    \ VLL4, VLL3, VLL2)(__VA_ARGS__)\n\n#define VS2(n, v)                        \
    \                                      \\\n    vs v(n);                      \
    \                                             \\\n    input(v);\n#define VS3(n,\
    \ v, w)                                                           \\\n    vs v(n),\
    \ w(n);                                                             \\\n    input(v,\
    \ w);\n#define VS4(n, v, w, x)                                               \
    \         \\\n    vs v(n), w(n), x(n);                                       \
    \                \\\n    input(v, w, x);\n#define VS(...) overload5(__VA_ARGS__,\
    \ VS4, VS3, VS2)(__VA_ARGS__)\n\n#define VVI(n, m, v)                        \
    \                                   \\\n    vvi v(n, vi(m));                 \
    \                                          \\\n    input(v);\n\n#define VVLL(n,\
    \ m, v)                                                          \\\n    vvll\
    \ v(n, vll(m));                                                         \\\n \
    \   input(v);\n"
  dependsOn:
  - build/pch/stdc++.hpp
  - library/template/base.hpp
  - library/template/macro.hpp
  - library/template/type.hpp
  isVerificationFile: false
  path: library/template/input.hpp
  requiredBy: []
  timestamp: '2025-11-18 08:06:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/template/input.hpp
layout: document
redirect_from:
- /library/library/template/input.hpp
- /library/library/template/input.hpp.html
title: library/template/input.hpp
---
