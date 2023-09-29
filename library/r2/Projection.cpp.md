---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/r2/XY.cpp
    title: library/r2/XY.cpp
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum_2.test.cpp
    title: test/library-checker/DataStructure/RectangleSum_2.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/util/Compress.cpp\"\n#define ALL_(v) v.begin(),v.end()\n\
    template<typename T,bool Sentinel=false>\nclass Compress{\n  vector<T> v;\n  bool\
    \ prepared;\npublic:\n  Compress():prepared(false){\n    if constexpr(Sentinel){\n\
    \      static_assert(std::numeric_limits<T>::is_specialized,\"cannot use Sentinel\"\
    );\n      v={numeric_limits<T>::min(),numeric_limits<T>::max()};\n    }\n  }\n\
    \  Compress(const vector<T>&w):v(w),prepared(false){\n    if constexpr(Sentinel){\n\
    \      static_assert(std::numeric_limits<T>::is_specialized,\"cannot use Sentinel\"\
    );\n      v.push_back(numeric_limits<T>::min());\n      v.push_back(numeric_limits<T>::max());\n\
    \    }\n    build();\n  }\n  \n  void add(T a){ \n    assert(!prepared);\n   \
    \ v.push_back(a); \n  }\n  void build(){\n    assert(!prepared);\n    prepared=true;\n\
    \    sort(ALL_(v));\n    v.erase(unique(ALL_(v)),v.end());\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  int operator[](const T&a)const{\n    assert(prepared);\n\
    \    auto it=lower_bound(ALL_(v),a);\n    assert(*it==a);\n    return distance(v.begin(),it);\n\
    \  }\n  int geq(const T&a)const{\n    assert(prepared);\n    auto it=lower_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int gt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=upper_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n  }\n\
    \  int leq(const T&a)const{\n    assert(prepared);\n    auto it=--upper_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int lt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=--lower_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n \
    \ }\n  T r(int id)const{\n    assert(prepared);\n    return v[id];\n  }\n  bool\
    \ exist(const T&a)const{\n    assert(prepared);\n    return (*lower_bound(ALL_(v),a))==a;\n\
    \  }\n  int size()const{return v.size();}\n  T max()const{ return v.back(); }\n\
    \  T min()const{ return v[0]; }\n\n  friend ostream&operator<<(ostream&os, const\
    \ Compress&C){ \n    for(int i=0;i<C.v.size();i++)os<<C.v[i]<<\":\"<<i<<\" \"\
    ;\n    return os;\n  }\n};\n#undef ALL_\n#line 2 \"library/r2/XY.cpp\"\ntemplate<typename\
    \ T>\nstruct XY{\n  T x,y;\n  XY()=default;\n  XY(T x,T y):x(x),y(y){}\n  XY(const\
    \ pair<T,T>&xy):x(xy.first),y(xy.second){}\n\n  XY operator+()const{ return *this;\
    \ }\n  XY operator-()const{ return XY(-x,-y); }\n\n  XY& operator++(){ x++;y++;return\
    \ *this; }\n  XY& operator--(){ x--;y--;return *this; }\n  XY& operator++(int){\
    \ XY a=*this; ++*this; return a; }\n  XY& operator--(int){ XY a=*this; --*this;\
    \ return a; }\n\n  XY& operator+=(const XY& v){ x+=v.x; y+=v.y; return *this;\
    \ }\n  XY& operator-=(const XY& v){ x-=v.x; y-=v.y; return *this; }\n  XY& operator*=(const\
    \ T& a){ x*=a; y*=a; return *this; }\n  XY& operator/=(const T& a){ x/=a; y/=a;\
    \ return *this; }\n\n  friend XY operator+(const XY& u,const XY& v){ return XY(u)+=v;\
    \ }\n  friend XY operator-(const XY& u,const XY& v){ return XY(u)-=v; }\n  friend\
    \ XY operator*(const XY&u,const T& a){ return XY(u)*=a; }\n  friend XY operator*(const\
    \ T& a,const XY&u){ return XY(u)*=a; }\n  friend XY operator/(const XY&u,const\
    \ T& a){ return XY(u)/=a; }\n\n  bool operator<(const XY&v)const{ return x!=v.x\
    \ ? x<v.x : y<v.y; }\n  bool operator>(const XY&v)const{ return x!=v.x ? x>v.x\
    \ : y>v.y; }\n  bool operator==(const XY&v)const{ return x==v.x and y==v.y; }\n\
    \  bool operator!=(const XY&v)const{ return !(*this==v); }\n\n  double arg()const{\
    \ return atan2(y,x); }\n\n  // [0,2pi) \u3067 \u03B8(u)<\u03B8(v) \u306E\u6642\
    \ true \n  // (0,0) \u306F 2pi \u306B\u76F8\u5F53\n  //static bool angle_cmp(const\
    \ XY&u,const XY&v){\n  //  using U=conditional_t< is_same_v<T,int>,long long,T>;\n\
    \  //  if(u==XY(0,0))return false;\n  //  if(v==XY(0,0))return true;\n  //  if(u.y==0){\n\
    \  //    if(u.x>0)return true;\n  //    if(v.y==0)return v.x<0;\n  //    return\
    \ v.y<0;\n  //  }\n  //  if(u.y>0){\n  //    if(v.y==0)return v.x<0;\n  //   \
    \ if(v.y<0)return true;\n  //    return U(v.x)*u.y <= U(u.x)*v.y;\n  //  }\n \
    \ //  if(v.y>=0)return false;\n  //  return U(v.x)*u.y <= U(u.x)*v.y;\n  //}\n\
    \n  friend T dot(const XY&u,const XY& v){ return u.x*v.x + u.y*v.y; }\n  T norm(){\
    \ return dot(*this,*this); }\n  T abs(){ return sqrt(norm()); }\n\n  friend istream&operator>>(istream&is,XY&v){\
    \ is>>v.x>>v.y; return is; }\n  friend ostream&operator<<(ostream&os,const XY&v){\
    \ os<<v.x<<\" \"<<v.y; return os;}\n\n  static XY direction(const char&c){\n \
    \   if(c=='R')return {1,0};\n    if(c=='L')return {-1,0};\n    if(c=='U')return\
    \ {0,-1};\n    if(c=='D')return {0,1};\n    return {0,0};\n  }\n};\n#line 4 \"\
    library/r2/Projection.cpp\"\ntemplate<typename T>\nclass Projection{\n  using\
    \ r2=XY<T>;\n  Compress<r2> C;\npublic:\n  Projection(const vector<r2>&v):C(v){}\n\
    \  int size(){ return C.size(); }\n  int id(r2 xy){ return C[xy]; }\n  int id(int\
    \ x,int y){ return C[r2(x,y)]; }\n  r2 r(int id){ return C.r(id); }\n  //[l,r)\
    \ \u3092\u8FD4\u3059\n  pair<int,int> interval(const T&l,const T&r){\n    if(C.max().x<l\
    \ or r<=C.min().x)return make_pair(0,0);\n    T mn=numeric_limits<T>::min();\n\
    \    int L=C.geq(r2(l,mn));\n    int R=C.geq(r2(r,mn));\n    return make_pair(L,R);\n\
    \  }\n};\n"
  code: "#pragma once\n#include \"library/util/Compress.cpp\"\n#include \"library/r2/XY.cpp\"\
    \ntemplate<typename T>\nclass Projection{\n  using r2=XY<T>;\n  Compress<r2> C;\n\
    public:\n  Projection(const vector<r2>&v):C(v){}\n  int size(){ return C.size();\
    \ }\n  int id(r2 xy){ return C[xy]; }\n  int id(int x,int y){ return C[r2(x,y)];\
    \ }\n  r2 r(int id){ return C.r(id); }\n  //[l,r) \u3092\u8FD4\u3059\n  pair<int,int>\
    \ interval(const T&l,const T&r){\n    if(C.max().x<l or r<=C.min().x)return make_pair(0,0);\n\
    \    T mn=numeric_limits<T>::min();\n    int L=C.geq(r2(l,mn));\n    int R=C.geq(r2(r,mn));\n\
    \    return make_pair(L,R);\n  }\n};\n"
  dependsOn:
  - library/util/Compress.cpp
  - library/r2/XY.cpp
  isVerificationFile: false
  path: library/r2/Projection.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/library-checker/DataStructure/RectangleSum_2.test.cpp
  - test/library-checker/DataStructure/RectangleSum.test.cpp
documentation_of: library/r2/Projection.cpp
layout: document
redirect_from:
- /library/library/r2/Projection.cpp
- /library/library/r2/Projection.cpp.html
title: library/r2/Projection.cpp
---
