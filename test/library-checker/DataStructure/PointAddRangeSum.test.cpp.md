---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
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
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/library-checker/DataStructure/PointAddRangeSum.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 2 \"library/segtree/SegmentTree.cpp\"\
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
    )\";\n    return os;\n  }\n};\n#line 2 \"library/algebra/group/Add.cpp\"\ntemplate<typename\
    \ X>\nstruct GroupAdd {\n  using value_type = X;\n  static constexpr X op(const\
    \ X &x, const X &y) noexcept { return x + y; }\n  static constexpr void Rchop(X&x,\
    \ const X&y){ x+=y; }\n  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n\
    \  static constexpr X inverse(const X &x) noexcept { return -x; }\n  static constexpr\
    \ X power(const X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr\
    \ X unit() { return X(0); }\n  static constexpr bool commute = true;\n};\n#line\
    \ 7 \"test/library-checker/DataStructure/PointAddRangeSum.test.cpp\"\n\nusing\
    \ ll=long long;\nusing G=GroupAdd<ll>;\n\nint main(){\n  int n,q;cin>>n>>q;\n\
    \  vector<ll> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n  SegmentTree<G> seg(v);\n\
    \  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r)<<\"\\\
    n\";\n    else seg.multiply(l,r);\n  }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\n\n#include \"library/segtree/SegmentTree.cpp\"\
    \n#include \"library/algebra/group/Add.cpp\"\n\nusing ll=long long;\nusing G=GroupAdd<ll>;\n\
    \nint main(){\n  int n,q;cin>>n>>q;\n  vector<ll> v(n);\n  for(int i=0;i<n;i++)cin>>v[i];\n\
    \  SegmentTree<G> seg(v);\n  while(q--){\n    int t,l,r;cin>>t>>l>>r;\n    if(t)cout<<seg.prod(l,r)<<\"\
    \\n\";\n    else seg.multiply(l,r);\n  }\n}"
  dependsOn:
  - library/segtree/SegmentTree.cpp
  - library/algebra/group/Add.cpp
  isVerificationFile: true
  path: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
  requiredBy: []
  timestamp: '2023-11-25 18:30:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp
- /verify/test/library-checker/DataStructure/PointAddRangeSum.test.cpp.html
title: test/library-checker/DataStructure/PointAddRangeSum.test.cpp
---
