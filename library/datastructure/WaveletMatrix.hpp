#pragma once
#include "library/datastructure/FullyIndexableDictionary.hpp"
#include "library/util/Compress.hpp"
#define REP_(i, n) for (int i = 0; i < (n); i++)
template <typename T, bool COMPRESS = true> class WaveletMatrix {
  protected:
    using U = std::conditional_t<COMPRESS, int, T>;
    static_assert(std::is_integral_v<U>, "Wavelet Matrix is only for integer");
    int n, memo, log;
    std::vector<FullyIndexableDictionary> mat;
    std::vector<int> zero_cnt;
    Compress<T, true> C;
    std::vector<T> data;

    constexpr U comp(const T &x) const {
        if constexpr (COMPRESS) {
            return C.geq(x);
        } else {
            return x;
        }
    }
    constexpr T uncomp(const U &a) {
        if constexpr (COMPRESS) {
            return C.r(a);
        } else {
            return a;
        }
    }

    // 0-indexed で下から i bit 目
    inline bool low_bit(const U &a, int i) const { return (a >> i) & 1; }
    // 0-indexed で上から i bit 目
    inline bool high_bit(const U &a, int i) const {
        return low_bit(a, log - i - 1);
    }

    int nxt(int idx, int h, const U &a) {
        // idx の位置に a があった場合上から h bit 目でどこに行くか
        bool bit = high_bit(a, h);
        return mat[h].rank(idx, bit) + (bit ? zero_cnt[h] : 0);
    }

  public:
    WaveletMatrix(std::vector<T> v, int log_ = 0)
        : n(v.size()), data(v), log(log_) {
        std::vector<U> cv(n);
        if constexpr (COMPRESS) {
            C = Compress<T, true>(v);
            for (int i = 0; i < n; i++)
                cv[i] = C[v[i]];
            while (C.size() >= (1ull << log))
                log++;
        } else {
            cv = v;
            T mx = 0;
            for (const T &a : v) {
                assert(a >= 0);
                if (mx < a)
                    mx = a;
            }
            while (mx >= (1ull << log))
                log++;
        }
        mat.resize(log);
        zero_cnt.resize(log);
        std::vector<U> lv(n), rv(n);
        REP_(h, log) {
            mat[h] = FullyIndexableDictionary(n);
            int l = 0, r = 0;
            REP_(i, n)
            if (high_bit(cv[i], h)) {
                rv[r++] = cv[i];
                mat[h].set(i);
            } else
                lv[l++] = cv[i];
            zero_cnt[h] = l;
            mat[h].build();
            std::swap(lv, cv);
            REP_(i, r) cv[l + i] = rv[i];
        }
    }

    // [l,r) の x の個数
    int rank(int l, int r, const T &x) {
        if constexpr (COMPRESS) {
            if (!C.exist(x))
                return 0;
        }
        U a = comp(x);
        REP_(h, log) {
            l = nxt(l, h, a);
            r = nxt(r, h, a);
        }
        memo = l;
        return r - l;
    }
    int rank(int r, const T &x) { return rank(x, 0, r); }

    // k 番目の x の index
    int select(int k, const T &x) {
        U a = comp(x);
        if (rank(a, n) < k)
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
        U res = 0;
        REP_(h, log) {
            int L = mat[h].rank(l);
            int R = mat[h].rank(r);
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
        U a = comp(upper);
        int res = 0;
        REP_(h, log) {
            if (high_bit(a, h)) {
                int L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);
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
        T y;
        if constexpr (COMPRESS) {
            y = C.r(C.gt(x));
        } else {
            y = x + 1;
        }
        return geq(l, r, y);
    }

    // セグ木などを載せる時用
    // BIT は専用のライブラリを作ってあるが、一応抽象化も持っておく
    // 構築したものを返してるので遅そう
    int height() const { return log; }
    std::vector<int> points(int idx) {
        std::vector<int> res(log);
        U a = comp(data[idx]);
        REP_(h, log) {
            idx = nxt(idx, h, a);
            res[h] = idx;
        }
        return res;
    }
    std::vector<std::tuple<int, int, int>> intervals(int l, int r,
                                                     const T &upper) {
        std::vector<std::tuple<int, int, int>> res;
        U a = comp(upper);
        REP_(h, log) {
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
        REP_(h, log) {
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
#undef REP_