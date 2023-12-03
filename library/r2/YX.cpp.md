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
  bundledCode: "#line 2 \"library/r2/YX.cpp\"\ntemplate<typename T>\nstruct YX{\n\
    \  T y,x;\n  YX()=default;\n  YX(T y,T x):y(y),x(x){}\n  YX(const pair<T,T>&yx):y(yx.first),x(yx.second){}\n\
    \n  YX operator+()const{ return *this; }\n  YX operator-()const{ return YX(-y,-x);\
    \ }\n\n  YX& operator++(){ y++;x++;return *this; }\n  YX& operator--(){ y--;x--;return\
    \ *this; }\n  YX& operator++(int){ YX a=*this; ++*this; return a; }\n  YX& operator--(int){\
    \ YX a=*this; --*this; return a; }\n\n  YX& operator+=(const YX& v){ y+=v.y; x+=v.x;\
    \ return *this; }\n  YX& operator-=(const YX& v){ y-=v.y; x-=v.x; return *this;\
    \ }\n  YX& operator*=(const T& a){ y*=a; x*=a; return *this; }\n  YX& operator/=(const\
    \ T& a){ y/=a; x/=a; return *this; }\n\n  friend YX operator+(const YX& u,const\
    \ YX& v){ return YX(u)+=v; }\n  friend YX operator-(const YX& u,const YX& v){\
    \ return YX(u)-=v; }\n  friend YX operator*(const YX&u,const T& a){ return YX(u)*=a;\
    \ }\n  friend YX operator*(const T& a,const YX&u){ return YX(u)*=a; }\n  friend\
    \ YX operator/(const YX&u,const T& a){ return YX(u)/=a; }\n\n  bool operator<(const\
    \ YX&v)const{ return y!=v.y ? y<v.y : x<v.x; }\n  bool operator>(const YX&v)const{\
    \ return y!=v.y ? y>v.y : x>v.x; }\n  bool operator==(const YX&v)const{ return\
    \ y==v.y and x==v.x; }\n  bool operator!=(const YX&v)const{ return !(*this==v);\
    \ }\n\n  friend T dot(const YX&u,const YX& v){ return u.y*v.y + u.x*v.x; }\n \
    \ T square_abs(){ return dot(*this,*this); }\n  T abs(){ return sqrt(square_abs());\
    \ }\n\n  friend istream&operator>>(istream&is,YX&v){ is>>v.y>>v.x; return is;\
    \ }\n  friend ostream&operator<<(ostream&os,const YX&v){ os<<v.y<<\" \"<<v.x;\
    \ return os;}\n\n  static YX direction(const char&c){\n    if(c=='R')return {0,1};\n\
    \    if(c=='L')return {0,-1};\n    if(c=='U')return {-1,0};\n    if(c=='D')return\
    \ {1,0};\n    return {0,0};\n  }\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct YX{\n  T y,x;\n  YX()=default;\n\
    \  YX(T y,T x):y(y),x(x){}\n  YX(const pair<T,T>&yx):y(yx.first),x(yx.second){}\n\
    \n  YX operator+()const{ return *this; }\n  YX operator-()const{ return YX(-y,-x);\
    \ }\n\n  YX& operator++(){ y++;x++;return *this; }\n  YX& operator--(){ y--;x--;return\
    \ *this; }\n  YX& operator++(int){ YX a=*this; ++*this; return a; }\n  YX& operator--(int){\
    \ YX a=*this; --*this; return a; }\n\n  YX& operator+=(const YX& v){ y+=v.y; x+=v.x;\
    \ return *this; }\n  YX& operator-=(const YX& v){ y-=v.y; x-=v.x; return *this;\
    \ }\n  YX& operator*=(const T& a){ y*=a; x*=a; return *this; }\n  YX& operator/=(const\
    \ T& a){ y/=a; x/=a; return *this; }\n\n  friend YX operator+(const YX& u,const\
    \ YX& v){ return YX(u)+=v; }\n  friend YX operator-(const YX& u,const YX& v){\
    \ return YX(u)-=v; }\n  friend YX operator*(const YX&u,const T& a){ return YX(u)*=a;\
    \ }\n  friend YX operator*(const T& a,const YX&u){ return YX(u)*=a; }\n  friend\
    \ YX operator/(const YX&u,const T& a){ return YX(u)/=a; }\n\n  bool operator<(const\
    \ YX&v)const{ return y!=v.y ? y<v.y : x<v.x; }\n  bool operator>(const YX&v)const{\
    \ return y!=v.y ? y>v.y : x>v.x; }\n  bool operator==(const YX&v)const{ return\
    \ y==v.y and x==v.x; }\n  bool operator!=(const YX&v)const{ return !(*this==v);\
    \ }\n\n  friend T dot(const YX&u,const YX& v){ return u.y*v.y + u.x*v.x; }\n \
    \ T square_abs(){ return dot(*this,*this); }\n  T abs(){ return sqrt(square_abs());\
    \ }\n\n  friend istream&operator>>(istream&is,YX&v){ is>>v.y>>v.x; return is;\
    \ }\n  friend ostream&operator<<(ostream&os,const YX&v){ os<<v.y<<\" \"<<v.x;\
    \ return os;}\n\n  static YX direction(const char&c){\n    if(c=='R')return {0,1};\n\
    \    if(c=='L')return {0,-1};\n    if(c=='U')return {-1,0};\n    if(c=='D')return\
    \ {1,0};\n    return {0,0};\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/r2/YX.cpp
  requiredBy: []
  timestamp: '2023-12-03 16:05:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/r2/YX.cpp
layout: document
redirect_from:
- /library/library/r2/YX.cpp
- /library/library/r2/YX.cpp.html
title: library/r2/YX.cpp
---
