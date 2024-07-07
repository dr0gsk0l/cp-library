#include "library/algebra/monoid/Concepts.cpp"

template <monoid M> class CumulativeMonoid {
    using T = typename M::value_type;
    std::vector<T> pre, suf;

  public:
    CumulativeMonoid() : pre(1, M::unit()), suf(pre) {}
    CumulativeMonoid(const std::vector<T> &v)
        : pre(v.size() + 1, M::unit()), suf(pre) {
        for (int i = 0; i < v.size(); i++)
            pre[i + 1] = M::op(pre[i], v[i]);
        for (int i = v.size() - 1; i >= 0; i--)
            suf[i] = M::op(v[i], suf[i + 1]);
        assert(pre.back() == suf[0]);
    }
    //[0,r)
    T pre_sum(int r) { return pre[r]; }
    // [l,n)
    T suf_sum(int l) { return suf[l]; }

    T sum() { return pre.back(); }
};
