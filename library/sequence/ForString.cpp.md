---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: library/sequence/AhoCorasick.cpp
    title: AhoCorasick
  - icon: ':heavy_check_mark:'
    path: library/sequence/RollingHash.cpp
    title: library/sequence/RollingHash.cpp
  - icon: ':question:'
    path: library/sequence/Trie.cpp
    title: library/sequence/Trie.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/2212.test.cpp
    title: test/AOJ/2212.test.cpp
  - icon: ':heavy_check_mark:'
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
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/sequence/ForString.cpp\"\ntemplate<char MARGIN>\n\
    struct ForString{\n  static constexpr char change(char c){ return c-MARGIN; }\n\
    \  static constexpr char restore(char a){ return a+MARGIN; }\n\n  static vector<char>\
    \ change(const string&s){\n    vector<char> v(s.size());\n    for(int i=0;i<s.size();i++)v[i]=change(s[i]);\n\
    \    return v;\n  }\n  static string restore(const vector<char>&v){\n    string\
    \ s(v.size(),'#');\n    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);\n    return\
    \ s;\n  }\n};\nstruct FSAa{\n  static constexpr char change(char c){ return c<='Z'?c-'A':26+c-'a';\
    \ }\n  static constexpr char restore(char a){ return a<26?'A':a-26+'a'; }\n  static\
    \ vector<char> change(const string&s){\n    vector<char> v(s.size());\n    for(int\
    \ i=0;i<s.size();i++)v[i]=change(s[i]);\n    return v;\n  }\n  static string restore(const\
    \ vector<char>&v){\n    string s(v.size(),'#');\n    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);\n\
    \    return s;\n  }\n};\nusing FSA=ForString<'A'>;\nusing FSa=ForString<'a'>;\n\
    using FS0=ForString<'0'>;\n\n#ifdef STR\n  #define STRA(s) STR(s##tomato);auto\
    \ s=FSA::change(s##tomato);\n  #define STRa(s) STR(s##tomato);auto s=FSa::change(s##tomato);\n\
    \  #define STR0(s) STR(s##tomato);auto s=FS0::change(s##tomato);\n#endif\n"
  code: "#pragma once\ntemplate<char MARGIN>\nstruct ForString{\n  static constexpr\
    \ char change(char c){ return c-MARGIN; }\n  static constexpr char restore(char\
    \ a){ return a+MARGIN; }\n\n  static vector<char> change(const string&s){\n  \
    \  vector<char> v(s.size());\n    for(int i=0;i<s.size();i++)v[i]=change(s[i]);\n\
    \    return v;\n  }\n  static string restore(const vector<char>&v){\n    string\
    \ s(v.size(),'#');\n    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);\n    return\
    \ s;\n  }\n};\nstruct FSAa{\n  static constexpr char change(char c){ return c<='Z'?c-'A':26+c-'a';\
    \ }\n  static constexpr char restore(char a){ return a<26?'A':a-26+'a'; }\n  static\
    \ vector<char> change(const string&s){\n    vector<char> v(s.size());\n    for(int\
    \ i=0;i<s.size();i++)v[i]=change(s[i]);\n    return v;\n  }\n  static string restore(const\
    \ vector<char>&v){\n    string s(v.size(),'#');\n    for(int i=0;i<v.size();i++)s[i]=restore(v[i]);\n\
    \    return s;\n  }\n};\nusing FSA=ForString<'A'>;\nusing FSa=ForString<'a'>;\n\
    using FS0=ForString<'0'>;\n\n#ifdef STR\n  #define STRA(s) STR(s##tomato);auto\
    \ s=FSA::change(s##tomato);\n  #define STRa(s) STR(s##tomato);auto s=FSa::change(s##tomato);\n\
    \  #define STR0(s) STR(s##tomato);auto s=FS0::change(s##tomato);\n#endif"
  dependsOn: []
  isVerificationFile: false
  path: library/sequence/ForString.cpp
  requiredBy:
  - library/sequence/AhoCorasick.cpp
  - library/sequence/RollingHash.cpp
  - library/sequence/Trie.cpp
  timestamp: '2023-12-03 16:05:20+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
  - test/AOJ/2212.test.cpp
  - test/yukicoder/430.test.cpp
  - test/yukicoder/430_2.test.cpp
documentation_of: library/sequence/ForString.cpp
layout: document
redirect_from:
- /library/library/sequence/ForString.cpp
- /library/library/sequence/ForString.cpp.html
title: library/sequence/ForString.cpp
---
