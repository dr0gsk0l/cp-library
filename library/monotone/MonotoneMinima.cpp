template <typename F>
std::vector<int> internal_monotone_minima(int u, int d, int l, int r,
                                          const F &argmin) {
    if (u == d)
        return {};
    std::vector<int> ret(d - u);
    int m = (u + d) >> 1;
    ret[m - u] = argmin(m, l, r);
    auto v1 = internal_monotone_minima(u, m, l, ret[m - u] + 1, argmin);
    std::ranges::copy(v1, ret.begin());
    auto v2 = internal_monotone_minima(m + 1, d, ret[m - u], r, argmin);
    std::ranges::copy(v2, ret.begin() + m - u + 1);
    return ret;
}

template <typename F>
std::vector<int> monotone_minima(int n, int m, const F &argmin) {
    return internal_monotone_minima(0, n, 0, m, argmin);
}