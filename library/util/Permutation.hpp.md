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
  bundledCode: "#line 2 \"library/util/Permutation.hpp\"\n#define REP_(i, n) for (int\
    \ i = 0; i < (n); i++)\nstruct Perm {\n    using vi = std::vector<int>;\n    //\
    \ (v[i],i) \u3067\u5EA7\u5727\n    template <typename T> static vi make_perm(const\
    \ std::vector<T> &v) {\n        vi w = v;\n        std::ranges::sort(w);\n   \
    \     std::map<T, int> mp;\n        REP_(i, v.size()) if (!i or w[i - 1] != w[i])\
    \ mp[w[i]] = i;\n        REP_(i, v.size()) w[i] = mp[v[i]]++;\n        return\
    \ w;\n    }\n    // r[p[i]]=i;\n    static vi rev(const vi &p) {\n        assert(is_permutation(p));\n\
    \        auto res = p;\n        REP_(i, p.size()) res[p[i]] = i;\n        return\
    \ res;\n    }\n    // r[i] = p[q[i]]\n    static vi composite(const vi &p, const\
    \ vi &q) {\n        assert(p.size() == q.size());\n        assert(is_permutation(p));\n\
    \        assert(is_permutation(q));\n        auto res = p;\n        REP_(i, p.size())\
    \ res[i] = p[q[i]];\n        return res;\n    }\n    static std::vector<vi> divide_cycle(const\
    \ vi &p) {\n        assert(is_permutation(p));\n        int n = p.size();\n  \
    \      std::vector<bool> used(n, false);\n        std::vector<vi> res;\n     \
    \   for (int x : p) {\n            if (used[x])\n                continue;\n \
    \           used[x] = true;\n            res.emplace_back(vi{x});\n          \
    \  int now = p[x];\n            while (now != x) {\n                assert(!used[now]);\n\
    \                used[now] = true;\n                res.back().push_back(now);\n\
    \                now = p[now];\n            }\n        }\n        return res;\n\
    \    }\n    static bool is_permutation(const vi &p) {\n        int n = p.size();\n\
    \        std::vector<bool> used(n, false);\n        for (int x : p) {\n      \
    \      if (used[x])\n                return false;\n            used[x] = true;\n\
    \        }\n        return true;\n    }\n\n  private:\n    static void rearrange(const\
    \ vi &p) {}\n    template <typename T>\n    static void execute_rearrange(const\
    \ vi &p, std::vector<T> &v) {\n        assert(p.size() == v.size());\n       \
    \ auto w = v;\n        REP_(i, p.size()) w[i] = v[p[i]];\n        std::swap(v,\
    \ w);\n    }\n\n  public:\n    // v \u3092 (p[i],v[i]) \u3067\u306E\u6607\u9806\
    \u306B\u3059\u308B\n    template <typename Head, typename... Tail>\n    static\
    \ void rearrange(const vi &p, Head &v, Tail &...tail) {\n        execute_rearrange(p,\
    \ v);\n        rearrange(p, tail...);\n    }\n};\n#undef REP_\n"
  code: "#pragma once\n#define REP_(i, n) for (int i = 0; i < (n); i++)\nstruct Perm\
    \ {\n    using vi = std::vector<int>;\n    // (v[i],i) \u3067\u5EA7\u5727\n  \
    \  template <typename T> static vi make_perm(const std::vector<T> &v) {\n    \
    \    vi w = v;\n        std::ranges::sort(w);\n        std::map<T, int> mp;\n\
    \        REP_(i, v.size()) if (!i or w[i - 1] != w[i]) mp[w[i]] = i;\n       \
    \ REP_(i, v.size()) w[i] = mp[v[i]]++;\n        return w;\n    }\n    // r[p[i]]=i;\n\
    \    static vi rev(const vi &p) {\n        assert(is_permutation(p));\n      \
    \  auto res = p;\n        REP_(i, p.size()) res[p[i]] = i;\n        return res;\n\
    \    }\n    // r[i] = p[q[i]]\n    static vi composite(const vi &p, const vi &q)\
    \ {\n        assert(p.size() == q.size());\n        assert(is_permutation(p));\n\
    \        assert(is_permutation(q));\n        auto res = p;\n        REP_(i, p.size())\
    \ res[i] = p[q[i]];\n        return res;\n    }\n    static std::vector<vi> divide_cycle(const\
    \ vi &p) {\n        assert(is_permutation(p));\n        int n = p.size();\n  \
    \      std::vector<bool> used(n, false);\n        std::vector<vi> res;\n     \
    \   for (int x : p) {\n            if (used[x])\n                continue;\n \
    \           used[x] = true;\n            res.emplace_back(vi{x});\n          \
    \  int now = p[x];\n            while (now != x) {\n                assert(!used[now]);\n\
    \                used[now] = true;\n                res.back().push_back(now);\n\
    \                now = p[now];\n            }\n        }\n        return res;\n\
    \    }\n    static bool is_permutation(const vi &p) {\n        int n = p.size();\n\
    \        std::vector<bool> used(n, false);\n        for (int x : p) {\n      \
    \      if (used[x])\n                return false;\n            used[x] = true;\n\
    \        }\n        return true;\n    }\n\n  private:\n    static void rearrange(const\
    \ vi &p) {}\n    template <typename T>\n    static void execute_rearrange(const\
    \ vi &p, std::vector<T> &v) {\n        assert(p.size() == v.size());\n       \
    \ auto w = v;\n        REP_(i, p.size()) w[i] = v[p[i]];\n        std::swap(v,\
    \ w);\n    }\n\n  public:\n    // v \u3092 (p[i],v[i]) \u3067\u306E\u6607\u9806\
    \u306B\u3059\u308B\n    template <typename Head, typename... Tail>\n    static\
    \ void rearrange(const vi &p, Head &v, Tail &...tail) {\n        execute_rearrange(p,\
    \ v);\n        rearrange(p, tail...);\n    }\n};\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/util/Permutation.hpp
  requiredBy: []
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/Permutation.hpp
layout: document
redirect_from:
- /library/library/util/Permutation.hpp
- /library/library/util/Permutation.hpp.html
title: library/util/Permutation.hpp
---
