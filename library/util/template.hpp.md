---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/util/template.hpp\"\n\n\n// TYPES\n\n// macro\n\n\
    #ifdef __DEBUG\n#include <debug>\n#else\n#define debug(...) void(0)\n#endif\n\n\
    std::string YES(bool f = true) { return (f ? \"YES\" : \"NO\"); }\nstd::string\
    \ Yes(bool f = true) { return (f ? \"Yes\" : \"No\"); }\nstd::string yes(bool\
    \ f = true) { return (f ? \"yes\" : \"no\"); }\n\nconstexpr int INF = 1e9 + 7;\n\
    constexpr ll LINF = ll(1e18) + 7;\nconstexpr ld EPS = 1e-10;\n\nTYPE(T)\nstd::vector<std::pair<T,\
    \ int>> query_sort(const std::vector<T> &v) {\n    std::vector<std::pair<T, int>>\
    \ res(v.size());\n    REP (i, v.size())\n        res[i] = {v[i], i};\n    SORT(res);\n\
    \    return res;\n}\n\nTYPE(T)\nbool chmax(T &a, T b) { return (a < b && (a =\
    \ b, true)); }\nTYPE(T)\nbool chmin(T &a, T b) { return (a > b && (a = b, true));\
    \ }\n\nbool in(const ll S, const int a) { return (S >> a) & 1; }\nint popcount(const\
    \ ll S) { return __builtin_popcountll(S); }\nint digit(char c) { return (c >=\
    \ '0' and c <= '9' ? c - '0' : -1); }\nll sqrtll(ll a) {\n    for (ll b = sqrt(a);\
    \ b * b <= a; b++)\n        if (b * b == a)\n            return b;\n    for (ll\
    \ b = sqrt(a); b >= 0 and b * b >= a; b--)\n        if (b * b == a)\n        \
    \    return b;\n    return -1;\n}\n"
  code: "\n\n// TYPES\n\n// macro\n\n#ifdef __DEBUG\n#include <debug>\n#else\n#define\
    \ debug(...) void(0)\n#endif\n\nstd::string YES(bool f = true) { return (f ? \"\
    YES\" : \"NO\"); }\nstd::string Yes(bool f = true) { return (f ? \"Yes\" : \"\
    No\"); }\nstd::string yes(bool f = true) { return (f ? \"yes\" : \"no\"); }\n\n\
    constexpr int INF = 1e9 + 7;\nconstexpr ll LINF = ll(1e18) + 7;\nconstexpr ld\
    \ EPS = 1e-10;\n\nTYPE(T)\nstd::vector<std::pair<T, int>> query_sort(const std::vector<T>\
    \ &v) {\n    std::vector<std::pair<T, int>> res(v.size());\n    REP (i, v.size())\n\
    \        res[i] = {v[i], i};\n    SORT(res);\n    return res;\n}\n\nTYPE(T)\n\
    bool chmax(T &a, T b) { return (a < b && (a = b, true)); }\nTYPE(T)\nbool chmin(T\
    \ &a, T b) { return (a > b && (a = b, true)); }\n\nbool in(const ll S, const int\
    \ a) { return (S >> a) & 1; }\nint popcount(const ll S) { return __builtin_popcountll(S);\
    \ }\nint digit(char c) { return (c >= '0' and c <= '9' ? c - '0' : -1); }\nll\
    \ sqrtll(ll a) {\n    for (ll b = sqrt(a); b * b <= a; b++)\n        if (b * b\
    \ == a)\n            return b;\n    for (ll b = sqrt(a); b >= 0 and b * b >= a;\
    \ b--)\n        if (b * b == a)\n            return b;\n    return -1;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/template.hpp
  requiredBy: []
  timestamp: '2025-11-16 20:55:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/template.hpp
layout: document
redirect_from:
- /library/library/util/template.hpp
- /library/library/util/template.hpp.html
title: library/util/template.hpp
---
