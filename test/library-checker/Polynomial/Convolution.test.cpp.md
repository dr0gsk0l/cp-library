---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: library/convolution/NTT.cpp
    title: library/convolution/NTT.cpp
  - icon: ':heavy_check_mark:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':heavy_check_mark:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/library-checker/Polynomial/Convolution.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/math/ExtraGCD.cpp\"\
    \nusing ll=long long;\npair<ll,ll> ext_gcd(ll a,ll b){\n  if(b==0)return {1,0};\n\
    \  auto [X,Y]=ext_gcd(b,a%b);\n  // bX + (a%b)Y = gcd(a,b)\n  // a%b = a - b(a/b)\n\
    \  // \u2234 aY + b(X-(a/b)Y) = gcd(a,b)\n  ll x=Y,y=X-(a/b)*Y;\n  return {x,y};\n\
    }\n#line 3 \"library/mod/Modint.cpp\"\ntemplate<typename T,T MOD=998244353>\n\
    struct Mint{\n  inline static constexpr T mod = MOD;\n  T v;\n  Mint():v(0){}\n\
    \  Mint(signed v):v(v){}\n  Mint(long long t){v=t%MOD;if(v<0)v+=MOD;}\n  \n  static\
    \ Mint raw(int v){\n    Mint x;\n    x.v=v;\n    return x;\n  }\n\n  Mint pow(long\
    \ long k)const{\n    Mint res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n\
    \      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  static Mint add_identity(){return\
    \ Mint(0);}\n  static Mint mul_identity(){return Mint(1);}\n\n  //Mint inv()const{return\
    \ pow(MOD-2);}\n  Mint inv()const{ return Mint(ext_gcd(v,mod).first); }\n\n  Mint&\
    \ operator+=(Mint a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator-=(Mint\
    \ a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return *this;}\n  Mint& operator*=(Mint a){v=1LL*v*a.v%MOD;return\
    \ *this;}\n  Mint& operator/=(Mint a){return (*this)*=a.inv();}\n\n  Mint operator+(Mint\
    \ a) const{return Mint(v)+=a;}\n  Mint operator-(Mint a) const{return Mint(v)-=a;}\n\
    \  Mint operator*(Mint a) const{return Mint(v)*=a;}\n  Mint operator/(Mint a)\
    \ const{return Mint(v)/=a;}\n#define FRIEND(op) friend Mint operator op (int a,Mint\
    \ b){ return Mint(a) op b; }\n  FRIEND(+);\n  FRIEND(-);\n  FRIEND(*);\n  FRIEND(/);\n\
    #undef FRIEND\n  Mint operator+() const{return *this;}\n  Mint operator-() const{return\
    \ v?Mint(MOD-v):Mint(v);}\n\n  bool operator==(const Mint a)const{return v==a.v;}\n\
    \  bool operator!=(const Mint a)const{return v!=a.v;}\n\n  static Mint comb(long\
    \ long n,int k){\n    Mint num(1),dom(1);\n    for(int i=0;i<k;i++){\n      num*=Mint(n-i);\n\
    \      dom*=Mint(i+1);\n    }\n    return num/dom;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ Mint &m){os<<m.v;return os;}\n  friend istream& operator>>(istream&is,Mint &m){is>>m.v;m.v%=MOD;if(m.v<0)m.v+=MOD;return\
    \ is;}\n};\n#line 2 \"library/convolution/NTT.cpp\"\n#define REP_(i,n) for(int\
    \ i=0;i<(n);i++)\n#define RREP_(i,n) for(int i=(n)-1;i>=0;i--)\n\ntemplate<typename\
    \ MINT>\nvector<MINT> convolution(vector<MINT>f,vector<MINT>g){\n  int nf=f.size(),ng=g.size();\n\
    \  if(!nf or !ng)return vector<MINT>{};\n  int M=nf+ng-1;\n\n  if(nf<=60 or ng<=60){\n\
    \    vector<MINT> res(M,0);\n    REP_(i,nf)REP_(j,ng)res[i+j]+=f[i]*g[j];\n  \
    \  return res;\n  }\n  \n  int lg;\n  for(lg=0;(1<<lg)<M;lg++){}\n  const int\
    \ N=1<<lg;\n  f.resize(N,0);\n  g.resize(N,0);\n\n  static_assert(MINT::mod ==\
    \ 998244353);\n  MINT c=MINT(3).pow((MINT::mod-1)>>lg);\n  vector<MINT> cs(N);\n\
    \  REP_(i,N)cs[i] = (i ? cs[i-1]*c : 1);\n  \n  vector<int> x(N,0);\n  REP_(h,lg)\n\
    \    REP_(S,1<<h)\n      REP_(T,1<<(lg-h-1)){\n        int l=(S<<(lg-h))|T;\n\
    \        int r=l|(1<<(lg-h-1));\n\n        x[l] >>= 1;\n        (x[r] >>= 1) |=\
    \ 1<<(lg-1);\n\n        MINT a=f[l];\n        f[l] += f[r] * cs[x[l]];\n     \
    \   (f[r] *= cs[x[r]]) += a;\n\n        a = g[l];\n        g[l] += g[r] * cs[x[l]];\n\
    \        (g[r] *= cs[x[r]]) += a;\n      }\n  REP_(i,N)f[i]*=g[i];\n\n  fill(x.begin(),x.end(),0);\n\
    \  c = c.inv();\n  REP_(i,N)cs[i] = (i ? cs[i-1]*c : 1);\n  RREP_(h,lg)\n    REP_(S,1<<h)\n\
    \      REP_(T,1<<(lg-h-1)){\n        int l=(S<<(lg-h))|T;\n        int r=l|(1<<(lg-h-1));\n\
    \n        x[l] >>= 1;\n        (x[r] >>= 1) |= 1<<(lg-1);\n\n        MINT a=f[l];\n\
    \        f[l] += f[r] * cs[x[l]];\n        (f[r] *= cs[x[r]]) += a;\n      }\n\
    \  f.resize(M);\n  MINT Ninv=MINT(N).inv();\n  REP_(i,M)f[i]*=Ninv;\n  return\
    \ f;\n}\n#undef REP_\n#undef RREP_\n#line 7 \"test/library-checker/Polynomial/Convolution.test.cpp\"\
    \n\nusing mint = Mint<long long,998244353>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n,m;cin>>n>>m;\n  vector<mint> f(n),g(m);\n  for(mint&p:f)cin>>p;\n\
    \  for(mint&p:g)cin>>p;\n  auto h = convolution(f,g);\n  for(mint&p:h)cout<<p<<\"\
    \ \";cout<<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/mod/Modint.cpp\"\
    \n#include \"library/convolution/NTT.cpp\"\n\nusing mint = Mint<long long,998244353>;\n\
    \nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n,m;cin>>n>>m;\n\
    \  vector<mint> f(n),g(m);\n  for(mint&p:f)cin>>p;\n  for(mint&p:g)cin>>p;\n \
    \ auto h = convolution(f,g);\n  for(mint&p:h)cout<<p<<\" \";cout<<endl;\n}"
  dependsOn:
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/convolution/NTT.cpp
  isVerificationFile: true
  path: test/library-checker/Polynomial/Convolution.test.cpp
  requiredBy: []
  timestamp: '2023-12-04 07:28:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/Polynomial/Convolution.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Polynomial/Convolution.test.cpp
- /verify/test/library-checker/Polynomial/Convolution.test.cpp.html
title: test/library-checker/Polynomial/Convolution.test.cpp
---
