# Doubling

## 概要
- パス: `library/datastructure/Doubling.hpp`
- 1 ステップ遷移とコストのモノイドから $2^k$ ステップ遷移を前計算するダブリング表。

## 公開 API
- `Doubling<Monoid, LOG>(int n)` — ノード数とテーブル高さを指定して用意。計算量 O(n \log n)。
- `void add_arc(int from, int to, X x)` — 辺 `from -> to` とそのコストを登録（準備完了前のみ）。計算量 O(1)。
- `std::pair<int,X> calc(int s, long long step)` — 始点 $s$ から $	ext{step}$ 回遷移した先と累積コスト $igoplus$ を返す。計算量 O(\log 	ext{step}).
