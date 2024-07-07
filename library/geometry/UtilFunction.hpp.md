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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: library/geometry/Base.cpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"library/geometry/Base.cpp\"\nnamespace geometry\
    \ {\ndouble cross(Vector a, Vector b) {\n    // std::cerr << a <<\" \"<<b<<\"\
    :\"<<a.x*b.y-a.y*b.x<<endl;\n    return a.x * b.y - a.y * b.x;\n}\n\nPoint orth(Point\
    \ p) { return Point(-p.y, p.x); }\n\nPoint project(Segment s, Point p) {\n   \
    \ Vector base = s.p2 - s.p1;\n    double r = dot(p - s.p1, base) / base.norm();\n\
    \    return s.p1 + base * r;\n}\n\nPoint reflect(Segment s, Point p) { return\
    \ p + (project(s, p) - p) * 2.0; }\n\nPolygon convex_hull(Polygon ps) {\n    int\
    \ n = ps.size();\n    std::ranges::sort(ps, cmp_y);\n    int k = 0;\n    Polygon\
    \ qs(n * 2);\n    for (int i = 0; i < n; i++) {\n        while (k > 1 and cross(qs[k\
    \ - 1] - qs[k - 2], ps[i] - qs[k - 1]) < 0)\n            k--;\n        qs[k++]\
    \ = ps[i];\n    }\n    for (int i = n - 2, t = k; i >= 0; i--) {\n        while\
    \ (k > t and cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) < 0)\n          \
    \  k--;\n        qs[k++] = ps[i];\n    }\n    qs.resize(k - 1);\n    return qs;\n\
    }\n} // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/UtilFunction.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/UtilFunction.hpp
layout: document
redirect_from:
- /library/library/geometry/UtilFunction.hpp
- /library/library/geometry/UtilFunction.hpp.html
title: library/geometry/UtilFunction.hpp
---
