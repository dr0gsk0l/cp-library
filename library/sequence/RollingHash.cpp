// reference: https://qiita.com/keymoon/items/11fac5627672a6d6a9f6
#pragma once
#include "library/mod/Modint61.cpp"
#include "library/sequence/ForString.cpp"

#include <random>
#include <vector>

std::random_device rollonghash_rnd;
std::mt19937 rollonghash_mt(rollonghash_rnd());

template <typename CHAR = char, typename MINT = Modint61> class RollingHash {
    using ll = long long;
    static constexpr ll mod = (1LL << 61) - 1;
    // using T = conditional_t< less<ll>(mod,ll(
    // std::numeric_limits<int>::max())), int, ll>;
    using T = ll;
    inline static const MINT base = MINT::raw(rollonghash_mt() % (mod - 2) + 2);

    int n;
    std::vector<MINT> hash;

  public:
    static std::vector<MINT> power;

    RollingHash() = default;
    RollingHash(const std::vector<CHAR> &v) : n(v.size()), hash(n + 1, 0) {
        if (!power.size())
            power.push_back(1);
        for (int i = 0; i < n; i++)
            hash[i + 1] = nxt_hash(hash[i], v[i]);

        if (power.size() <= n) {
            int sz = std::max(int(2 * power.size()), n + 1);
            power.reserve(sz);
            while (power.size() < sz)
                power.push_back(power.back() * base);
        }
    }

    static MINT nxt_hash(MINT x, CHAR c) { return (x * base) + MINT::raw(c); }

    T get_hash(int l = 0, int r = -1) {
        if (r < 0)
            r = n;
        return (hash[r] - hash[l] * power[r - l]).v;
    }

    static T full_hash(const std::vector<CHAR> &v) {
        MINT res = 0;
        for (const char &c : v)
            res = nxt_hash(res, c);
        return res.v;
    }
};