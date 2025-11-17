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
  bundledCode: "#line 1 \"library/local/Debug.hpp\"\ntemplate <typename T>\nstd::ostream\
    \ &operator<<(std::ostream &os, const std::set<T> &se) {\n    if (se.size) {\n\
    \        os << \"{\";\n        for (const auto &p : se)\n            os << p <<\
    \ \",}\"[p == *se.rbegin()];\n    } else\n        os << \"{}\";\n    return os;\n\
    }\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream &os, const unordered_std::set<T>\
    \ &se) {\n    os << \"{\";\n    for (const auto &p : se)\n        os << p << \"\
    ,\";\n    os << \"}\";\n    return os;\n}\n\ntemplate <typename T, typename U>\n\
    std::ostream &operator<<(std::ostream &os, const std::map<T, U> &mp) {\n    for\
    \ (const auto &[key, val] : mp)\n        os << \"[\" << key << \":\" << val <<\
    \ \"]\";\n    return os;\n}\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const unordered_std::map<T, U> &mp) {\n    for (const auto &[key, val]\
    \ : mp)\n        os << \"[\" << key << \":\" << val << \"]\";\n    return os;\n\
    }\n\ntemplate <typename T, typename U>\nstd::ostream &operator<<(std::ostream\
    \ &os, const std::pair<T, U> &P) {\n    os << \"[\" << P.first << \",\" << P.second\
    \ << \"]\";\n    return os;\n}\n\n#define debug(...) debug_internal(#__VA_ARGS__,\
    \ __VA_ARGS__)\n\ntemplate <class T, class... Args>\nvoid debug_internal(const\
    \ char *s, T &&first, Args &&...args) {\n    constexpr const char *open_brakets\
    \ = sizeof...(args) == 0 ? \"\" : \"(\";\n    constexpr const char *close_brakets\
    \ = sizeof...(args) == 0 ? \"\" : \")\";\n    std::cerr << open_brakets << s <<\
    \ close_brakets << \": \" << open_brakets\n              << std::forward<T>(first);\n\
    \    ((std::cerr << \", \" << std::forward<Args>(args)), ...);\n    std::cerr\
    \ << close_brakets << std::endl;\n}\n"
  code: "template <typename T>\nstd::ostream &operator<<(std::ostream &os, const std::set<T>\
    \ &se) {\n    if (se.size) {\n        os << \"{\";\n        for (const auto &p\
    \ : se)\n            os << p << \",}\"[p == *se.rbegin()];\n    } else\n     \
    \   os << \"{}\";\n    return os;\n}\n\ntemplate <typename T>\nstd::ostream &operator<<(std::ostream\
    \ &os, const unordered_std::set<T> &se) {\n    os << \"{\";\n    for (const auto\
    \ &p : se)\n        os << p << \",\";\n    os << \"}\";\n    return os;\n}\n\n\
    template <typename T, typename U>\nstd::ostream &operator<<(std::ostream &os,\
    \ const std::map<T, U> &mp) {\n    for (const auto &[key, val] : mp)\n       \
    \ os << \"[\" << key << \":\" << val << \"]\";\n    return os;\n}\ntemplate <typename\
    \ T, typename U>\nstd::ostream &operator<<(std::ostream &os, const unordered_std::map<T,\
    \ U> &mp) {\n    for (const auto &[key, val] : mp)\n        os << \"[\" << key\
    \ << \":\" << val << \"]\";\n    return os;\n}\n\ntemplate <typename T, typename\
    \ U>\nstd::ostream &operator<<(std::ostream &os, const std::pair<T, U> &P) {\n\
    \    os << \"[\" << P.first << \",\" << P.second << \"]\";\n    return os;\n}\n\
    \n#define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)\n\ntemplate <class\
    \ T, class... Args>\nvoid debug_internal(const char *s, T &&first, Args &&...args)\
    \ {\n    constexpr const char *open_brakets = sizeof...(args) == 0 ? \"\" : \"\
    (\";\n    constexpr const char *close_brakets = sizeof...(args) == 0 ? \"\" :\
    \ \")\";\n    std::cerr << open_brakets << s << close_brakets << \": \" << open_brakets\n\
    \              << std::forward<T>(first);\n    ((std::cerr << \", \" << std::forward<Args>(args)),\
    \ ...);\n    std::cerr << close_brakets << std::endl;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/local/Debug.hpp
  requiredBy: []
  timestamp: '2025-11-17 22:58:45+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/Debug.hpp
layout: document
redirect_from:
- /library/library/local/Debug.hpp
- /library/library/local/Debug.hpp.html
title: library/local/Debug.hpp
---
