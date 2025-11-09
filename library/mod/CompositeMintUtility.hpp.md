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
  bundledCode: "#line 2 \"library/mod/CompositeMintUtility.hpp\"\n// set_mod \u3088\
    \u308A\u5F8C\u3067\u5BA3\u8A00\u3059\u308B\ntemplate <typename MINT> class MintUtility\
    \ {\n    std::vector<std::vector<MINT>> nCk_{std::vector<MINT>{1}};\n    int S\
    \ = 1;\n\n    void extend(const int n) {\n        if (n < S)\n            return;\n\
    \        const int preS = S;\n        do {\n            S <<= 1;\n        } while\
    \ (S <= n);\n\n        nCk_.resize(S);\n        for (int i = preS; i < S; i++)\
    \ {\n            nCk_[i].resize(i / 2 + 1);\n            nCk_[i][0] = 1;\n   \
    \         for (int j = 1; j <= i / 2; j++)\n                nCk_[i][j] = nCk_[i\
    \ - 1][min(j, i - 1 - j)] +\n                             nCk_[i - 1][min(j -\
    \ 1, i - 1 - (j - 1))];\n        }\n    }\n\n  public:\n    MINT nCk(int n, int\
    \ k) {\n        if (k < 0 || n < k)\n            return 0;\n        extend(n);\n\
    \        return nCk_[n][min(k, n - k)];\n    }\n};\n"
  code: "#pragma once\n// set_mod \u3088\u308A\u5F8C\u3067\u5BA3\u8A00\u3059\u308B\
    \ntemplate <typename MINT> class MintUtility {\n    std::vector<std::vector<MINT>>\
    \ nCk_{std::vector<MINT>{1}};\n    int S = 1;\n\n    void extend(const int n)\
    \ {\n        if (n < S)\n            return;\n        const int preS = S;\n  \
    \      do {\n            S <<= 1;\n        } while (S <= n);\n\n        nCk_.resize(S);\n\
    \        for (int i = preS; i < S; i++) {\n            nCk_[i].resize(i / 2 +\
    \ 1);\n            nCk_[i][0] = 1;\n            for (int j = 1; j <= i / 2; j++)\n\
    \                nCk_[i][j] = nCk_[i - 1][min(j, i - 1 - j)] +\n             \
    \                nCk_[i - 1][min(j - 1, i - 1 - (j - 1))];\n        }\n    }\n\
    \n  public:\n    MINT nCk(int n, int k) {\n        if (k < 0 || n < k)\n     \
    \       return 0;\n        extend(n);\n        return nCk_[n][min(k, n - k)];\n\
    \    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/CompositeMintUtility.hpp
  requiredBy: []
  timestamp: '2025-11-09 23:27:39+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/mod/CompositeMintUtility.hpp
layout: document
redirect_from:
- /library/library/mod/CompositeMintUtility.hpp
- /library/library/mod/CompositeMintUtility.hpp.html
title: library/mod/CompositeMintUtility.hpp
---
