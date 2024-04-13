---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/sequence/AhoCorasick.cpp
    title: AhoCorasick
  - icon: ':x:'
    path: library/sequence/RollingHash.cpp
    title: library/sequence/RollingHash.cpp
  - icon: ':x:'
    path: library/sequence/Trie.cpp
    title: library/sequence/Trie.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':x:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  - icon: ':x:'
    path: test/yukicoder/430_2.test.cpp
    title: test/yukicoder/430_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/ForString.cpp\"\ntemplate <char MARGIN>\
    \ struct ForString {\n    static constexpr char change(char c) { return c - MARGIN;\
    \ }\n    static constexpr char restore(char a) { return a + MARGIN; }\n\n    static\
    \ std::vector<char> change(const string &s) {\n        std::vector<char> v(s.size());\n\
    \        for (int i = 0; i < s.size(); i++)\n            v[i] = change(s[i]);\n\
    \        return v;\n    }\n    static string restore(const std::vector<char> &v)\
    \ {\n        string s(v.size(), '#');\n        for (int i = 0; i < v.size(); i++)\n\
    \            s[i] = restore(v[i]);\n        return s;\n    }\n};\nstruct FSAa\
    \ {\n    static constexpr char change(char c) {\n        return c <= 'Z' ? c -\
    \ 'A' : 26 + c - 'a';\n    }\n    static constexpr char restore(char a) {\n  \
    \      return a < 26 ? 'A' : a - 26 + 'a';\n    }\n    static std::vector<char>\
    \ change(const string &s) {\n        std::vector<char> v(s.size());\n        for\
    \ (int i = 0; i < s.size(); i++)\n            v[i] = change(s[i]);\n        return\
    \ v;\n    }\n    static string restore(const std::vector<char> &v) {\n       \
    \ string s(v.size(), '#');\n        for (int i = 0; i < v.size(); i++)\n     \
    \       s[i] = restore(v[i]);\n        return s;\n    }\n};\nusing FSA = ForString<'A'>;\n\
    using FSa = ForString<'a'>;\nusing FS0 = ForString<'0'>;\n\n#ifdef STR\n#define\
    \ STRA(s)                                                                \\\n\
    \    STR(s##tomato);                                                         \
    \   \\\n    auto s = FSA::change(s##tomato);\n#define STRa(s)                \
    \                                                \\\n    STR(s##tomato);     \
    \                                                       \\\n    auto s = FSa::change(s##tomato);\n\
    #define STR0(s)                                                              \
    \  \\\n    STR(s##tomato);                                                   \
    \         \\\n    auto s = FS0::change(s##tomato);\n#endif\n"
  code: "#pragma once\ntemplate <char MARGIN> struct ForString {\n    static constexpr\
    \ char change(char c) { return c - MARGIN; }\n    static constexpr char restore(char\
    \ a) { return a + MARGIN; }\n\n    static std::vector<char> change(const string\
    \ &s) {\n        std::vector<char> v(s.size());\n        for (int i = 0; i < s.size();\
    \ i++)\n            v[i] = change(s[i]);\n        return v;\n    }\n    static\
    \ string restore(const std::vector<char> &v) {\n        string s(v.size(), '#');\n\
    \        for (int i = 0; i < v.size(); i++)\n            s[i] = restore(v[i]);\n\
    \        return s;\n    }\n};\nstruct FSAa {\n    static constexpr char change(char\
    \ c) {\n        return c <= 'Z' ? c - 'A' : 26 + c - 'a';\n    }\n    static constexpr\
    \ char restore(char a) {\n        return a < 26 ? 'A' : a - 26 + 'a';\n    }\n\
    \    static std::vector<char> change(const string &s) {\n        std::vector<char>\
    \ v(s.size());\n        for (int i = 0; i < s.size(); i++)\n            v[i] =\
    \ change(s[i]);\n        return v;\n    }\n    static string restore(const std::vector<char>\
    \ &v) {\n        string s(v.size(), '#');\n        for (int i = 0; i < v.size();\
    \ i++)\n            s[i] = restore(v[i]);\n        return s;\n    }\n};\nusing\
    \ FSA = ForString<'A'>;\nusing FSa = ForString<'a'>;\nusing FS0 = ForString<'0'>;\n\
    \n#ifdef STR\n#define STRA(s)                                                \
    \                \\\n    STR(s##tomato);                                     \
    \                       \\\n    auto s = FSA::change(s##tomato);\n#define STRa(s)\
    \                                                                \\\n    STR(s##tomato);\
    \                                                            \\\n    auto s =\
    \ FSa::change(s##tomato);\n#define STR0(s)                                   \
    \                             \\\n    STR(s##tomato);                        \
    \                                    \\\n    auto s = FS0::change(s##tomato);\n\
    #endif"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/ForString.cpp
  requiredBy:
  - library/sequence/AhoCorasick.cpp
  - library/sequence/Trie.cpp
  - library/sequence/RollingHash.cpp
  timestamp: '2024-04-13 17:39:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/430_2.test.cpp
  - test/yukicoder/430.test.cpp
  - test/AOJ/2212.test.cpp
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: library/sequence/ForString.cpp
layout: document
redirect_from:
- /library/library/sequence/ForString.cpp
- /library/library/sequence/ForString.cpp.html
title: library/sequence/ForString.cpp
---
