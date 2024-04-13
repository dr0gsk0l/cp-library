---
title: OfflineRangeQuery
documentation_of: library/datastructure/OfflineRangeQuery.cpp
---
Offline Dynamic Connectivity の一般化  
可換群の作用 $f$ を時刻 $[l,r)$ に作用させるクエリをオフラインで捌く．

* ```OfflineRangeQuery(size_t n_)```
時刻 $[0,n)$ で定義．

* ```size_t add_query(size_t l, size_t r)```  
時刻 $[l,r)$ の作用を登録．
返り値はその作用のID

* ```std::vector querys```
長さ $n$ の配列．
```[end, start] = querys[t]``` としたとき
```std::vector<size_t> end```  : 時刻 $t$ になるときに終わる作用 ID 列
```std::vector<size_t> start```  : 時刻 $t$ になるときに始まる作用 ID 列