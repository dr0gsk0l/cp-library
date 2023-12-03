---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/algebra/group/Add.cpp
    title: library/algebra/group/Add.cpp
  - icon: ':question:'
    path: library/datastructure/FenwickTree.cpp
    title: library/datastructure/FenwickTree.cpp
  - icon: ':question:'
    path: library/datastructure/FullyIndexableDictionary.cpp
    title: library/datastructure/FullyIndexableDictionary.cpp
  - icon: ':question:'
    path: library/datastructure/WaveletMatrix.cpp
    title: library/datastructure/WaveletMatrix.cpp
  - icon: ':question:'
    path: library/util/Compress.cpp
    title: library/util/Compress.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
    title: test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/library-checker/DataStructure/RectangleSum.test.cpp
    title: test/library-checker/DataStructure/RectangleSum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/924.test.cpp
    title: test/yukicoder/924.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/datastructure/FullyIndexableDictionary.cpp\"\nclass\
    \ FullyIndexableDictionary{\n  int n,\n      block; // 64\u500B\u4E8B\u306B\u533A\
    \u5207\u3063\u305F\u30D6\u30ED\u30C3\u30AF\u306E\u500B\u6570\n  vector<unsigned\
    \ long long> bit;\n  vector<unsigned int> sum; // \u30D6\u30ED\u30C3\u30AF\u6BCE\
    \u306E\u7D2F\u7A4D\u548C\n  bool prepared;\npublic:\n  FullyIndexableDictionary(){}\n\
    \  FullyIndexableDictionary(int n)\n    :n(n),block((n+63)>>6),bit(block,0),sum(block+1,0),prepared(false){}\n\
    \n  bool is_prepared(){ return prepared; }\n\n  void set(int k){\n    bit[k>>6]|=1ull<<(k&63);\n\
    \    sum[(k>>6)+1]++;\n  }\n  void build(){ \n    assert(!prepared);\n    prepared=true;\n\
    \    for(int i=0;i<block;i++)sum[i+1]+=sum[i]; \n  }\n\n  bool operator[](int\
    \ k)const{\n    return bool((bit[k>>6]>>(k&63))&1);\n  }\n\n  // [0,j) \u306E\u5408\
    \u8A08\n  int rank(int j,bool f=1){\n    assert(prepared);\n    int a=sum[j>>6]+__builtin_popcountll(bit[j>>6]&((1ull<<(j&63))-1));\n\
    \    return (f?a:j-a);\n  }\n  // 0-indexed \u3067 k \u756A\u76EE\u306E f \u306E\
    \u5834\u6240 \n  int select(int k,bool f=1){\n    assert(prepared);\n    if(k<0\
    \ or rank(n,f)<=k)return -1;\n    int l=0,r=n;\n    while(r-l>1){\n      int m=(l+r)>>1;\n\
    \      (rank(m,f)>=k+1?r:l)=m;\n    }\n    return r-1;\n  }\n  // l\u4EE5\u4E0A\
    \u3067 k \u756A\u76EE\u306E f \u306E\u5834\u6240\n  int select(int k,bool f,int\
    \ l){\n    return select(rank(l,f)+k,f);\n  }\n};\n#line 2 \"library/util/Compress.cpp\"\
    \n#define ALL_(v) v.begin(),v.end()\ntemplate<typename T,bool Sentinel=false>\n\
    class Compress{\n  vector<T> v;\n  bool prepared;\npublic:\n  Compress():prepared(false){\n\
    \    if constexpr(Sentinel){\n      static_assert(std::numeric_limits<T>::is_specialized,\"\
    cannot use Sentinel\");\n      v={numeric_limits<T>::min(),numeric_limits<T>::max()};\n\
    \    }\n  }\n  Compress(const vector<T>&w):v(w),prepared(false){\n    if constexpr(Sentinel){\n\
    \      static_assert(std::numeric_limits<T>::is_specialized,\"cannot use Sentinel\"\
    );\n      v.push_back(numeric_limits<T>::min());\n      v.push_back(numeric_limits<T>::max());\n\
    \    }\n    build();\n  }\n  \n  void add(T a){ \n    assert(!prepared);\n   \
    \ v.push_back(a); \n  }\n  void build(){\n    assert(!prepared);\n    prepared=true;\n\
    \    sort(ALL_(v));\n    v.erase(unique(ALL_(v)),v.end());\n  }\n\n  bool is_prepared()const{\
    \ return prepared; }\n\n  int operator[](const T&a)const{\n    assert(prepared);\n\
    \    auto it=lower_bound(ALL_(v),a);\n    assert(*it==a);\n    return distance(v.begin(),it);\n\
    \  }\n  int geq(const T&a)const{\n    assert(prepared);\n    auto it=lower_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int gt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=upper_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n  }\n\
    \  int leq(const T&a)const{\n    assert(prepared);\n    auto it=--upper_bound(ALL_(v),a);\n\
    \    return distance(v.begin(),it);\n  }\n  int lt(const T&a)const{\n    assert(prepared);\n\
    \    auto it=--lower_bound(ALL_(v),a);\n    return distance(v.begin(),it);\n \
    \ }\n  T r(int id)const{\n    assert(prepared);\n    return v[id];\n  }\n  bool\
    \ exist(const T&a)const{\n    assert(prepared);\n    return (*lower_bound(ALL_(v),a))==a;\n\
    \  }\n  int size()const{return v.size();}\n  T max()const{ return v.back(); }\n\
    \  T min()const{ return v[0]; }\n\n  friend ostream&operator<<(ostream&os, const\
    \ Compress&C){ \n    for(int i=0;i<C.v.size();i++)os<<C.v[i]<<\":\"<<i<<\" \"\
    ;\n    return os;\n  }\n};\n#undef ALL_\n#line 4 \"library/datastructure/WaveletMatrix.cpp\"\
    \n#define REP_(i,n) for(int i=0;i<(n);i++)\ntemplate<typename T,bool COMPRESS=true>\n\
    class WaveletMatrix{\nprotected:\n  using U=conditional_t<COMPRESS,int,T>;\n \
    \ static_assert(is_integral_v<U>,\"Wavelet Matrix is only for integer\");\n  int\
    \ n,memo,log;\n  vector<FullyIndexableDictionary> mat;\n  vector<int> zero_cnt;\n\
    \  Compress<T,true> C;\n  vector<T> data;\n\n  constexpr U comp(const T&x)const{\n\
    \    if constexpr(COMPRESS){ return C.geq(x); }\n    else{ return x; }\n  }\n\
    \  constexpr T uncomp(const U&a){\n    if constexpr(COMPRESS){ return C.r(a);\
    \ }\n    else{ return a; }\n  }\n\n  // 0-indexed \u3067\u4E0B\u304B\u3089 i bit\
    \ \u76EE\n  inline bool low_bit (const U&a,int i)const{ return (a>>i)&1; }\n \
    \ // 0-indexed \u3067\u4E0A\u304B\u3089 i bit \u76EE\n  inline bool high_bit(const\
    \ U&a,int i)const{ return low_bit(a,log-i-1); }\n\n  int nxt(int idx,int h,const\
    \ U&a){\n    // idx \u306E\u4F4D\u7F6E\u306B a \u304C\u3042\u3063\u305F\u5834\u5408\
    \u4E0A\u304B\u3089 h bit \u76EE\u3067\u3069\u3053\u306B\u884C\u304F\u304B\n  \
    \  bool bit=high_bit(a,h);\n    return mat[h].rank(idx,bit)+(bit?zero_cnt[h]:0);\n\
    \  }\npublic:\n  WaveletMatrix(vector<T> v,int log_=0):n(v.size()),data(v),log(log_){\n\
    \    vector<U> cv(n);\n    if constexpr(COMPRESS){\n      C=Compress<T,true>(v);\n\
    \      for(int i=0;i<n;i++)cv[i]=C[v[i]];\n      while(C.size()>=(1ull<<log))log++;\n\
    \    }\n    else{\n      cv=v;\n      T mx=0;\n      for(const T&a:v){\n     \
    \   assert(a>=0);\n        if(mx<a)mx=a;\n      }\n      while(mx>=(1ull<<log))log++;\n\
    \    }\n    mat.resize(log);\n    zero_cnt.resize(log);\n    vector<U> lv(n),rv(n);\n\
    \    REP_(h,log){\n      mat[h]=FullyIndexableDictionary(n);\n      int l=0,r=0;\n\
    \      REP_(i,n)\n        if(high_bit(cv[i],h)){\n          rv[r++]=cv[i];\n \
    \         mat[h].set(i);\n        }\n        else\n          lv[l++]=cv[i];\n\
    \      zero_cnt[h]=l;\n      mat[h].build();\n      swap(lv,cv);\n      REP_(i,r)cv[l+i]=rv[i];\n\
    \    }\n  }\n\n  // [l,r) \u306E x \u306E\u500B\u6570\n  int rank(int l,int r,const\
    \ T&x){\n    if constexpr(COMPRESS){\n      if(!C.exist(x))return 0;\n    }\n\
    \    U a=comp(x);\n    REP_(h,log){\n      l=nxt(l,h,a);\n      r=nxt(r,h,a);\n\
    \    }\n    memo=l;\n    return r-l;\n  }\n  int rank(int r,const T&x){ return\
    \ rank(x,0,r); }\n\n  // k \u756A\u76EE\u306E x \u306E index\n  int select(int\
    \ k,const T&x){\n    U a=comp(x);\n    if(rank(a,n)<k)return -1;\n    k+=memo;\n\
    \    for(int h=log-1;h>=0;h--){\n      bool bit=high_bit(a,h);\n      if(bit)k-=zero_cnt[h];\n\
    \      k=mat[h].select(k,bit);\n    }\n    return k;\n  }\n  \n  // [l,r) \u3067\
    \ 0-indexed k \u756A\u76EE\u306B\u5927\u304D\u3044\u5024\n  T kth_largest(int\
    \ l,int r,int k){\n    if(k<0 or r-l<=k) return -1;\n    U res=0;\n    REP_(h,log){\n\
    \      int L=mat[h].rank(l);\n      int R=mat[h].rank(r);\n      res<<=1;\n  \
    \    if(R-L>k){\n        l=L+zero_cnt[h];\n        r=R+zero_cnt[h];\n        res++;\n\
    \      }\n      else{\n        k-=R-L;\n        l-=L;\n        r-=R;\n      }\n\
    \    }\n    return uncomp(res);\n  }\n  T kth_smallest(int l,int r,int k){ return\
    \ kth_largest(l,r,r-l-k-1); }\n\n  // [l,r) \u3067 x \u672A\u6E80\u306E\u500B\u6570\
    \n  int range_freq(int l,int r,const T&upper){\n    U a=comp(upper);\n    int\
    \ res=0;\n    REP_(h,log){\n      if(high_bit(a,h)){\n        int L=mat[h].rank(l,0),R=mat[h].rank(r,0);\n\
    \        res+=R-L;\n      }\n      l=nxt(l,h,a);\n      r=nxt(r,h,a);\n    }\n\
    \    return res;\n  }\n  // [l,r) \u3067 [lower,upper) \u306E\u500B\u6570\n  int\
    \ range_freq(int l,int r,const T&lower,const T&upper){\n    return range_freq(l,r,upper)-range_freq(l,r,lower);\n\
    \  }\n\n  optional<T> lt(int l,int r,const T&x){\n    int cnt=range_freq(l,r,x);\n\
    \    if(cnt)return kth_smallest(l,r,cnt-1);\n    return nullopt;\n  }\n  optional<T>\
    \ leq(int l,int r,const T&x){\n    if(rank(l,r,x))return x;\n    return lt(l,r,x);\n\
    \  }\n  optional<T> geq(int l,int r,const T&x){\n    int cnt=r-l-range_freq(l,r,x);\n\
    \    if(cnt)return kth_largest(l,r,cnt-1);\n    return nullopt;\n  }\n  optional<T>\
    \ gt(int l,int r,const T&x){\n    T y;\n    if constexpr(COMPRESS){ y=C.r(C.gt(x));\
    \ }\n    else{ y=x+1; }\n    return geq(l,r,y);\n  }\n\n  // \u30BB\u30B0\u6728\
    \u306A\u3069\u3092\u8F09\u305B\u308B\u6642\u7528\n  // BIT \u306F\u5C02\u7528\u306E\
    \u30E9\u30A4\u30D6\u30E9\u30EA\u3092\u4F5C\u3063\u3066\u3042\u308B\u304C\u3001\
    \u4E00\u5FDC\u62BD\u8C61\u5316\u3082\u6301\u3063\u3066\u304A\u304F\n  // \u69CB\
    \u7BC9\u3057\u305F\u3082\u306E\u3092\u8FD4\u3057\u3066\u308B\u306E\u3067\u9045\
    \u305D\u3046\n  int height()const{ return log; }\n  vector<int> points(int idx){\n\
    \    vector<int> res(log);\n    U a=comp(data[idx]);\n    REP_(h,log){\n     \
    \ idx=nxt(idx,h,a);\n      res[h]=idx;\n    }\n    return res;\n  }\n  vector<tuple<int,int,int>>\
    \ intervals(int l,int r,const T&upper){\n    vector<tuple<int,int,int>> res;\n\
    \    U a=comp(upper);\n    REP_(h,log){\n      if(high_bit(a,h)){\n        int\
    \ L=mat[h].rank(l,0),R=mat[h].rank(r,0);\n        res.emplace_back(h,L,R);\n \
    \     }\n      l=nxt(l,h,a);\n      r=nxt(r,h,a);\n    }\n    return res;\n  }\n\
    \  vector<tuple<int,int,int>> kth_largest_intervals(int l,int r,int k){\n    assert(0<=k\
    \ and k<r-l);\n    vector<tuple<int,int,int>> res;\n    REP_(h,log){\n      int\
    \ L=mat[h].rank(l);\n      int R=mat[h].rank(r);\n      if(R-L>k){\n        l=L+zero_cnt[h];\n\
    \        r=R+zero_cnt[h];\n      }\n      else{\n        res.emplace_back(h,L+zero_cnt[h],R+zero_cnt[h]);\n\
    \        k-=R-L;\n        l-=L;\n        r-=R;\n      }\n    }\n    return res;\n\
    \  }\n  vector<tuple<int,int,int>> kth_smallest_intervals(int l,int r,int k){\n\
    \    return kth_largest_intervals(l,r,r-l-k-1);\n  }\n};\n#undef REP_\n#line 2\
    \ \"library/algebra/group/Add.cpp\"\ntemplate<typename X>\nstruct GroupAdd {\n\
    \  using value_type = X;\n  static constexpr X op(const X &x, const X &y) noexcept\
    \ { return x + y; }\n  static constexpr void Rchop(X&x, const X&y){ x+=y; }\n\
    \  static constexpr void Lchop(const X&x, X&y){ y+=x; }\n  static constexpr X\
    \ inverse(const X &x) noexcept { return -x; }\n  static constexpr X power(const\
    \ X &x, long long n) noexcept { return X(n) * x; }\n  static constexpr X unit()\
    \ { return X(0); }\n  static constexpr bool commute = true;\n};\n#line 3 \"library/datastructure/FenwickTree.cpp\"\
    \ntemplate<typename AbelGroup=GroupAdd<long long>>\nclass FenwickTree{\n  using\
    \ G=AbelGroup;\n  using T=typename G::value_type;\n  int n;\n  vector<T> dat,raw;\n\
    public:\n  FenwickTree(){\n    assert(G::commute);\n  }\n  FenwickTree(int n):n(n){\n\
    \    assert(G::commute);\n    dat=raw=vector<T>(n,G::unit());\n  }\n  FenwickTree(const\
    \ vector<T>&v):n(v.size()),raw(v),dat(v){\n    assert(G::commute);\n    for(int\
    \ i=1;i<=n;i++){\n      int j=i+(i&-i);\n      if(j<=n)G::Rchop(dat[j-1],dat[i-1]);\n\
    \    }\n  }\n\n  T operator[](int k)const{ return raw[k]; }\n  T get(int k)const{\
    \ return raw[k]; }\n\n  void multiply(int k,const T&x){\n    G::Rchop(raw[k],x);\n\
    \    for(++k;k<=n;k+=k&-k)G::Rchop(dat[k-1],x);\n  }\n  void add(int k,const T&x){\
    \ multiply(k,x); }\n  void set(int k,const T&x){ multiply(k,G::op(x,G::inverse(raw[k])));\
    \ }\n\n  T prod(int k)const{\n    T res=G::unit();\n    while(k>0){\n      G::Rchop(res,\
    \ dat[k-1]);\n      k -= k&-k;\n    }\n    return res;\n  }\n  T sum(int k)const{\
    \ return prod(k); }\n  T prod(int L,int R)const{\n    T pos=G::unit();\n    while(L<R){\n\
    \      G::Rchop(pos,dat[R-1]);\n      R -= R&-R;\n    }\n    T neg=G::unit();\n\
    \    while(R<L){\n      G::Rchop(neg,dat[L-1]);\n      L -= L&-L;\n    }\n   \
    \ return G::op(pos,G::inverse(neg));\n  }\n  T sum(int L,int R)const{ return prod(L,R);\
    \ }\n\n  template<class F>\n  int max_right(const F check)const{\n    assert(check(G::unit()));\n\
    \    int r=0;\n    T sum=G::unit();\n    int k=1;\n    while(2*k<=n)k<<=1;\n \
    \   while(k){\n      if(r+k-1<dat.size())\n        if(check(G::op(sum,dat[r+k-1]))){\n\
    \          G::Rchop(sum,dat[r+k-1]);\n          r += k;\n        }\n      k >>=\
    \ 1;\n    }\n    return r;\n  }\n\n  int kth(T k)const{\n    return max_right(\
    \ [&k](T x){ return x<=k; } );\n  }\n};\n#line 4 \"library/datastructure/GroupWaveletMatrix.cpp\"\
    \n#define REP_(i,n) for(int i=0;i<(n);i++)\ntemplate<typename T,typename AbelGroup>\n\
    class GroupWaveletMatrix:WaveletMatrix<T,true>{\n  using super=WaveletMatrix<T,true>;\n\
    \  using super::log,super::n,super::nxt,super::comp,super::data,super::high_bit,super::mat,super::zero_cnt;\n\
    \  using U=typename super::U;\n  using FT=FenwickTree<AbelGroup>;\n  using S=typename\
    \ AbelGroup::value_type;\n  vector<FT> ft;\npublic:\n  using super::rank,super::select,super::kth_largest,super::kth_smallest,super::range_freq,super::lt,super::leq,super::gt,super::geq;\n\
    \  GroupWaveletMatrix(vector<T> v):super::WaveletMatrix(v){\n    ft.resize(log);\n\
    \    for(auto&p:ft)p=FT(n);\n  }\n  GroupWaveletMatrix(vector<T> v,const vector<S>&w):GroupWaveletMatrix(v){\n\
    \    for(int i=0;i<n;i++)add(i,w[i]);\n  }\n  void add(int idx,const S&val){\n\
    \    U a=comp(data[idx]);\n    REP_(h,log){\n      idx=nxt(idx,h,a);\n      ft[h].add(idx,val);\n\
    \    }\n  }\n  S sum(int l,int r,const T&upper){\n    U a=comp(upper);\n    S\
    \ res=AbelGroup::unit();\n    REP_(h,log){\n      if(high_bit(a,h)){\n       \
    \ int L=mat[h].rank(l,0),R=mat[h].rank(r,0);\n        AbelGroup::Rchop(res,ft[h].sum(L,R));\n\
    \      }\n      l=nxt(l,h,a);\n      r=nxt(r,h,a);\n    }\n    return res;\n \
    \ }\n  S sum(int l,int r,const T&lower,const T&upper){\n    return AbelGroup::op(sum(l,r,upper),AbelGroup::inverse(sum(l,r,lower)));\n\
    \  }\n  S kth_largest_sum(int l,int r,int k){\n    assert(0<=k and k<r-l);\n \
    \   S res=AbelGroup::unit();\n    REP_(h,log){\n      int L=mat[h].rank(l);\n\
    \      int R=mat[h].rank(r);\n      if(R-L>k){\n        l=L+zero_cnt[h];\n   \
    \     r=R+zero_cnt[h];\n      }\n      else{\n        AbelGroup::Rchop(res,ft[h].sum(L+zero_cnt[h],R+zero_cnt[h]));\n\
    \        k-=R-L;\n        l-=L;\n        r-=R;\n      }\n    }\n    return res;\n\
    \  }\n};\n#undef REP_\n"
  code: "#pragma once\n#include \"library/datastructure/WaveletMatrix.cpp\"\n#include\
    \ \"library/datastructure/FenwickTree.cpp\"\n#define REP_(i,n) for(int i=0;i<(n);i++)\n\
    template<typename T,typename AbelGroup>\nclass GroupWaveletMatrix:WaveletMatrix<T,true>{\n\
    \  using super=WaveletMatrix<T,true>;\n  using super::log,super::n,super::nxt,super::comp,super::data,super::high_bit,super::mat,super::zero_cnt;\n\
    \  using U=typename super::U;\n  using FT=FenwickTree<AbelGroup>;\n  using S=typename\
    \ AbelGroup::value_type;\n  vector<FT> ft;\npublic:\n  using super::rank,super::select,super::kth_largest,super::kth_smallest,super::range_freq,super::lt,super::leq,super::gt,super::geq;\n\
    \  GroupWaveletMatrix(vector<T> v):super::WaveletMatrix(v){\n    ft.resize(log);\n\
    \    for(auto&p:ft)p=FT(n);\n  }\n  GroupWaveletMatrix(vector<T> v,const vector<S>&w):GroupWaveletMatrix(v){\n\
    \    for(int i=0;i<n;i++)add(i,w[i]);\n  }\n  void add(int idx,const S&val){\n\
    \    U a=comp(data[idx]);\n    REP_(h,log){\n      idx=nxt(idx,h,a);\n      ft[h].add(idx,val);\n\
    \    }\n  }\n  S sum(int l,int r,const T&upper){\n    U a=comp(upper);\n    S\
    \ res=AbelGroup::unit();\n    REP_(h,log){\n      if(high_bit(a,h)){\n       \
    \ int L=mat[h].rank(l,0),R=mat[h].rank(r,0);\n        AbelGroup::Rchop(res,ft[h].sum(L,R));\n\
    \      }\n      l=nxt(l,h,a);\n      r=nxt(r,h,a);\n    }\n    return res;\n \
    \ }\n  S sum(int l,int r,const T&lower,const T&upper){\n    return AbelGroup::op(sum(l,r,upper),AbelGroup::inverse(sum(l,r,lower)));\n\
    \  }\n  S kth_largest_sum(int l,int r,int k){\n    assert(0<=k and k<r-l);\n \
    \   S res=AbelGroup::unit();\n    REP_(h,log){\n      int L=mat[h].rank(l);\n\
    \      int R=mat[h].rank(r);\n      if(R-L>k){\n        l=L+zero_cnt[h];\n   \
    \     r=R+zero_cnt[h];\n      }\n      else{\n        AbelGroup::Rchop(res,ft[h].sum(L+zero_cnt[h],R+zero_cnt[h]));\n\
    \        k-=R-L;\n        l-=L;\n        r-=R;\n      }\n    }\n    return res;\n\
    \  }\n};\n#undef REP_\n"
  dependsOn:
  - library/datastructure/WaveletMatrix.cpp
  - library/datastructure/FullyIndexableDictionary.cpp
  - library/util/Compress.cpp
  - library/datastructure/FenwickTree.cpp
  - library/algebra/group/Add.cpp
  isVerificationFile: false
  path: library/datastructure/GroupWaveletMatrix.cpp
  requiredBy: []
  timestamp: '2023-12-03 21:15:11+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/library-checker/DataStructure/RectangleSum.test.cpp
  - test/library-checker/DataStructure/PointAddRectangleSum.test.cpp
  - test/yukicoder/924.test.cpp
documentation_of: library/datastructure/GroupWaveletMatrix.cpp
layout: document
redirect_from:
- /library/library/datastructure/GroupWaveletMatrix.cpp
- /library/library/datastructure/GroupWaveletMatrix.cpp.html
title: library/datastructure/GroupWaveletMatrix.cpp
---
