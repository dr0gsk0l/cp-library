#pragma once
#include <algorithm>
#include <array>
#include <cassert>
#include <ranges>
#include <type_traits>
#include <vector>

template <unsigned short LOG, typename COUNT = int> class BinaryTrie {
    static_assert(LOG <= 64, "Binary Trie overflow");
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    using T = std::conditional_t<LOG <= 32, u32, u64>;
    struct Node {
        std::array<u32, 2> nxt_node;
        COUNT count;
        Node() : count(0) { std::ranges::fill(nxt_node, u32(-1)); }
    };
    std::vector<Node> nodes;
    u32 &nxt(u32 now, bool f) { return nodes[now].nxt_node[f]; }
    const u32 &nxt(u32 now, bool f) const { return nodes[now].nxt_node[f]; }
    static bool bit(const T &a, int i) { return (a >> i) & 1; }

    // 数列の各数に xor_add をした後、r 未満の個数を返す
    COUNT _count_ranges(const T &r, T xor_add = 0) const {
        COUNT res = 0;
        u32 now = 0;
        for (int i = LOG - 1; ~now and i >= 0; i--) {
            int f = bit(xor_add, i);
            u32 next_low = nxt(now, f);
            u32 next_high = nxt(now, !f);

            if (bit(r, i)) {
                if (~next_low)
                    res += nodes[next_low].count;
                now = next_high;
            } else
                now = next_low;
        }
        return res;
    }

  public:
    BinaryTrie() : nodes(1, Node()) {}

    u32 add(const T &a, COUNT num = COUNT(1)) {
        u32 now = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            nodes[now].count += num;
            const bool f = bit(a, i);
            if (!~nxt(now, f)) {
                nxt(now, f) = nodes.size();
                nodes.emplace_back();
            }
            now = nxt(now, f);
        }
        nodes[now].count += num;
        return now;
    }

    u32 node_idx(const T &a) const {
        u32 now = 0;
        for (int i = LOG - 1; ~now and i >= 0; i--)
            now = nxt(now, bit(a, i));
        return now;
    }

    COUNT count(const T &a) const {
        u32 id = node_idx(a);
        return (~id ? nodes[id].count : 0);
    }

    COUNT size() { return nodes[0].count; }

    // 数列の各数に xor_add をした後、[l, r) 未満の個数を返す
    COUNT count_ranges(const T &l, const T &r, T xor_add = 0) const {
        return _count_ranges(r, xor_add) - _count_ranges(l, xor_add);
    }

    // 数列の各数に xor_add をした後、0-indexed で昇順 k 番目を出力
    T k_th(COUNT k, T xor_add = 0) {
        assert(size() > k);
        T res = 0;
        u32 now = 0;
        for (int i = LOG - 1; i >= 0; i--) {
            int f = bit(xor_add, i);
            u32 next_low = nxt(now, f);
            u32 next_high = nxt(now, !f);
            COUNT k_low = ~next_low ? nodes[next_low].count : 0;

            if (k_low <= k) {
                k -= k_low;
                now = next_high;
                res += T{1} << i;
            } else
                now = next_low;
        }
        return res;
    }
    T min(T xor_add = 0) { return k_th(0, xor_add); }
    T max(T xor_add = 0) { return k_th(size() - 1, xor_add); }
};
