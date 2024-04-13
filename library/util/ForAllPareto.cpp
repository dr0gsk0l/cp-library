template <typename F>
void for_all_pareto(const std::vector<int> &v, const F &f) {
    int n = v.size();
    std::vector<int> a(n, 0);
    while (true) {
        f(a);
        int idx = 0;
        while (idx < n and a[idx] == v[idx])
            a[idx++] = 0;
        if (idx == n)
            break;
        a[idx]++;
    }
}