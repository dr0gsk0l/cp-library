---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Ranked.cpp
    title: library/bitwise/Ranked.cpp
  - icon: ':heavy_check_mark:'
    path: library/bitwise/Util.cpp
    title: library/bitwise/Util.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/subset_convolution
    links:
    - https://judge.yosupo.jp/problem/subset_convolution
  bundledCode: "#line 1 \"test/library-checker/Convolution/SubsetConvolution.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n#define REP(i,n) for(int i=0;i<(n);i++)\n\
    \n#line 2 \"library/bitwise/Util.cpp\"\nnamespace bitwise{\n  static int log2(int\
    \ N){\n    int n=__builtin_ffs(N)-1;\n    assert((1<<n)==N);\n    return n;\n\
    \  }\n  static bool in(int S,int a){ return (S>>a)&1; }\n}\n#line 3 \"library/bitwise/Ranked.cpp\"\
    \n#define REP_(i,n) for(int i=0;i<(n);i++)\n#define RREP_(i,n) for(int i=(n)-1;i>=0;i--)\n\
    class BitwiseRanked{\n  static int popcount(int S){ return __builtin_popcount(S);\
    \ }\npublic:\n  template<typename T>\n  static vector<vector<T>> zeta(const vector<T>&A){\n\
    \    const int n=bitwise::log2(A.size());\n    vector<vector<T>> RA(1<<n,vector<T>(n+1,0));\n\
    \    REP_(S,1<<n)RA[S][popcount(S)]=A[S];\n    REP_(i,n)REP_(S,1<<n)if(!bitwise::in(S,i))\n\
    \      REP_(d,n+1)RA[S|(1<<i)][d]+=RA[S][d];\n    return RA;\n  }\n  template<typename\
    \ T>\n  static vector<T> mobius(vector<vector<T>> RA){\n    const int n=bitwise::log2(RA.size());\n\
    \    REP_(i,n)REP_(S,1<<n)if(!bitwise::in(S,i))\n      REP_(d,n+1)RA[S|(1<<i)][d]-=RA[S][d];\n\
    \    vector<T> A(1<<n);\n    REP_(S,1<<n)A[S]=RA[S][popcount(S)];\n    return\
    \ A;\n  }\n  template<typename T>\n  static vector<T> convolution(const vector<T>&A,const\
    \ vector<T>&B){\n    const int n=bitwise::log2(A.size());\n    auto RA=zeta(A);\n\
    \    auto RB=zeta(B);\n    REP_(S,1<<n){\n      auto&ra=RA[S],rb=RB[S];\n    \
    \  RREP_(d,n+1){\n        ra[d]*=rb[0];\n        REP_(i,d)ra[d]+=ra[i]*rb[d-i];\n\
    \      }\n    }\n    return mobius(RA);\n  }\n};\n#undef REP_\n#undef RREP_\n\
    #line 2 \"library/math/ExtraGCD.cpp\"\nusing ll=long long;\npair<ll,ll> ext_gcd(ll\
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
    \ is;}\n};\n#line 8 \"test/library-checker/Convolution/SubsetConvolution.test.cpp\"\
    \nusing mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n;cin>>n;\n  int N=1<<n;\n  vector<mint> a(N),b(N);\n\
    \  REP(i,N)cin>>a[i];\n  REP(i,N)cin>>b[i];\n  auto c=BitwiseRanked::convolution(a,b);\n\
    \  REP(i,N)cout<<c[i]<<\"\\n \"[i+1<N];\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/subset_convolution\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n#define REP(i,n) for(int i=0;i<(n);i++)\n\
    \n#include \"library/bitwise/Ranked.cpp\"\n#include \"library/mod/Modint.cpp\"\
    \nusing mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n;cin>>n;\n  int N=1<<n;\n  vector<mint> a(N),b(N);\n\
    \  REP(i,N)cin>>a[i];\n  REP(i,N)cin>>b[i];\n  auto c=BitwiseRanked::convolution(a,b);\n\
    \  REP(i,N)cout<<c[i]<<\"\\n \"[i+1<N];\n}"
  dependsOn:
  - library/bitwise/Ranked.cpp
  - library/bitwise/Util.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/library-checker/Convolution/SubsetConvolution.test.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:20:41+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Convolution/SubsetConvolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Convolution/SubsetConvolution.test.cpp
- /verify/test/library-checker/Convolution/SubsetConvolution.test.cpp.html
title: test/library-checker/Convolution/SubsetConvolution.test.cpp
---