---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/linearalgebra/Matrix.cpp
    title: library/linearalgebra/Matrix.cpp
  - icon: ':question:'
    path: library/math/ExtraGCD.cpp
    title: library/math/ExtraGCD.cpp
  - icon: ':question:'
    path: library/mod/Modint.cpp
    title: library/mod/Modint.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inverse_matrix
    links:
    - https://judge.yosupo.jp/problem/inverse_matrix
  bundledCode: "#line 1 \"test/library-checker/Matrix/Inverse.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 2 \"library/linearalgebra/Matrix.cpp\"\n#define\
    \ REP_(i,n) for(int i=0;i<(n);i++)\n#define REP2_(i,s,n) for(int i=(s);i<(n);i++)\n\
    template<typename K>\nstruct Matrix{\n  using value_type=K;\n  using vec=vector<K>;\n\
    \  using mat=vector<vec>;\n  size_t r,c;\n  mat M;\n\n  Matrix(size_t r,size_t\
    \ c):r(r),c(c),M(r,vec(c,K())){}\n  Matrix(mat A):M(A),r(A.size()),c(A[0].size()){}\n\
    \n  vec& operator[](size_t k){return M[k];}\n  const vec& operator[](size_t k)const{return\
    \ M[k];}\n\n  \n  Matrix& operator+=(const Matrix &A){\n    assert(r==A.r&&c==A.c);\n\
    \    REP_(i,r)REP_(j,c)M[i][j]+=A[i][j];\n    return *this;\n  }\n  Matrix& operator-=(const\
    \ Matrix &A){\n    assert(r==A.r&&c==A.c);\n    REP_(i,r)REP_(j,c)M[i][j]-=A[i][j];\n\
    \    return *this;\n  }\n  Matrix operator+(const Matrix &A){ return Matrix(M)+=A;\
    \ }\n  Matrix operator-(const Matrix &A){ return Matrix(M)-=A; }\n\n  friend Matrix\
    \ operator*(const Matrix &A,const Matrix &B){\n    assert(A.c==B.r);\n    Matrix\
    \ res(A.r,B.c);\n    REP_(i,A.r)REP_(k,A.c)REP_(j,B.c)res[i][j]+=A[i][k]*B[k][j];\n\
    \    return res;\n  }\n  Matrix& operator*=(const Matrix &A){\n    M=((*this)*A).M;\n\
    \    return *this;\n  }\n\n  bool operator==(const Matrix &A){\n    if(r!=A.r||c!=A.c)return\
    \ false;\n    REP_(i,r)REP_(j,c)if(M[i][j]!=A[i][j])return false;\n    return\
    \ true;\n  }\n  bool operator!=(const Matrix &A){ return !((*this)==A); }\n  \n\
    \  static Matrix I(size_t n){\n    Matrix res(n,n);\n    REP_(i,n)res[i][i]=K(1);\n\
    \    return res;\n  }\n  \n  Matrix pow(long long n)const{\n    assert(n>=0&&r==c);\n\
    \    Matrix A(M),res=I(r);\n    while(n){\n      if(n&1)res*=A;\n      A*=A;\n\
    \      n>>=1;\n    }\n    return res;\n  }\n\n  pair<int,int> GaussJordan(){\n\
    \    int rnk=0,cnt=0;\n    REP_(k,c){\n      if(M[rnk][k]==0)\n        REP2_(i,rnk+1,r)\n\
    \          if(M[i][k]!=0){\n            swap(M[i],M[rnk]);\n            cnt^=1;\n\
    \            break;\n          }\n      if(M[rnk][k]==0)continue;\n      REP_(i,r)if(i!=rnk){\n\
    \        K x=M[i][k]/M[rnk][k];\n        REP_(j,c)M[i][j]-=M[rnk][j]*x;\n    \
    \  }\n      if(++rnk==r)break;\n    }\n    return {rnk,cnt};\n  }\n\n  K det()const{\n\
    \    assert(r==c);\n    Matrix A(M);\n    const auto&[rnk,cnt]=A.GaussJordan();\n\
    \    if(rnk!=r)return 0;\n    K res=1;\n    REP_(i,r)res*=A[i][i];\n    return\
    \ (cnt?-res:res);\n  }\n\n  optional<Matrix> inv()const{\n    assert(r==c);\n\
    \    Matrix A(r,c+c);\n    REP_(i,r)REP_(j,c)A[i][j]=M[i][j];\n    REP_(i,r)REP_(j,c)A[i][c+j]=K(i==j);\n\
    \    A.GaussJordan();\n    REP_(i,r)if(A[i][i]==0)return nullopt;\n    Matrix\
    \ res(r,c);\n    REP_(i,r)REP_(j,c)res[i][j]=A[i][c+j]/A[i][i];\n    return res;\n\
    \  }\n  \n  friend ostream& operator<<(ostream&os,const Matrix &M){ os<<M.M; return\
    \ os; }\n  friend istream& operator>>(istream&is,Matrix &M){ REP_(i,M.r)REP_(j,M.c)is>>M.M[i][j];\
    \ return is; }\n};\n#undef REP_\n#undef REP2_\n#line 2 \"library/math/ExtraGCD.cpp\"\
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
    \ is;}\n};\n#line 7 \"test/library-checker/Matrix/Inverse.test.cpp\"\n\nusing\
    \ mint=Mint<long long,998244353>;\nusing M=Matrix<mint>;\n\n#define REP(i,n) for(int\
    \ i=0;i<(n);i++)\n\nint main(){\n\tint n;cin>>n;\n\tM A(n,n);\n\tcin>>A;\n\tauto\
    \ B=A.inv();\n\tif(B.has_value())\n\t\tREP(i,n)REP(j,n)cout<<B.value()[i][j]<<\"\
    \\n \"[j+1<n];\n\telse\n\t\tcout<<-1<<\"\\n\";\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inverse_matrix\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/linearalgebra/Matrix.cpp\"\
    \n#include \"library/mod/Modint.cpp\"\n\nusing mint=Mint<long long,998244353>;\n\
    using M=Matrix<mint>;\n\n#define REP(i,n) for(int i=0;i<(n);i++)\n\nint main(){\n\
    \tint n;cin>>n;\n\tM A(n,n);\n\tcin>>A;\n\tauto B=A.inv();\n\tif(B.has_value())\n\
    \t\tREP(i,n)REP(j,n)cout<<B.value()[i][j]<<\"\\n \"[j+1<n];\n\telse\n\t\tcout<<-1<<\"\
    \\n\";\n}"
  dependsOn:
  - library/linearalgebra/Matrix.cpp
  - library/mod/Modint.cpp
  - library/math/ExtraGCD.cpp
  isVerificationFile: true
  path: test/library-checker/Matrix/Inverse.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 19:56:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Matrix/Inverse.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Matrix/Inverse.test.cpp
- /verify/test/library-checker/Matrix/Inverse.test.cpp.html
title: test/library-checker/Matrix/Inverse.test.cpp
---
