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
  bundledCode: "#line 1 \"library/util/Subsequence.hpp\"\ntemplate <typename T, typename\
    \ U>\nT sparse_subsequence(const std::vector<U> &v) {\n    std::map<U, T> mp;\n\
    \    T res = 1;\n    for (const U &p : v) {\n        T tmp = res;\n        res\
    \ = res * 2 - mp[p];\n        mp[p] = tmp;\n    }\n    return res;\n}\ntemplate\
    \ <typename T, int SIZE> T subsequence(const std::vector<int> &v) {\n    std::vector<T>\
    \ memo(SIZE, 0);\n    T res = 1;\n    for (int p : v) {\n        T tmp = res;\n\
    \        res = res * 2 - memo[p];\n        memo[p] = tmp;\n    }\n    return res;\n\
    }\ntemplate <typename T> T subsequence_alphabet(const std::string &s) {\n    std::vector<int>\
    \ v;\n    v.reserve(s.size());\n    for (char c : s)\n        v.push_back(c -\
    \ (c <= 'Z' ? 'A' : 'a'));\n    return subsequence<T, 26>(v);\n}\n"
  code: "template <typename T, typename U>\nT sparse_subsequence(const std::vector<U>\
    \ &v) {\n    std::map<U, T> mp;\n    T res = 1;\n    for (const U &p : v) {\n\
    \        T tmp = res;\n        res = res * 2 - mp[p];\n        mp[p] = tmp;\n\
    \    }\n    return res;\n}\ntemplate <typename T, int SIZE> T subsequence(const\
    \ std::vector<int> &v) {\n    std::vector<T> memo(SIZE, 0);\n    T res = 1;\n\
    \    for (int p : v) {\n        T tmp = res;\n        res = res * 2 - memo[p];\n\
    \        memo[p] = tmp;\n    }\n    return res;\n}\ntemplate <typename T> T subsequence_alphabet(const\
    \ std::string &s) {\n    std::vector<int> v;\n    v.reserve(s.size());\n    for\
    \ (char c : s)\n        v.push_back(c - (c <= 'Z' ? 'A' : 'a'));\n    return subsequence<T,\
    \ 26>(v);\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/util/Subsequence.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/util/Subsequence.hpp
layout: document
redirect_from:
- /library/library/util/Subsequence.hpp
- /library/library/util/Subsequence.hpp.html
title: library/util/Subsequence.hpp
---
