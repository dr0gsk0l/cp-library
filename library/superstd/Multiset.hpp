template <typename T> class Multiset {
    using u32 = std::uint32_t;
    u32 size_;

  public:
    std::map<T, u32> m;

    Multiset() : size_(0) {}

    void banpei() {
        insert(std::numeric_limits<T>::max() / 2);
        insert(std::numeric_limits<T>::min() / 2);
        size_ -= 2;
    }

    bool contains(const T &a) const { return m.contains(a); }
    u32 count(const T &a) { return contains(a) ? m[a] : 0; }
    u32 size() const { return size_; }
    void clear() {
        m.clear();
        size_ = 0;
    }

    void insert(const T &a, u32 k = 1) {
        if (!k)
            return;
        m[a] += k;
        size_ += k;
    }

    void erase(const T &a) {
        size_ -= count(a);
        m.erase(a);
    }
    void erase_k(const T &a, u32 k = 1) {
        if (count(a) <= k) {
            size_ -= count(a);
            erase(a);
        } else {
            m[a] -= k;
            size_ -= k;
        }
    }

    T min_value() const {
        assert(size());
        return m.begin()->first;
    }
    T max_value() const { // MaxValu
        assert(size());
        return m.rbegin()->first;
    }

    T pick_min() { // ピクミン
        T res = min_value();
        erase1(res);
        return res;
    }
    T pick_max() {
        T res = max_value();
        erase1(res);
        return res;
    }

    T lt(const T &a) const {
        assert(min_value() < a);
        return (--m.lower_bound(a))->first;
    }
    T leq(const T &a) const {
        assert(min_value() <= a);
        return (--m.upper_bound(a))->first;
    }
    T gt(const T &a) const {
        assert(max_value() > a);
        return upper_bound(a)->first;
    }
    T geq(const T &a) const {
        assert(max_value() >= a);
        return lower_bound(a)->first;
    }
};