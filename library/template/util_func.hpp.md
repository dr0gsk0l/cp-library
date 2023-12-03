---
data:
  _extendedDependsOn:
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
    )\n#include <bits/stdc++.h>\n#line 2 \"library/template/macro.hpp\"\n\n#define\
    \ overload2(a, b, c, ...) c\n#define overload3(a, b, c, d, ...) d\n#define overload4(a,\
    \ b, c, d, e, ...) e\n#define overload5(a, b, c, d, e, f, ...) f\n\n#define REP4(i,\
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
    \ V, W, X)                                                   \\\n  template <class\
    \ T, class U, class V, class W, class X>\n#define TYPE(...)                  \
    \                                            \\\n  overload5(__VA_ARGS__, TYPE5,\
    \ TYPE4, TYPE3, TYPE2, TYPE1)(__VA_ARGS__)\n#define TYPES1(T) template <class...\
    \ T>\n#define TYPES2(H, T) template <class H, class... T>\n#define TYPES(...)\
    \ overload2(__VA_ARGS__, TYPES2, TYPES1)(__VA_ARGS__)\n\nTYPE(T)\nusing vec<T>\
    \ = std::vector<T>;\nTYPE(T)\nusing vvec<T> = vec<vec<T>>;\nTYPE(T)\nusing vvvec<T>\
    \ = vec<vvec<T>>;\nTYPE(T)\nusing vvvvec<T> = vec<vvvec<T>>;\nTYPE(T)\nusing ptt<T>\
    \ = std::pair<T, T>;\nusing ll = long long;\nusing ld = long double;\nusing vi\
    \ = vec<int>;\nusing vvi = vvec<int>;\nusing vvvi = vvvec<int>;\nusing vvvvi =\
    \ vvvvec<int>;\nusing vll = vec<ll>;\nusing vvll = vvec<ll>;\nusing vvvll = vvvec<ll>;\n\
    using vvvvll = vvvvec<ll>;\nusing vs = vec<std::string>;\nusing pi = ptt<int>;\n\
    using pll = ptt<ll>;\n\nTYPE(T)\nusing pq = std::priority_queue<T>;\nTYPE(T)\n\
    using pqg = std::priority_queue<T, vec<T>, std::greater<T>>;\n#line 3 \"library/template/util_func.hpp\"\
    \n#pragma region queue\nTYPE(T)\nT pick(std::queue<T> &que) {\n  assert(que.size());\n\
    \  T a = que.front();\n  que.pop();\n  return a;\n}\nTYPE(T)\nT pick(pq<T> &que)\
    \ {\n  assert(que.size());\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    TYPE(T)\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\nTYPE(T)\nT pick(std::stack<T> &sta) {\n  assert(sta.size());\n\
    \  T a = sta.top();\n  sta.pop();\n  return a;\n}\nTYPE(T)\nvoid clear(T &v) {\
    \ v = decltype(v)(); }\n#pragma endregion\n#pragma region vec\nvi iota(int n)\
    \ {\n  vi a(n);\n  std::iota(ALL(a), 0);\n  return a;\n}\nTYPE(T)\nvoid add(vec<T>\
    \ &v, const T &a = 1) {\n  AFOR (p, v)\n    p += a;\n}\nTYPE(T)\nT rev(T a) {\n\
    \  REVERSE(a);\n  return a;\n}\n\nll sum(const vi &v) { return std::accumulate(ALL(v),\
    \ 0LL); }\nTYPE(T) T sum(const vec<T> &v) { return std::accumulate(ALL(v), T(0));\
    \ }\n\nTYPE(T, Ns)\nauto make_vector(T x, int n, Ns... ns) {\n  if constexpr (sizeof...(ns)\
    \ == 0)\n    return vector<T>(n, x);\n  else\n    return vector(n, make_vector<T>(x,\
    \ ns...));\n}\n#pragma endregion\n"
  code: "#include \"library/template/macro.hpp\"\n#include \"library/template/type.hpp\"\
    \n#pragma region queue\nTYPE(T)\nT pick(std::queue<T> &que) {\n  assert(que.size());\n\
    \  T a = que.front();\n  que.pop();\n  return a;\n}\nTYPE(T)\nT pick(pq<T> &que)\
    \ {\n  assert(que.size());\n  T a = que.top();\n  que.pop();\n  return a;\n}\n\
    TYPE(T)\nT pick(pqg<T> &que) {\n  assert(que.size());\n  T a = que.top();\n  que.pop();\n\
    \  return a;\n}\nTYPE(T)\nT pick(std::stack<T> &sta) {\n  assert(sta.size());\n\
    \  T a = sta.top();\n  sta.pop();\n  return a;\n}\nTYPE(T)\nvoid clear(T &v) {\
    \ v = decltype(v)(); }\n#pragma endregion\n#pragma region vec\nvi iota(int n)\
    \ {\n  vi a(n);\n  std::iota(ALL(a), 0);\n  return a;\n}\nTYPE(T)\nvoid add(vec<T>\
    \ &v, const T &a = 1) {\n  AFOR (p, v)\n    p += a;\n}\nTYPE(T)\nT rev(T a) {\n\
    \  REVERSE(a);\n  return a;\n}\n\nll sum(const vi &v) { return std::accumulate(ALL(v),\
    \ 0LL); }\nTYPE(T) T sum(const vec<T> &v) { return std::accumulate(ALL(v), T(0));\
    \ }\n\nTYPE(T, Ns)\nauto make_vector(T x, int n, Ns... ns) {\n  if constexpr (sizeof...(ns)\
    \ == 0)\n    return vector<T>(n, x);\n  else\n    return vector(n, make_vector<T>(x,\
    \ ns...));\n}\n#pragma endregion"
  dependsOn:
  - library/template/macro.hpp
  - library/template/base.hpp
  - library/template/type.hpp
  isVerificationFile: false
  path: library/template/util_func.hpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/template/util_func.hpp
layout: document
redirect_from:
- /library/library/template/util_func.hpp
- /library/library/template/util_func.hpp.html
title: library/template/util_func.hpp
---
