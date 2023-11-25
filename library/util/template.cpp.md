---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/template.cpp\"\n\n\n// TYPES\n\n// macro\n\n\
    #ifdef __DEBUG\n#include <debug>\n#else\n#define debug(...) void(0)\n#endif\n\n\
    string YES(bool f = true) { return (f ? \"YES\" : \"NO\"); }\nstring Yes(bool\
    \ f = true) { return (f ? \"Yes\" : \"No\"); }\nstring yes(bool f = true) { return\
    \ (f ? \"yes\" : \"no\"); }\n\nconstexpr int INF = 1e9 + 7;\nconstexpr ll LINF\
    \ = ll(1e18) + 7;\nconstexpr ld EPS = 1e-10;\n\nTYPE(T)\nvector<pair<T, int>>\
    \ query_sort(const vector<T> &v) {\n  vector<pair<T, int>> res(v.size());\n  REP\
    \ (i, v.size())\n    res[i] = {v[i], i};\n  SORT(res);\n  return res;\n}\n\nTYPE(T)\n\
    bool chmax(T &a, T b) { return (a < b && (a = b, true)); }\nTYPE(T)\nbool chmin(T\
    \ &a, T b) { return (a > b && (a = b, true)); }\n\nbool in(const ll S, const int\
    \ a) { return (S >> a) & 1; }\nint popcount(const ll S) { return __builtin_popcountll(S);\
    \ }\nint digit(char c) { return (c >= '0' and c <= '9' ? c - '0' : -1); }\nll\
    \ sqrtll(ll a) {\n  for (ll b = sqrt(a); b * b <= a; b++)\n    if (b * b == a)\n\
    \      return b;\n  for (ll b = sqrt(a); b >= 0 and b * b >= a; b--)\n    if (b\
    \ * b == a)\n      return b;\n  return -1;\n}\n"
  code: "\n\n// TYPES\n\n// macro\n\n#ifdef __DEBUG\n#include <debug>\n#else\n#define\
    \ debug(...) void(0)\n#endif\n\nstring YES(bool f = true) { return (f ? \"YES\"\
    \ : \"NO\"); }\nstring Yes(bool f = true) { return (f ? \"Yes\" : \"No\"); }\n\
    string yes(bool f = true) { return (f ? \"yes\" : \"no\"); }\n\nconstexpr int\
    \ INF = 1e9 + 7;\nconstexpr ll LINF = ll(1e18) + 7;\nconstexpr ld EPS = 1e-10;\n\
    \nTYPE(T)\nvector<pair<T, int>> query_sort(const vector<T> &v) {\n  vector<pair<T,\
    \ int>> res(v.size());\n  REP (i, v.size())\n    res[i] = {v[i], i};\n  SORT(res);\n\
    \  return res;\n}\n\nTYPE(T)\nbool chmax(T &a, T b) { return (a < b && (a = b,\
    \ true)); }\nTYPE(T)\nbool chmin(T &a, T b) { return (a > b && (a = b, true));\
    \ }\n\nbool in(const ll S, const int a) { return (S >> a) & 1; }\nint popcount(const\
    \ ll S) { return __builtin_popcountll(S); }\nint digit(char c) { return (c >=\
    \ '0' and c <= '9' ? c - '0' : -1); }\nll sqrtll(ll a) {\n  for (ll b = sqrt(a);\
    \ b * b <= a; b++)\n    if (b * b == a)\n      return b;\n  for (ll b = sqrt(a);\
    \ b >= 0 and b * b >= a; b--)\n    if (b * b == a)\n      return b;\n  return\
    \ -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/template.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:03:31+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/template.cpp
layout: document
redirect_from:
- /library/library/util/template.cpp
- /library/library/util/template.cpp.html
title: library/util/template.cpp
---
