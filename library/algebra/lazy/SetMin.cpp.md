---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/monoid/Min.cpp
    title: library/algebra/monoid/Min.cpp
  - icon: ':heavy_check_mark:'
    path: library/algebra/monoid/Set.cpp
    title: library/algebra/monoid/Set.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_D.test.cpp
    title: test/AOJ/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/AOJ/DSL_2_F.test.cpp
    title: test/AOJ/DSL_2_F.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/monoid/Min.cpp\"\ntemplate<typename X>\n\
    struct MonoidMin{\n  using value_type = X;\n  static constexpr X op(const X &x,\
    \ const X &y) noexcept { return min(x,y); }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ if(x>y)x=y; }\n  static constexpr void Lchop(const X&x, X&y){ if(y>x)y=x;\
    \ }\n  static constexpr X unit() { return numeric_limits<X>::max()/2; }\n  static\
    \ constexpr bool commute = true;\n};\n#line 2 \"library/algebra/monoid/Set.cpp\"\
    \n// \u5408\u6210\u306E\u9806\u756A\u306F\u95A2\u6570\u3068\u4E00\u7DD2\u3060\u3088\
    \ntemplate<typename X>\nstruct MonoidSet{\n  using O=optional<X>;\n  using value_type=O;\n\
    \  static constexpr O op(const O &x,const O &y)noexcept{ return (x.has_value()?x:y);\
    \ }\n  static constexpr void Rchop(O&x, const O&y){ if(!x)x=y; }\n  static constexpr\
    \ void Lchop(const O&x, O&y){ if(x)y=x; } \n  static constexpr O unit()noexcept{\
    \ return nullopt; }\n  static constexpr bool commute=false;\n};\n#line 4 \"library/algebra/lazy/SetMin.cpp\"\
    \ntemplate<typename X>\nstruct LazySetMin{\n  using MX=MonoidMin<X>;\n  using\
    \ MF=MonoidSet<X>;\n  using F=typename MF::value_type;\n  static constexpr X mapping(const\
    \ F&f,const X&x){\n    return f.value_or(x);\n  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/monoid/Min.cpp\"\n#include \"library/algebra/monoid/Set.cpp\"\
    \ntemplate<typename X>\nstruct LazySetMin{\n  using MX=MonoidMin<X>;\n  using\
    \ MF=MonoidSet<X>;\n  using F=typename MF::value_type;\n  static constexpr X mapping(const\
    \ F&f,const X&x){\n    return f.value_or(x);\n  }\n};"
  dependsOn:
  - library/algebra/monoid/Min.cpp
  - library/algebra/monoid/Set.cpp
  isVerificationFile: false
  path: library/algebra/lazy/SetMin.cpp
  requiredBy: []
  timestamp: '2023-12-03 14:54:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/DSL_2_F.test.cpp
  - test/AOJ/DSL_2_D.test.cpp
documentation_of: library/algebra/lazy/SetMin.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/SetMin.cpp
- /library/library/algebra/lazy/SetMin.cpp.html
title: library/algebra/lazy/SetMin.cpp
---
