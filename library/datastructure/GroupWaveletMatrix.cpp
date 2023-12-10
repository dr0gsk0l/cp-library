#pragma once
#include "library/datastructure/FenwickTree.cpp"
#include "library/datastructure/WaveletMatrix.cpp"
#define REP_(i, n) for (int i = 0; i < (n); i++)
template <typename T, group G>
class GroupWaveletMatrix : WaveletMatrix<T, true> {
    using super = WaveletMatrix<T, true>;
    using super::log, super::n, super::nxt, super::comp, super::data,
        super::high_bit, super::mat, super::zero_cnt;
    using U = typename super::U;
    using FT = FenwickTree<G>;
    using S = typename G::value_type;
    vector<FT> ft;

  public:
    using super::rank, super::select, super::kth_largest, super::kth_smallest,
        super::range_freq, super::lt, super::leq, super::gt, super::geq;
    GroupWaveletMatrix(vector<T> v) : super::WaveletMatrix(v) {
        ft.resize(log);
        for (auto &p : ft)
            p = FT(n);
    }
    GroupWaveletMatrix(vector<T> v, const vector<S> &w)
        : GroupWaveletMatrix(v) {
        for (int i = 0; i < n; i++)
            add(i, w[i]);
    }
    void add(int idx, const S &val) {
        U a = comp(data[idx]);
        REP_(h, log) {
            idx = nxt(idx, h, a);
            ft[h].add(idx, val);
        }
    }
    S sum(int l, int r, const T &upper) {
        U a = comp(upper);
        S res = G::unit();
        REP_(h, log) {
            if (high_bit(a, h)) {
                int L = mat[h].rank(l, 0), R = mat[h].rank(r, 0);
                G::Rchop(res, ft[h].sum(L, R));
            }
            l = nxt(l, h, a);
            r = nxt(r, h, a);
        }
        return res;
    }
    S sum(int l, int r, const T &lower, const T &upper) {
        return G::op(sum(l, r, upper), G::inverse(sum(l, r, lower)));
    }
    S kth_largest_sum(int l, int r, int k) {
        assert(0 <= k and k < r - l);
        S res = G::unit();
        REP_(h, log) {
            int L = mat[h].rank(l);
            int R = mat[h].rank(r);
            if (R - L > k) {
                l = L + zero_cnt[h];
                r = R + zero_cnt[h];
            } else {
                G::Rchop(res, ft[h].sum(L + zero_cnt[h], R + zero_cnt[h]));
                k -= R - L;
                l -= L;
                r -= R;
            }
        }
        return res;
    }
};
#undef REP_
