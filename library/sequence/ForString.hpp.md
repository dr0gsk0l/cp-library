---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/sequence/AhoCorasick.hpp
    title: library/sequence/AhoCorasick.hpp
  - icon: ':x:'
    path: library/sequence/RollingHash.hpp
    title: library/sequence/RollingHash.hpp
  - icon: ':heavy_check_mark:'
    path: library/sequence/Trie.hpp
    title: library/sequence/Trie.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':x:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430_2.test.cpp
    title: test/yukicoder/430_2.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/ForString.hpp\"\ntemplate <char MARGIN>\
    \ struct ForString {\n    static constexpr char change(char c) { return c - MARGIN;\
    \ }\n    static constexpr char restore(char a) { return a + MARGIN; }\n\n    static\
    \ std::vector<char> change(const std::string &s) {\n        std::vector<char>\
    \ v(s.size());\n        for (int i = 0; i < s.size(); i++)\n            v[i] =\
    \ change(s[i]);\n        return v;\n    }\n    static std::string restore(const\
    \ std::vector<char> &v) {\n        std::string s(v.size(), '#');\n        for\
    \ (int i = 0; i < v.size(); i++)\n            s[i] = restore(v[i]);\n        return\
    \ s;\n    }\n};\nstruct FSAa {\n    static constexpr char change(char c) {\n \
    \       return c <= 'Z' ? c - 'A' : 26 + c - 'a';\n    }\n    static constexpr\
    \ char restore(char a) {\n        return a < 26 ? 'A' : a - 26 + 'a';\n    }\n\
    \    static std::vector<char> change(const std::string &s) {\n        std::vector<char>\
    \ v(s.size());\n        for (int i = 0; i < s.size(); i++)\n            v[i] =\
    \ change(s[i]);\n        return v;\n    }\n    static std::string restore(const\
    \ std::vector<char> &v) {\n        std::string s(v.size(), '#');\n        for\
    \ (int i = 0; i < v.size(); i++)\n            s[i] = restore(v[i]);\n        return\
    \ s;\n    }\n};\nusing FSA = ForString<'A'>;\nusing FSa = ForString<'a'>;\nusing\
    \ FS0 = ForString<'0'>;\n\n#ifdef STR\n#define STRA(s)                       \
    \                                         \\\n    STR(s##tomato);            \
    \                                                \\\n    auto s = FSA::change(s##tomato);\n\
    #define STRa(s)                                                              \
    \  \\\n    STR(s##tomato);                                                   \
    \         \\\n    auto s = FSa::change(s##tomato);\n#define STR0(s)          \
    \                                                      \\\n    STR(s##tomato);\
    \                                                            \\\n    auto s =\
    \ FS0::change(s##tomato);\n#endif\n"
  code: "#pragma once\ntemplate <char MARGIN> struct ForString {\n    static constexpr\
    \ char change(char c) { return c - MARGIN; }\n    static constexpr char restore(char\
    \ a) { return a + MARGIN; }\n\n    static std::vector<char> change(const std::string\
    \ &s) {\n        std::vector<char> v(s.size());\n        for (int i = 0; i < s.size();\
    \ i++)\n            v[i] = change(s[i]);\n        return v;\n    }\n    static\
    \ std::string restore(const std::vector<char> &v) {\n        std::string s(v.size(),\
    \ '#');\n        for (int i = 0; i < v.size(); i++)\n            s[i] = restore(v[i]);\n\
    \        return s;\n    }\n};\nstruct FSAa {\n    static constexpr char change(char\
    \ c) {\n        return c <= 'Z' ? c - 'A' : 26 + c - 'a';\n    }\n    static constexpr\
    \ char restore(char a) {\n        return a < 26 ? 'A' : a - 26 + 'a';\n    }\n\
    \    static std::vector<char> change(const std::string &s) {\n        std::vector<char>\
    \ v(s.size());\n        for (int i = 0; i < s.size(); i++)\n            v[i] =\
    \ change(s[i]);\n        return v;\n    }\n    static std::string restore(const\
    \ std::vector<char> &v) {\n        std::string s(v.size(), '#');\n        for\
    \ (int i = 0; i < v.size(); i++)\n            s[i] = restore(v[i]);\n        return\
    \ s;\n    }\n};\nusing FSA = ForString<'A'>;\nusing FSa = ForString<'a'>;\nusing\
    \ FS0 = ForString<'0'>;\n\n#ifdef STR\n#define STRA(s)                       \
    \                                         \\\n    STR(s##tomato);            \
    \                                                \\\n    auto s = FSA::change(s##tomato);\n\
    #define STRa(s)                                                              \
    \  \\\n    STR(s##tomato);                                                   \
    \         \\\n    auto s = FSa::change(s##tomato);\n#define STR0(s)          \
    \                                                      \\\n    STR(s##tomato);\
    \                                                            \\\n    auto s =\
    \ FS0::change(s##tomato);\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/ForString.hpp
  requiredBy:
  - library/sequence/AhoCorasick.hpp
  - library/sequence/Trie.hpp
  - library/sequence/RollingHash.hpp
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
  - test/AOJ/2212.test.cpp
  - test/yukicoder/430_2.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: library/sequence/ForString.hpp
layout: document
redirect_from:
- /library/library/sequence/ForString.hpp
- /library/library/sequence/ForString.hpp.html
title: library/sequence/ForString.hpp
---
