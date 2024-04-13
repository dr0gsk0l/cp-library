---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':x:'
    path: library/algebra/group/CntSum.cpp
    title: library/algebra/group/CntSum.cpp
  - icon: ':x:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
    title: test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/algebra/group/CntSum.cpp\"\ntemplate <typename X>\
    \ struct GroupCntSum {\n    using P = pair<X, X>;\n    using value_type = P;\n\
    \    static constexpr P op(const P &x, const P &y) {\n        return {x.first\
    \ + y.first, x.second + y.second};\n    }\n    static constexpr void Rchop(P &x,\
    \ const P &y) {\n        x.first += y.first;\n        x.second += y.second;\n\
    \    }\n    static constexpr void Lchop(const P &x, P &y) {\n        y.first +=\
    \ x.first;\n        y.second += x.second;\n    }\n    static constexpr P inverse(const\
    \ P &x) { return {-x.fi, -x.se}; }\n    static constexpr P unit() { return {0,\
    \ 0}; }\n    static constexpr bool commute = true;\n};\ntemplate <typename X>\
    \ vector<pair<X, X>> cnt_init(int n, const X &x) {\n    return std::vector<pair<X,\
    \ X>>(n, {x, 1});\n}\ntemplate <typename X> vector<pair<X, X>> cnt_init(const\
    \ std::vector<X> &v) {\n    int n = v.size();\n    std::vector<pair<X, X>> res(n);\n\
    \    for (int i = 0; i < n; i++)\n        res[i] = {v[i], 1};\n    return res;\n\
    }\n#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate<typename T>\nstruct\
    \ Line{\n  T a,b;\n  Line()=default;\n  Line(T a,T b):a(a),b(b){}\n  Line(pair<T,T>\
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
    \  else os<<l.a<<\"x-\"<<-l.b;\n    return os;\n  }\n};\n#line 3 \"library/algebra/group/Affine.cpp\"\
    \ntemplate<typename T>\nstruct GroupAffine{\n  using L = Line<T>;\n  using value_type\
    \ = L;\n  static constexpr L op(const L&f, const L&g)noexcept{ return f(g); }\n\
    \  static constexpr void Rchop(L&f, const L&g){\n    f.b += f.a*g.b;\n    f.a\
    \ *= g.a;\n  }\n  static constexpr void Lchop(const L&f, L&g){\n    (g.b *= f.a)\
    \ += f.b;\n    g.a *= f.a;\n  }\n  static constexpr L inverse(const L&f){ return\
    \ f.inv(); }\n  /*\n  static constexpr L power(const L& f,long long n) noexcept\
    \ {\n    if(a==1)return {1,n*b};\n    K an=power(a,n);\n    return {an,b*((1-an)/(1-a))};\n\
    \  }\n  */\n  static constexpr L unit(){ return L(1,0); }\n  static constexpr\
    \ bool commute = false;\n};\n#line 4 \"library/algebra/lazy/AffineSum.cpp\"\n\
    template<typename X>\nstruct LazyAffineSum{\n  using MX=GroupCntSum<X>;\n  using\
    \ MF=GroupAffine<X>;\n  using P=typename MX::value_type;\n  using F=typename MF::value_type;\n\
    \  static constexpr P mapping(const F&f,const P&x){\n    return {f.a*x.first+f.b*x.second,\
    \ x.second};\n  }\n};\n"
  code: "#pragma once\n#include \"library/algebra/group/CntSum.cpp\"\n#include \"\
    library/algebra/group/Affine.cpp\"\ntemplate<typename X>\nstruct LazyAffineSum{\n\
    \  using MX=GroupCntSum<X>;\n  using MF=GroupAffine<X>;\n  using P=typename MX::value_type;\n\
    \  using F=typename MF::value_type;\n  static constexpr P mapping(const F&f,const\
    \ P&x){\n    return {f.a*x.first+f.b*x.second, x.second};\n  }\n};\n"
  dependsOn:
  - library/algebra/group/CntSum.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  isVerificationFile: false
  path: library/algebra/lazy/AffineSum.cpp
  requiredBy: []
  timestamp: '2024-04-13 17:39:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/DataStructure/RangeAffineRangeSum.test.cpp
documentation_of: library/algebra/lazy/AffineSum.cpp
layout: document
redirect_from:
- /library/library/algebra/lazy/AffineSum.cpp
- /library/library/algebra/lazy/AffineSum.cpp.html
title: library/algebra/lazy/AffineSum.cpp
---
