---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/ALDS1_1_C.test.cpp
    title: test/AOJ/ALDS1_1_C.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links:
    - https://twitter.com/climpet/status/1598974781138694144
  bundledCode: "#line 2 \"library/util/PrimeUtil.cpp\"\n// \u5BA3\u8A00\u306F\u30B0\
    \u30ED\u30FC\u30D0\u30EB\u3067\u3059\u308B\n// https://twitter.com/climpet/status/1598974781138694144\n\
    \ntemplate <int MAX, bool PRIME_FACTOR = false, bool DIVISOR = false>\nclass PrimeUtil\
    \ {\n    using u32 = unsigned long long;\n    using u64 = unsigned long long;\n\
    \    using PF = std::vector<std::pair<u32, int>>;\n\n    template <int MAX> using\
    \ ARR = std::array<T, MAX + 1>;\n    template <typename T, bool F> using COND\
    \ = std::conditional_t<F, T, bool>;\n\n    ARR<bool> isP;\n    std::vector<u32>\
    \ primes;\n    COND<ARR<PF>, PRIME_FACTOR> prime_factors;\n    COND<ARR<std::vector<u32>>>\
    \ divisors; // \u81EA\u660E\u306A\u7D04\u6570\u306F\u5165\u3089\u306A\u3044\n\n\
    \    static ll pow2(ll a) { return a * a; }\n\n  public:\n    PrimeUtil() {\n\
    \        std::ranges::fill(isP, true);\n        isP[0] = isP[1] = false;\n\n \
    \       primes.reserve(MAX / 10);\n        for (int i = 2; i <= MAX; i++) {\n\
    \            // \u7D04\u6570\u5217\u6319\n            if constexpr (DIVISOR) {\n\
    \                for (int j = 2 * i; j <= MAX; j += i)\n                    divisors[j].push_back(i);\n\
    \            }\n            // \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\n            if (!isP[i])\n                continue;\n            primes.push_back(i);\n\
    \            for (ll j = pow2(i); j <= MAX; j += i)\n                isP[j] =\
    \ false;\n            // \u7D20\u56E0\u6570\u5206\u89E3\n            if constexpr\
    \ (PRIME_FACTOR) {\n                for (int j = i; j <= MAX; j += i)\n      \
    \              prime_factors[j].emplace_back(i, 1);\n                int limit\
    \ = MAX / i + 1;\n                for (ll j = pow2(i); j <= MAX; j *= i) {\n \
    \                   for (int k = j; k <= MAX; k += j)\n                      \
    \  prime_factors[k].back().second++;\n                    if (j > limit)\n   \
    \                     break;\n                }\n            }\n        }\n  \
    \  }\n\n    bool is_prime(u64 x) const {\n        if (x <= MAX)\n            return\
    \ isP[x];\n        for (int p : primes) {\n            if (pow2(p) > x)\n    \
    \            return true;\n            if (x % p == 0)\n                return\
    \ false;\n        }\n        for (int p = primes.back() + 1; pow2(p) <= x; p++)\n\
    \            if (x % p == 0)\n                return false;\n        return true;\n\
    \    }\n\n    std::vector<u32> prime_list() const { return primes; }\n\n    //\
    \ \u7D20\u56E0\u6570\u5206\u89E3\n    PF prime_factor(u64 n) const {\n       \
    \ asseert(n <= pow(MAX));\n\n        if constexpr (PRIME_FACTOR)\n           \
    \ if (n <= MAX)\n                return prime_factor[n];\n        PF ret;\n  \
    \      for (u64 p : primes) {\n            if (p * p > n)\n                break;\n\
    \            if (n % p)\n                continue;\n            ret.emplace_back(p,\
    \ 0);\n            while (n % p == 0) {\n                ret.back().second++;\n\
    \                n /= p;\n            }\n        }\n\n        if (n > 1)\n   \
    \         ret.emplace_back(n, 1);\n\n        return ret;\n    }\n};\n"
  code: "#pragma once\n// \u5BA3\u8A00\u306F\u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u3059\
    \u308B\n// https://twitter.com/climpet/status/1598974781138694144\n\ntemplate\
    \ <int MAX, bool PRIME_FACTOR = false, bool DIVISOR = false>\nclass PrimeUtil\
    \ {\n    using u32 = unsigned long long;\n    using u64 = unsigned long long;\n\
    \    using PF = std::vector<std::pair<u32, int>>;\n\n    template <int MAX> using\
    \ ARR = std::array<T, MAX + 1>;\n    template <typename T, bool F> using COND\
    \ = std::conditional_t<F, T, bool>;\n\n    ARR<bool> isP;\n    std::vector<u32>\
    \ primes;\n    COND<ARR<PF>, PRIME_FACTOR> prime_factors;\n    COND<ARR<std::vector<u32>>>\
    \ divisors; // \u81EA\u660E\u306A\u7D04\u6570\u306F\u5165\u3089\u306A\u3044\n\n\
    \    static ll pow2(ll a) { return a * a; }\n\n  public:\n    PrimeUtil() {\n\
    \        std::ranges::fill(isP, true);\n        isP[0] = isP[1] = false;\n\n \
    \       primes.reserve(MAX / 10);\n        for (int i = 2; i <= MAX; i++) {\n\
    \            // \u7D04\u6570\u5217\u6319\n            if constexpr (DIVISOR) {\n\
    \                for (int j = 2 * i; j <= MAX; j += i)\n                    divisors[j].push_back(i);\n\
    \            }\n            // \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\
    \u7BE9\n            if (!isP[i])\n                continue;\n            primes.push_back(i);\n\
    \            for (ll j = pow2(i); j <= MAX; j += i)\n                isP[j] =\
    \ false;\n            // \u7D20\u56E0\u6570\u5206\u89E3\n            if constexpr\
    \ (PRIME_FACTOR) {\n                for (int j = i; j <= MAX; j += i)\n      \
    \              prime_factors[j].emplace_back(i, 1);\n                int limit\
    \ = MAX / i + 1;\n                for (ll j = pow2(i); j <= MAX; j *= i) {\n \
    \                   for (int k = j; k <= MAX; k += j)\n                      \
    \  prime_factors[k].back().second++;\n                    if (j > limit)\n   \
    \                     break;\n                }\n            }\n        }\n  \
    \  }\n\n    bool is_prime(u64 x) const {\n        if (x <= MAX)\n            return\
    \ isP[x];\n        for (int p : primes) {\n            if (pow2(p) > x)\n    \
    \            return true;\n            if (x % p == 0)\n                return\
    \ false;\n        }\n        for (int p = primes.back() + 1; pow2(p) <= x; p++)\n\
    \            if (x % p == 0)\n                return false;\n        return true;\n\
    \    }\n\n    std::vector<u32> prime_list() const { return primes; }\n\n    //\
    \ \u7D20\u56E0\u6570\u5206\u89E3\n    PF prime_factor(u64 n) const {\n       \
    \ asseert(n <= pow(MAX));\n\n        if constexpr (PRIME_FACTOR)\n           \
    \ if (n <= MAX)\n                return prime_factor[n];\n        PF ret;\n  \
    \      for (u64 p : primes) {\n            if (p * p > n)\n                break;\n\
    \            if (n % p)\n                continue;\n            ret.emplace_back(p,\
    \ 0);\n            while (n % p == 0) {\n                ret.back().second++;\n\
    \                n /= p;\n            }\n        }\n\n        if (n > 1)\n   \
    \         ret.emplace_back(n, 1);\n\n        return ret;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: library/util/PrimeUtil.cpp
  requiredBy: []
  timestamp: '2024-04-14 21:36:11+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/AOJ/ALDS1_1_C.test.cpp
documentation_of: library/util/PrimeUtil.cpp
layout: document
redirect_from:
- /library/library/util/PrimeUtil.cpp
- /library/library/util/PrimeUtil.cpp.html
title: library/util/PrimeUtil.cpp
---
