---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/template/base.hpp
    title: library/template/base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/template/input.hpp
    title: library/template/input.hpp
  - icon: ':warning:'
    path: library/template/util_func.hpp
    title: library/template/util_func.hpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 1 "library/template/base.hpp"

    #pragma GCC optimize("Ofast")

    #include <bits/stdc++.h>

    #line 2 "library/template/macro.hpp"


    #define overload2(a, b, c, ...) c

    #define overload3(a, b, c, d, ...) d

    #define overload4(a, b, c, d, e, ...) e

    #define overload5(a, b, c, d, e, f, ...) f


    #define REP4(i, s, n, d) for (int i = (s); i < (n); i += (d))

    #define REP3(i, s, n) REP4(i, s, n, 1)

    #define REP2(i, n) REP3(i, 0, n)

    #define REP1(n) REP2(tomato, n)

    #define REP(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)


    #define RREP4(i, n, s, d) for (int i = (n)-1; i >= (s); i -= (d))

    #define RREP3(i, n, s) RREP4(i, n, s, 1)

    #define RREP2(i, n) RREP3(i, n, 0)

    #define RREP1(n) RREP2(tomato, n)

    #define RREP(...) overload4(__VA_ARGS__, RREP4, RREP3, RREP2, RREP1)(__VA_ARGS__)


    #define FOR4(a, b, c, d, v) for (auto [a, b, c, d] : v)

    #define FOR3(a, b, c, v) for (auto [a, b, c] : v)

    #define FOR2(a, b, v) for (auto [a, b] : v)

    #define FOR1(a, v) for (auto a : v)

    #define FOR(...) overload5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)


    #define AFOR4(a, b, c, d, v) for (auto &[a, b, c, d] : v)

    #define AFOR3(a, b, c, v) for (auto &[a, b, c] : v)

    #define AFOR2(a, b, v) for (auto &[a, b] : v)

    #define AFOR1(a, v) for (auto &a : v)

    #define AFOR(...) overload5(__VA_ARGS__, AFOR4, AFOR3, AFOR2, AFOR1)(__VA_ARGS__)


    #define CFOR4(a, b, c, d, v) for (const auto &[a, b, c, d] : v)

    #define CFOR3(a, b, c, v) for (const auto &[a, b, c] : v)

    #define CFOR2(a, b, v) for (const auto &[a, b] : v)

    #define CFOR1(a, v) for (const auto &a : v)

    #define CFOR(...) overload5(__VA_ARGS__, CFOR4, CFOR3, CFOR2, CFOR1)(__VA_ARGS__)


    #define ALL(v) v.begin(), v.end()

    #define RALL(v) v.rbegin(), v.rend()

    #define SORT(v) std::sort(ALL(v))

    #define RSORT(v) std::sort(RALL(v))

    #define REVERSE(v) std::reverse(ALL(v))

    #define UNIQUE(v) SORT(v), v.erase(std::unique(ALL(v)), v.end())


    #define PFOR(v) for (bool f = true; (f ? std::exchange(f, false) : std::next_permutation(ALL(v)));)

    '
  code: '#include "library/template/base.hpp"


    #define overload2(a, b, c, ...) c

    #define overload3(a, b, c, d, ...) d

    #define overload4(a, b, c, d, e, ...) e

    #define overload5(a, b, c, d, e, f, ...) f


    #define REP4(i, s, n, d) for (int i = (s); i < (n); i += (d))

    #define REP3(i, s, n) REP4(i, s, n, 1)

    #define REP2(i, n) REP3(i, 0, n)

    #define REP1(n) REP2(tomato, n)

    #define REP(...) overload4(__VA_ARGS__, REP4, REP3, REP2, REP1)(__VA_ARGS__)


    #define RREP4(i, n, s, d) for (int i = (n)-1; i >= (s); i -= (d))

    #define RREP3(i, n, s) RREP4(i, n, s, 1)

    #define RREP2(i, n) RREP3(i, n, 0)

    #define RREP1(n) RREP2(tomato, n)

    #define RREP(...) overload4(__VA_ARGS__, RREP4, RREP3, RREP2, RREP1)(__VA_ARGS__)


    #define FOR4(a, b, c, d, v) for (auto [a, b, c, d] : v)

    #define FOR3(a, b, c, v) for (auto [a, b, c] : v)

    #define FOR2(a, b, v) for (auto [a, b] : v)

    #define FOR1(a, v) for (auto a : v)

    #define FOR(...) overload5(__VA_ARGS__, FOR4, FOR3, FOR2, FOR1)(__VA_ARGS__)


    #define AFOR4(a, b, c, d, v) for (auto &[a, b, c, d] : v)

    #define AFOR3(a, b, c, v) for (auto &[a, b, c] : v)

    #define AFOR2(a, b, v) for (auto &[a, b] : v)

    #define AFOR1(a, v) for (auto &a : v)

    #define AFOR(...) overload5(__VA_ARGS__, AFOR4, AFOR3, AFOR2, AFOR1)(__VA_ARGS__)


    #define CFOR4(a, b, c, d, v) for (const auto &[a, b, c, d] : v)

    #define CFOR3(a, b, c, v) for (const auto &[a, b, c] : v)

    #define CFOR2(a, b, v) for (const auto &[a, b] : v)

    #define CFOR1(a, v) for (const auto &a : v)

    #define CFOR(...) overload5(__VA_ARGS__, CFOR4, CFOR3, CFOR2, CFOR1)(__VA_ARGS__)


    #define ALL(v) v.begin(), v.end()

    #define RALL(v) v.rbegin(), v.rend()

    #define SORT(v) std::sort(ALL(v))

    #define RSORT(v) std::sort(RALL(v))

    #define REVERSE(v) std::reverse(ALL(v))

    #define UNIQUE(v) SORT(v), v.erase(std::unique(ALL(v)), v.end())


    #define PFOR(v) for (bool f = true; (f ? std::exchange(f, false) : std::next_permutation(ALL(v)));)

    '
  dependsOn:
  - library/template/base.hpp
  isVerificationFile: false
  path: library/template/macro.hpp
  requiredBy:
  - library/template/input.hpp
  - library/template/util_func.hpp
  timestamp: '2024-04-13 19:59:47+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/template/macro.hpp
layout: document
redirect_from:
- /library/library/template/macro.hpp
- /library/library/template/macro.hpp.html
title: library/template/macro.hpp
---
