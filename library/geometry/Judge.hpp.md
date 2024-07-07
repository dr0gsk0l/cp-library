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
  code: "#pragma once\n#include \"library/geometry/Base.cpp\"\n#include \"library/geometry/UtilFunction.cpp\"\
    \nnamespace geometry{\n  bool is_orthogonal(Vector a,Vector b){\n    return is_equal(dot(a,b),0.0);\n\
    \  }\n  bool is_orthogonal(Point a1,Point a2,Point b1,Point b2){\n    return is_orthogonal(a1-a2,b1-b2);\n\
    \  }\n  bool is_orthogonal(Segment s1,Segment s2){\n    return is_equal(dot(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n\
    \  }\n\n  bool is_parallel(Vector a,Vector b){\n    return is_equal(cross(a,b),0.0);\n\
    \  }\n  bool is_parallel(Point a1,Point a2,Point b1,Point b2){\n    return is_parallel(a1-a2,b1-b2);\n\
    \  }\n  bool is_parallel(Segment s1,Segment s2){\n    return is_equal(cross(s1.p2-s1.p1,s2.p2-s2.p1),0.0);\n\
    \  }\n  \n  //bool is_intersect(Point p1,Point p2,Point p3,Point p4){\n  //  return\
    \ (ccw(p1,p2,p3)*ccw(p1,p2,p4) <= 0 and\n  //          ccw(p3,p4,p1)*ccw(p3,p4,p2)\
    \ <= 0 );\n  //}\n  //bool is_intersect(Segment s1,Segment s2){\n  //  return\
    \ is_intersect(s1.p1,s1.p2,s2.p1,s2.p2);\n  //}\n  //bool is_intersect(Polygon\
    \ p,Segment l){\n  //  int n=p.size();\n  //  for(int i=0;i<n;i++)\n  //    if(is_intersect(Segment(p[i],p[(i+1)%n]),l))\
    \ return 1;\n  //  return 0;\n  //}\n//\n  //bool is_convex(Polygon p){\n  //\
    \  bool f=1;\n  //  int n=p.size();\n  //  for(int i=0;i<n;i++){\n  //    int\
    \ t=ccw(p[(i+n-1)%n],p[i],p[(i+1)%n]);\n  //    f&=t!=CCW_CLOCKWISE;\n  //  }\n\
    \  //  return f;\n  //}\n}"
  dependsOn: []
  isVerificationFile: false
  path: library/geometry/Judge.hpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/geometry/Judge.hpp
layout: document
redirect_from:
- /library/library/geometry/Judge.hpp
- /library/library/geometry/Judge.hpp.html
title: library/geometry/Judge.hpp
---
