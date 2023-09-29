---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/650.test.cpp
    title: test/yukicoder/650.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/SquareMatrix.cpp\"\n#define REP_(i,n)\
    \ for(int i=0;i<(n);i++)\n#define REP2_(i,s,n) for(int i=(s);i<(n);i++)\ntemplate<typename\
    \ K,size_t N>\nstruct SquareMatrix{\n  using value_type=K;\n  using vec=array<K,N>;\n\
    \  using mat=array<vec,N>;\n  mat M;\n\n  SquareMatrix(K a=0){ \n    for(vec&\
    \ v:M)v.fill(0); \n    if(a!=0)REP_(i,N)M[i][i]=a;\n  }\n  SquareMatrix(const\
    \ mat&A):M(A){}\n  SquareMatrix(const vector<vector<K>>&v){\n    assert(v.size()==N\
    \ and v[0].size()==N);\n    REP_(i,N)REP_(j,N)M[i][j]=v[i][j];\n  }\n\n  vec&\
    \ operator[](size_t k){return M[k];}\n  const vec& operator[](size_t k)const{return\
    \ M[k];}\n  \n  SquareMatrix& operator+=(const SquareMatrix &A){\n    REP_(i,N)REP_(j,N)M[i][j]+=A[i][j];\n\
    \    return *this;\n  }\n  SquareMatrix& operator-=(const SquareMatrix &A){\n\
    \    REP_(i,N)REP_(j,N)M[i][j]-=A[i][j];\n    return *this;\n  }\n  SquareMatrix\
    \ operator+(const SquareMatrix &A)const{ return SquareMatrix(M)+=A; }\n  SquareMatrix\
    \ operator-(const SquareMatrix &A)const{ return SquareMatrix(M)-=A; }\n\n  friend\
    \ SquareMatrix operator*(const SquareMatrix &A,const SquareMatrix &B){\n    SquareMatrix\
    \ res;\n    REP_(i,N)REP_(k,N)REP_(j,N)res[i][j]+=A[i][k]*B[k][j];\n    return\
    \ res;\n  }\n  SquareMatrix& operator*=(const SquareMatrix &A){\n    M=((*this)*A).M;\n\
    \    return *this;\n  }\n\n  SquareMatrix& operator/=(const SquareMatrix&A){ return\
    \ (*this) *= A.inv(); }\n  SquareMatrix operator/(const SquareMatrix&A)const{\
    \ return SquareMatrix(M) /= A; }\n\n  bool operator==(const SquareMatrix &A){\n\
    \    REP_(i,N)REP_(j,N)if(M[i][j]!=A[i][j])return false;\n    return true;\n \
    \ }\n  bool operator!=(const SquareMatrix &A){ return !((*this)==A); }\n  \n \
    \ static SquareMatrix I(){ return SquareMatrix(1); }\n  \n  SquareMatrix pow(long\
    \ long n)const{\n    assert(n>=0);\n    SquareMatrix A(M),res(1);\n    while(n){\n\
    \      if(n&1)res*=A;\n      A*=A;\n      n>>=1;\n    }\n    return res;\n  }\n\
    \n  pair<int,int> GaussJordan(){\n    int rnk=0,cnt=0;\n    REP_(k,N){\n     \
    \ if(M[rnk][k]==0)\n        REP2_(i,rnk+1,N)\n          if(M[i][k]!=0){\n    \
    \        swap(M[i],M[rnk]);\n            cnt^=1;\n            break;\n       \
    \   }\n      if(M[rnk][k]==0)continue;\n      REP_(i,N)if(i!=rnk){\n        K\
    \ x=M[i][k]/M[rnk][k];\n        REP_(j,N)M[i][j]-=M[rnk][j]*x;\n      }\n    \
    \  if(++rnk==N)break;\n    }\n    return {rnk,cnt};\n  }\n\n  K det()const{\n\
    \    SquareMatrix A(M);\n    const auto&[rnk,cnt]=A.GaussJordan();\n    if(rnk!=N)return\
    \ 0;\n    K res=1;\n    REP_(i,N)res*=A[i][i];\n    return (cnt?-res:res);\n \
    \ }\n\n  SquareMatrix inv()const{\n    SquareMatrix A(M),B(1);\n    REP_(k,N){\n\
    \      if(A[k][k]==0)\n        REP2_(i,k+1,N)\n          if(A[i][k]!=0){\n   \
    \         swap(A[i],A[k]);\n            swap(B[i],B[k]);\n          }\n      assert(A[k][k]!=0);\n\
    \      REP_(i,N)if(i!=k){\n        K x=A[i][k]/A[k][k];\n        REP_(j,N){\n\
    \          A[i][j]-=A[k][j]*x;\n          B[i][j]-=B[k][j]*x;\n        }\n   \
    \   }\n      K x=A[k][k];\n      REP_(j,N){\n        A[k][j]/=x;\n        B[k][j]/=x;\n\
    \      }\n    }\n    return B;\n  }\n  \n  friend ostream& operator<<(ostream&os,const\
    \ SquareMatrix &M){ \n    REP_(i,N)REP_(j,N)os<<M.M[i][j]<<\"\\n \"[j+1<N];\n\
    \    return os;\n  }\n  friend istream& operator>>(istream&is,SquareMatrix &M){\
    \ REP_(i,N)REP_(j,N)is>>M.M[i][j]; return is; }\n};\n#undef REP_\n#undef REP2_\n"
  code: "#pragma once\n#define REP_(i,n) for(int i=0;i<(n);i++)\n#define REP2_(i,s,n)\
    \ for(int i=(s);i<(n);i++)\ntemplate<typename K,size_t N>\nstruct SquareMatrix{\n\
    \  using value_type=K;\n  using vec=array<K,N>;\n  using mat=array<vec,N>;\n \
    \ mat M;\n\n  SquareMatrix(K a=0){ \n    for(vec& v:M)v.fill(0); \n    if(a!=0)REP_(i,N)M[i][i]=a;\n\
    \  }\n  SquareMatrix(const mat&A):M(A){}\n  SquareMatrix(const vector<vector<K>>&v){\n\
    \    assert(v.size()==N and v[0].size()==N);\n    REP_(i,N)REP_(j,N)M[i][j]=v[i][j];\n\
    \  }\n\n  vec& operator[](size_t k){return M[k];}\n  const vec& operator[](size_t\
    \ k)const{return M[k];}\n  \n  SquareMatrix& operator+=(const SquareMatrix &A){\n\
    \    REP_(i,N)REP_(j,N)M[i][j]+=A[i][j];\n    return *this;\n  }\n  SquareMatrix&\
    \ operator-=(const SquareMatrix &A){\n    REP_(i,N)REP_(j,N)M[i][j]-=A[i][j];\n\
    \    return *this;\n  }\n  SquareMatrix operator+(const SquareMatrix &A)const{\
    \ return SquareMatrix(M)+=A; }\n  SquareMatrix operator-(const SquareMatrix &A)const{\
    \ return SquareMatrix(M)-=A; }\n\n  friend SquareMatrix operator*(const SquareMatrix\
    \ &A,const SquareMatrix &B){\n    SquareMatrix res;\n    REP_(i,N)REP_(k,N)REP_(j,N)res[i][j]+=A[i][k]*B[k][j];\n\
    \    return res;\n  }\n  SquareMatrix& operator*=(const SquareMatrix &A){\n  \
    \  M=((*this)*A).M;\n    return *this;\n  }\n\n  SquareMatrix& operator/=(const\
    \ SquareMatrix&A){ return (*this) *= A.inv(); }\n  SquareMatrix operator/(const\
    \ SquareMatrix&A)const{ return SquareMatrix(M) /= A; }\n\n  bool operator==(const\
    \ SquareMatrix &A){\n    REP_(i,N)REP_(j,N)if(M[i][j]!=A[i][j])return false;\n\
    \    return true;\n  }\n  bool operator!=(const SquareMatrix &A){ return !((*this)==A);\
    \ }\n  \n  static SquareMatrix I(){ return SquareMatrix(1); }\n  \n  SquareMatrix\
    \ pow(long long n)const{\n    assert(n>=0);\n    SquareMatrix A(M),res(1);\n \
    \   while(n){\n      if(n&1)res*=A;\n      A*=A;\n      n>>=1;\n    }\n    return\
    \ res;\n  }\n\n  pair<int,int> GaussJordan(){\n    int rnk=0,cnt=0;\n    REP_(k,N){\n\
    \      if(M[rnk][k]==0)\n        REP2_(i,rnk+1,N)\n          if(M[i][k]!=0){\n\
    \            swap(M[i],M[rnk]);\n            cnt^=1;\n            break;\n   \
    \       }\n      if(M[rnk][k]==0)continue;\n      REP_(i,N)if(i!=rnk){\n     \
    \   K x=M[i][k]/M[rnk][k];\n        REP_(j,N)M[i][j]-=M[rnk][j]*x;\n      }\n\
    \      if(++rnk==N)break;\n    }\n    return {rnk,cnt};\n  }\n\n  K det()const{\n\
    \    SquareMatrix A(M);\n    const auto&[rnk,cnt]=A.GaussJordan();\n    if(rnk!=N)return\
    \ 0;\n    K res=1;\n    REP_(i,N)res*=A[i][i];\n    return (cnt?-res:res);\n \
    \ }\n\n  SquareMatrix inv()const{\n    SquareMatrix A(M),B(1);\n    REP_(k,N){\n\
    \      if(A[k][k]==0)\n        REP2_(i,k+1,N)\n          if(A[i][k]!=0){\n   \
    \         swap(A[i],A[k]);\n            swap(B[i],B[k]);\n          }\n      assert(A[k][k]!=0);\n\
    \      REP_(i,N)if(i!=k){\n        K x=A[i][k]/A[k][k];\n        REP_(j,N){\n\
    \          A[i][j]-=A[k][j]*x;\n          B[i][j]-=B[k][j]*x;\n        }\n   \
    \   }\n      K x=A[k][k];\n      REP_(j,N){\n        A[k][j]/=x;\n        B[k][j]/=x;\n\
    \      }\n    }\n    return B;\n  }\n  \n  friend ostream& operator<<(ostream&os,const\
    \ SquareMatrix &M){ \n    REP_(i,N)REP_(j,N)os<<M.M[i][j]<<\"\\n \"[j+1<N];\n\
    \    return os;\n  }\n  friend istream& operator>>(istream&is,SquareMatrix &M){\
    \ REP_(i,N)REP_(j,N)is>>M.M[i][j]; return is; }\n};\n#undef REP_\n#undef REP2_\n"
  dependsOn: []
  isVerificationFile: false
  path: library/linearalgebra/SquareMatrix.cpp
  requiredBy: []
  timestamp: '2023-07-02 19:12:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/650.test.cpp
documentation_of: library/linearalgebra/SquareMatrix.cpp
layout: document
redirect_from:
- /library/library/linearalgebra/SquareMatrix.cpp
- /library/library/linearalgebra/SquareMatrix.cpp.html
title: library/linearalgebra/SquareMatrix.cpp
---