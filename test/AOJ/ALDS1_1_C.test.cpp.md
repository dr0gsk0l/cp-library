---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/util/PrimeUtil.hpp
    title: library/util/PrimeUtil.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
    links:
    - https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C
  bundledCode: "#line 1 \"test/AOJ/ALDS1_1_C.test.cpp\"\n#define PROBLEM         \
    \                                                       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include <bits/stdc++.h>\n\n#line 2 \"library/util/PrimeUtil.hpp\"\n// \u5BA3\
    \u8A00\u306F\u30B0\u30ED\u30FC\u30D0\u30EB\u3067\u3059\u308B\n// https://twitter.com/climpet/status/1598974781138694144\n\
    \ntemplate <int MAX, bool PRIME_FACTOR = false, bool DIVISOR = false>\nclass PrimeUtil\
    \ {\n    using u32 = std::uint32_t;\n    using u64 = std::uint64_t;\n    using\
    \ PF = std::vector<std::pair<u32, int>>;\n\n    template <typename T> using ARR\
    \ = std::array<T, MAX + 1>;\n    template <typename T, bool F> using COND = std::conditional_t<F,\
    \ T, bool>;\n\n    ARR<bool> isP;\n    std::vector<u32> primes;\n    COND<ARR<PF>,\
    \ PRIME_FACTOR> prime_factors;\n    COND<ARR<std::vector<u32>>, DIVISOR> divisors;\
    \ // \u81EA\u660E\u306A\u7D04\u6570\u306F\u5165\u3089\u306A\u3044\n\n    static\
    \ u64 pow2(u64 a) { return a * a; }\n\n  public:\n    PrimeUtil() {\n        std::ranges::fill(isP,\
    \ true);\n        isP[0] = isP[1] = false;\n\n        primes.reserve(MAX / 10);\n\
    \        for (int i = 2; i <= MAX; i++) {\n            // \u7D04\u6570\u5217\u6319\
    \n            if constexpr (DIVISOR) {\n                for (int j = 2 * i; j\
    \ <= MAX; j += i)\n                    divisors[j].push_back(i);\n           \
    \ }\n            // \u30A8\u30E9\u30C8\u30B9\u30C6\u30CD\u30B9\u306E\u7BE9\n \
    \           if (!isP[i])\n                continue;\n            primes.push_back(i);\n\
    \            for (u64 j = pow2(i); j <= MAX; j += i)\n                isP[j] =\
    \ false;\n            // \u7D20\u56E0\u6570\u5206\u89E3\n            if constexpr\
    \ (PRIME_FACTOR) {\n                for (int j = i; j <= MAX; j += i)\n      \
    \              prime_factors[j].emplace_back(i, 1);\n                int limit\
    \ = MAX / i + 1;\n                for (u64 j = pow2(i); j <= MAX; j *= i) {\n\
    \                    for (int k = j; k <= MAX; k += j)\n                     \
    \   prime_factors[k].back().second++;\n                    if (j > limit)\n  \
    \                      break;\n                }\n            }\n        }\n \
    \   }\n\n    bool is_prime(u64 x) const {\n        if (x <= MAX)\n           \
    \ return isP[x];\n        for (int p : primes) {\n            if (pow2(p) > x)\n\
    \                return true;\n            if (x % p == 0)\n                return\
    \ false;\n        }\n        for (int p = primes.back() + 1; pow2(p) <= x; p++)\n\
    \            if (x % p == 0)\n                return false;\n        return true;\n\
    \    }\n\n    std::vector<u32> prime_list() const { return primes; }\n\n    //\
    \ \u7D20\u56E0\u6570\u5206\u89E3\n    PF prime_factor(u64 n) const {\n       \
    \ assert(n <= pow2(MAX));\n\n        if constexpr (PRIME_FACTOR)\n           \
    \ if (n <= MAX)\n                return prime_factor[n];\n        PF ret;\n  \
    \      for (u64 p : primes) {\n            if (p * p > n)\n                break;\n\
    \            if (n % p)\n                continue;\n            ret.emplace_back(p,\
    \ 0);\n            while (n % p == 0) {\n                ret.back().second++;\n\
    \                n /= p;\n            }\n        }\n\n        if (n > 1)\n   \
    \         ret.emplace_back(n, 1);\n\n        return ret;\n    }\n};\n#line 6 \"\
    test/AOJ/ALDS1_1_C.test.cpp\"\nPrimeUtil<1000000> PU;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    std::cin >> n;\n    int ans = 0;\n\
    \    while (n--) {\n        int a;\n        std::cin >> a;\n        ans += PU.is_prime(a);\n\
    \    }\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/util/PrimeUtil.hpp\"\nPrimeUtil<1000000>\
    \ PU;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    std::cin >> n;\n    int ans = 0;\n    while (n--) {\n      \
    \  int a;\n        std::cin >> a;\n        ans += PU.is_prime(a);\n    }\n   \
    \ std::cout << ans << std::endl;\n}"
  dependsOn:
  - library/util/PrimeUtil.hpp
  isVerificationFile: true
  path: test/AOJ/ALDS1_1_C.test.cpp
  requiredBy: []
  timestamp: '2024-07-08 08:43:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/AOJ/ALDS1_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/AOJ/ALDS1_1_C.test.cpp
- /verify/test/AOJ/ALDS1_1_C.test.cpp.html
title: test/AOJ/ALDS1_1_C.test.cpp
---
