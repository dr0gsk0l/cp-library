---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':x:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':x:'
    path: library/algebra/lazy/AffineSum.cpp
    title: library/algebra/lazy/AffineSum.cpp
  - icon: ':x:'
    path: library/linearalgebra/ConvexHullTrick.cpp
    title: library/linearalgebra/ConvexHullTrick.cpp
  - icon: ':warning:'
    path: library/linearalgebra/InsertConvexHullTrick.cpp
    title: library/linearalgebra/InsertConvexHullTrick.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
    title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
    title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - icon: ':x:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - icon: ':x:'
    path: test/library-checker/Tree/vertex_set_path_composite.test.cpp
    title: test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - icon: ':x:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate<typename T>\n\
    struct Line{\n  T a,b;\n  Line()=default;\n  Line(T a,T b):a(a),b(b){}\n  Line(pair<T,T>\
    \ l):a(l.first),b(l.second){}\n  Line(T c):a(0),b(c){}\n\n  T operator()(const\
    \ T x)const{ return a*x+b; }\n  Line operator()(const Line&l)const{ return Line(a*l.a,\
    \ a*l.b+b); }\n\n  bool operator==(const Line&l)const{ return a==l.a and b==l.b;\
    \ }\n  bool operator!=(const Line&l)const{ return !(*this == l); }\n  bool operator<(const\
    \ Line&l)const{ return (a==l.a ? a<l.a : b<l.b); }\n\n  Line&operator+=(const\
    \ Line&l){ a+=l.a; b+=l.b; return *this; }\n  Line operator+(const Line&l)const{return\
    \ Line(*this) += l; }\n  Line&operator-=(const Line&l){ a-=l.a; b-=l.b; return\
    \ *this; }\n  Line operator-(const Line&l)const{return Line(*this) -= l; }\n \
    \ Line operator-()const{ return Line(-a,-b); }\n\n  Line&operator+=(const T&c){\
    \ b+=c; return *this; }\n  Line operator+(const T&c)const{ return Line(*this)\
    \ += c; }\n  Line&operator-=(const T&c){ b-=c; return *this; }\n  Line operator-(const\
    \ T&c)const{ return Line(*this) -= c; }\n  Line&operator*=(const T&c){ a*=c; b*=c;\
    \ return *this; }\n  Line operator*(const T&c)const{ return Line(*this) *= c;\
    \ }\n  Line&operator/=(const T&c){ a/=c; b/=c; return *this; }\n  Line operator/(const\
    \ T&c)const{ return Line(*this) /= c; }\n\n  Line inv()const{\n    assert(a!=0);\n\
    \    return Line(T(1)/a, -b/a);\n  }\n\n  friend istream&operator>>(istream&is,Line&l){\n\
    \    is>>l.a>>l.b;\n    return is;\n  }\n  friend ostream&operator<<(ostream&os,const\
    \ Line&l){\n    if(l.a==0 and l.b==0)os<<0;\n    else if(l.a==0)os<<l.b;\n   \
    \ else if(l.b==0)os<<l.a<<\"x\";\n    else if(l.b>0)os<<l.a<<\"x+\"<<l.b;\n  \
    \  else os<<l.a<<\"x-\"<<-l.b;\n    return os;\n  }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct Line{\n  T a,b;\n  Line()=default;\n\
    \  Line(T a,T b):a(a),b(b){}\n  Line(pair<T,T> l):a(l.first),b(l.second){}\n \
    \ Line(T c):a(0),b(c){}\n\n  T operator()(const T x)const{ return a*x+b; }\n \
    \ Line operator()(const Line&l)const{ return Line(a*l.a, a*l.b+b); }\n\n  bool\
    \ operator==(const Line&l)const{ return a==l.a and b==l.b; }\n  bool operator!=(const\
    \ Line&l)const{ return !(*this == l); }\n  bool operator<(const Line&l)const{\
    \ return (a==l.a ? a<l.a : b<l.b); }\n\n  Line&operator+=(const Line&l){ a+=l.a;\
    \ b+=l.b; return *this; }\n  Line operator+(const Line&l)const{return Line(*this)\
    \ += l; }\n  Line&operator-=(const Line&l){ a-=l.a; b-=l.b; return *this; }\n\
    \  Line operator-(const Line&l)const{return Line(*this) -= l; }\n  Line operator-()const{\
    \ return Line(-a,-b); }\n\n  Line&operator+=(const T&c){ b+=c; return *this; }\n\
    \  Line operator+(const T&c)const{ return Line(*this) += c; }\n  Line&operator-=(const\
    \ T&c){ b-=c; return *this; }\n  Line operator-(const T&c)const{ return Line(*this)\
    \ -= c; }\n  Line&operator*=(const T&c){ a*=c; b*=c; return *this; }\n  Line operator*(const\
    \ T&c)const{ return Line(*this) *= c; }\n  Line&operator/=(const T&c){ a/=c; b/=c;\
    \ return *this; }\n  Line operator/(const T&c)const{ return Line(*this) /= c;\
    \ }\n\n  Line inv()const{\n    assert(a!=0);\n    return Line(T(1)/a, -b/a);\n\
    \  }\n\n  friend istream&operator>>(istream&is,Line&l){\n    is>>l.a>>l.b;\n \
    \   return is;\n  }\n  friend ostream&operator<<(ostream&os,const Line&l){\n \
    \   if(l.a==0 and l.b==0)os<<0;\n    else if(l.a==0)os<<l.b;\n    else if(l.b==0)os<<l.a<<\"\
    x\";\n    else if(l.b>0)os<<l.a<<\"x+\"<<l.b;\n    else os<<l.a<<\"x-\"<<-l.b;\n\
    \    return os;\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/Linear.cpp
  requiredBy:
  - library/linearalgebra/InsertConvexHullTrick.cpp
  - library/linearalgebra/ConvexHullTrick.cpp
  - library/algebra/group/Affine.cpp
  - library/algebra/lazy/AffineSum.cpp
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  - test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  - test/library-checker/Tree/vertex_set_path_composite.test.cpp
  - test/yukicoder/2012.test.cpp
documentation_of: library/linearalgebra/Linear.cpp
layout: document
redirect_from:
- /library/library/linearalgebra/Linear.cpp
- /library/library/linearalgebra/Linear.cpp.html
title: library/linearalgebra/Linear.cpp
---
