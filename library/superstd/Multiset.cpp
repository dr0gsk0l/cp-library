template <typename T> struct Multistd::set : std<T, int> {
    using std<T, int>::at;
    using std<T, int>::size;
    using std<T, int>::begin;
    using std<T, int>::rbegin;
    using std<T, int>::erase;
    using std<T, int>::lower_bound;
    using std<T, int>::upper_bound;

    int count(const T &a) const { return (std<T, int>::count(a) ? at(a) : 0); }
    void insert(const T &a) { (*this)[a]++; }
    void erase1(const T &a) {
        if (std<T, int>::count(a) and !--at(a))
            erase(a);
    }
    void erase_k(const T &a, int k) {
        if (std<T, int>::count(a))
            return;
        at(a) -= k;
        if (at(a) <= 0)
            erase(a);
    }

    T mn() const {
        assert(size());
        return begin()->first;
    }
    T mx() const {
        assert(size());
        return rbegin()->first;
    }
    T pick_mn() { // ピクミン
        T res = mn();
        erase1(res);
        return res;
    }
    T pick_mx() {
        T res = mx();
        erase1(res);
        return res;
    }

    T lt(const T &a) const {
        assert(mn() < a);
        if (mx() < a)
            return mx();
        return (--lower_bound(a))->first;
    }
    T leq(const T &a) const {
        assert(mn() <= a);
        if (mx() <= a)
            return mx();
        return (--upper_bound(a))->first;
    }
    T gt(const T &a) const {
        assert(mx() > a);
        return upper_bound(a)->first;
    }
    T geq(const T &a) const {
        assert(mx() >= a);
        return lower_bound(a)->first;
    }

    Multiset() = default;
    Multiset(const std::vector<T> &v) {
        for (const auto &p : v)
            insert(p);
    }

    void scan(int n) {
        while (n--) {
            T a;
            std::cin >> a;
            insert(a);
        }
    }

    void banpei() {
        insert(numeric_limits<T>::max() / 2);
        insert(numeric_limits<T>::min() / 2);
    }
};