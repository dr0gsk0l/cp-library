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
  bundledCode: "#line 2 \"library/math/Fraction.cpp\"\ntemplate<typename T>\nstruct\
    \ Fraction{\n  T num,den;\n  Fraction(T n=0,T d=1):num(n),den(d){\n    assert(den!=0);\n\
    \    if(den<0)num=-num,den=-den;\n    T g=gcd(abs(num),abs(den));\n    num/=g;\n\
    \    den/=g;\n  }\n\n  Fraction operator+(const Fraction& b)const{ return Fraction(\
    \ num*b.den + den*b.num, den*b.den ); }\n  Fraction operator-(const Fraction&\
    \ b)const{ return Fraction( num*b.den - den*b.num, den*b.den ); }\n  Fraction\
    \ operator*(const Fraction& b)const{ return Fraction( num*b.num, den*b.den );\
    \ }\n  Fraction operator/(const Fraction& b)const{ return Fraction( num*b.den,\
    \ den*b.num ); }\n  Fraction& operator+=(const Fraction& b){ return *this = (*this)\
    \ + b; }\n  Fraction& operator-=(const Fraction& b){ return *this = (*this) -\
    \ b; }\n  Fraction& operator*=(const Fraction& b){ return *this = (*this) * b;\
    \ }\n  Fraction& operator/=(const Fraction& b){ return *this = (*this) / b; }\n\
    \  Fraction operator+(const T&c)const{ return (*this)+Fraction(c,1); }\n  Fraction\
    \ operator-(const T&c)const{ return (*this)-Fraction(c,1); }\n  Fraction operator*(const\
    \ T&c)const{ return (*this)*Fraction(c,1); }\n  Fraction operator/(const T&c)const{\
    \ return (*this)/Fraction(c,1); }\n  friend Fraction operator+(const T&c, Fraction\
    \ b){ return Fraction(c,1)+b; }\n  friend Fraction operator-(const T&c, Fraction\
    \ b){ return Fraction(c,1)-b; }\n  friend Fraction operator*(const T&c, Fraction\
    \ b){ return Fraction(c,1)*b; }\n  friend Fraction operator/(const T&c, Fraction\
    \ b){ return Fraction(c,1)/b; }\n  Fraction& operator+=(const T&c){ return *this\
    \ = (*this)+c; }\n  Fraction& operator-=(const T&c){ return *this = (*this)-c;\
    \ }\n  Fraction& operator*=(const T&c){ return *this = (*this)*c; }\n  Fraction&\
    \ operator/=(const T&c){ return *this = (*this)/c; }\n  Fraction& operator++(){\
    \ return (*this)+=1; }\n  Fraction& operator--(){ return (*this)-=1; }\n  Fraction&\
    \ operator++(int){ return (*this)+=1; }\n  Fraction& operator--(int){ return (*this)-=1;\
    \ }\n  Fraction operator+()const{ return *this; }\n  Fraction operator-()const{\
    \ return Fraction(-num,den); }\n\n  static Fraction raw(T a){ return Fraction(a,1);\
    \ }\n  Fraction pow(long long k)const{\n    Fraction res(1,1), tmp(*this);\n \
    \   while(k){\n      if(k&1)res*=res;\n      tmp*=tmp;\n      k>>=1;\n    }\n\
    \    return res;\n  }\n  Fraction inv(){ return Fraction(den,num); }\n\n  friend\
    \ ostream& operator<<(ostream&os,const Fraction &a){os<<a.num<<\"/\"<<a.den;return\
    \ os;}\n  friend istream& operator>>(istream&is,Fraction &a){ is>>a.num;a.den=1;\
    \ return is;}\n\n#define define_cmp(op) \\\n  bool operator op (const Fraction&\
    \ b) const{ return num*b.den op b.num*den; }\n  define_cmp(==)\n  define_cmp(!=)\n\
    \  define_cmp(<)\n  define_cmp(>)\n  define_cmp(<=)\n  define_cmp(>=)\n#undef\
    \ define_cmp\n};\n"
  code: "#pragma once\ntemplate<typename T>\nstruct Fraction{\n  T num,den;\n  Fraction(T\
    \ n=0,T d=1):num(n),den(d){\n    assert(den!=0);\n    if(den<0)num=-num,den=-den;\n\
    \    T g=gcd(abs(num),abs(den));\n    num/=g;\n    den/=g;\n  }\n\n  Fraction\
    \ operator+(const Fraction& b)const{ return Fraction( num*b.den + den*b.num, den*b.den\
    \ ); }\n  Fraction operator-(const Fraction& b)const{ return Fraction( num*b.den\
    \ - den*b.num, den*b.den ); }\n  Fraction operator*(const Fraction& b)const{ return\
    \ Fraction( num*b.num, den*b.den ); }\n  Fraction operator/(const Fraction& b)const{\
    \ return Fraction( num*b.den, den*b.num ); }\n  Fraction& operator+=(const Fraction&\
    \ b){ return *this = (*this) + b; }\n  Fraction& operator-=(const Fraction& b){\
    \ return *this = (*this) - b; }\n  Fraction& operator*=(const Fraction& b){ return\
    \ *this = (*this) * b; }\n  Fraction& operator/=(const Fraction& b){ return *this\
    \ = (*this) / b; }\n  Fraction operator+(const T&c)const{ return (*this)+Fraction(c,1);\
    \ }\n  Fraction operator-(const T&c)const{ return (*this)-Fraction(c,1); }\n \
    \ Fraction operator*(const T&c)const{ return (*this)*Fraction(c,1); }\n  Fraction\
    \ operator/(const T&c)const{ return (*this)/Fraction(c,1); }\n  friend Fraction\
    \ operator+(const T&c, Fraction b){ return Fraction(c,1)+b; }\n  friend Fraction\
    \ operator-(const T&c, Fraction b){ return Fraction(c,1)-b; }\n  friend Fraction\
    \ operator*(const T&c, Fraction b){ return Fraction(c,1)*b; }\n  friend Fraction\
    \ operator/(const T&c, Fraction b){ return Fraction(c,1)/b; }\n  Fraction& operator+=(const\
    \ T&c){ return *this = (*this)+c; }\n  Fraction& operator-=(const T&c){ return\
    \ *this = (*this)-c; }\n  Fraction& operator*=(const T&c){ return *this = (*this)*c;\
    \ }\n  Fraction& operator/=(const T&c){ return *this = (*this)/c; }\n  Fraction&\
    \ operator++(){ return (*this)+=1; }\n  Fraction& operator--(){ return (*this)-=1;\
    \ }\n  Fraction& operator++(int){ return (*this)+=1; }\n  Fraction& operator--(int){\
    \ return (*this)-=1; }\n  Fraction operator+()const{ return *this; }\n  Fraction\
    \ operator-()const{ return Fraction(-num,den); }\n\n  static Fraction raw(T a){\
    \ return Fraction(a,1); }\n  Fraction pow(long long k)const{\n    Fraction res(1,1),\
    \ tmp(*this);\n    while(k){\n      if(k&1)res*=res;\n      tmp*=tmp;\n      k>>=1;\n\
    \    }\n    return res;\n  }\n  Fraction inv(){ return Fraction(den,num); }\n\n\
    \  friend ostream& operator<<(ostream&os,const Fraction &a){os<<a.num<<\"/\"<<a.den;return\
    \ os;}\n  friend istream& operator>>(istream&is,Fraction &a){ is>>a.num;a.den=1;\
    \ return is;}\n\n#define define_cmp(op) \\\n  bool operator op (const Fraction&\
    \ b) const{ return num*b.den op b.num*den; }\n  define_cmp(==)\n  define_cmp(!=)\n\
    \  define_cmp(<)\n  define_cmp(>)\n  define_cmp(<=)\n  define_cmp(>=)\n#undef\
    \ define_cmp\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/math/Fraction.cpp
  requiredBy: []
  timestamp: '2023-12-03 16:05:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: library/math/Fraction.cpp
layout: document
redirect_from:
- /library/library/math/Fraction.cpp
- /library/library/math/Fraction.cpp.html
title: library/math/Fraction.cpp
---
