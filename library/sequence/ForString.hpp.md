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
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/sequence/ForString.hpp
layout: document
redirect_from:
- /library/library/sequence/ForString.hpp
- /library/library/sequence/ForString.hpp.html
title: library/sequence/ForString.hpp
---
