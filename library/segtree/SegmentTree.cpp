#include "library/algebra/monoid/Concepts.cpp"

#pragma once
template <monoid M> class SegmentTree {
    using X = typename M::value_type;
    std::vector<X> dat;
    int n, log, size;

    void update(int i) { dat[i] = M::op(dat[2 * i], dat[2 * i + 1]); }

  public:
    SegmentTree() : SegmentTree(0) {}
    SegmentTree(int n) : SegmentTree(std::vector<X>(n, M::unit())) {}
    SegmentTree(std::vector<X> v) : n(v.size()) {
        for (log = 1; (1 << log) < n; log++) {
        }
        size = 1 << log;
        dat.assign(size << 1, M::unit());
        for (int i = 0; i < n; ++i)
            dat[size + i] = v[i];
        for (int i = size - 1; i >= 1; --i)
            update(i);
    }

    X operator[](int i) const { return dat[size + i]; }

    void set(int i, const X &x) {
        assert(0 <= i and i < n);
        dat[i += size] = x;
        while (i >>= 1)
            update(i);
    }
    void multiply(int i, const X &x) { set(i, M::op(dat[i + size], x)); }

    X prod(int L, int R) const {
        assert(0 <= L and L <= R and R <= n);
        X vl = M::unit(), vr = M::unit();
        L += size, R += size;
        while (L < R) {
            if (L & 1)
                M::Rchop(vl, dat[L++]);
            if (R & 1)
                M::Lchop(dat[--R], vr);
            L >>= 1, R >>= 1;
        }
        return M::op(vl, vr);
    }
    X prod_all() const { return dat[1]; }

    template <class F> int max_right(F &check, int L) {
        assert(0 <= L && L <= n && check(M::unit()));
        if (L == n)
            return n;
        L += size;
        X sm = M::unit();
        do {
            while (L % 2 == 0)
                L >>= 1;
            if (!check(M::op(sm, dat[L]))) {
                while (L < size) {
                    L <<= 1;
                    if (check(M::op(sm, dat[L])))
                        M::Rchop(sm, dat[L++]);
                }
                return L - size;
            }
            M::Rchop(sm, dat[L++]);
        } while ((L & -L) != L);
        return n;
    }

    template <class F> int min_left(F &check, int R) {
        assert(0 <= R && R <= n && check(M::unit()));
        if (R == 0)
            return 0;
        R += size;
        X sm = M::unit();
        do {
            --R;
            while (R > 1 && (R % 2))
                R >>= 1;
            if (!check(M::op(dat[R], sm))) {
                while (R < size) {
                    (R <<= 1)++;
                    if (check(M::op(dat[R], sm)))
                        M::Lchop(dat[R--], sm);
                }
                return R + 1 - size;
            }
            M::Lchop(dat[R], sm);
        } while ((R & -R) != R);
        return 0;
    }

    // モノイドが可換なら、prod_{l<=i<r}A[i^x] が計算可能
    // https://codeforces.com/contest/1401/problem/F
    X Xor_prod(int l, int r, int xor_val) {
        assert(M::commute);
        X x = M::unit();
        for (int k = 0; k < log + 1; ++k) {
            if (l >= r)
                break;
            if (l & 1) {
                M::Rchop(x, dat[(size >> k) + ((l++) ^ xor_val)]);
            }
            if (r & 1) {
                M::Rchop(x, dat[(size >> k) + ((--r) ^ xor_val)]);
            }
            l /= 2, r /= 2, xor_val /= 2;
        }
        return x;
    }

    friend std::ostream &operator<<(std::ostream &os, const SegmentTree &seg) {
        os << "(";
        for (int L = 1; L <= seg.size; L <<= 1) {
            os << "[";
            for (int j = L; j < (L << 1); j++) {
                os << seg.dat[j];
                if (j + 1 < (L << 1))
                    os << ",";
            }
            os << "]";
        }
        os << ")";
        return os;
    }
};