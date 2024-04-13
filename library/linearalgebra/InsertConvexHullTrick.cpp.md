---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate <typename T>\
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
    \ << -l.b;\n        return os;\n    }\n};\n#line 3 \"library/linearalgebra/InsertConvexHullTrick.cpp\"\
    \nnamespace insert_convex_hull_trick {\nenum Objective {\n    MINIMIZE = +1,\n\
    \    MAXIMIZE = -1,\n};\n\n// \u6700\u5927\u5316\u306E\u5834\u5408\u306F\u53CD\
    \u8EE2\u3057\u3066\u3001\u5185\u90E8\u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\
    \u306E\u307F\u3092\u6271\u3046\n// \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\
    \u5C11\u306B\u306A\u308B\u3088\u3046\u306B\u4FDD\u5B58\n\ntemplate <typename T,\
    \ Objective OBJ> class InsertConvexHullTrick {\n    using L = Line<T>;\n\n   \
    \ std::map<T, T> mp1, mp2; // \u50BE\u304D \u2192 \u5207\u7247, \u533A\u9593\u306E\
    \u53F3\u7AEF \u2192 \u50BE\u304D\n    // f(x)=ax+b \u306B\u5BFE\u3057 r = max_x\
    \ { f(x) = min_g g(x)} \u3068\u3057\u3066\n    // mp1[a]=b, mp2[r]=a \u304C\u5165\
    \u3063\u3066\u3044\u308B\n    // r = \\inf \u306E\u6642\u306F mp2 \u306B\u306F\
    \u5165\u308C\u306A\u3044\n\n    template <typename IT> bool check(const IT it)\
    \ {\n        // mp1 \u306E it \u304C\u8981\u3089\u306A\u3044\u306A\u3089 true\
    \ \u3092\u8FD4\u3059\n        if (it == mp1.begin() or it == mp1.rbegin().base())\n\
    \            return false;\n        const auto &[a1, b1] = *prev(it);\n      \
    \  const auto &[a2, b2] = *it;\n        const auto &[a3, b3] = *nxt(it);\n   \
    \     // \u4EA4\u70B9\u306E x \u5EA7\u6A19\u306F\u305D\u308C\u305E\u308C (b2-b1)/(a1-a2),\
    \ (b3-b2)/(a2-a3)\n        // \u3053\u308C\u304C <= \u306A\u3089\u8981\u3089\u306A\
    \u3044\n        return (b2 - b1) * (a2 - a3) <= (b3 - b2) * (a1 - a2);\n    }\n\
    \n    template <typename IT> T r(const IT it) {\n        // it \u304C\u6700\u5C0F\
    \u3067\u3044\u3089\u308C\u308B\u6700\u5927\u306E r \u3092\u8FD4\u3059\n    }\n\
    \n  public:\n    using value_type = L;\n\n    InsertConvexHullTrick() = default;\n\
    \    InsertConvexHullTrick(const std::vector<L> &lines) {\n        for (const\
    \ auto &l : lines)\n            add(l);\n    }\n\n    void add(L l) {\n      \
    \  if (OBJ == -1)\n            l = -l;\n        if (mp1.count(l.a)) {\n      \
    \      if (mp1[l.a] <= l.b)\n                return;\n            mp1.erase(l.a);\n\
    \        }\n        auto [it, flag] = mp1.insert(make_std::pair(l.a, l.b));\n\
    \        if (check(it)) {\n            mp1.erase(it);\n            return;\n \
    \       }\n        if (it != mp1.begin())\n            for (auto l = pre(it);\
    \ check(l); l = --mp1.erase(l)) {\n            }\n        if (nxt(it) != mp1.end())\n\
    \            for (auto r = nxt(it); check(r); r = mp1.erase(r)) {\n          \
    \  }\n    }\n    void add(T a, T b) { add(L(a, b)); }\n\n    T query(T x) const\
    \ {\n        assert(mp1.size());\n        if (mp2.begin())\n    }\n};\n} // namespace\
    \ insert_convex_hull_trick\ntemplate <typename T>\nusing MinConvexHullTrick =\n\
    \    convex_hull_trick::ConvexHullTrick<T,\n                                 \
    \      convex_hull_trick::Objective::MINIMIZE>;\ntemplate <typename T>\nusing\
    \ MaxConvexHullTrick =\n    convex_hull_trick::ConvexHullTrick<T,\n          \
    \                             convex_hull_trick::Objective::MAXIMIZE>;\n"
  code: "#pragma once\n#include \"library/linearalgebra/Linear.cpp\"\nnamespace insert_convex_hull_trick\
    \ {\nenum Objective {\n    MINIMIZE = +1,\n    MAXIMIZE = -1,\n};\n\n// \u6700\
    \u5927\u5316\u306E\u5834\u5408\u306F\u53CD\u8EE2\u3057\u3066\u3001\u5185\u90E8\
    \u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\u306E\u307F\u3092\u6271\u3046\n// \u50BE\
    \u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306B\u306A\u308B\u3088\u3046\
    \u306B\u4FDD\u5B58\n\ntemplate <typename T, Objective OBJ> class InsertConvexHullTrick\
    \ {\n    using L = Line<T>;\n\n    std::map<T, T> mp1, mp2; // \u50BE\u304D \u2192\
    \ \u5207\u7247, \u533A\u9593\u306E\u53F3\u7AEF \u2192 \u50BE\u304D\n    // f(x)=ax+b\
    \ \u306B\u5BFE\u3057 r = max_x { f(x) = min_g g(x)} \u3068\u3057\u3066\n    //\
    \ mp1[a]=b, mp2[r]=a \u304C\u5165\u3063\u3066\u3044\u308B\n    // r = \\inf \u306E\
    \u6642\u306F mp2 \u306B\u306F\u5165\u308C\u306A\u3044\n\n    template <typename\
    \ IT> bool check(const IT it) {\n        // mp1 \u306E it \u304C\u8981\u3089\u306A\
    \u3044\u306A\u3089 true \u3092\u8FD4\u3059\n        if (it == mp1.begin() or it\
    \ == mp1.rbegin().base())\n            return false;\n        const auto &[a1,\
    \ b1] = *prev(it);\n        const auto &[a2, b2] = *it;\n        const auto &[a3,\
    \ b3] = *nxt(it);\n        // \u4EA4\u70B9\u306E x \u5EA7\u6A19\u306F\u305D\u308C\
    \u305E\u308C (b2-b1)/(a1-a2), (b3-b2)/(a2-a3)\n        // \u3053\u308C\u304C <=\
    \ \u306A\u3089\u8981\u3089\u306A\u3044\n        return (b2 - b1) * (a2 - a3) <=\
    \ (b3 - b2) * (a1 - a2);\n    }\n\n    template <typename IT> T r(const IT it)\
    \ {\n        // it \u304C\u6700\u5C0F\u3067\u3044\u3089\u308C\u308B\u6700\u5927\
    \u306E r \u3092\u8FD4\u3059\n    }\n\n  public:\n    using value_type = L;\n\n\
    \    InsertConvexHullTrick() = default;\n    InsertConvexHullTrick(const std::vector<L>\
    \ &lines) {\n        for (const auto &l : lines)\n            add(l);\n    }\n\
    \n    void add(L l) {\n        if (OBJ == -1)\n            l = -l;\n        if\
    \ (mp1.count(l.a)) {\n            if (mp1[l.a] <= l.b)\n                return;\n\
    \            mp1.erase(l.a);\n        }\n        auto [it, flag] = mp1.insert(make_std::pair(l.a,\
    \ l.b));\n        if (check(it)) {\n            mp1.erase(it);\n            return;\n\
    \        }\n        if (it != mp1.begin())\n            for (auto l = pre(it);\
    \ check(l); l = --mp1.erase(l)) {\n            }\n        if (nxt(it) != mp1.end())\n\
    \            for (auto r = nxt(it); check(r); r = mp1.erase(r)) {\n          \
    \  }\n    }\n    void add(T a, T b) { add(L(a, b)); }\n\n    T query(T x) const\
    \ {\n        assert(mp1.size());\n        if (mp2.begin())\n    }\n};\n} // namespace\
    \ insert_convex_hull_trick\ntemplate <typename T>\nusing MinConvexHullTrick =\n\
    \    convex_hull_trick::ConvexHullTrick<T,\n                                 \
    \      convex_hull_trick::Objective::MINIMIZE>;\ntemplate <typename T>\nusing\
    \ MaxConvexHullTrick =\n    convex_hull_trick::ConvexHullTrick<T,\n          \
    \                             convex_hull_trick::Objective::MAXIMIZE>;"
  dependsOn:
  - library/linearalgebra/Linear.cpp
  isVerificationFile: false
  path: library/linearalgebra/InsertConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2024-04-13 19:11:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/linearalgebra/InsertConvexHullTrick.cpp
layout: document
redirect_from:
- /library/library/linearalgebra/InsertConvexHullTrick.cpp
- /library/library/linearalgebra/InsertConvexHullTrick.cpp.html
title: library/linearalgebra/InsertConvexHullTrick.cpp
---
