---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  - icon: ':x:'
    path: library/util/Subsequence.cpp
    title: "\u90E8\u5206\u5217\u306E\u7A2E\u985E\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_subsequences
    links:
    - https://judge.yosupo.jp/problem/number_of_subsequences
  bundledCode: "#line 1 \"test/library-checker/New/NumberOfSubsequence.test.cpp\"\n\
    #define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\n#include\
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
    \ is;}\n};\n#line 1 \"library/util/Subsequence.cpp\"\ntemplate<typename T,typename\
    \ U>\nT sparse_subsequence(const vector<U>&v){\n  map<U,T> mp;\n  T res=1;\n \
    \ for(const U&p:v){\n    T tmp=res;\n    res=res*2-mp[p];\n    mp[p]=tmp;\n  }\n\
    \  return res;\n}\ntemplate<typename T,int SIZE>\nT subsequence(const vector<int>&v){\n\
    \  vector<T> memo(SIZE,0);\n  T res=1;\n  for(int p:v){\n    T tmp=res;\n    res=res*2-memo[p];\n\
    \    memo[p]=tmp;\n  }\n  return res;\n}\ntemplate<typename T>\nT subsequence_alphabet(const\
    \ string&s){\n  vector<int> v;v.reserve(s.size());\n  for(char c:s)v.push_back(c-(c<='Z'?'A':'a'));\n\
    \  return subsequence<T,26>(v);\n}\n#line 7 \"test/library-checker/New/NumberOfSubsequence.test.cpp\"\
    \nusing mint=Mint<long long>;\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  int n;cin>>n;\n  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  cout<< sparse_subsequence<mint,int>(v)-1 <<endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_subsequences\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/mod/Modint.cpp\"\
    \n#include \"library/util/Subsequence.cpp\"\nusing mint=Mint<long long>;\n\nint\
    \ main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  int n;cin>>n;\n\
    \  vector<int> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n  cout<< sparse_subsequence<mint,int>(v)-1\
    \ <<endl;\n}"
  dependsOn:
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  - library/util/Subsequence.cpp
  isVerificationFile: true
  path: test/library-checker/New/NumberOfSubsequence.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/New/NumberOfSubsequence.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/New/NumberOfSubsequence.test.cpp
- /verify/test/library-checker/New/NumberOfSubsequence.test.cpp.html
title: test/library-checker/New/NumberOfSubsequence.test.cpp
---
