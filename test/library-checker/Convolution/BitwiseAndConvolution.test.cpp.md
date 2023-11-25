---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/bitwise/And.cpp
    title: library/bitwise/And.cpp
  - icon: ':x:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  - icon: ':x:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':x:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/library-checker/Convolution/BitwiseAndConvolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define REP(i,n) for(int i=0;i<(n);i++)\n\
    \n#line 2 \"library/math/ExtraGCD.cpp\"\nusing ll=long long;\npair<ll,ll> ext_gcd(ll\
    \ a,ll b){\n  if(b==0)return {1,0};\n  auto [X,Y]=ext_gcd(b,a%b);\n  // bX + (a%b)Y\
    \ = gcd(a,b)\n  // a%b = a - b(a/b)\n  // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n\
    \  ll x=Y,y=X-(a/b)*Y;\n  return {x,y};\n}\n#line 3 \"library/mod/Modint.cpp\"\
    \ntemplate<typename T,T MOD=998244353>\nstruct Mint{\n  inline static constexpr\
    \ T mod = MOD;\n  T v;\n  Mint():v(0){}\n  Mint(signed v):v(v){}\n  Mint(long\
    \ long t){v=t%MOD;if(v<0)v+=MOD;}\n  \n  static Mint raw(int v){\n    Mint x;\n\
    \    x.v=v;\n    return x;\n  }\n\n  Mint pow(long long k)const{\n    Mint res(1),tmp(v);\n\
    \    while(k){\n      if(k&1)res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n\
    \    return res;\n  }\n\n  static Mint add_identity(){return Mint(0);}\n  static\
    \ Mint mul_identity(){return Mint(1);}\n\n  //Mint inv()const{return pow(MOD-2);}\n\
    \  Mint inv()const{ return Mint(ext_gcd(v,mod).first); }\n\n  Mint& operator+=(Mint\
    \ a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator-=(Mint a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return *this;}\n  Mint&\
    \ operator/=(Mint a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint a) const{return\
    \ Mint(v)+=a;}\n  Mint operator-(Mint a) const{return Mint(v)-=a;}\n  Mint operator*(Mint\
    \ a) const{return Mint(v)*=a;}\n  Mint operator/(Mint a) const{return Mint(v)/=a;}\n\
    #define FRIEND(op) friend Mint operator op (int a,Mint b){ return Mint(a) op b;\
    \ }\n  FRIEND(+);\n  FRIEND(-);\n  FRIEND(*);\n  FRIEND(/);\n#undef FRIEND\n \
    \ Mint operator+() const{return *this;}\n  Mint operator-() const{return v?Mint(MOD-v):Mint(v);}\n\
    \n  bool operator==(const Mint a)const{return v==a.v;}\n  bool operator!=(const\
    \ Mint a)const{return v!=a.v;}\n\n  static Mint comb(long long n,int k){\n   \
    \ Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n    \
    \  dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Mint &m){os<<m.v;return os;}\n  friend istream& operator>>(istream&is,Mint &m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return\
    \ is;}\n};\n#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static\
    \ int log2(int N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n  \
    \  return n;\n  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line\
    \ 3 \"library/bitwise/And.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\nstruct\
    \ BitwiseAnd{\n  template<typename T>\n  static void zeta(vector<T>& A){\n   \
    \ int n=bitwise::log2(A.size());\n    REP_(k,n)REP_(S,1<<n)if(!bitwise::in(S,k))A[S]+=A[S^(1<<k)];\n\
    \  }\n  template<typename T>\n  static void mobius(vector<T>& A){\n    int n=bitwise::log2(A.size());\n\
    \    REP_(k,n)REP_(S,1<<n)if(!bitwise::in(S,k))A[S]-=A[S^(1<<k)];\n  }\n  template<typename\
    \ T>\n  static vector<T> convolution(vector<T> A,vector<T> B){\n    assert(A.size()==B.size());\n\
    \    zeta(A);\n    zeta(B);\n    REP_(i,A.size())A[i]*=B[i];\n    mobius(A);\n\
    \    return A;\n  }\n};\n#undef REP_\n#line 8 \"test/library-checker/Convolution/BitwiseAndConvolution.test.cpp\"\
    \n\nusing mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n;cin>>n;\n  int N=1<<n;\n  vector<mint> a(N),b(N);\n\
    \  REP(i,N)cin>>a[i];\n  REP(i,N)cin>>b[i];\n  auto c=BitwiseAnd::convolution(a,b);\n\
    \  REP(i,N)cout<<c[i]<<\"\\n \"[i+1<N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#define REP(i,n) for(int i=0;i<(n);i++)\n\
    \n#include \"library/mod/Modint.cpp\"\n#include \"library/bitwise/And.cpp\"\n\n\
    using mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n \
    \ cin.tie(nullptr);\n\n  int n;cin>>n;\n  int N=1<<n;\n  vector<mint> a(N),b(N);\n\
    \  REP(i,N)cin>>a[i];\n  REP(i,N)cin>>b[i];\n  auto c=BitwiseAnd::convolution(a,b);\n\
    \  REP(i,N)cout<<c[i]<<\"\\n \"[i+1<N];\n}"
  dependsOn:
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/bitwise/And.cpp
  - library/bitwise/Util.cpp
  isVerificationFile: true
  path: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
- /verify/test/library-checker/Convolution/BitwiseAndConvolution.test.cpp.html
title: test/library-checker/Convolution/BitwiseAndConvolution.test.cpp
---
