---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':x:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':x:'
    path: library/datastructure/SWAG.cpp
    title: library/datastructure/SWAG.cpp
  - icon: ':x:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "#line 1 \"test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/linearalgebra/Linear.cpp\"\
    \ntemplate<typename T>\nstruct Line{\n  T a,b;\n  Line()=default;\n  Line(T a,T\
    \ b):a(a),b(b){}\n  Line(pair<T,T> l):a(l.first),b(l.second){}\n  Line(T c):a(0),b(c){}\n\
    \n  T operator()(const T x)const{ return a*x+b; }\n  Line operator()(const Line&l)const{\
    \ return Line(a*l.a, a*l.b+b); }\n\n  bool operator==(const Line&l)const{ return\
    \ a==l.a and b==l.b; }\n  bool operator!=(const Line&l)const{ return !(*this ==\
    \ l); }\n  bool operator<(const Line&l)const{ return (a==l.a ? a<l.a : b<l.b);\
    \ }\n\n  Line&operator+=(const Line&l){ a+=l.a; b+=l.b; return *this; }\n  Line\
    \ operator+(const Line&l)const{return Line(*this) += l; }\n  Line&operator-=(const\
    \ Line&l){ a-=l.a; b-=l.b; return *this; }\n  Line operator-(const Line&l)const{return\
    \ Line(*this) -= l; }\n  Line operator-()const{ return Line(-a,-b); }\n\n  Line&operator+=(const\
    \ T&c){ b+=c; return *this; }\n  Line operator+(const T&c)const{ return Line(*this)\
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
    \ bool commute = false;\n};\n#line 2 \"library/algebra/Reverse.cpp\"\ntemplate<typename\
    \ Algebra>\nstruct AlgebraReverse:Algebra{\n  using X=typename Algebra::value_type;\n\
    \  static constexpr X op(const X& x, const X& y){ return Algebra::op(y,x); }\n\
    \  static constexpr void Rchop(X&x,const X&y){ Algebra::Lchop(y,x); }\n  static\
    \ constexpr void Lchop(const X&x,X&y){ Algebra::Rchop(y,x); }\n};\n#line 2 \"\
    library/datastructure/SWAG.cpp\"\ntemplate<typename Monoid>\nclass SWAG{\n  using\
    \ X=typename Monoid::value_type;\n\n  stack<X> back_stack,front_stack; // back\
    \ \u306F\u5F8C\u308D\u306E\u5404\u8981\u7D20 front \u306F\u524D\u306E\u7D2F\u7A4D\
    \u548C\n  X back_value;\n\n  inline X front_value()const{\n    return front_stack.size()?front_stack.top():Monoid::unit();\n\
    \  }\npublic:\n  SWAG():back_value(Monoid::unit()){}\n  void push_back(X x){\n\
    \    back_stack.push(x);\n    Monoid::Rchop(back_value,x);\n  }\n  void push_front(X\
    \ x){\n    front_stack.push(Monoid::op(x,front_value()));\n  }\n  void pop_front(){\n\
    \    if(front_stack.empty()){\n      if(back_stack.empty())return;\n      while(back_stack.size()){\n\
    \        push_front(back_stack.top());\n        back_stack.pop();\n      }\n \
    \     back_value=Monoid::unit();\n    }\n    front_stack.pop();\n  }\n  X prod(){\n\
    \    return Monoid::op(front_value(),back_value);\n  }\n  int size(){\n    return\
    \ back_stack.size()+front_stack.size();\n  }\n};\n#line 2 \"library/math/ExtraGCD.cpp\"\
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
    \ is;}\n};\n#line 9 \"test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp\"\
    \n\nint main(){\n  ios::sync_with_stdio(false);\n  cin.tie(nullptr);\n\n  using\
    \ mint=Mint<long long>;\n  using G=AlgebraReverse<GroupAffine<mint>>;\n  using\
    \ F=G::value_type;\n\n  SWAG<G> S;\n\n  int q;cin>>q;\n  while(q--){\n    int\
    \ t;cin>>t;\n    if(t==0){\n      F f;cin>>f;\n      S.push_back(f);\n    }\n\
    \    if(t==1)S.pop_front();\n    if(t==2){\n      int x;cin>>x;\n      F f=S.prod();\n\
    \      cout<<f(x)<<\"\\n\";\n    }\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/algebra/group/Affine.cpp\"\
    \n#include \"library/algebra/Reverse.cpp\"\n#include \"library/datastructure/SWAG.cpp\"\
    \n#include \"library/mod/Modint.cpp\"\n\nint main(){\n  ios::sync_with_stdio(false);\n\
    \  cin.tie(nullptr);\n\n  using mint=Mint<long long>;\n  using G=AlgebraReverse<GroupAffine<mint>>;\n\
    \  using F=G::value_type;\n\n  SWAG<G> S;\n\n  int q;cin>>q;\n  while(q--){\n\
    \    int t;cin>>t;\n    if(t==0){\n      F f;cin>>f;\n      S.push_back(f);\n\
    \    }\n    if(t==1)S.pop_front();\n    if(t==2){\n      int x;cin>>x;\n     \
    \ F f=S.prod();\n      cout<<f(x)<<\"\\n\";\n    }\n  }\n}"
  dependsOn:
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  - library/algebra/Reverse.cpp
  - library/datastructure/SWAG.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
- /verify/test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp.html
title: test/library-checker/DataStructure/QueueOperateAllComposite.test.cpp
---
