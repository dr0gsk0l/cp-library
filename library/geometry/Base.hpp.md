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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/r2/XY.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/r2/XY.cpp\"\nnamespace geometry {\nconstexpr\
    \ double EPS = 1e-10, PI = acos(-1);\n\nbool is_equal(double a, double b) { return\
    \ abs(a - b) < EPS; }\n\nusing Point = XY<double>;\nbool cmp_y(const Point &p1,\
    \ const Point &p2) {\n    return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x;\n}\n\
    \nusing Vector = Point;\nusing Polygon = std::vector<Point>;\n\nstd::istream &operator>>(std::istream\
    \ &is, Polygon &p) {\n    for (Point &c : p)\n        is >> c;\n    return is;\n\
    }\n\nstruct Segment {\n    Point p1, p2;\n    Segment() {}\n    Segment(Point\
    \ p1, Point p2) : p1(p1), p2(p2) {}\n    friend std::istream &operator>>(std::istream\
    \ &is, Segment &s) {\n        is >> s.p1 >> s.p2;\n        return is;\n    }\n\
    \    double arg() const { return (p2 - p1).arg(); }\n};\nusing Line = Segment;\n\
    \nstruct Circle {\n    Point c;\n    double r;\n    Circle() {}\n    Circle(Point\
    \ c, double r) : c(c), r(r) {}\n    friend std::istream &operator>>(std::istream\
    \ &is, Circle &c) {\n        is >> c.c >> c.r;\n        return is;\n    }\n};\n\
    } // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/Base.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/Base.hpp
layout: document
redirect_from:
- /library/library/geometry/Base.hpp
- /library/library/geometry/Base.hpp.html
title: library/geometry/Base.hpp
---
