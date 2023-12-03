---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/Reverse.cpp
    title: library/algebra/Reverse.cpp
  - icon: ':question:'
    path: library/algebra/group/Affine.cpp
    title: library/algebra/group/Affine.cpp
  - icon: ':question:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  - icon: ':question:'
    path: library/segtree/SegmentTree.cpp
    title: library/segtree/SegmentTree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PointSetRangeComposite.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/segtree/SegmentTree.cpp\"\
    \ntemplate<class Monoid>\nclass SegmentTree{\n  using X=typename Monoid::value_type;\n\
    \  vector<X> dat;\n  int n,log,size;\n\n  void update(int i){ dat[i]=Monoid::op(dat[2*i],dat[2*i+1]);\
    \ }\npublic:\n  SegmentTree():SegmentTree(0){}\n  SegmentTree(int n):SegmentTree(vector<X>(n,\
    \ Monoid::unit())){}\n  SegmentTree(vector<X> v):n(v.size()){\n    for(log=1;(1<<log)<n;log++){}\n\
    \    size=1<<log;\n    dat.assign(size<<1,Monoid::unit());\n    for (int i=0;i<n;++i)dat[size+i]=v[i];\n\
    \    for (int i=size-1;i>=1;--i) update(i);\n  }\n\n  X operator[](int i)const{\
    \ return dat[size+i]; }\n\n  void set(int i,const X&x){\n    assert(0<=i and i<n);\n\
    \    dat[i+=size]=x;\n    while(i>>=1)update(i);\n  }\n  void multiply(int i,const\
    \ X&x){ set(i,Monoid::op(dat[i+size],x));}\n\n  X prod(int L,int R)const{\n  \
    \  assert(0<=L and L<=R and R<=n);\n    X vl=Monoid::unit(),vr=Monoid::unit();\n\
    \    L+=size, R+=size;\n    while(L<R){\n      if(L&1)Monoid::Rchop(vl,dat[L++]);\n\
    \      if(R&1)Monoid::Lchop(dat[--R],vr);\n      L>>=1,R>>=1;\n    }\n    return\
    \ Monoid::op(vl,vr);\n  }\n  X prod_all()const{ return dat[1]; }\n\n  template\
    \ <class F>\n  int max_right(F& check,int L){\n    assert(0<=L && L<=n && check(Monoid::unit()));\n\
    \    if(L == n) return n;\n    L += size;\n    X sm = Monoid::unit();\n    do\
    \ {\n      while (L % 2 == 0) L >>= 1;\n      if (!check(Monoid::op(sm, dat[L])))\
    \ {\n        while (L < size) {\n          L <<= 1;\n          if (check(Monoid::op(sm,\
    \ dat[L])))\n            Monoid::Rchop(sm, dat[L++]);\n        }\n        return\
    \ L - size;\n      }\n      Monoid::Rchop(sm, dat[L++]);\n    } while ((L & -L)\
    \ != L);\n    return n;\n  }\n\n  template <class F>\n  int min_left(F& check,\
    \ int R) {\n    assert(0 <= R && R <= n && check(Monoid::unit()));\n    if (R\
    \ == 0) return 0;\n    R += size;\n    X sm = Monoid::unit();\n    do {\n    \
    \  --R;\n      while (R > 1 && (R % 2)) R >>= 1;\n      if (!check(Monoid::op(dat[R],\
    \ sm))) {\n        while (R < size) {\n          ( R <<= 1 )++;\n          if\
    \ (check(Monoid::op(dat[R], sm)))\n            Monoid::Lchop(dat[R--], sm);\n\
    \        }\n        return R + 1 - size;\n      }\n      Monoid::Lchop(dat[R],\
    \ sm);\n    } while ((R & -R) != R);\n    return 0;\n  }\n\n  // \u30E2\u30CE\u30A4\
    \u30C9\u304C\u53EF\u63DB\u306A\u3089\u3001prod_{l<=i<r}A[i^x] \u304C\u8A08\u7B97\
    \u53EF\u80FD\n  // https://codeforces.com/contest/1401/problem/F\n  X Xor_prod(int\
    \ l, int r, int xor_val) {\n    assert(Monoid::commute);\n    X x = Monoid::unit();\n\
    \    for (int k = 0; k < log + 1; ++k) {\n      if (l >= r) break;\n      if (l\
    \ & 1) { Monoid::Rchop(x, dat[(size >> k) + ((l++) ^ xor_val)]); }\n      if (r\
    \ & 1) { Monoid::Rchop(x, dat[(size >> k) + ((--r) ^ xor_val)]); }\n      l /=\
    \ 2, r /= 2, xor_val /= 2;\n    }\n    return x;\n  }\n\n  friend ostream& operator<<(ostream&os,const\
    \ SegmentTree&seg){\n    os<<\"(\";\n    for(int L=1;L<=seg.size;L<<=1){\n   \
    \   os<<\"[\";\n      for(int j=L;j<(L<<1);j++){\n        os<<seg.dat[j];\n  \
    \      if(j+1<(L<<1))os<<\",\";\n      }\n      os<<\"]\";\n    }\n    os<<\"\
    )\";\n    return os;\n  }\n};\n#line 2 \"library/linearalgebra/Linear.cpp\"\n\
    template<typename T>\nstruct Line{\n  T a,b;\n  Line()=default;\n  Line(T a,T\
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
    library/math/ExtraGCD.cpp\"\nusing ll=long long;\npair<ll,ll> ext_gcd(ll a,ll\
    \ b){\n  if(b==0)return {1,0};\n  auto [X,Y]=ext_gcd(b,a%b);\n  // bX + (a%b)Y\
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
    \ is;}\n};\n#line 9 \"test/library-checker/DataStructure/PointSetRangeComposite.test.cpp\"\
    \n\nusing ll=long long;\nusing mint=Mint<ll>;\nusing G_=GroupAffine<mint>;\nusing\
    \ G=AlgebraReverse<G_>;\nusing F=G::value_type;\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vector<F> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n  SegmentTree<G> seg(v);\n\
    \  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n    if(t){\n      F f=seg.prod(l,r);\n\
    \      cout<<f(x)<<\"\\n\";\n    }\n    else seg.set(l,F(r,x));\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/segtree/SegmentTree.cpp\"\
    \n#include \"library/algebra/group/Affine.cpp\"\n#include \"library/algebra/Reverse.cpp\"\
    \n#include \"library/mod/Modint.cpp\"\n\nusing ll=long long;\nusing mint=Mint<ll>;\n\
    using G_=GroupAffine<mint>;\nusing G=AlgebraReverse<G_>;\nusing F=G::value_type;\n\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vector<F> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  SegmentTree<G> seg(v);\n  while(q--){\n    int t,l,r,x;cin>>t>>l>>r>>x;\n \
    \   if(t){\n      F f=seg.prod(l,r);\n      cout<<f(x)<<\"\\n\";\n    }\n    else\
    \ seg.set(l,F(r,x));\n  }\n}"
  dependsOn:
  - library/segtree/SegmentTree.cpp
  - library/algebra/group/Affine.cpp
  - library/linearalgebra/Linear.cpp
  - library/algebra/Reverse.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
  requiredBy: []
  timestamp: '2023-12-03 15:49:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
- /verify/test/library-checker/DataStructure/PointSetRangeComposite.test.cpp.html
title: test/library-checker/DataStructure/PointSetRangeComposite.test.cpp
---
