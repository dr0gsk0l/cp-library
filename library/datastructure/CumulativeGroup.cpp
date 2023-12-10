#include "library/algebra/group/Concepts.cpp"

template <group G> struct CumulativeGroup {
    using T = typename G::value_type;
    std::vector<T> A;
    CumulativeGroup() : A(1, G::unit()) {}
    CumulativeGroup(const std::vector<T> &v) : A(v.size() + 1, G::unit()) {
        for (int i = 0; i < v.size(); i++)
            A[i + 1] = G::op(A[i], v[i]);
    }
    void add(const T &a) { A.push_back(G::op(A.back(), a)); }
    T sum(int l, int r) {
        assert(0 <= l and l <= r and r < A.size());
        return G::op(A[r], Group::inverse(A[l]));
    }
    T sum() { return A.back(); }
};