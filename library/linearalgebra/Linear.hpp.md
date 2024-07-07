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
  bundledCode: "#line 2 \"library/linearalgebra/Linear.hpp\"\ntemplate <typename T>\
    \ struct Line {\n    T a, b;\n    Line() = default;\n    Line(T a, T b) : a(a),\
    \ b(b) {}\n    Line(std::pair<T, T> l) : a(l.first), b(l.second) {}\n    Line(T\
    \ c) : a(0), b(c) {}\n\n    T operator()(const T x) const { return a * x + b;\
    \ }\n    Line operator()(const Line &l) const { return Line(a * l.a, a * l.b +\
    \ b); }\n\n    bool operator==(const Line &l) const { return a == l.a and b ==\
    \ l.b; }\n    bool operator!=(const Line &l) const { return !(*this == l); }\n\
    \    bool operator<(const Line &l) const {\n        return (a == l.a ? a < l.a\
    \ : b < l.b);\n    }\n\n    Line &operator+=(const Line &l) {\n        a += l.a;\n\
    \        b += l.b;\n        return *this;\n    }\n    Line operator+(const Line\
    \ &l) const { return Line(*this) += l; }\n    Line &operator-=(const Line &l)\
    \ {\n        a -= l.a;\n        b -= l.b;\n        return *this;\n    }\n    Line\
    \ operator-(const Line &l) const { return Line(*this) -= l; }\n    Line operator-()\
    \ const { return Line(-a, -b); }\n\n    Line &operator+=(const T &c) {\n     \
    \   b += c;\n        return *this;\n    }\n    Line operator+(const T &c) const\
    \ { return Line(*this) += c; }\n    Line &operator-=(const T &c) {\n        b\
    \ -= c;\n        return *this;\n    }\n    Line operator-(const T &c) const {\
    \ return Line(*this) -= c; }\n    Line &operator*=(const T &c) {\n        a *=\
    \ c;\n        b *= c;\n        return *this;\n    }\n    Line operator*(const\
    \ T &c) const { return Line(*this) *= c; }\n    Line &operator/=(const T &c) {\n\
    \        a /= c;\n        b /= c;\n        return *this;\n    }\n    Line operator/(const\
    \ T &c) const { return Line(*this) /= c; }\n\n    Line inv() const {\n       \
    \ assert(a != 0);\n        return Line(T(1) / a, -b / a);\n    }\n\n    friend\
    \ std::istream &operator>>(std::istream &is, Line &l) {\n        is >> l.a >>\
    \ l.b;\n        return is;\n    }\n    friend std::ostream &operator<<(std::ostream\
    \ &os, const Line &l) {\n        if (l.a == 0 and l.b == 0)\n            os <<\
    \ 0;\n        else if (l.a == 0)\n            os << l.b;\n        else if (l.b\
    \ == 0)\n            os << l.a << \"x\";\n        else if (l.b > 0)\n        \
    \    os << l.a << \"x+\" << l.b;\n        else\n            os << l.a << \"x-\"\
    \ << -l.b;\n        return os;\n    }\n};\n"
  code: "#pragma once\ntemplate <typename T> struct Line {\n    T a, b;\n    Line()\
    \ = default;\n    Line(T a, T b) : a(a), b(b) {}\n    Line(std::pair<T, T> l)\
    \ : a(l.first), b(l.second) {}\n    Line(T c) : a(0), b(c) {}\n\n    T operator()(const\
    \ T x) const { return a * x + b; }\n    Line operator()(const Line &l) const {\
    \ return Line(a * l.a, a * l.b + b); }\n\n    bool operator==(const Line &l) const\
    \ { return a == l.a and b == l.b; }\n    bool operator!=(const Line &l) const\
    \ { return !(*this == l); }\n    bool operator<(const Line &l) const {\n     \
    \   return (a == l.a ? a < l.a : b < l.b);\n    }\n\n    Line &operator+=(const\
    \ Line &l) {\n        a += l.a;\n        b += l.b;\n        return *this;\n  \
    \  }\n    Line operator+(const Line &l) const { return Line(*this) += l; }\n \
    \   Line &operator-=(const Line &l) {\n        a -= l.a;\n        b -= l.b;\n\
    \        return *this;\n    }\n    Line operator-(const Line &l) const { return\
    \ Line(*this) -= l; }\n    Line operator-() const { return Line(-a, -b); }\n\n\
    \    Line &operator+=(const T &c) {\n        b += c;\n        return *this;\n\
    \    }\n    Line operator+(const T &c) const { return Line(*this) += c; }\n  \
    \  Line &operator-=(const T &c) {\n        b -= c;\n        return *this;\n  \
    \  }\n    Line operator-(const T &c) const { return Line(*this) -= c; }\n    Line\
    \ &operator*=(const T &c) {\n        a *= c;\n        b *= c;\n        return\
    \ *this;\n    }\n    Line operator*(const T &c) const { return Line(*this) *=\
    \ c; }\n    Line &operator/=(const T &c) {\n        a /= c;\n        b /= c;\n\
    \        return *this;\n    }\n    Line operator/(const T &c) const { return Line(*this)\
    \ /= c; }\n\n    Line inv() const {\n        assert(a != 0);\n        return Line(T(1)\
    \ / a, -b / a);\n    }\n\n    friend std::istream &operator>>(std::istream &is,\
    \ Line &l) {\n        is >> l.a >> l.b;\n        return is;\n    }\n    friend\
    \ std::ostream &operator<<(std::ostream &os, const Line &l) {\n        if (l.a\
    \ == 0 and l.b == 0)\n            os << 0;\n        else if (l.a == 0)\n     \
    \       os << l.b;\n        else if (l.b == 0)\n            os << l.a << \"x\"\
    ;\n        else if (l.b > 0)\n            os << l.a << \"x+\" << l.b;\n      \
    \  else\n            os << l.a << \"x-\" << -l.b;\n        return os;\n    }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/Linear.hpp
  requiredBy: []
  timestamp: '2024-07-07 16:34:26+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linearalgebra/Linear.hpp
layout: document
redirect_from:
- /library/library/linearalgebra/Linear.hpp
- /library/library/linearalgebra/Linear.hpp.html
title: library/linearalgebra/Linear.hpp
---
