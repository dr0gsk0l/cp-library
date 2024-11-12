---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/mod/Modint61.hpp
    title: library/mod/Modint61.hpp
  - icon: ':question:'
    path: library/sequence/ForString.hpp
    title: library/sequence/ForString.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ library/sequence/RollingHash.hpp: line 2: #pragma once found in a non-first\
    \ line\n"
  code: "// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6\n#pragma\
    \ once\n#include \"library/mod/Modint61.hpp\"\n#include \"library/sequence/ForString.hpp\"\
    \n\n#include <random>\n#include <vector>\n\nstd::random_device rollonghash_rnd;\n\
    std::mt19937 rollonghash_mt(rollonghash_rnd());\n\ntemplate <typename CHAR = char,\
    \ typename MINT = Modint61> class RollingHash {\n    using ll = long long;\n \
    \   static constexpr ll mod = (1LL << 61) - 1;\n    // using T = conditional_t<\
    \ less<ll>(mod,ll(\n    // std::numeric_limits<int>::max())), int, ll>;\n    using\
    \ T = ll;\n    inline static const MINT base = MINT::raw(rollonghash_mt() % (mod\
    \ - 2) + 2);\n\n    int n;\n    std::vector<MINT> hash;\n\n  public:\n    static\
    \ std::vector<MINT> power;\n\n    RollingHash() = default;\n    RollingHash(const\
    \ std::vector<CHAR> &v) : n(v.size()), hash(n + 1, 0) {\n        if (!power.size())\n\
    \            power.push_back(1);\n        for (int i = 0; i < n; i++)\n      \
    \      hash[i + 1] = nxt_hash(hash[i], v[i]);\n\n        if (power.size() <= n)\
    \ {\n            int sz = std::max(int(2 * power.size()), n + 1);\n          \
    \  power.reserve(sz);\n            while (power.size() < sz)\n               \
    \ power.push_back(power.back() * base);\n        }\n    }\n\n    static MINT nxt_hash(MINT\
    \ x, CHAR c) { return (x * base) + MINT::raw(c); }\n\n    T get_hash(int l = 0,\
    \ int r = -1) {\n        if (r < 0)\n            r = n;\n        return (hash[r]\
    \ - hash[l] * power[r - l]).v;\n    }\n\n    static T full_hash(const std::vector<CHAR>\
    \ &v) {\n        MINT res = 0;\n        for (const char &c : v)\n            res\
    \ = nxt_hash(res, c);\n        return res.v;\n    }\n};"
  dependsOn:
  - library/mod/Modint61.hpp
  - library/sequence/ForString.hpp
  isVerificationFile: false
  path: library/sequence/RollingHash.hpp
  requiredBy: []
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: library/sequence/RollingHash.hpp
layout: document
redirect_from:
- /library/library/sequence/RollingHash.hpp
- /library/library/sequence/RollingHash.hpp.html
title: library/sequence/RollingHash.hpp
---
