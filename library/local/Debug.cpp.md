---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/local/Debug.cpp\"\ntemplate<typename T>\nostream&\
    \ operator<<(ostream&os,const set<T>&se){\n  if(se.size){\n    os<<\"{\";\n  \
    \  for(const auto&p:se)os<<p<<\",}\"[p==*se.rbegin()];\n  }\n  else os<<\"{}\"\
    ;\n  return os;\n}\n\ntemplate<typename T>\nostream& operator<<(ostream&os,const\
    \ unordered_set<T>&se){\n  os<<\"{\";\n  for(const auto&p:se)os<<p<<\",\";\n \
    \ os<<\"}\";\n  return os;\n}\n\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ map<T,U>&mp){\n  for(const auto&[key,val]:mp)os<<\"[\"<<key<<\":\"<<val<<\"\
    ]\";\n  return os;\n}\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ unordered_map<T,U>&mp){\n  for(const auto&[key,val]:mp)os<<\"[\"<<key<<\":\"\
    <<val<<\"]\";\n  return os;\n}\n\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ pair<T,U>&P){\n  os<<\"[\"<<P.first<<\",\"<<P.second<<\"]\";\n  return os;\n\
    }\n\n#  define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)\n\ntemplate\
    \ <class T, class... Args>\nvoid debug_internal(const char* s, T&& first, Args&&...\
    \ args) {\n    constexpr const char* open_brakets = sizeof...(args) == 0 ? \"\"\
    \ : \"(\";\n    constexpr const char* close_brakets = sizeof...(args) == 0 ? \"\
    \" : \")\";\n    std::cerr << open_brakets << s << close_brakets << \": \"\n \
    \             << open_brakets << std::forward<T>(first);\n    ((std::cerr << \"\
    , \" << std::forward<Args>(args)), ...);\n    std::cerr << close_brakets << endl;\n\
    }\n"
  code: "template<typename T>\nostream& operator<<(ostream&os,const set<T>&se){\n\
    \  if(se.size){\n    os<<\"{\";\n    for(const auto&p:se)os<<p<<\",}\"[p==*se.rbegin()];\n\
    \  }\n  else os<<\"{}\";\n  return os;\n}\n\ntemplate<typename T>\nostream& operator<<(ostream&os,const\
    \ unordered_set<T>&se){\n  os<<\"{\";\n  for(const auto&p:se)os<<p<<\",\";\n \
    \ os<<\"}\";\n  return os;\n}\n\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ map<T,U>&mp){\n  for(const auto&[key,val]:mp)os<<\"[\"<<key<<\":\"<<val<<\"\
    ]\";\n  return os;\n}\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ unordered_map<T,U>&mp){\n  for(const auto&[key,val]:mp)os<<\"[\"<<key<<\":\"\
    <<val<<\"]\";\n  return os;\n}\n\ntemplate<typename T,typename U>\nostream& operator<<(ostream&os,const\
    \ pair<T,U>&P){\n  os<<\"[\"<<P.first<<\",\"<<P.second<<\"]\";\n  return os;\n\
    }\n\n#  define debug(...) debug_internal(#__VA_ARGS__, __VA_ARGS__)\n\ntemplate\
    \ <class T, class... Args>\nvoid debug_internal(const char* s, T&& first, Args&&...\
    \ args) {\n    constexpr const char* open_brakets = sizeof...(args) == 0 ? \"\"\
    \ : \"(\";\n    constexpr const char* close_brakets = sizeof...(args) == 0 ? \"\
    \" : \")\";\n    std::cerr << open_brakets << s << close_brakets << \": \"\n \
    \             << open_brakets << std::forward<T>(first);\n    ((std::cerr << \"\
    , \" << std::forward<Args>(args)), ...);\n    std::cerr << close_brakets << endl;\n\
    }"
  dependsOn: []
  isVerificationFile: false
  path: library/local/Debug.cpp
  requiredBy: []
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/Debug.cpp
layout: document
redirect_from:
- /library/library/local/Debug.cpp
- /library/library/local/Debug.cpp.html
title: library/local/Debug.cpp
---
