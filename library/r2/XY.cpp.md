---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/geometry/Base.cpp
    title: library/geometry/Base.cpp
  - icon: ':warning:'
    path: library/geometry/Judge.cpp
    title: library/geometry/Judge.cpp
  - icon: ':heavy_check_mark:'
    path: library/geometry/UtilFunction.cpp
    title: library/geometry/UtilFunction.cpp
  - icon: ':heavy_check_mark:'
    path: library/r2/Projection.cpp
    title: library/r2/Projection.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/CGL_4_A.test.cpp
    title: test/AOJ/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/r2/XY.cpp\"\ntemplate<typename T>\nstruct XY{\n\
    \  T x,y;\n  XY()=default;\n  XY(T x,T y):x(x),y(y){}\n  XY(const pair<T,T>&xy):x(xy.first),y(xy.second){}\n\
    \n  XY operator+()const{ return *this; }\n  XY operator-()const{ return XY(-x,-y);\
    \ }\n\n  XY& operator++(){ x++;y++;return *this; }\n  XY& operator--(){ x--;y--;return\
    \ *this; }\n  XY& operator++(int){ XY a=*this; ++*this; return a; }\n  XY& operator--(int){\
    \ XY a=*this; --*this; return a; }\n\n  XY& operator+=(const XY& v){ x+=v.x; y+=v.y;\
    \ return *this; }\n  XY& operator-=(const XY& v){ x-=v.x; y-=v.y; return *this;\
    \ }\n  XY& operator*=(const T& a){ x*=a; y*=a; return *this; }\n  XY& operator/=(const\
    \ T& a){ x/=a; y/=a; return *this; }\n\n  friend XY operator+(const XY& u,const\
    \ XY& v){ return XY(u)+=v; }\n  friend XY operator-(const XY& u,const XY& v){\
    \ return XY(u)-=v; }\n  friend XY operator*(const XY&u,const T& a){ return XY(u)*=a;\
    \ }\n  friend XY operator*(const T& a,const XY&u){ return XY(u)*=a; }\n  friend\
    \ XY operator/(const XY&u,const T& a){ return XY(u)/=a; }\n\n  bool operator<(const\
    \ XY&v)const{ return x!=v.x ? x<v.x : y<v.y; }\n  bool operator>(const XY&v)const{\
    \ return x!=v.x ? x>v.x : y>v.y; }\n  bool operator==(const XY&v)const{ return\
    \ x==v.x and y==v.y; }\n  bool operator!=(const XY&v)const{ return !(*this==v);\
    \ }\n\n  double arg()const{ return atan2(y,x); }\n\n  // [0,2pi) \u3067 \u03B8\
    (u)<\u03B8(v) \u306E\u6642 true \n  // (0,0) \u306F 2pi \u306B\u76F8\u5F53\n \
    \ //static bool angle_cmp(const XY&u,const XY&v){\n  //  using U=conditional_t<\
    \ is_same_v<T,int>,long long,T>;\n  //  if(u==XY(0,0))return false;\n  //  if(v==XY(0,0))return\
    \ true;\n  //  if(u.y==0){\n  //    if(u.x>0)return true;\n  //    if(v.y==0)return\
    \ v.x<0;\n  //    return v.y<0;\n  //  }\n  //  if(u.y>0){\n  //    if(v.y==0)return\
    \ v.x<0;\n  //    if(v.y<0)return true;\n  //    return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \  //  }\n  //  if(v.y>=0)return false;\n  //  return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \  //}\n\n  friend T dot(const XY&u,const XY& v){ return u.x*v.x + u.y*v.y; }\n\
    \  T norm(){ return dot(*this,*this); }\n  T abs(){ return sqrt(norm()); }\n\n\
    \  friend istream&operator>>(istream&is,XY&v){ is>>v.x>>v.y; return is; }\n  friend\
    \ ostream&operator<<(ostream&os,const XY&v){ os<<v.x<<\" \"<<v.y; return os;}\n\
    \n  static XY direction(const char&c){\n    if(c=='R')return {1,0};\n    if(c=='L')return\
    \ {-1,0};\n    if(c=='U')return {0,-1};\n    if(c=='D')return {0,1};\n    return\
    \ {0,0};\n  }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct XY{\n  T x,y;\n  XY()=default;\n\
    \  XY(T x,T y):x(x),y(y){}\n  XY(const pair<T,T>&xy):x(xy.first),y(xy.second){}\n\
    \n  XY operator+()const{ return *this; }\n  XY operator-()const{ return XY(-x,-y);\
    \ }\n\n  XY& operator++(){ x++;y++;return *this; }\n  XY& operator--(){ x--;y--;return\
    \ *this; }\n  XY& operator++(int){ XY a=*this; ++*this; return a; }\n  XY& operator--(int){\
    \ XY a=*this; --*this; return a; }\n\n  XY& operator+=(const XY& v){ x+=v.x; y+=v.y;\
    \ return *this; }\n  XY& operator-=(const XY& v){ x-=v.x; y-=v.y; return *this;\
    \ }\n  XY& operator*=(const T& a){ x*=a; y*=a; return *this; }\n  XY& operator/=(const\
    \ T& a){ x/=a; y/=a; return *this; }\n\n  friend XY operator+(const XY& u,const\
    \ XY& v){ return XY(u)+=v; }\n  friend XY operator-(const XY& u,const XY& v){\
    \ return XY(u)-=v; }\n  friend XY operator*(const XY&u,const T& a){ return XY(u)*=a;\
    \ }\n  friend XY operator*(const T& a,const XY&u){ return XY(u)*=a; }\n  friend\
    \ XY operator/(const XY&u,const T& a){ return XY(u)/=a; }\n\n  bool operator<(const\
    \ XY&v)const{ return x!=v.x ? x<v.x : y<v.y; }\n  bool operator>(const XY&v)const{\
    \ return x!=v.x ? x>v.x : y>v.y; }\n  bool operator==(const XY&v)const{ return\
    \ x==v.x and y==v.y; }\n  bool operator!=(const XY&v)const{ return !(*this==v);\
    \ }\n\n  double arg()const{ return atan2(y,x); }\n\n  // [0,2pi) \u3067 \u03B8\
    (u)<\u03B8(v) \u306E\u6642 true \n  // (0,0) \u306F 2pi \u306B\u76F8\u5F53\n \
    \ //static bool angle_cmp(const XY&u,const XY&v){\n  //  using U=conditional_t<\
    \ is_same_v<T,int>,long long,T>;\n  //  if(u==XY(0,0))return false;\n  //  if(v==XY(0,0))return\
    \ true;\n  //  if(u.y==0){\n  //    if(u.x>0)return true;\n  //    if(v.y==0)return\
    \ v.x<0;\n  //    return v.y<0;\n  //  }\n  //  if(u.y>0){\n  //    if(v.y==0)return\
    \ v.x<0;\n  //    if(v.y<0)return true;\n  //    return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \  //  }\n  //  if(v.y>=0)return false;\n  //  return U(v.x)*u.y <= U(u.x)*v.y;\n\
    \  //}\n\n  friend T dot(const XY&u,const XY& v){ return u.x*v.x + u.y*v.y; }\n\
    \  T norm(){ return dot(*this,*this); }\n  T abs(){ return sqrt(norm()); }\n\n\
    \  friend istream&operator>>(istream&is,XY&v){ is>>v.x>>v.y; return is; }\n  friend\
    \ ostream&operator<<(ostream&os,const XY&v){ os<<v.x<<\" \"<<v.y; return os;}\n\
    \n  static XY direction(const char&c){\n    if(c=='R')return {1,0};\n    if(c=='L')return\
    \ {-1,0};\n    if(c=='U')return {0,-1};\n    if(c=='D')return {0,1};\n    return\
    \ {0,0};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/r2/XY.cpp
  requiredBy:
  - library/r2/Projection.cpp
  - library/geometry/Judge.cpp
  - library/geometry/UtilFunction.cpp
  - library/geometry/Base.cpp
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/2012.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/AOJ/CGL_4_A.test.cpp
documentation_of: library/r2/XY.cpp
layout: document
redirect_from:
- /library/library/r2/XY.cpp
- /library/library/r2/XY.cpp.html
title: library/r2/XY.cpp
---