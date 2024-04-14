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
  bundledCode: "#line 2 \"library/math/Fraction.cpp\"\ntemplate <typename T> struct\
    \ Fraction {\n    T num, den;\n    Fraction(T n = 0, T d = 1) : num(n), den(d)\
    \ {\n        assert(den != 0);\n        if (den < 0)\n            num = -num,\
    \ den = -den;\n        T g = std::gcd(abs(num), abs(den));\n        num /= g;\n\
    \        den /= g;\n    }\n\n    Fraction operator+(const Fraction &b) const {\n\
    \        return Fraction(num * b.den + den * b.num, den * b.den);\n    }\n   \
    \ Fraction operator-(const Fraction &b) const {\n        return Fraction(num *\
    \ b.den - den * b.num, den * b.den);\n    }\n    Fraction operator*(const Fraction\
    \ &b) const {\n        return Fraction(num * b.num, den * b.den);\n    }\n   \
    \ Fraction operator/(const Fraction &b) const {\n        return Fraction(num *\
    \ b.den, den * b.num);\n    }\n    Fraction &operator+=(const Fraction &b) { return\
    \ *this = (*this) + b; }\n    Fraction &operator-=(const Fraction &b) { return\
    \ *this = (*this) - b; }\n    Fraction &operator*=(const Fraction &b) { return\
    \ *this = (*this) * b; }\n    Fraction &operator/=(const Fraction &b) { return\
    \ *this = (*this) / b; }\n    Fraction operator+(const T &c) const { return (*this)\
    \ + Fraction(c, 1); }\n    Fraction operator-(const T &c) const { return (*this)\
    \ - Fraction(c, 1); }\n    Fraction operator*(const T &c) const { return (*this)\
    \ * Fraction(c, 1); }\n    Fraction operator/(const T &c) const { return (*this)\
    \ / Fraction(c, 1); }\n    friend Fraction operator+(const T &c, Fraction b) {\n\
    \        return Fraction(c, 1) + b;\n    }\n    friend Fraction operator-(const\
    \ T &c, Fraction b) {\n        return Fraction(c, 1) - b;\n    }\n    friend Fraction\
    \ operator*(const T &c, Fraction b) {\n        return Fraction(c, 1) * b;\n  \
    \  }\n    friend Fraction operator/(const T &c, Fraction b) {\n        return\
    \ Fraction(c, 1) / b;\n    }\n    Fraction &operator+=(const T &c) { return *this\
    \ = (*this) + c; }\n    Fraction &operator-=(const T &c) { return *this = (*this)\
    \ - c; }\n    Fraction &operator*=(const T &c) { return *this = (*this) * c; }\n\
    \    Fraction &operator/=(const T &c) { return *this = (*this) / c; }\n    Fraction\
    \ &operator++() { return (*this) += 1; }\n    Fraction &operator--() { return\
    \ (*this) -= 1; }\n    Fraction &operator++(int) { return (*this) += 1; }\n  \
    \  Fraction &operator--(int) { return (*this) -= 1; }\n    Fraction operator+()\
    \ const { return *this; }\n    Fraction operator-() const { return Fraction(-num,\
    \ den); }\n\n    static Fraction raw(T a) { return Fraction(a, 1); }\n    Fraction\
    \ pow(long long k) const {\n        Fraction res(1, 1), tmp(*this);\n        while\
    \ (k) {\n            if (k & 1)\n                res *= res;\n            tmp\
    \ *= tmp;\n            k >>= 1;\n        }\n        return res;\n    }\n    Fraction\
    \ inv() { return Fraction(den, num); }\n\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Fraction &a) {\n        os << a.num << \"/\" << a.den;\n        return\
    \ os;\n    }\n    friend std::istream &operator>>(std::istream &is, Fraction &a)\
    \ {\n        is >> a.num;\n        a.den = 1;\n        return is;\n    }\n\n#define\
    \ define_cmp(op)                                                         \\\n\
    \    bool operator op(const Fraction &b) const {                             \
    \   \\\n        return num * b.den op b.num * den;                           \
    \          \\\n    }\n    define_cmp(==) define_cmp(!=) define_cmp(<) define_cmp(>)\
    \ define_cmp(<=)\n        define_cmp(>=)\n#undef define_cmp\n};\n"
  code: "#pragma once\ntemplate <typename T> struct Fraction {\n    T num, den;\n\
    \    Fraction(T n = 0, T d = 1) : num(n), den(d) {\n        assert(den != 0);\n\
    \        if (den < 0)\n            num = -num, den = -den;\n        T g = std::gcd(abs(num),\
    \ abs(den));\n        num /= g;\n        den /= g;\n    }\n\n    Fraction operator+(const\
    \ Fraction &b) const {\n        return Fraction(num * b.den + den * b.num, den\
    \ * b.den);\n    }\n    Fraction operator-(const Fraction &b) const {\n      \
    \  return Fraction(num * b.den - den * b.num, den * b.den);\n    }\n    Fraction\
    \ operator*(const Fraction &b) const {\n        return Fraction(num * b.num, den\
    \ * b.den);\n    }\n    Fraction operator/(const Fraction &b) const {\n      \
    \  return Fraction(num * b.den, den * b.num);\n    }\n    Fraction &operator+=(const\
    \ Fraction &b) { return *this = (*this) + b; }\n    Fraction &operator-=(const\
    \ Fraction &b) { return *this = (*this) - b; }\n    Fraction &operator*=(const\
    \ Fraction &b) { return *this = (*this) * b; }\n    Fraction &operator/=(const\
    \ Fraction &b) { return *this = (*this) / b; }\n    Fraction operator+(const T\
    \ &c) const { return (*this) + Fraction(c, 1); }\n    Fraction operator-(const\
    \ T &c) const { return (*this) - Fraction(c, 1); }\n    Fraction operator*(const\
    \ T &c) const { return (*this) * Fraction(c, 1); }\n    Fraction operator/(const\
    \ T &c) const { return (*this) / Fraction(c, 1); }\n    friend Fraction operator+(const\
    \ T &c, Fraction b) {\n        return Fraction(c, 1) + b;\n    }\n    friend Fraction\
    \ operator-(const T &c, Fraction b) {\n        return Fraction(c, 1) - b;\n  \
    \  }\n    friend Fraction operator*(const T &c, Fraction b) {\n        return\
    \ Fraction(c, 1) * b;\n    }\n    friend Fraction operator/(const T &c, Fraction\
    \ b) {\n        return Fraction(c, 1) / b;\n    }\n    Fraction &operator+=(const\
    \ T &c) { return *this = (*this) + c; }\n    Fraction &operator-=(const T &c)\
    \ { return *this = (*this) - c; }\n    Fraction &operator*=(const T &c) { return\
    \ *this = (*this) * c; }\n    Fraction &operator/=(const T &c) { return *this\
    \ = (*this) / c; }\n    Fraction &operator++() { return (*this) += 1; }\n    Fraction\
    \ &operator--() { return (*this) -= 1; }\n    Fraction &operator++(int) { return\
    \ (*this) += 1; }\n    Fraction &operator--(int) { return (*this) -= 1; }\n  \
    \  Fraction operator+() const { return *this; }\n    Fraction operator-() const\
    \ { return Fraction(-num, den); }\n\n    static Fraction raw(T a) { return Fraction(a,\
    \ 1); }\n    Fraction pow(long long k) const {\n        Fraction res(1, 1), tmp(*this);\n\
    \        while (k) {\n            if (k & 1)\n                res *= res;\n  \
    \          tmp *= tmp;\n            k >>= 1;\n        }\n        return res;\n\
    \    }\n    Fraction inv() { return Fraction(den, num); }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const Fraction &a) {\n        os << a.num << \"\
    /\" << a.den;\n        return os;\n    }\n    friend std::istream &operator>>(std::istream\
    \ &is, Fraction &a) {\n        is >> a.num;\n        a.den = 1;\n        return\
    \ is;\n    }\n\n#define define_cmp(op)                                       \
    \                  \\\n    bool operator op(const Fraction &b) const {       \
    \                         \\\n        return num * b.den op b.num * den;     \
    \                                \\\n    }\n    define_cmp(==) define_cmp(!=)\
    \ define_cmp(<) define_cmp(>) define_cmp(<=)\n        define_cmp(>=)\n#undef define_cmp\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/math/Fraction.cpp
  requiredBy: []
  timestamp: '2024-04-14 21:36:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/Fraction.cpp
layout: document
redirect_from:
- /library/library/math/Fraction.cpp
- /library/library/math/Fraction.cpp.html
title: library/math/Fraction.cpp
---
