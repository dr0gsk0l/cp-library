---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.hpp
    title: library/bitwise/Ranked.hpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.hpp
    title: library/bitwise/Util.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/setpowerseries/Compose.hpp
    title: library/setpowerseries/Compose.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
    title: test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/bitwise/Util.hpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/Ranked.hpp\"\n#define REP_(i, n) for (int i = 0; i < (n);\
    \ i++)\n#define RREP_(i, n) for (int i = (n) - 1; i >= 0; i--)\nclass BitwiseRanked\
    \ {\n    static int popcount(int S) { return __builtin_popcount(S); }\n\n  public:\n\
    \    template <typename T>\n    static std::vector<std::vector<T>> zeta(const\
    \ std::vector<T> &A) {\n        const int n = bitwise::log2(A.size());\n     \
    \   std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));\n      \
    \  REP_(S, 1 << n) RA[S][popcount(S)] = A[S];\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] += RA[S][d];\n        return RA;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> mobius(std::vector<std::vector<T>> RA) {\n   \
    \     const int n = bitwise::log2(RA.size());\n        REP_(i, n)\n        REP_(S,\
    \ 1 << n)\n        if (!bitwise::in(S, i))\n            REP_(d, n + 1) RA[S |\
    \ (1 << i)][d] -= RA[S][d];\n        std::vector<T> A(1 << n);\n        REP_(S,\
    \ 1 << n) A[S] = RA[S][popcount(S)];\n        return A;\n    }\n    template <typename\
    \ T>\n    static std::vector<T> convolution(const std::vector<T> &A,\n       \
    \                               const std::vector<T> &B) {\n        const int\
    \ n = bitwise::log2(A.size());\n        auto RA = zeta(A);\n        auto RB =\
    \ zeta(B);\n        REP_(S, 1 << n) {\n            auto &ra = RA[S], rb = RB[S];\n\
    \            RREP_(d, n + 1) {\n                ra[d] *= rb[0];\n            \
    \    REP_(i, d) ra[d] += ra[i] * rb[d - i];\n            }\n        }\n      \
    \  return mobius(RA);\n    }\n};\n#undef REP_\n#undef RREP_\n#line 2 \"library/setpowerseries/Base.hpp\"\
    \ntemplate <typename T> struct SetPowerSeries : std::vector<T> {\n    using SPS\
    \ = SetPowerSeries;\n    using value_type = T;\n    using std::vector<T>::vector;\n\
    \    using std::vector<T>::resize;\n    using std::vector<T>::at;\n    using std::vector<T>::size;\n\
    \n    SetPowerSeries(const std::vector<T> &f) {\n        resize(f.size());\n \
    \       for (int i = 0; i < size(); i++)\n            at(i) = f[i];\n    }\n\n\
    \    SPS operator-() const {\n        SPS ret(*this);\n        for (auto &a :\
    \ ret)\n            a = -a;\n        return ret;\n    }\n\n    SPS &operator+=(const\
    \ SPS &b) {\n        if (size() < b.size())\n            resize(b.size(), 0);\n\
    \        for (int i = 0; i < size(); i++)\n            at(i) += b[i];\n      \
    \  return *this;\n    }\n    SPS operator+(const SPS &b) const { return SPS(*this)\
    \ += b; }\n\n    SPS &operator-=(const SPS &b) {\n        if (size() < b.size())\n\
    \            resize(b.size(), 0);\n        for (int i = 0; i < size(); i++)\n\
    \            at(i) -= b[i];\n        return *this;\n    }\n    SPS operator-(const\
    \ SPS &b) const { return SPS(*this) -= b; }\n\n    SPS operator*(const SPS &b)\
    \ const {\n        return SPS(BitwiseRanked::convolution<T>(*this, b));\n    }\n\
    \    SPS &operator*=(const SPS &b) { return (*this) = (*this) * b; }\n};\n"
  code: "#include \"library/bitwise/Ranked.hpp\"\ntemplate <typename T> struct SetPowerSeries\
    \ : std::vector<T> {\n    using SPS = SetPowerSeries;\n    using value_type =\
    \ T;\n    using std::vector<T>::vector;\n    using std::vector<T>::resize;\n \
    \   using std::vector<T>::at;\n    using std::vector<T>::size;\n\n    SetPowerSeries(const\
    \ std::vector<T> &f) {\n        resize(f.size());\n        for (int i = 0; i <\
    \ size(); i++)\n            at(i) = f[i];\n    }\n\n    SPS operator-() const\
    \ {\n        SPS ret(*this);\n        for (auto &a : ret)\n            a = -a;\n\
    \        return ret;\n    }\n\n    SPS &operator+=(const SPS &b) {\n        if\
    \ (size() < b.size())\n            resize(b.size(), 0);\n        for (int i =\
    \ 0; i < size(); i++)\n            at(i) += b[i];\n        return *this;\n   \
    \ }\n    SPS operator+(const SPS &b) const { return SPS(*this) += b; }\n\n   \
    \ SPS &operator-=(const SPS &b) {\n        if (size() < b.size())\n          \
    \  resize(b.size(), 0);\n        for (int i = 0; i < size(); i++)\n          \
    \  at(i) -= b[i];\n        return *this;\n    }\n    SPS operator-(const SPS &b)\
    \ const { return SPS(*this) -= b; }\n\n    SPS operator*(const SPS &b) const {\n\
    \        return SPS(BitwiseRanked::convolution<T>(*this, b));\n    }\n    SPS\
    \ &operator*=(const SPS &b) { return (*this) = (*this) * b; }\n};\n"
  dependsOn:
  - library/bitwise/Ranked.hpp
  - library/bitwise/Util.hpp
  isVerificationFile: false
  path: library/setpowerseries/Base.hpp
  requiredBy:
  - library/setpowerseries/Compose.hpp
  timestamp: '2024-11-12 15:55:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/SPS/ExpOfSetPowerSeries.test.cpp
documentation_of: library/setpowerseries/Base.hpp
layout: document
redirect_from:
- /library/library/setpowerseries/Base.hpp
- /library/library/setpowerseries/Base.hpp.html
title: library/setpowerseries/Base.hpp
---
