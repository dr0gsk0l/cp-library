---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/Add.hpp
    title: library/algebra/group/Add.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.hpp
    title: library/algebra/group/CntSum.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_G.test.cpp
    title: test/AOJ/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/GRL_5_E.test.cpp
    title: test/AOJ/GRL_5_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/algebra/group/Add.hpp\"\ntemplate<typename X>\n\
    struct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x, const\
    \ X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static\
    \ constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 1 \"library/algebra/group/CntSum.hpp\"\ntemplate <typename X> struct GroupCntSum\
    \ {\n    using P = std::pair<X, X>;\n    using value_type = P;\n    static constexpr\
    \ P op(const P &x, const P &y) {\n        return {x.first + y.first, x.second\
    \ + y.second};\n    }\n    static constexpr void Rchop(P &x, const P &y) {\n \
    \       x.first += y.first;\n        x.second += y.second;\n    }\n    static\
    \ constexpr void Lchop(const P &x, P &y) {\n        y.first += x.first;\n    \
    \    y.second += x.second;\n    }\n    static constexpr P inverse(const P &x)\
    \ { return {-x.fi, -x.se}; }\n    static constexpr P unit() { return {0, 0}; }\n\
    \    static constexpr bool commute = true;\n};\ntemplate <typename X> std::vector<std::pair<X,\
    \ X>> cnt_init(int n, const X &x) {\n    return std::vector<std::pair<X, X>>(n,\
    \ {x, 1});\n}\ntemplate <typename X>\nstd::vector<std::pair<X, X>> cnt_init(const\
    \ std::vector<X> &v) {\n    int n = v.size();\n    std::vector<std::pair<X, X>>\
    \ res(n);\n    for (int i = 0; i < n; i++)\n        res[i] = {v[i], 1};\n    return\
    \ res;\n}\n#line 4 \"library/algebra/lazy/AddSum.hpp\"\ntemplate <typename X>\
    \ struct LazyAddSum {\n    using MX = GroupCntSum<X>;\n    using MF = GroupAdd<X>;\n\
    \    using S = typename MX::value_type;\n    static constexpr S mapping(const\
    \ X &f, const S &x) {\n        return {x.first + f * x.second, x.second};\n  \
    \  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/Add.hpp\"\n#include \"library/algebra/group/CntSum.hpp\"\
    \ntemplate <typename X> struct LazyAddSum {\n    using MX = GroupCntSum<X>;\n\
    \    using MF = GroupAdd<X>;\n    using S = typename MX::value_type;\n    static\
    \ constexpr S mapping(const X &f, const S &x) {\n        return {x.first + f *\
    \ x.second, x.second};\n    }\n};"
  dependsOn:
  - library/algebra/group/Add.hpp
  - library/algebra/group/CntSum.hpp
  isVerificationFile: false
  path: library/algebra/lazy/AddSum.hpp
  requiredBy: []
  timestamp: '2025-11-10 10:09:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_G.test.cpp
  - test/AOJ/GRL_5_E.test.cpp
documentation_of: library/algebra/lazy/AddSum.hpp
layout: document
redirect_from:
- /library/library/algebra/lazy/AddSum.hpp
- /library/library/algebra/lazy/AddSum.hpp.html
title: library/algebra/lazy/AddSum.hpp
---
