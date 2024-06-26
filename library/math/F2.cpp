#pragma once
template <typename T, int LOG> class F2 {
    bool is_sorted;
    std::vector<T> B;
    bool xor_chmin(T &a, T b) {
        if (a > (a ^ b)) {
            a ^= b;
            return true;
        }
        return false;
    }

  public:
    F2() : is_sorted(true) {}
    F2(const std::vector<T> &v) : is_sorted(true) {
        for (const T &a : v)
            add(a);
    }

    bool add(T a) {
        if (B.size() == LOG)
            return false;
        for (T e : B)
            xor_chmin(a, e);
        if (a) {
            for (T &e : B)
                xor_chmin(e, a);
            if (B.size() and B.back() > a)
                is_sorted = false;
            B.push_back(a);
            return true;
        }
        return false;
    }

    std::vector<T> base() {
        if (!is_sorted) {
            std::ranges::sort(B);
            is_sorted = true;
        }
        return B;
    }

    T kth_smallest(T k) {
        assert(!(k >> (B.size())));
        if (k == 0)
            return 0;
        if (!is_sorted) {
            std::ranges::sort(B);
            is_sorted = true;
        }
        T res = 0;
        for (int i = 0; i < B.size(); i++)
            if ((k >> i) & 1)
                res ^= B[i];
        return res;
    }
    T kth_largest(T k) {
        assert(!(k >> (B.size())));
        return kth_smallest((T{1} << B.size()) - k - 1);
    }

    bool in(T a) {
        if (B.size() == LOG)
            return true;
        for (T e : B)
            xor_chmin(a, e);
        return a;
    }

    std::optional<std::vector<T>> make(T a) {
        std::vector<T> v;
        for (T e : B)
            if (xor_chmin(a, e))
                v.push_back(e);
        if (a)
            return std::nullopt;
        return v;
    }
};