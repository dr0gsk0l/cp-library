# SWAG

## 概要
- パス: `library/datastructure/SWAG.hpp`
- モノイド上の sliding window aggregation。2 スタックで双方向の追加と先頭削除を扱う。

## 公開 API
- `void push_back(X x)` — 末尾に要素を追加。計算量 償却 O(1)。
- `void push_front(X x)` — 先頭側スタックに追加。計算量 償却 O(1)。
- `void pop_front()` — 先頭から 1 要素削除。計算量 償却 O(1)。
- `X prod()` — 現在の全体畳み込み値 $igoplus_{i} a_i$。計算量 O(1)。
- `int size()` — 要素数。計算量 O(1)。
