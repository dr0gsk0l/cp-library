#pragma once
template <typename T, bool Sentinel = false> class Compress {
    std::vector<T> v;
    bool prepared;

  public:
    Compress() : prepared(false) {
        if constexpr (Sentinel) {
            static_assert(std::numeric_limits<T>::is_specialized,
                          "cannot use Sentinel");
            v = {std::numeric_limits<T>::min(), std::numeric_limits<T>::max()};
        }
    }
    Compress(const std::vector<T> &w) : v(w), prepared(false) {
        if constexpr (Sentinel) {
            static_assert(std::numeric_limits<T>::is_specialized,
                          "cannot use Sentinel");
            v.push_back(std::numeric_limits<T>::min());
            v.push_back(std::numeric_limits<T>::max());
        }
        build();
    }

    void add(T a) {
        assert(!prepared);
        v.push_back(a);
    }
    void build() {
        assert(!prepared);
        prepared = true;
        std::ranges::sort(v);
        auto result = std::ranges::unique(v);
        v.erase(result.begin(), result.end());
    }

    bool is_prepared() const { return prepared; }

    int operator[](const T &a) const {
        assert(prepared);
        auto it = std::ranges::lower_bound(v, a);
        assert(*it == a);
        return std::distance(v.begin(), it);
    }
    int geq(const T &a) const {
        assert(prepared);
        auto it = std::ranges::lower_bound(v, a);
        return std::distance(v.begin(), it);
    }
    int gt(const T &a) const {
        assert(prepared);
        auto it = std::ranges::upper_bound(v, a);
        return std::distance(v.begin(), it);
    }
    int leq(const T &a) const {
        assert(prepared);
        auto it = --std::ranges::upper_bound(v, a);
        return std::distance(v.begin(), it);
    }
    int lt(const T &a) const {
        assert(prepared);
        auto it = --std::ranges::lower_bound(v, a);
        return std::distance(v.begin(), it);
    }
    T r(int id) const {
        assert(prepared);
        return v[id];
    }
    bool exist(const T &a) const {
        assert(prepared);
        return (*std::ranges::lower_bound(v, a)) == a;
    }
    int size() const { return v.size(); }
    T max() const { return v.back(); }
    T min() const { return v[0]; }

    friend std::ostream &operator<<(std::ostream &os, const Compress &C) {
        for (int i = 0; i < C.v.size(); i++)
            os << C.v[i] << ":" << i << " ";
        return os;
    }
};