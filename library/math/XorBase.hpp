#pragma once
#include <algorithm>
#include <concepts>
#include <vector>

template <std::unsigned_integral T> class XorBase {
    std::vector<T> basis;

    static void chmin_xor(T &a, T b) { a = std::min(a, a ^ b); }

  public:
    XorBase() = default;
    XorBase(const std::vector<T> &v) {
        for (T x : v)
            add(x);
    }

    size_t size() const { return basis.size(); }

    bool empty() const { return basis.empty(); }

    T reduce(T x) const {
        for (const T &b : basis)
            chmin_xor(x, b);
        return x;
    }

    bool add(T x) {
        x = reduce(x);
        if (!x)
            return false;

        for (T &b : basis)
            chmin_xor(b, x);
        basis.push_back(x);
        return true;
    }

    bool contains(T x) const { return reduce(x) == 0; }

    const std::vector<T> &vectors() const { return basis; }
};
