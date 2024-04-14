// https://maspypy.com/%e9%9b%86%e5%90%88%e3%81%b9%e3%81%8d%e7%b4%9a%e6%95%b0%e9%96%a2%e9%80%a3-2-%e5%a4%9a%e9%a0%85%e5%bc%8f%e3%81%a8%e3%81%ae%e5%90%88%e6%88%90
#include "library/setpowerseries/Base.cpp"
#include <vector>

template <typename SPS, typename T = typename SPS::value_type>
SPS SPS_exp_comp(const std::vector<T> &f, const SPS &a) {
    int N = a.size();
    int n = bitwise::log2(N);

    std::vector<SPS> ret(n + 1);
    for (int d = n; d >= 0; d--) {
        ret[d].resize(1 << (n - d));
        ret[d][0] = f[d];
        for (int m = 0; m < n - d; m++) {
            // ret[d] の [2^m, 2^{m+1}] を求める
            SPS pre(ret[d + 1].begin(), ret[d + 1].begin() + (1 << m));
            SPS a2(a.begin() + (1 << m), a.begin() + (1 << (m + 1)));
            pre *= a2;
            std::ranges::copy(pre, ret[d].begin() + (1 << m));
        }
    }
    return ret[0];
}

// sum_k f_k a^k
template <typename SPS, typename T = typename SPS::value_type>
SPS SPS_composition(const std::vector<T> &f, SPS a) {
    int N = a.size();
    int n = bitwise::log2(N);

    std::vector<T> c_pow(f.size() + 1, 1);
    for (int i = 1; i <= f.size(); i++)
        c_pow[i] = c_pow[i - 1] * a[0];

    std::vector<T> f2(n + 1, 0);
    for (int i = 0; i < f.size(); i++) {
        T now = f[i];
        for (int k = 0; k <= std::min(i, n); k++) {
            f2[k] += now * c_pow[i - k];
            now *= i - k;
        }
    }
    a[0] = 0;
    return SPS_exp_comp(f2, a);
}

template <typename SPS, typename T = typename SPS::value_type> SPS exp(SPS a) {
    int N = a.size();
    int n = bitwise::log2(N);

    SPS ret(N, 1);
    for (int d = n - 1; d >= 0; d--) {
        const int M = 1 << (n - d - 1);
        SPS pre(ret.begin(), ret.begin() + M);
        SPS a2(a.begin() + M, a.begin() + 2 * M);
        pre *= a2;
        std::ranges::copy(pre, ret.begin() + M);
    }
    return ret;
}

template <typename SPS, typename T = typename SPS::value_type> SPS log(SPS a) {
    int n = bitwise::log2(a.size());
    assert((1 << n) == a.size() and a[0] == 1);
    std::vector<T> lg(n + 1, 0);
    for (int k = 1; k <= n; k++)
        lg[k] = T(-1) / k;
    return SPS_composition(lg, SPS(1, 1) - a);
}
