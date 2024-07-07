template <typename T> struct CumulativeSum {
    using U = std::conditional_t<std::is_same_v<T, int>, long long, T>;
    std::vector<U> A;
    CumulativeSum() : A(1, 0) {}
    CumulativeSum(const std::vector<T> &v) : A(v.size() + 1, 0) {
        for (int i = 0; i < v.size(); i++)
            A[i + 1] = A[i] + v[i];
    }
    void add(const T &a) { A.push_back(A.back() + a); }
    U sum(int l, int r) { return A[r] - A[l]; }
    U sum() { return A.back(); }
};