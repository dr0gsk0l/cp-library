---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1097.test.cpp
    title: test/yukicoder/1097.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/datastructure/Doubling.cpp\"\ntemplate <typename\
    \ Monoid, int LOG> class Doubling {\n    using X = typename Monoid::value_type;\n\
    \    int n;\n    bool is_prepared;\n\n    using P = std::pair<int, X>;\n    static\
    \ constexpr P unit = {-1, Monoid::unit()};\n    std::vector<std::vector<P>> DP;\n\
    \n    // a \u304B\u3089 2^k \u52D5\u304F\n    P k_move(const P &a, int k) {\n\
    \        if (a.first == -1)\n            return a;\n        const auto [now, val]\
    \ = a;\n        const auto [nxt, cost] = DP[k][now];\n        return {nxt, Monoid::op(val,\
    \ cost)};\n    }\n\n    void build() {\n        is_prepared = true;\n        for\
    \ (int k = 0; k < LOG - 1; k++)\n            for (int v = 0; v < n; v++)\n   \
    \             DP[k + 1][v] = k_move(DP[k][v], k);\n    }\n\n  public:\n    Doubling(int\
    \ n) : n(n), is_prepared(false) {\n        DP.assign(LOG, std::vector<P>(n, unit));\n\
    \    }\n\n    void add_arc(int from, int to, X x) {\n        assert(!is_prepared);\n\
    \        assert(-1 <= to and to < n);\n        DP[0][from] = {to, x};\n    }\n\
    \n    // [\u7D42\u70B9,\u5024] \u8FBA\u304C\u51FA\u3066\u306A\u3044\u5834\u6240\
    \u304B\u3089\u79FB\u52D5\u3059\u308B\u5834\u5408\u306F -1 \u306B\u7740\u304F\n\
    \    P calc(int s, long long step) {\n        assert(step <= (1LL << LOG));\n\
    \        if (!is_prepared)\n            build();\n\n        P res{s, Monoid::unit()};\n\
    \        for (int k = 0; step; k++, step >>= 1)\n            if (step & 1)\n \
    \               res = k_move(res, k);\n        return res;\n    }\n};\n"
  code: "template <typename Monoid, int LOG> class Doubling {\n    using X = typename\
    \ Monoid::value_type;\n    int n;\n    bool is_prepared;\n\n    using P = std::pair<int,\
    \ X>;\n    static constexpr P unit = {-1, Monoid::unit()};\n    std::vector<std::vector<P>>\
    \ DP;\n\n    // a \u304B\u3089 2^k \u52D5\u304F\n    P k_move(const P &a, int\
    \ k) {\n        if (a.first == -1)\n            return a;\n        const auto\
    \ [now, val] = a;\n        const auto [nxt, cost] = DP[k][now];\n        return\
    \ {nxt, Monoid::op(val, cost)};\n    }\n\n    void build() {\n        is_prepared\
    \ = true;\n        for (int k = 0; k < LOG - 1; k++)\n            for (int v =\
    \ 0; v < n; v++)\n                DP[k + 1][v] = k_move(DP[k][v], k);\n    }\n\
    \n  public:\n    Doubling(int n) : n(n), is_prepared(false) {\n        DP.assign(LOG,\
    \ std::vector<P>(n, unit));\n    }\n\n    void add_arc(int from, int to, X x)\
    \ {\n        assert(!is_prepared);\n        assert(-1 <= to and to < n);\n   \
    \     DP[0][from] = {to, x};\n    }\n\n    // [\u7D42\u70B9,\u5024] \u8FBA\u304C\
    \u51FA\u3066\u306A\u3044\u5834\u6240\u304B\u3089\u79FB\u52D5\u3059\u308B\u5834\
    \u5408\u306F -1 \u306B\u7740\u304F\n    P calc(int s, long long step) {\n    \
    \    assert(step <= (1LL << LOG));\n        if (!is_prepared)\n            build();\n\
    \n        P res{s, Monoid::unit()};\n        for (int k = 0; step; k++, step >>=\
    \ 1)\n            if (step & 1)\n                res = k_move(res, k);\n     \
    \   return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/datastructure/Doubling.cpp
  requiredBy: []
  timestamp: '2024-04-15 22:22:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1097.test.cpp
documentation_of: library/datastructure/Doubling.cpp
layout: document
redirect_from:
- /library/library/datastructure/Doubling.cpp
- /library/library/datastructure/Doubling.cpp.html
title: library/datastructure/Doubling.cpp
---
