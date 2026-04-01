---
documentation_of: library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp
---

# IntegerSumRuleUnionFind

## 概要
- パス: `library/datastructure/unionfind/IntegerSumRuleUnionFind.hpp`
- 整数重み付きポテンシャルを扱う UnionFind。差分制約の矛盾検出と値取得を行う。

## 公開 API
- `IntegerSumRuleUnionFind(int n)` — 初期化。計算量 O(n)。
- `int leader(int x)` / `bool same(int x, int y)` / `int size(int x)` / `int count() const` — 基本操作。計算量 ならし O(lpha(n))。
- `bool merge(int x, int y, int d)` — $w(y)-w(x)=d$ を課してマージ。矛盾時は `false`。計算量 ならし O(lpha(n))。
- `int diff(int x, int y)` — 同成分なら差分 $w(y)-w(x)$ を返す。計算量 ならし O(lpha(n))。
