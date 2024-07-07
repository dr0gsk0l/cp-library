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
  bundledCode: "#line 1 \"library/mod/MintUtility.hpp\"\ntemplate <typename MINT>\
    \ class MintUtility {\n    std::vector<MINT> fact_ = {MINT::raw(1)};\n    std::vector<MINT>\
    \ inv_fact_{MINT::raw(1)};\n    int S = 1; // \u4ECA\u306E\u30B5\u30A4\u30BA\n\
    \n    void extend(const int n) {\n        if (n < S)\n            return;\n  \
    \      const int preS = S;\n        do {\n            S <<= 1;\n        } while\
    \ (S <= n);\n\n        fact_.resize(S);\n        for (int i = preS; i < S; i++)\n\
    \            fact_[i] = fact_[i - 1] * MINT::raw(i);\n\n        inv_fact_.resize(S);\n\
    \        inv_fact_.back() = fact_.back().inv();\n        for (int i = S - 1; i\
    \ > preS; i--)\n            inv_fact_[i - 1] = inv_fact_[i] * MINT::raw(i);\n\
    \    }\n\n  public:\n    MINT fact(const int n) {\n        assert(n >= 0);\n \
    \       extend(n);\n        return fact_[n];\n    }\n    MINT inv_fact(const int\
    \ n) {\n        assert(n >= 0);\n        extend(n);\n        return inv_fact_[n];\n\
    \    }\n    MINT nCk(const int n, const int k) {\n        if (k < 0 || n < k)\n\
    \            return MINT::raw(0);\n        extend(n);\n        return fact_[n]\
    \ * inv_fact_[k] * inv_fact_[n - k];\n    }\n    MINT nPk(const int n, const int\
    \ k) {\n        if (k < 0 || n < k)\n            return MINT::raw(0);\n      \
    \  extend(n);\n        return fact_[n] * inv_fact_[n - k];\n    }\n    MINT nHk(const\
    \ int n, const int k) {\n        return (n == 0 and k == 0 ? 1 : nCk(n + k - 1,\
    \ k));\n    }\n};\n"
  code: "template <typename MINT> class MintUtility {\n    std::vector<MINT> fact_\
    \ = {MINT::raw(1)};\n    std::vector<MINT> inv_fact_{MINT::raw(1)};\n    int S\
    \ = 1; // \u4ECA\u306E\u30B5\u30A4\u30BA\n\n    void extend(const int n) {\n \
    \       if (n < S)\n            return;\n        const int preS = S;\n       \
    \ do {\n            S <<= 1;\n        } while (S <= n);\n\n        fact_.resize(S);\n\
    \        for (int i = preS; i < S; i++)\n            fact_[i] = fact_[i - 1] *\
    \ MINT::raw(i);\n\n        inv_fact_.resize(S);\n        inv_fact_.back() = fact_.back().inv();\n\
    \        for (int i = S - 1; i > preS; i--)\n            inv_fact_[i - 1] = inv_fact_[i]\
    \ * MINT::raw(i);\n    }\n\n  public:\n    MINT fact(const int n) {\n        assert(n\
    \ >= 0);\n        extend(n);\n        return fact_[n];\n    }\n    MINT inv_fact(const\
    \ int n) {\n        assert(n >= 0);\n        extend(n);\n        return inv_fact_[n];\n\
    \    }\n    MINT nCk(const int n, const int k) {\n        if (k < 0 || n < k)\n\
    \            return MINT::raw(0);\n        extend(n);\n        return fact_[n]\
    \ * inv_fact_[k] * inv_fact_[n - k];\n    }\n    MINT nPk(const int n, const int\
    \ k) {\n        if (k < 0 || n < k)\n            return MINT::raw(0);\n      \
    \  extend(n);\n        return fact_[n] * inv_fact_[n - k];\n    }\n    MINT nHk(const\
    \ int n, const int k) {\n        return (n == 0 and k == 0 ? 1 : nCk(n + k - 1,\
    \ k));\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/MintUtility.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/MintUtility.hpp
layout: document
redirect_from:
- /library/library/mod/MintUtility.hpp
- /library/library/mod/MintUtility.hpp.html
title: library/mod/MintUtility.hpp
---
