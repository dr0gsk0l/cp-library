---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
    title: test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1002.test.cpp
    title: test/yukicoder/1002.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1038.test.cpp
    title: test/yukicoder/1038.test.cpp
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"library/tree/CentroidDecomposition.cpp\"\ntemplate<typename\
    \ TREE>\nclass CentroidDecomposition{\n  TREE T;\n  vector<int> sz,pre,timing;\n\
    \n  int find_centroid(int v){\n    vector<int> S{v};\n    pre[v]=-1;\n    for(int\
    \ i=0;i<S.size();i++){\n      const int u=S[i];\n      sz[u]=1;\n      for(int\
    \ to:T[u]){\n        if(to==pre[u]||~timing[to])continue;\n        pre[to]=u;\n\
    \        S.push_back(to);\n      }\n    }\n    int SZ=S.size();\n    reverse(S.begin(),S.end());\n\
    \    for(int u:S){\n      if( SZ-sz[u] <= SZ/2 )return u;\n      sz[pre[u]] +=\
    \ sz[u];\n    }\n    assert(false);\n    return -1;\n  };\npublic:\n  vector<int>\
    \ order;\n  CentroidDecomposition(TREE T):T(T),sz(T.n),pre(T.n),timing(T.n,-1){\n\
    \    order.reserve(T.n);\n    queue<int> que;\n    que.push(0);\n    while(que.size()){\n\
    \      int c=find_centroid(que.front());que.pop();\n      timing[c]=order.size();\n\
    \      order.push_back(c);\n      for(int to:T[c])\n        if(timing[to]<0)\n\
    \          que.push(to);\n    }\n  }\n\n  template<typename X,typename F,typename\
    \ G,typename H>\n  void calc(int root,X initial_val,const F&next_val,const G&action,const\
    \ H&finish){\n    queue<tuple<int,int,X>> que;\n\n    auto f=[&](int v_,int pre_,X\
    \ val_,bool is_all){\n      que.emplace(v_,pre_,val_);\n      while(que.size()){\n\
    \        auto [v,pre,val]=que.front();que.pop();\n        action(val,is_all);\n\
    \        for(const auto&e:T[v]){\n          if(e.to==pre||timing[e.to]<=timing[root])continue;\n\
    \          que.emplace(e.to,v,next_val(val,e));\n        }\n      }\n      finish(is_all);\n\
    \    };\n\n    for(const auto&e:T[root])\n      if(timing[e.to]>timing[root])\n\
    \        f(e.to,root,next_val(initial_val,e),false);\n    \n    f(root,-1,initial_val,true);\n\
    \  }\n\n  template<typename X,typename F,typename G,typename H>\n  void all_calc(X\
    \ initial_val,const F&next_val,const G&action,const H&finish){\n    for(int i=0;i<T.n;i++)calc(i,initial_val,next_val,action,finish);\n\
    \  }\n};\n"
  code: "template<typename TREE>\nclass CentroidDecomposition{\n  TREE T;\n  vector<int>\
    \ sz,pre,timing;\n\n  int find_centroid(int v){\n    vector<int> S{v};\n    pre[v]=-1;\n\
    \    for(int i=0;i<S.size();i++){\n      const int u=S[i];\n      sz[u]=1;\n \
    \     for(int to:T[u]){\n        if(to==pre[u]||~timing[to])continue;\n      \
    \  pre[to]=u;\n        S.push_back(to);\n      }\n    }\n    int SZ=S.size();\n\
    \    reverse(S.begin(),S.end());\n    for(int u:S){\n      if( SZ-sz[u] <= SZ/2\
    \ )return u;\n      sz[pre[u]] += sz[u];\n    }\n    assert(false);\n    return\
    \ -1;\n  };\npublic:\n  vector<int> order;\n  CentroidDecomposition(TREE T):T(T),sz(T.n),pre(T.n),timing(T.n,-1){\n\
    \    order.reserve(T.n);\n    queue<int> que;\n    que.push(0);\n    while(que.size()){\n\
    \      int c=find_centroid(que.front());que.pop();\n      timing[c]=order.size();\n\
    \      order.push_back(c);\n      for(int to:T[c])\n        if(timing[to]<0)\n\
    \          que.push(to);\n    }\n  }\n\n  template<typename X,typename F,typename\
    \ G,typename H>\n  void calc(int root,X initial_val,const F&next_val,const G&action,const\
    \ H&finish){\n    queue<tuple<int,int,X>> que;\n\n    auto f=[&](int v_,int pre_,X\
    \ val_,bool is_all){\n      que.emplace(v_,pre_,val_);\n      while(que.size()){\n\
    \        auto [v,pre,val]=que.front();que.pop();\n        action(val,is_all);\n\
    \        for(const auto&e:T[v]){\n          if(e.to==pre||timing[e.to]<=timing[root])continue;\n\
    \          que.emplace(e.to,v,next_val(val,e));\n        }\n      }\n      finish(is_all);\n\
    \    };\n\n    for(const auto&e:T[root])\n      if(timing[e.to]>timing[root])\n\
    \        f(e.to,root,next_val(initial_val,e),false);\n    \n    f(root,-1,initial_val,true);\n\
    \  }\n\n  template<typename X,typename F,typename G,typename H>\n  void all_calc(X\
    \ initial_val,const F&next_val,const G&action,const H&finish){\n    for(int i=0;i<T.n;i++)calc(i,initial_val,next_val,action,finish);\n\
    \  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: library/tree/CentroidDecomposition.cpp
  requiredBy: []
  timestamp: '2023-11-25 17:38:17+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/library-checker/Tree/FrequencyTableOfTreeDistance.test.cpp
  - test/yukicoder/1038.test.cpp
  - test/yukicoder/1002.test.cpp
documentation_of: library/tree/CentroidDecomposition.cpp
layout: document
redirect_from:
- /library/library/tree/CentroidDecomposition.cpp
- /library/library/tree/CentroidDecomposition.cpp.html
title: library/tree/CentroidDecomposition.cpp
---
