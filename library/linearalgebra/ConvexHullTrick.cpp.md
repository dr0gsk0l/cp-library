---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: library/linearalgebra/Linear.cpp
    title: library/linearalgebra/Linear.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/2012.test.cpp
    title: test/yukicoder/2012.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"library/linearalgebra/Linear.cpp\"\ntemplate<typename T>\n\
    struct Line{\n  T a,b;\n  Line()=default;\n  Line(T a,T b):a(a),b(b){}\n  Line(pair<T,T>\
    \ l):a(l.first),b(l.second){}\n  Line(T c):a(0),b(c){}\n\n  T operator()(const\
    \ T x)const{ return a*x+b; }\n  Line operator()(const Line&l)const{ return Line(a*l.a,\
    \ a*l.b+b); }\n\n  bool operator==(const Line&l)const{ return a==l.a and b==l.b;\
    \ }\n  bool operator!=(const Line&l)const{ return !(*this == l); }\n  bool operator<(const\
    \ Line&l)const{ return (a==l.a ? a<l.a : b<l.b); }\n\n  Line&operator+=(const\
    \ Line&l){ a+=l.a; b+=l.b; return *this; }\n  Line operator+(const Line&l)const{return\
    \ Line(*this) += l; }\n  Line&operator-=(const Line&l){ a-=l.a; b-=l.b; return\
    \ *this; }\n  Line operator-(const Line&l)const{return Line(*this) -= l; }\n \
    \ Line operator-()const{ return Line(-a,-b); }\n\n  Line&operator+=(const T&c){\
    \ b+=c; return *this; }\n  Line operator+(const T&c)const{ return Line(*this)\
    \ += c; }\n  Line&operator-=(const T&c){ b-=c; return *this; }\n  Line operator-(const\
    \ T&c)const{ return Line(*this) -= c; }\n  Line&operator*=(const T&c){ a*=c; b*=c;\
    \ return *this; }\n  Line operator*(const T&c)const{ return Line(*this) *= c;\
    \ }\n  Line&operator/=(const T&c){ a/=c; b/=c; return *this; }\n  Line operator/(const\
    \ T&c)const{ return Line(*this) /= c; }\n\n  Line inv()const{\n    assert(a!=0);\n\
    \    return Line(T(1)/a, -b/a);\n  }\n\n  friend istream&operator>>(istream&is,Line&l){\n\
    \    is>>l.a>>l.b;\n    return is;\n  }\n  friend ostream&operator<<(ostream&os,const\
    \ Line&l){\n    if(l.a==0 and l.b==0)os<<0;\n    else if(l.a==0)os<<l.b;\n   \
    \ else if(l.b==0)os<<l.a<<\"x\";\n    else if(l.b>0)os<<l.a<<\"x+\"<<l.b;\n  \
    \  else os<<l.a<<\"x-\"<<-l.b;\n    return os;\n  }\n};\n#line 3 \"library/linearalgebra/ConvexHullTrick.cpp\"\
    \nnamespace convex_hull_trick{\n  enum Objective{\n    MINIMIZE = +1,\n    MAXIMIZE\
    \ = -1,\n  };\n\n  // \u6700\u5927\u5316\u306E\u5834\u5408\u306F\u53CD\u8EE2\u3057\
    \u3066\u3001\u5185\u90E8\u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\u306E\u307F\
    \u3092\u6271\u3046\n  // \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\
    \u306B\u306A\u308B\u3088\u3046\u306B\u4FDD\u5B58\n  \n  template<typename T,Objective\
    \ OBJ>\n  class ConvexHullTrick:deque<Line<T>>{\n    using L=Line<T>;\n    using\
    \ deque<L>::back;\n    using deque<L>::front;\n    using deque<L>::push_back;\n\
    \    using deque<L>::push_front;\n    using deque<L>::pop_back;\n    using deque<L>::pop_front;\n\
    \    using deque<L>::at;\n\n    static bool check(const L&l1,const L&l2,const\
    \ L&l3){\n      // l2 \u304C\u8981\u3089\u306A\u3044\u306A\u3089 true \u3092\u8FD4\
    \u3059\n      // \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306F\u4FDD\
    \u8A3C\u3055\u308C\u3066\u308B\n      // \u4EA4\u70B9\u306E x \u5EA7\u6A19\u306F\
    \ (l2.b-l1.b)/(l1.a-l2.a) \u3068 (l3.b-l2.b)/(l2.a-l3.a)\n      // \u3053\u308C\
    \u304C >= \u3060\u3068\u8981\u3089\u306A\u3044\n      return (l2.b-l1.b)*(l2.a-l3.a)\
    \ >= (l3.b-l2.b)*(l1.a-l2.a);\n    }\n\n    void internal_push_back(const L&l){\n\
    \      if(size()){\n        if(back().a == l.a){\n          if(back().b <= l.b)return;\n\
    \          else pop_back();\n        }\n        while(size() >= 2){\n        \
    \  L l1 = at(size()-2), l2 = back();\n          if(check(l1,l2,l))pop_back();\n\
    \          else break;\n        }\n      }\n      push_back(l);\n    }\n\n   \
    \ void internal_push_front(const L&l){\n      if(size()){\n        if(front().a\
    \ == l.a){\n          if(front().b <= l.b)return;\n          else pop_front();\n\
    \        }\n        while(size() >= 2){\n          L l2 = at(0), l3 = at(1);\n\
    \          if(check(l,l2,l3))pop_front();\n          else break;\n        }\n\
    \      }\n      push_front(l);\n    }\n  public:\n    using value_type = L;\n\
    \    using deque<L>::size;\n\n    ConvexHullTrick()=default;\n    ConvexHullTrick(vector<L>\
    \ lines){\n      if(OBJ==-1)for(auto&l:lines)l=-l;\n      sort(lines.begin(),lines.end());\n\
    \      for(const auto&l:lines)internal_push_back(l);\n    }\n\n    void add(L\
    \ l){\n      if(OBJ==-1)l=-l;\n      if(!size() or back().a >= l.a)internal_push_back(l);\n\
    \      else if(l.a >= front().a)internal_push_front(l);\n      else assert(false);\n\
    \    }\n\n    void add(T a,T b){ add(L(a,b)); }\n\n    T query(T x)const{\n  \
    \    assert(size());\n      int l=-1,r=size()-1;\n      while(r-l>1){\n      \
    \  int m=(l+r)>>1;\n        (at(m)(x)>=at(m+1)(x) ? l : r)=m;\n      }\n     \
    \ return at(r)(x)*OBJ;\n    }\n\n    T query_monotone_inc(T x){\n      assert(size());\n\
    \      while(size()>=2 and at(0)(x)>=at(1)(x))\n        pop_front();\n      return\
    \ at(0)(x)*OBJ;\n    }\n\n    T query_monotone_dec(T x){\n      assert(size());\n\
    \      while(size()>=2 and at(size()-2)(x)<=back()(x))\n        pop_back();\n\
    \      return back()(x)*OBJ;\n    }\n    \n    vector<T> query(const vector<T>&xs){\n\
    \      int n=xs.size();\n      vector<int> idx(n);\n      iota(idx.begin(),idx.end(),0);\n\
    \      sort(idx.begin(),idx.end(),[&](int i,int j){ return xs[i]<xs[j]; });\n\
    \      vector<T> ans(n);\n      for(int id:idx)ans[id]=query_monotone_inc(xs[id]);\n\
    \      return ans;\n    }\n\n    friend ostream&operator<<(ostream&os,const ConvexHullTrick&cht){\n\
    \      os<<\"[\";\n      for(int i=0;i<cht.size();i++)\n        os<<(OBJ==-1 ?\
    \ -cht.at(i) : cht.at(i))<<\"],\"[i+1<cht.size()];\n      if(!cht.size())os<<\"\
    ]\";\n      return os;\n    }\n  };\n}\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MINIMIZE>;\n\
    template<typename T>\nusing MaxConvexHullTrick = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MAXIMIZE>;\n"
  code: "#pragma once\n#include \"library/linearalgebra/Linear.cpp\"\nnamespace convex_hull_trick{\n\
    \  enum Objective{\n    MINIMIZE = +1,\n    MAXIMIZE = -1,\n  };\n\n  // \u6700\
    \u5927\u5316\u306E\u5834\u5408\u306F\u53CD\u8EE2\u3057\u3066\u3001\u5185\u90E8\
    \u3067\u306F\u6700\u5C0F\u5316\u554F\u984C\u306E\u307F\u3092\u6271\u3046\n  //\
    \ \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\u6E1B\u5C11\u306B\u306A\u308B\u3088\
    \u3046\u306B\u4FDD\u5B58\n  \n  template<typename T,Objective OBJ>\n  class ConvexHullTrick:deque<Line<T>>{\n\
    \    using L=Line<T>;\n    using deque<L>::back;\n    using deque<L>::front;\n\
    \    using deque<L>::push_back;\n    using deque<L>::push_front;\n    using deque<L>::pop_back;\n\
    \    using deque<L>::pop_front;\n    using deque<L>::at;\n\n    static bool check(const\
    \ L&l1,const L&l2,const L&l3){\n      // l2 \u304C\u8981\u3089\u306A\u3044\u306A\
    \u3089 true \u3092\u8FD4\u3059\n      // \u50BE\u304D\u304C\u72ED\u7FA9\u5358\u8ABF\
    \u6E1B\u5C11\u306F\u4FDD\u8A3C\u3055\u308C\u3066\u308B\n      // \u4EA4\u70B9\u306E\
    \ x \u5EA7\u6A19\u306F (l2.b-l1.b)/(l1.a-l2.a) \u3068 (l3.b-l2.b)/(l2.a-l3.a)\n\
    \      // \u3053\u308C\u304C >= \u3060\u3068\u8981\u3089\u306A\u3044\n      return\
    \ (l2.b-l1.b)*(l2.a-l3.a) >= (l3.b-l2.b)*(l1.a-l2.a);\n    }\n\n    void internal_push_back(const\
    \ L&l){\n      if(size()){\n        if(back().a == l.a){\n          if(back().b\
    \ <= l.b)return;\n          else pop_back();\n        }\n        while(size()\
    \ >= 2){\n          L l1 = at(size()-2), l2 = back();\n          if(check(l1,l2,l))pop_back();\n\
    \          else break;\n        }\n      }\n      push_back(l);\n    }\n\n   \
    \ void internal_push_front(const L&l){\n      if(size()){\n        if(front().a\
    \ == l.a){\n          if(front().b <= l.b)return;\n          else pop_front();\n\
    \        }\n        while(size() >= 2){\n          L l2 = at(0), l3 = at(1);\n\
    \          if(check(l,l2,l3))pop_front();\n          else break;\n        }\n\
    \      }\n      push_front(l);\n    }\n  public:\n    using value_type = L;\n\
    \    using deque<L>::size;\n\n    ConvexHullTrick()=default;\n    ConvexHullTrick(vector<L>\
    \ lines){\n      if(OBJ==-1)for(auto&l:lines)l=-l;\n      sort(lines.begin(),lines.end());\n\
    \      for(const auto&l:lines)internal_push_back(l);\n    }\n\n    void add(L\
    \ l){\n      if(OBJ==-1)l=-l;\n      if(!size() or back().a >= l.a)internal_push_back(l);\n\
    \      else if(l.a >= front().a)internal_push_front(l);\n      else assert(false);\n\
    \    }\n\n    void add(T a,T b){ add(L(a,b)); }\n\n    T query(T x)const{\n  \
    \    assert(size());\n      int l=-1,r=size()-1;\n      while(r-l>1){\n      \
    \  int m=(l+r)>>1;\n        (at(m)(x)>=at(m+1)(x) ? l : r)=m;\n      }\n     \
    \ return at(r)(x)*OBJ;\n    }\n\n    T query_monotone_inc(T x){\n      assert(size());\n\
    \      while(size()>=2 and at(0)(x)>=at(1)(x))\n        pop_front();\n      return\
    \ at(0)(x)*OBJ;\n    }\n\n    T query_monotone_dec(T x){\n      assert(size());\n\
    \      while(size()>=2 and at(size()-2)(x)<=back()(x))\n        pop_back();\n\
    \      return back()(x)*OBJ;\n    }\n    \n    vector<T> query(const vector<T>&xs){\n\
    \      int n=xs.size();\n      vector<int> idx(n);\n      iota(idx.begin(),idx.end(),0);\n\
    \      sort(idx.begin(),idx.end(),[&](int i,int j){ return xs[i]<xs[j]; });\n\
    \      vector<T> ans(n);\n      for(int id:idx)ans[id]=query_monotone_inc(xs[id]);\n\
    \      return ans;\n    }\n\n    friend ostream&operator<<(ostream&os,const ConvexHullTrick&cht){\n\
    \      os<<\"[\";\n      for(int i=0;i<cht.size();i++)\n        os<<(OBJ==-1 ?\
    \ -cht.at(i) : cht.at(i))<<\"],\"[i+1<cht.size()];\n      if(!cht.size())os<<\"\
    ]\";\n      return os;\n    }\n  };\n}\ntemplate<typename T>\nusing MinConvexHullTrick\
    \ = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MINIMIZE>;\n\
    template<typename T>\nusing MaxConvexHullTrick = convex_hull_trick::ConvexHullTrick<T,convex_hull_trick::Objective::MAXIMIZE>;"
  dependsOn:
  - library/linearalgebra/Linear.cpp
  isVerificationFile: false
  path: library/linearalgebra/ConvexHullTrick.cpp
  requiredBy: []
  timestamp: '2023-12-03 15:49:28+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/2012.test.cpp
documentation_of: library/linearalgebra/ConvexHullTrick.cpp
layout: document
redirect_from:
- /library/library/linearalgebra/ConvexHullTrick.cpp
- /library/library/linearalgebra/ConvexHullTrick.cpp.html
title: library/linearalgebra/ConvexHullTrick.cpp
---
