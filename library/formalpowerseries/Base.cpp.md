---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: library/formalpowerseries/ComposeEXP.cpp
    title: library/formalpowerseries/ComposeEXP.cpp
  - icon: ':heavy_check_mark:'
    path: library/formalpowerseries/DivMod.cpp
    title: library/formalpowerseries/DivMod.cpp
  - icon: ':heavy_check_mark:'
    path: library/formalpowerseries/MultipointEvaluation.cpp
    title: library/formalpowerseries/MultipointEvaluation.cpp
  - icon: ':heavy_check_mark:'
    path: library/formalpowerseries/Prod.cpp
    title: library/formalpowerseries/Prod.cpp
  - icon: ':warning:'
    path: library/formalpowerseries/RationalSum.cpp
    title: library/formalpowerseries/RationalSum.cpp
  - icon: ':warning:'
    path: library/formalpowerseries/Sqrt.cpp
    title: library/formalpowerseries/Sqrt.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Composition.test.cpp
    title: test/library-checker/Polynomial/Composition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
    title: test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Exp.test.cpp
    title: test/library-checker/Polynomial/Exp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Inv.test.cpp
    title: test/library-checker/Polynomial/Inv.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Log.test.cpp
    title: test/library-checker/Polynomial/Log.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
    title: test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/Pow.test.cpp
    title: test/library-checker/Polynomial/Pow.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
    title: test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/Polynomial/TaylorShift.test.cpp
    title: test/library-checker/Polynomial/TaylorShift.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/formalpowerseries/Base.cpp\"\n#define REP_(i,n)\
    \ for(int i=0;i<(n);i++)\ntemplate<typename T,int MX>\nstruct FormalPowerSeries:vector<T>{\n\
    \  using FPS=FormalPowerSeries;\n  using vector<T>::resize;\n  using vector<T>::size;\n\
    \  using vector<T>::at;\n  using vector<T>::assign;\n  using vector<T>::vector;\n\
    \  using vector<T>::begin;\n  using vector<T>::end;\n  using vector<T>::back;\n\
    \  using vector<T>::pop_back;\n  using value_type=T;\n\n  void strict(int n){\
    \ if(size()>n)resize(n); }\n  void shrink(){ while(size() and back()==0)pop_back();\
    \ }\n\n  FormalPowerSeries(const vector<T>&f){\n    int n=min(MX,int(f.size()));\n\
    \    resize(n);\n    REP_(i,n)at(i)=f[i];\n    shrink();\n  }\n\n  static FPS\
    \ unit(){ return {1}; }\n  static FPS x(){ return {0,1}; }\n#pragma region operator\n\
    \  FPS operator-()const{\n    FPS g=*this;\n    for(T&a:g)a=-a;\n    return g;\n\
    \  }\n  \n  FPS &operator+=(const FPS&g){\n    if(size()<g.size())resize(g.size());\n\
    \    REP_(i,g.size())at(i)+=g[i];\n    return *this;\n  }\n  FPS operator+(const\
    \ FPS &g)const{return FPS(*this)+=g;}\n\n  FPS &operator+=(const T &a){\n    if(!size())resize(1);\n\
    \    at(0)+=a;\n    return *this;\n  }\n  FPS operator+(const T& a)const{return\
    \ FPS(*this)+=a;}\n  friend FPS operator+(const T&a,const FPS&f){return f+a;}\n\
    \n  FPS &operator-=(const FPS &g){\n    if(size()<g.size())resize(g.size());\n\
    \    REP_(i,g.size())at(i)-=g[i];\n    return *this;\n  }\n  FPS operator-(const\
    \ FPS &g)const{return FPS(*this)-=g;}\n\n  FPS &operator-=(const T &a){\n    if(!size())resize(1);\n\
    \    at(0)-=a;\n    return *this;\n  }\n  FPS operator-(const T& a){return FPS(*this)-=a;}\n\
    \  friend FPS operator-(const T&a,const FPS&f){return a+(-f);}\n  \n  FPS operator*(const\
    \ FPS&g)const{ return FPS(convolution(*this,g)); }\n  FPS&operator*=(const FPS&g){\
    \ return (*this)=(*this)*g; }\n\n  FPS&operator*=(const T &a){\n    REP_(i,size())at(i)*=a;\n\
    \    return *this;\n  }\n  FPS operator*(const T &a)const{ return FPS(*this)*=a;\
    \ }\n  friend FPS operator*(const T&a,const FPS&f){return f*a;}\n\n  FPS operator/(const\
    \ FPS g)const{ return (*this)*g.inv(); }\n  FPS&operator/=(const FPS&g){ return\
    \ (*this)=(*this)/g; }\n\n  FPS&operator/=(const T &a){ return *this *= a.inv();\
    \ }\n  FPS operator/(const T &a){ return  FPS(*this)/=a; }\n\n  FPS&operator<<=(const\
    \ int d){\n    if(d>=MX)return *this=FPS(0);\n    resize(min(MX,int(size())+d));\n\
    \    for(int i=int(size())-1-d;i>=0;i--)\n      at(i+d)=at(i);\n    for(int i=d-1;i>=0;i--)at(i)=0;\n\
    \    return *this;\n  }\n  FPS operator<<(const int d)const{ return FPS(*this)<<=d;\
    \ }\n  FPS&operator>>=(const int d){\n    if(d>=size())return *this=FPS(0);\n\
    \    for(int i=d;i<size();i++)\n      at(i-d)=at(i);\n    strict(int(size())-d);\n\
    \    return *this;\n  }\n  FPS operator>>(const int d)const{ return FPS(*this)>>=d;\
    \ }\n#pragma endregion operator\n\n  FPS pre(int n)const{\n    if(size()<=n)return\
    \ *this;\n    return FPS(begin(),begin()+n);\n  }\n\n  FPS inv(int SZ=MX)const{\n\
    \    assert(size() and at(0)!=0);\n    FPS res(1,at(0).inv());\n    for(int n=0;(1<<n)<SZ;n++){\n\
    \      // mod[1<<n] \u2192 mod[1<<(n+1)]\n      res *= (2- (res*pre(1<<(n+1))).pre(1<<(n+1)));\n\
    \      res.strict(1<<(n+1));\n    }\n    return res.pre(SZ);\n  }\n\n  FPS pow(long\
    \ long n)const{\n    assert(n>=0);\n    if(n==0)return unit();\n    if(n==1)return\
    \ *this;\n\n    FPS now=*this;\n    now.shrink();\n    if(!now.size())return now;\n\
    \    int d;\n    for(d=0;d<now.size() and now[d]==0;d++){}\n    if(d>=(MX+n-1)/n)return\
    \ FPS(0);\n    now >>= d;\n    d *= n;\n    if(at(0)==1)return exp(n*log(now))<<d;\n\
    \    FPS res=unit();\n    while(n){\n      if(n&1)res*=now;\n      now*=now;\n\
    \      n>>=1;\n    }\n    return res<<d;\n  }\n\n  // *this = f_1 + f_2 x^n \u21D2\
    \ [*this\u2190f_1, return f_2]\n  FPS separate(int n){\n    if(size()<=n)return\
    \ FPS(0);\n    FPS f_2(size()-n);\n    for(int i=n;i<size();i++)f_2[i-n]=at(i);\n\
    \    strict(n);\n    return f_2;\n  }\n\n  FPS operator()(FPS g)const{\n    assert(!g.size()\
    \ or g[0]==0); // \u81EA\u8EAB\u304C\u591A\u9805\u5F0F\u306A\u3089 g[0]!=0 \u3067\
    \u3082\u826F\u3044\n    if(size()==0)return *this;\n    if(size()==1)return FPS(1,at(0));\n\
    \    if(size()==2)return FPS(at(0)+at(1)*g);\n\n    int m=sqrt(MX/20);\n    FPS&g1=g;\n\
    \    FPS g2=g1.separate(m);\n\n    int z;\n    for(z=1;z<g1.size() and g1[z]==0;z++){}\n\
    \    if(z==g1.size()){\n      FPS res(0),\n          g2pow=FPS::unit();\n    \
    \  for(int i=0;i*m<MX and i<size();i++,g2pow*=g2)\n        res += at(i) * g2pow<<(i*m);\n\
    \      return res;\n    }\n    \n    //\u3000f[l,l+d) \u25CB g1 \u3092\u518D\u5E30\
    \u3067\u8A08\u7B97\n    auto rec=[&](auto rec,int l,int d){\n      if(d==0 or\
    \ l>=size())return FPS(0);\n      if(d==1)return FPS(1,at(l));\n      if(d==2)return\
    \ at(l) + (l+1<size()?at(l+1)*g1:FPS(0));\n      FPS f1=rec(rec,l,d>>1);\n   \
    \   FPS f2=rec(rec,l+(d>>1),d-(d>>1));\n      f2 *= g1.pow(d>>1);\n      return\
    \ f1+f2;\n    };\n    FPS res = rec(rec,0,size());\n\n    FPS dfg=res,\n     \
    \   g1inv=(differential(g)>>(--z)).inv(),\n        g2pow=FPS::unit();\n    T factinv=1;\n\
    \    \n    for(int i=1;i*m<MX;i++){\n      dfg=(differential(dfg)>>z)*g1inv;\n\
    \      dfg.strict(MX-m*i);\n      (g2pow*=g2).strict(MX-m*i);\n      factinv /=\
    \ i;\n      res += factinv * (dfg * g2pow) << (m*i);\n    }\n    return res;\n\
    \  }\n  T operator()(T a)const{\n    T res=0,b=1;\n    for(int i=0;i<size();i++,b*=a)\n\
    \      res += at(i)*b;\n    return res;\n  }\n\n  // f(x+c)\n  void taylor_shift(T\
    \ c){\n    shrink();\n    if(size()<=1 or c==0)return;\n    int n=size();\n  \
    \  T fact=1;\n    REP_(i,n){\n      if(i)fact*=i;\n      at(i)*=fact;\n    }\n\
    \    reverse(begin(),end());\n    *this *= exp(c).pre(n);\n    strict(n);\n  \
    \  reverse(begin(),end());\n    T finv=fact.inv();\n    for(int i=n-1;i>=0;i--){\n\
    \      at(i)*=finv;\n      finv *= i;\n    }\n  }\n\n  static FPS differential(FPS\
    \ f){\n    if(f.size()<=1)return FPS(0);\n    REP_(i,f.size()-1)f[i]=(i+1)*f[i+1];\n\
    \    f.resize(f.size()-1);\n    return f;\n  }\n  static FPS integral(FPS f){\n\
    \    if(f.size()<MX)f.resize(f.size()+1);\n    for(int i=f.size()-1;i>0;i--)f[i]=f[i-1]/i;\n\
    \    f[0]=0;\n    return f;\n  }\n\n  static FPS log(const FPS&f){\n    assert(f.size()\
    \ and f[0]==1);\n    return integral(differential(f)/f);\n  }\n  static FPS exp(const\
    \ FPS f){\n    if(!f.size())return unit();\n    assert(f[0]==0);\n    FPS res=unit();\n\
    \    for(int n=0;(1<<n)<MX;n++){\n      // mod[1<<n] \u2192 mod[1<<(n+1)]\n  \
    \    res *= (f.pre(1<<(n+1))+1-log(res).pre(1<<(n+1)));\n      res.strict(1<<(n+1));\n\
    \    }\n    return res;\n  }\n  // exp(nx)\n  static FPS exp(const T n){\n   \
    \ if(n==0)return unit();\n    FPS res(MX,1);\n    for(int i=1;i<MX;i++)res[i]=res[i-1]*n/i;\n\
    \    return res;\n  }\n};\n#undef REP_\n"
  code: "#pragma once\n#define REP_(i,n) for(int i=0;i<(n);i++)\ntemplate<typename\
    \ T,int MX>\nstruct FormalPowerSeries:vector<T>{\n  using FPS=FormalPowerSeries;\n\
    \  using vector<T>::resize;\n  using vector<T>::size;\n  using vector<T>::at;\n\
    \  using vector<T>::assign;\n  using vector<T>::vector;\n  using vector<T>::begin;\n\
    \  using vector<T>::end;\n  using vector<T>::back;\n  using vector<T>::pop_back;\n\
    \  using value_type=T;\n\n  void strict(int n){ if(size()>n)resize(n); }\n  void\
    \ shrink(){ while(size() and back()==0)pop_back(); }\n\n  FormalPowerSeries(const\
    \ vector<T>&f){\n    int n=min(MX,int(f.size()));\n    resize(n);\n    REP_(i,n)at(i)=f[i];\n\
    \    shrink();\n  }\n\n  static FPS unit(){ return {1}; }\n  static FPS x(){ return\
    \ {0,1}; }\n#pragma region operator\n  FPS operator-()const{\n    FPS g=*this;\n\
    \    for(T&a:g)a=-a;\n    return g;\n  }\n  \n  FPS &operator+=(const FPS&g){\n\
    \    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)+=g[i];\n\
    \    return *this;\n  }\n  FPS operator+(const FPS &g)const{return FPS(*this)+=g;}\n\
    \n  FPS &operator+=(const T &a){\n    if(!size())resize(1);\n    at(0)+=a;\n \
    \   return *this;\n  }\n  FPS operator+(const T& a)const{return FPS(*this)+=a;}\n\
    \  friend FPS operator+(const T&a,const FPS&f){return f+a;}\n\n  FPS &operator-=(const\
    \ FPS &g){\n    if(size()<g.size())resize(g.size());\n    REP_(i,g.size())at(i)-=g[i];\n\
    \    return *this;\n  }\n  FPS operator-(const FPS &g)const{return FPS(*this)-=g;}\n\
    \n  FPS &operator-=(const T &a){\n    if(!size())resize(1);\n    at(0)-=a;\n \
    \   return *this;\n  }\n  FPS operator-(const T& a){return FPS(*this)-=a;}\n \
    \ friend FPS operator-(const T&a,const FPS&f){return a+(-f);}\n  \n  FPS operator*(const\
    \ FPS&g)const{ return FPS(convolution(*this,g)); }\n  FPS&operator*=(const FPS&g){\
    \ return (*this)=(*this)*g; }\n\n  FPS&operator*=(const T &a){\n    REP_(i,size())at(i)*=a;\n\
    \    return *this;\n  }\n  FPS operator*(const T &a)const{ return FPS(*this)*=a;\
    \ }\n  friend FPS operator*(const T&a,const FPS&f){return f*a;}\n\n  FPS operator/(const\
    \ FPS g)const{ return (*this)*g.inv(); }\n  FPS&operator/=(const FPS&g){ return\
    \ (*this)=(*this)/g; }\n\n  FPS&operator/=(const T &a){ return *this *= a.inv();\
    \ }\n  FPS operator/(const T &a){ return  FPS(*this)/=a; }\n\n  FPS&operator<<=(const\
    \ int d){\n    if(d>=MX)return *this=FPS(0);\n    resize(min(MX,int(size())+d));\n\
    \    for(int i=int(size())-1-d;i>=0;i--)\n      at(i+d)=at(i);\n    for(int i=d-1;i>=0;i--)at(i)=0;\n\
    \    return *this;\n  }\n  FPS operator<<(const int d)const{ return FPS(*this)<<=d;\
    \ }\n  FPS&operator>>=(const int d){\n    if(d>=size())return *this=FPS(0);\n\
    \    for(int i=d;i<size();i++)\n      at(i-d)=at(i);\n    strict(int(size())-d);\n\
    \    return *this;\n  }\n  FPS operator>>(const int d)const{ return FPS(*this)>>=d;\
    \ }\n#pragma endregion operator\n\n  FPS pre(int n)const{\n    if(size()<=n)return\
    \ *this;\n    return FPS(begin(),begin()+n);\n  }\n\n  FPS inv(int SZ=MX)const{\n\
    \    assert(size() and at(0)!=0);\n    FPS res(1,at(0).inv());\n    for(int n=0;(1<<n)<SZ;n++){\n\
    \      // mod[1<<n] \u2192 mod[1<<(n+1)]\n      res *= (2- (res*pre(1<<(n+1))).pre(1<<(n+1)));\n\
    \      res.strict(1<<(n+1));\n    }\n    return res.pre(SZ);\n  }\n\n  FPS pow(long\
    \ long n)const{\n    assert(n>=0);\n    if(n==0)return unit();\n    if(n==1)return\
    \ *this;\n\n    FPS now=*this;\n    now.shrink();\n    if(!now.size())return now;\n\
    \    int d;\n    for(d=0;d<now.size() and now[d]==0;d++){}\n    if(d>=(MX+n-1)/n)return\
    \ FPS(0);\n    now >>= d;\n    d *= n;\n    if(at(0)==1)return exp(n*log(now))<<d;\n\
    \    FPS res=unit();\n    while(n){\n      if(n&1)res*=now;\n      now*=now;\n\
    \      n>>=1;\n    }\n    return res<<d;\n  }\n\n  // *this = f_1 + f_2 x^n \u21D2\
    \ [*this\u2190f_1, return f_2]\n  FPS separate(int n){\n    if(size()<=n)return\
    \ FPS(0);\n    FPS f_2(size()-n);\n    for(int i=n;i<size();i++)f_2[i-n]=at(i);\n\
    \    strict(n);\n    return f_2;\n  }\n\n  FPS operator()(FPS g)const{\n    assert(!g.size()\
    \ or g[0]==0); // \u81EA\u8EAB\u304C\u591A\u9805\u5F0F\u306A\u3089 g[0]!=0 \u3067\
    \u3082\u826F\u3044\n    if(size()==0)return *this;\n    if(size()==1)return FPS(1,at(0));\n\
    \    if(size()==2)return FPS(at(0)+at(1)*g);\n\n    int m=sqrt(MX/20);\n    FPS&g1=g;\n\
    \    FPS g2=g1.separate(m);\n\n    int z;\n    for(z=1;z<g1.size() and g1[z]==0;z++){}\n\
    \    if(z==g1.size()){\n      FPS res(0),\n          g2pow=FPS::unit();\n    \
    \  for(int i=0;i*m<MX and i<size();i++,g2pow*=g2)\n        res += at(i) * g2pow<<(i*m);\n\
    \      return res;\n    }\n    \n    //\u3000f[l,l+d) \u25CB g1 \u3092\u518D\u5E30\
    \u3067\u8A08\u7B97\n    auto rec=[&](auto rec,int l,int d){\n      if(d==0 or\
    \ l>=size())return FPS(0);\n      if(d==1)return FPS(1,at(l));\n      if(d==2)return\
    \ at(l) + (l+1<size()?at(l+1)*g1:FPS(0));\n      FPS f1=rec(rec,l,d>>1);\n   \
    \   FPS f2=rec(rec,l+(d>>1),d-(d>>1));\n      f2 *= g1.pow(d>>1);\n      return\
    \ f1+f2;\n    };\n    FPS res = rec(rec,0,size());\n\n    FPS dfg=res,\n     \
    \   g1inv=(differential(g)>>(--z)).inv(),\n        g2pow=FPS::unit();\n    T factinv=1;\n\
    \    \n    for(int i=1;i*m<MX;i++){\n      dfg=(differential(dfg)>>z)*g1inv;\n\
    \      dfg.strict(MX-m*i);\n      (g2pow*=g2).strict(MX-m*i);\n      factinv /=\
    \ i;\n      res += factinv * (dfg * g2pow) << (m*i);\n    }\n    return res;\n\
    \  }\n  T operator()(T a)const{\n    T res=0,b=1;\n    for(int i=0;i<size();i++,b*=a)\n\
    \      res += at(i)*b;\n    return res;\n  }\n\n  // f(x+c)\n  void taylor_shift(T\
    \ c){\n    shrink();\n    if(size()<=1 or c==0)return;\n    int n=size();\n  \
    \  T fact=1;\n    REP_(i,n){\n      if(i)fact*=i;\n      at(i)*=fact;\n    }\n\
    \    reverse(begin(),end());\n    *this *= exp(c).pre(n);\n    strict(n);\n  \
    \  reverse(begin(),end());\n    T finv=fact.inv();\n    for(int i=n-1;i>=0;i--){\n\
    \      at(i)*=finv;\n      finv *= i;\n    }\n  }\n\n  static FPS differential(FPS\
    \ f){\n    if(f.size()<=1)return FPS(0);\n    REP_(i,f.size()-1)f[i]=(i+1)*f[i+1];\n\
    \    f.resize(f.size()-1);\n    return f;\n  }\n  static FPS integral(FPS f){\n\
    \    if(f.size()<MX)f.resize(f.size()+1);\n    for(int i=f.size()-1;i>0;i--)f[i]=f[i-1]/i;\n\
    \    f[0]=0;\n    return f;\n  }\n\n  static FPS log(const FPS&f){\n    assert(f.size()\
    \ and f[0]==1);\n    return integral(differential(f)/f);\n  }\n  static FPS exp(const\
    \ FPS f){\n    if(!f.size())return unit();\n    assert(f[0]==0);\n    FPS res=unit();\n\
    \    for(int n=0;(1<<n)<MX;n++){\n      // mod[1<<n] \u2192 mod[1<<(n+1)]\n  \
    \    res *= (f.pre(1<<(n+1))+1-log(res).pre(1<<(n+1)));\n      res.strict(1<<(n+1));\n\
    \    }\n    return res;\n  }\n  // exp(nx)\n  static FPS exp(const T n){\n   \
    \ if(n==0)return unit();\n    FPS res(MX,1);\n    for(int i=1;i<MX;i++)res[i]=res[i-1]*n/i;\n\
    \    return res;\n  }\n};\n#undef REP_"
  dependsOn: []
  isVerificationFile: false
  path: library/formalpowerseries/Base.cpp
  requiredBy:
  - library/formalpowerseries/ComposeEXP.cpp
  - library/formalpowerseries/Sqrt.cpp
  - library/formalpowerseries/RationalSum.cpp
  - library/formalpowerseries/DivMod.cpp
  - library/formalpowerseries/MultipointEvaluation.cpp
  - library/formalpowerseries/Prod.cpp
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/library-checker/Polynomial/DivisionOfPolynomials.test.cpp
  - test/library-checker/Polynomial/Pow.test.cpp
  - test/library-checker/Polynomial/Log.test.cpp
  - test/library-checker/Polynomial/TaylorShift.test.cpp
  - test/library-checker/Polynomial/ProductOfPolynomialSequence.test.cpp
  - test/library-checker/Polynomial/MultipointEvaluation.test.cpp
  - test/library-checker/Polynomial/Composition.test.cpp
  - test/library-checker/Polynomial/Exp.test.cpp
  - test/library-checker/Polynomial/Inv.test.cpp
documentation_of: library/formalpowerseries/Base.cpp
layout: document
redirect_from:
- /library/library/formalpowerseries/Base.cpp
- /library/library/formalpowerseries/Base.cpp.html
title: library/formalpowerseries/Base.cpp
---
