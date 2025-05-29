---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/algebra/group/CntSum.hpp
    title: library/algebra/group/CntSum.hpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Set.hpp
    title: library/algebra/monoid/Set.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_I.test.cpp
    title: test/AOJ/DSL_2_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
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
    \ res;\n}\n#line 2 \"library/algebra/monoid/Set.hpp\"\n// \u5408\u6210\u306E\u9806\
    \u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\ntemplate <typename X>\
    \ struct MonoidSet {\n    using O = std::optional<X>;\n    using value_type =\
    \ O;\n    static constexpr O op(const O &x, const O &y) noexcept {\n        return\
    \ (x.has_value() ? x : y);\n    }\n    static constexpr void Rchop(O &x, const\
    \ O &y) {\n        if (!x)\n            x = y;\n    }\n    static constexpr void\
    \ Lchop(const O &x, O &y) {\n        if (x)\n            y = x;\n    }\n    static\
    \ constexpr O unit() noexcept { return std::nullopt; }\n    static constexpr bool\
    \ commute = false;\n};\n#line 4 \"library/algebra/lazy/SetSum.hpp\"\ntemplate\
    \ <typename X> struct LazySetSum {\n    using MX = GroupCntSum<X>;\n    using\
    \ MF = MonoidSet<X>;\n    using P = typename MX::value_type;\n    using F = typename\
    \ MF::value_type;\n    static constexpr P mapping(const F &f, const P &x) {\n\
    \        if (f.has_value())\n            return {f.value() * x.second, x.second};\n\
    \        return x;\n    }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/CntSum.hpp\"\n#include \"\
    library/algebra/monoid/Set.hpp\"\ntemplate <typename X> struct LazySetSum {\n\
    \    using MX = GroupCntSum<X>;\n    using MF = MonoidSet<X>;\n    using P = typename\
    \ MX::value_type;\n    using F = typename MF::value_type;\n    static constexpr\
    \ P mapping(const F &f, const P &x) {\n        if (f.has_value())\n          \
    \  return {f.value() * x.second, x.second};\n        return x;\n    }\n};"
  dependsOn:
  - library/algebra/group/CntSum.hpp
  - library/algebra/monoid/Set.hpp
  isVerificationFile: false
  path: library/algebra/lazy/SetSum.hpp
  requiredBy: []
  timestamp: '2025-05-29 22:07:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_I.test.cpp
documentation_of: library/algebra/lazy/SetSum.hpp
layout: document
redirect_from:
- /library/library/algebra/lazy/SetSum.hpp
- /library/library/algebra/lazy/SetSum.hpp.html
title: library/algebra/lazy/SetSum.hpp
---
