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
  bundledCode: "#line 1 \"library/local/Distance.hpp\"\ntemplate <typename T> class\
    \ Distance {\n    std::map<T, int> d;\n    std::queue<T> que;\n\n  public:\n \
    \   // s \u304B\u3089\u7D42\u7AEF\u306B\u305F\u3069\u308A\u7740\u304F\u307E\u3067\
    \u306E\u8DDD\u96E2\n    template <typename F> int shortest_path(const F &f, const\
    \ T &s) {\n        if (d.count(s))\n            return d[s];\n        if (!f(s).size())\n\
    \            return d[s] = 0;\n        int res = 1e9;\n        for (const T &to\
    \ : f(s))\n            res = std::min(res, shortest_path(f, to) + 1);\n      \
    \  return d[s] = res;\n    }\n\n    // s \u304B\u3089\u306E\u6700\u77ED\u8DDD\u96E2\
    \u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n    template <typename\
    \ F>\n    std::vector<std::vector<T>> from_root(const F &f, const T &s,\n    \
    \                                      int MAX = 10) {\n        std::vector<std::vector<T>>\
    \ level(MAX + 1);\n        d[s] = 0;\n        que.push(s);\n        while (que.size())\
    \ {\n            T v = que.front();\n            que.pop();\n            int D\
    \ = d[v];\n            for (const T &to : f(v)) {\n                if (d.count(to))\n\
    \                    continue;\n                d[to] = D + 1;\n             \
    \   if (D + 1 < MAX)\n                    que.push(to);\n            }\n     \
    \   }\n        for (const auto &[key, val] : d)\n            level[val].push_back(key);\n\
    \        return level;\n    }\n\n    template <typename F>\n    std::vector<std::vector<T>>\
    \ from_root(const F &f, const std::vector<T> &s,\n                           \
    \               int MAX = 10) {\n        std::vector<std::vector<T>> level(MAX\
    \ + 1);\n        for (const T &v : s) {\n            d[v] = 0;\n            que.push(v);\n\
    \        }\n        while (que.size()) {\n            T v = que.front();\n   \
    \         que.pop();\n            int D = d[v];\n            for (const T &to\
    \ : f(v)) {\n                if (d.count(to))\n                    continue;\n\
    \                d[to] = D + 1;\n                if (D + 1 < MAX)\n          \
    \          que.push(to);\n            }\n        }\n        for (const auto &[key,\
    \ val] : d)\n            level[val].push_back(key);\n        return level;\n \
    \   }\n};\n"
  code: "template <typename T> class Distance {\n    std::map<T, int> d;\n    std::queue<T>\
    \ que;\n\n  public:\n    // s \u304B\u3089\u7D42\u7AEF\u306B\u305F\u3069\u308A\
    \u7740\u304F\u307E\u3067\u306E\u8DDD\u96E2\n    template <typename F> int shortest_path(const\
    \ F &f, const T &s) {\n        if (d.count(s))\n            return d[s];\n   \
    \     if (!f(s).size())\n            return d[s] = 0;\n        int res = 1e9;\n\
    \        for (const T &to : f(s))\n            res = std::min(res, shortest_path(f,\
    \ to) + 1);\n        return d[s] = res;\n    }\n\n    // s \u304B\u3089\u306E\u6700\
    \u77ED\u8DDD\u96E2\u304C MAX \u4EE5\u4E0B\u306E\u3082\u306E\u3092\u5217\u6319\n\
    \    template <typename F>\n    std::vector<std::vector<T>> from_root(const F\
    \ &f, const T &s,\n                                          int MAX = 10) {\n\
    \        std::vector<std::vector<T>> level(MAX + 1);\n        d[s] = 0;\n    \
    \    que.push(s);\n        while (que.size()) {\n            T v = que.front();\n\
    \            que.pop();\n            int D = d[v];\n            for (const T &to\
    \ : f(v)) {\n                if (d.count(to))\n                    continue;\n\
    \                d[to] = D + 1;\n                if (D + 1 < MAX)\n          \
    \          que.push(to);\n            }\n        }\n        for (const auto &[key,\
    \ val] : d)\n            level[val].push_back(key);\n        return level;\n \
    \   }\n\n    template <typename F>\n    std::vector<std::vector<T>> from_root(const\
    \ F &f, const std::vector<T> &s,\n                                          int\
    \ MAX = 10) {\n        std::vector<std::vector<T>> level(MAX + 1);\n        for\
    \ (const T &v : s) {\n            d[v] = 0;\n            que.push(v);\n      \
    \  }\n        while (que.size()) {\n            T v = que.front();\n         \
    \   que.pop();\n            int D = d[v];\n            for (const T &to : f(v))\
    \ {\n                if (d.count(to))\n                    continue;\n       \
    \         d[to] = D + 1;\n                if (D + 1 < MAX)\n                 \
    \   que.push(to);\n            }\n        }\n        for (const auto &[key, val]\
    \ : d)\n            level[val].push_back(key);\n        return level;\n    }\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: library/local/Distance.hpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/local/Distance.hpp
layout: document
redirect_from:
- /library/library/local/Distance.hpp
- /library/library/local/Distance.hpp.html
title: library/local/Distance.hpp
---
