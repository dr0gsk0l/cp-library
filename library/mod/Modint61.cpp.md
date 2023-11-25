---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: library/sequence/RollingHash.cpp
    title: library/sequence/RollingHash.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/AOJ/ALDS1_14_B.test.cpp
    title: test/AOJ/ALDS1_14_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/mod/Modint61.cpp\"\nstruct Modint61{\n  using ll=long\
    \ long;\n  static constexpr ll MOD=(1LL<<61)-1;\n  ll v;\n  Modint61(const ll\
    \ x=0):v(x){\n    if(v<0||v>=MOD){\n      v%=MOD;\n      if(v<0)v+=MOD;\n    }\n\
    \  }\n  static Modint61 raw(ll v){\n    Modint61 x;\n    x.v=v;\n    return x;\n\
    \  }\nprivate:\n  template<int d>\n  static constexpr pair<ll,ll> divide(const\
    \ ll&a){\n    return {a>>d, a&((1LL<<d)-1)};\n  }\npublic:\n  Modint61 pow(long\
    \ long k){\n    Modint61 res(1),tmp(v);\n    while(k){\n      if(k&1)res*=tmp;\n\
    \      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n  }\n\n  Modint61 inv(){\
    \ return pow(MOD-2); }\n\n  Modint61& operator+=(Modint61 a){v+=a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Modint61& operator-=(Modint61 a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Modint61& operator*=(Modint61 a){\n    const auto [vu,vd]=divide<31>(v);\n\
    \    const auto [au,ad]=divide<31>(a.v);\n    ll x = vd*au + vu*ad;\n    const\
    \ auto [xu,xd]=divide<30>(x);\n    v = vu*au*2 + xu + (xd<<31) + vd*ad;\n    if(v>=MOD){\n\
    \      const auto [vu2,vd2]=divide<61>(v);\n      v=vu2+vd2;\n    }\n    if(v>=MOD)v-=MOD;\n\
    \    return *this;\n  }\n  Modint61& operator/=(Modint61 a){\n    return (*this)*=a.inv();\n\
    \  }\n  Modint61 operator+(Modint61 a) const{return Modint61(v)+=a;}\n  Modint61\
    \ operator-(Modint61 a) const{return Modint61(v)-=a;}\n  Modint61 operator*(Modint61\
    \ a) const{return Modint61(v)*=a;}\n  Modint61 operator/(Modint61 a) const{return\
    \ Modint61(v)/=a;}\n\n  Modint61 operator+() const{return *this;}\n  Modint61\
    \ operator-() const{return v?Modint61(MOD-v):Modint61(v);}\n\n  bool operator==(const\
    \ Modint61 a)const{return v==a.v;}\n  bool operator!=(const Modint61 a)const{return\
    \ v!=a.v;}\n  bool operator<(const Modint61 a)const{return v<a.v;}\n};\n"
  code: "struct Modint61{\n  using ll=long long;\n  static constexpr ll MOD=(1LL<<61)-1;\n\
    \  ll v;\n  Modint61(const ll x=0):v(x){\n    if(v<0||v>=MOD){\n      v%=MOD;\n\
    \      if(v<0)v+=MOD;\n    }\n  }\n  static Modint61 raw(ll v){\n    Modint61\
    \ x;\n    x.v=v;\n    return x;\n  }\nprivate:\n  template<int d>\n  static constexpr\
    \ pair<ll,ll> divide(const ll&a){\n    return {a>>d, a&((1LL<<d)-1)};\n  }\npublic:\n\
    \  Modint61 pow(long long k){\n    Modint61 res(1),tmp(v);\n    while(k){\n  \
    \    if(k&1)res*=tmp;\n      tmp*=tmp;\n      k>>=1;\n    }\n    return res;\n\
    \  }\n\n  Modint61 inv(){ return pow(MOD-2); }\n\n  Modint61& operator+=(Modint61\
    \ a){v+=a.v;if(v>=MOD)v-=MOD;return *this;}\n  Modint61& operator-=(Modint61 a){v+=MOD-a.v;if(v>=MOD)v-=MOD;return\
    \ *this;}\n  Modint61& operator*=(Modint61 a){\n    const auto [vu,vd]=divide<31>(v);\n\
    \    const auto [au,ad]=divide<31>(a.v);\n    ll x = vd*au + vu*ad;\n    const\
    \ auto [xu,xd]=divide<30>(x);\n    v = vu*au*2 + xu + (xd<<31) + vd*ad;\n    if(v>=MOD){\n\
    \      const auto [vu2,vd2]=divide<61>(v);\n      v=vu2+vd2;\n    }\n    if(v>=MOD)v-=MOD;\n\
    \    return *this;\n  }\n  Modint61& operator/=(Modint61 a){\n    return (*this)*=a.inv();\n\
    \  }\n  Modint61 operator+(Modint61 a) const{return Modint61(v)+=a;}\n  Modint61\
    \ operator-(Modint61 a) const{return Modint61(v)-=a;}\n  Modint61 operator*(Modint61\
    \ a) const{return Modint61(v)*=a;}\n  Modint61 operator/(Modint61 a) const{return\
    \ Modint61(v)/=a;}\n\n  Modint61 operator+() const{return *this;}\n  Modint61\
    \ operator-() const{return v?Modint61(MOD-v):Modint61(v);}\n\n  bool operator==(const\
    \ Modint61 a)const{return v==a.v;}\n  bool operator!=(const Modint61 a)const{return\
    \ v!=a.v;}\n  bool operator<(const Modint61 a)const{return v<a.v;}\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/mod/Modint61.cpp
  requiredBy:
  - library/sequence/RollingHash.cpp
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/AOJ/ALDS1_14_B.test.cpp
documentation_of: library/mod/Modint61.cpp
layout: document
redirect_from:
- /library/library/mod/Modint61.cpp
- /library/library/mod/Modint61.cpp.html
title: library/mod/Modint61.cpp
---
