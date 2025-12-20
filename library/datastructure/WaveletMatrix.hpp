#pragma once
#include "library/datastructure/FullyIndexableDictionary.hpp"
#include "library/util/Compress.hpp"
#include <bit>
#include <cassert>
#include <concepts>
#include <cstdint>
#include <optional>
#include <ranges>
#include <tuple>
#include <utility>
#include <vector>
template <std::integral T> class WaveletMatrix {
  protected:
    using u32 = std::uint32_t;

    u32 n, memo, log;
    std::vector<FullyIndexableDictionary> mat;
    std::vector<int> zero_cnt;
    Compress<T, true> C;
    std::vector<T> data;

    constexpr u32 comp(const T &x) const { return C.geq(x); }
    constexpr T uncomp(const u32 &a) { return C.r(a); }

    // 0-indexed で下から i bit 目
    inline bool low_bit(const u32 &a, int i) const { return (a >> i) & 1; }
    // 0-indexed で上から i bit 目
    inline bool high_bit(const u32 &a, int i) const {
        return low_bit(a, log - i - 1);
    }

    int nxt(int idx, int h, const u32 &a) {
        // idx の位置に a があった場合上から h bit 目でどこに行くか
        bool bit = high_bit(a, h);
        return mat[h].rank(idx, bit) + (bit ? zero_cnt[h] : 0);
    }

  public:
    WaveletMatrix(std::vector<T> v) : n(v.size()), data(v), C(v) {
        std::vector<u32> cv(n);
        for (auto &&[cx, x] : std::views::zip(cv, v))
            cx = C[x];

        log = std::bit_width(C.size());
        mat.resize(log);
        zero_cnt.resize(log);

        std::vector<u32> lv(n), rv(n);
        for (int h : std::views::iota(0, log)) {
            std::vector<unsigned int> ones(n);
            int l = 0, r = 0;
            for (int i : std::views::iota(0, n))
                if (high_bit(cv[i], h)) {
                    rv[r++] = cv[i];
                    ones[i] = 1;
                } else
                    lv[l++] = cv[i];

            zero_cnt[h] = l;
            mat[h] = FullyIndexableDictionary(std::move(ones));
            std::swap(lv, cv);
            std::ranges::copy(rv.begin(), rv.begin() + r, cv.begin() + l);
        }
    }

    // [l,r) の x の個数
    int rank(int l, int r, const T &x) {
        if (!C.exist(x))
            return 0;
        u32 a = comp(x);
        for (int h : std::views::iota(0, log)) {
            l = nxt(l, h, a);
            r = nxt(r, h, a);
        }
        memo = l;
        return r - l;
    }
    int rank(int r, const T &x) { return rank(0, r, x); }

    // k 番目の x の index
    int select(int k, const T &x) {
        u32 a = comp(x);
        if (rank(n, x) < k)
            return -1;
        k += memo;
        for (int h = log - 1; h >= 0; h--) {
            bool bit = high_bit(a, h);
            if (bit)
                k -= zero_cnt[h];
            k = mat[h].select(k, bit);
        }
        return k;
    }

    // [l,r) で 0-indexed k 番目に大きい値
    T kth_largest(int l, int r, int k) {
        if (k < 0 or r - l <= k)
            return -1;
        u32 res = 0;
        for (int h : std::views::iota(0, log)) {
            const int L = mat[h].rank(l);
            const int R = mat[h].rank(r);
            res <<= 1;
            if (R - L > k) {
                l = L + zero_cnt[h];
                r = R + zero_cnt[h];
                res++;
            } else {
                k -= R - L;
                l -= L;
                r -= R;
            }
        }
        return uncomp(res);
    }
    T kth_smallest(int l, int r, int k) {
        return kth_largest(l, r, r - l - k - 1);
    }

    // [l,r) で x 未満の個数
    int range_freq(int l, int r, const T &upper) {
        u32 a = comp(upper);
        int res = 0;
        for (int h : std::views::iota(0, log)) {
            if (high_bit(a, h)) {
                const int L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);
                res += R - L;
            }
            l = nxt(l, h, a);
            r = nxt(r, h, a);
        }
        return res;
    }
    // [l,r) で [lower,upper) の個数
    int range_freq(int l, int r, const T &lower, const T &upper) {
        return range_freq(l, r, upper) - range_freq(l, r, lower);
    }

    std::optional<T> lt(int l, int r, const T &x) {
        int cnt = range_freq(l, r, x);
        if (cnt)
            return kth_smallest(l, r, cnt - 1);
        return std::nullopt;
    }
    std::optional<T> leq(int l, int r, const T &x) {
        if (rank(l, r, x))
            return x;
        return lt(l, r, x);
    }
    std::optional<T> geq(int l, int r, const T &x) {
        int cnt = r - l - range_freq(l, r, x);
        if (cnt)
            return kth_largest(l, r, cnt - 1);
        return std::nullopt;
    }
    std::optional<T> gt(int l, int r, const T &x) {
        T y = C.r(C.gt(x));
        return geq(l, r, y);
    }

    // セグ木などを載せる時用
    // BIT は専用のライブラリを作ってあるが、一応抽象化も持っておく
    // 構築したものを返してるので遅そう
    int height() const { return log; }
    std::vector<int> points(int idx) {
        std::vector<int> res(log);
        u32 a = comp(data[idx]);
        for (int h : std::views::iota(0, log)) {
            idx = nxt(idx, h, a);
            res[h] = idx;
        }
        return res;
    }
    std::vector<std::tuple<int, int, int>> intervals(int l, int r,
                                                     const T &upper) {
        std::vector<std::tuple<int, int, int>> res;
        u32 a = comp(upper);
        for (int h : std::views::iota(0, log)) {
            if (high_bit(a, h)) {
                int L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);
                res.emplace_back(h, L, R);
            }
            l = nxt(l, h, a);
            r = nxt(r, h, a);
        }
        return res;
    }
    std::vector<std::tuple<int, int, int>> kth_largest_intervals(int l, int r,
                                                                 int k) {
        assert(0 <= k and k < r - l);
        std::vector<std::tuple<int, int, int>> res;
        for (int h : std::views::iota(0, log)) {
            int L = mat[h].rank(l);
            int R = mat[h].rank(r);
            if (R - L > k) {
                l = L + zero_cnt[h];
                r = R + zero_cnt[h];
            } else {
                res.emplace_back(h, L + zero_cnt[h], R + zero_cnt[h]);
                k -= R - L;
                l -= L;
                r -= R;
            }
        }
        return res;
    }
    std::vector<std::tuple<int, int, int>> kth_smallest_intervals(int l, int r,
                                                                  int k) {
        return kth_largest_intervals(l, r, r - l - k - 1);
    }
};
