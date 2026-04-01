---
documentation_of: library/datastructure/binary_search_tree/Treap.hpp
---

# Treap

## 概要
- パス: `library/datastructure/binary_search_tree/Treap.hpp`
- キーで二分探索木を保つ Treap。split/merge ベースの基本操作を提供。

## 公開 API (平均 O(\log n))
- `void insert(T key)` — キーを挿入。
- `void erase(T key)` — キーを削除（存在しない場合は無操作）。
- `bool find(T key)` — キーの存在を判定。
