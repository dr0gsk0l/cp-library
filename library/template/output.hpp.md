---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: library/template/base.hpp
    title: library/template/base.hpp
  - icon: ':warning:'
    path: library/template/type.hpp
    title: library/template/type.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/template/base.hpp\"\n#pragma GCC optimize(\"Ofast\"\
    )\n#include <bits/stdc++.h>\n#line 1 \"library/template/base.hpp\"\n#pragma GCC\
    \ optimize(\"Ofast\")\n#line 2 \"library/template/type.hpp\"\n\n#define TYPE1(T)\
    \ template <class T>\n#define TYPE2(T, U) template <class T, class U>\n#define\
    \ TYPE3(T, U, V) template <class T, class U, class V>\n#define TYPE4(T, U, V,\
    \ W) template <class T, class U, class V, class W>\n#define TYPE5(T, U, V, W,\
    \ X)                                                   \\\n    template <class\
    \ T, class U, class V, class W, class X>\n#define TYPE(...)                  \
    \                                            \\\n    overload5(__VA_ARGS__, TYPE5,\
    \ TYPE4, TYPE3, TYPE2, TYPE1)(__VA_ARGS__)\n#define TYPES1(T) template <class...\
    \ T>\n#define TYPES2(H, T) template <class H, class... T>\n#define TYPES(...)\
    \ overload2(__VA_ARGS__, TYPES2, TYPES1)(__VA_ARGS__)\n\nTYPE(T)\nusing vec<T>\
    \ = std::vector<T>;\nTYPE(T)\nusing vvec<T> = vec<vec<T>>;\nTYPE(T)\nusing vvvec<T>\
    \ = vec<vvec<T>>;\nTYPE(T)\nusing vvvvec<T> = vec<vvvec<T>>;\nTYPE(T)\nusing ptt<T>\
    \ = std::pair<T, T>;\nusing ll = long long;\nusing ld = long double;\nusing vi\
    \ = vec<int>;\nusing vvi = vvec<int>;\nusing vvvi = vvvec<int>;\nusing vvvvi =\
    \ vvvvec<int>;\nusing vll = vec<ll>;\nusing vvll = vvec<ll>;\nusing vvvll = vvvec<ll>;\n\
    using vvvvll = vvvvec<ll>;\nusing vs = vec<std::string>;\nusing pi = ptt<int>;\n\
    using pll = ptt<ll>;\n\nTYPE(T)\nusing pq = std::priority_queue<T>;\nTYPE(T)\n\
    using pqg = std::priority_queue<T, vec<T>, std::greater<T>>;\n#line 3 \"library/template/output.hpp\"\
    \n\nvoid outputs() {}\n\nTYPES(T, Ts)\nvoid outputs(const std::ostream &os, const\
    \ T &a, const Ts &...b) {\n    os << a;\n    (os << ...(os << ' ', b));\n}\n\n\
    void print() { std::cout << '\\n'; }\n\nTYPES(T, Ts)\nvoid print(const T &a, const\
    \ Ts &...b) {\n    outputs(std::cout, a, b);\n    std::cout << \"\\n\";\n}\n\n\
    TYPES(T, Ts)\nvoid fin(const T &a, const Ts &...b) {\n    print(a, b);\n    exit(0);\n\
    }\n"
  code: "#include \"library/template/base.hpp\"\n#include \"library/template/type.hpp\"\
    \n\nvoid outputs() {}\n\nTYPES(T, Ts)\nvoid outputs(const std::ostream &os, const\
    \ T &a, const Ts &...b) {\n    os << a;\n    (os << ...(os << ' ', b));\n}\n\n\
    void print() { std::cout << '\\n'; }\n\nTYPES(T, Ts)\nvoid print(const T &a, const\
    \ Ts &...b) {\n    outputs(std::cout, a, b);\n    std::cout << \"\\n\";\n}\n\n\
    TYPES(T, Ts)\nvoid fin(const T &a, const Ts &...b) {\n    print(a, b);\n    exit(0);\n\
    }"
  dependsOn:
  - library/template/base.hpp
  - library/template/type.hpp
  isVerificationFile: false
  path: library/template/output.hpp
  requiredBy: []
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/template/output.hpp
layout: document
redirect_from:
- /library/library/template/output.hpp
- /library/library/template/output.hpp.html
title: library/template/output.hpp
---
