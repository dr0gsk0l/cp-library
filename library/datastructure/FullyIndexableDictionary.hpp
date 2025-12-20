#pragma once
#include <bit>
#include <concepts>
#include <cstddef>
#include <cstdint>
#include <vector>
class FullyIndexableDictionary {
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;

    const std::size_t n;
    const std::size_t block; // 64個事に区切ったブロックの個数
    std::vector<u64> bit;
    std::vector<u32> sum; // ブロック毎の累積和

  public:
    FullyIndexableDictionary() : n(0), block(0), bit(1, 0), sum(1, 0) {}

    template <std::unsigned_integral U>
    explicit FullyIndexableDictionary(const std::vector<U> &bits)
        : n(bits.size()), block((n + 63) >> 6), bit(block + 1, 0),
          sum(block + 1, 0) {
        for (std::size_t i = 0; i < n; i++)
            if (bits[i])
                bit[i >> 6] |= 1ull << (i & 63);
        for (std::size_t i = 0; i < block; i++)
            sum[i + 1] = sum[i] + std::popcount(bit[i]);
    }

    bool operator[](int k) const {
        return bool((bit[static_cast<std::size_t>(k) >> 6]
                     >> (static_cast<std::size_t>(k) & 63)) &
                    1);
    }

    // [0,j) の b の合計
    int rank(int j, bool b = 1) const {
        const auto jj = static_cast<std::size_t>(j);
        auto a = sum[jj >> 6] +
                 std::popcount(bit[jj >> 6] & ((1ull << (jj & 63)) - 1));
        return static_cast<int>(b ? a : jj - a);
    }
    // 0-indexed で k 番目の b の場所
    int select(int k, bool b = 1) const {
        if (k < 0 or rank(n, b) <= k)
            return -1;
        int l = 0, r = static_cast<int>(n);
        while (r - l > 1) {
            int m = (l + r) >> 1;
            (rank(m, b) >= k + 1 ? r : l) = m;
        }
        return r - 1;
    }
    // l以上で k 番目の b の場所
    int select(int k, bool b, int l) const { return select(rank(l, b) + k, b); }
};
