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
  bundledCode: "#line 1 \"library/algebra/group/CntSum.hpp\"\ntemplate <typename X>\
    \ struct GroupCntSum {\n    using P = std::pair<X, X>;\n    using value_type =\
    \ P;\n    static constexpr P op(const P &x, const P &y) {\n        return {x.first\
    \ + y.first, x.second + y.second};\n    }\n    static constexpr void Rchop(P &x,\
    \ const P &y) {\n        x.first += y.first;\n        x.second += y.second;\n\
    \    }\n    static constexpr void Lchop(const P &x, P &y) {\n        y.first +=\
    \ x.first;\n        y.second += x.second;\n    }\n    static constexpr P inverse(const\
    \ P &x) { return {-x.fi, -x.se}; }\n    static constexpr P unit() { return {0,\
    \ 0}; }\n    static constexpr bool commute = true;\n};\ntemplate <typename X>\
    \ std::vector<std::pair<X, X>> cnt_init(int n, const X &x) {\n    return std::vector<std::pair<X,\
    \ X>>(n, {x, 1});\n}\ntemplate <typename X>\nstd::vector<std::pair<X, X>> cnt_init(const\
    \ std::vector<X> &v) {\n    int n = v.size();\n    std::vector<std::pair<X, X>>\
    \ res(n);\n    for (int i = 0; i < n; i++)\n        res[i] = {v[i], 1};\n    return\
    \ res;\n}\n"
  code: "template <typename X> struct GroupCntSum {\n    using P = std::pair<X, X>;\n\
    \    using value_type = P;\n    static constexpr P op(const P &x, const P &y)\
    \ {\n        return {x.first + y.first, x.second + y.second};\n    }\n    static\
    \ constexpr void Rchop(P &x, const P &y) {\n        x.first += y.first;\n    \
    \    x.second += y.second;\n    }\n    static constexpr void Lchop(const P &x,\
    \ P &y) {\n        y.first += x.first;\n        y.second += x.second;\n    }\n\
    \    static constexpr P inverse(const P &x) { return {-x.fi, -x.se}; }\n    static\
    \ constexpr P unit() { return {0, 0}; }\n    static constexpr bool commute = true;\n\
    };\ntemplate <typename X> std::vector<std::pair<X, X>> cnt_init(int n, const X\
    \ &x) {\n    return std::vector<std::pair<X, X>>(n, {x, 1});\n}\ntemplate <typename\
    \ X>\nstd::vector<std::pair<X, X>> cnt_init(const std::vector<X> &v) {\n    int\
    \ n = v.size();\n    std::vector<std::pair<X, X>> res(n);\n    for (int i = 0;\
    \ i < n; i++)\n        res[i] = {v[i], 1};\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/algebra/group/CntSum.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/algebra/group/CntSum.hpp
layout: document
redirect_from:
- /library/library/algebra/group/CntSum.hpp
- /library/library/algebra/group/CntSum.hpp.html
title: library/algebra/group/CntSum.hpp
---
