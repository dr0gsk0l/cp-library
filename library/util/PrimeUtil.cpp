#pragma once
// 宣言はグローバルでする
// https://twitter.com/climpet/status/1598974781138694144

template <int MAX, bool PRIME_FACTOR = false, bool DIVISOR = false>
class PrimeUtil {
    using u32 = std::uint32_t;
    using u64 = std::uint64_t;
    using PF = std::vector<std::pair<u32, int>>;

    template <typename T> using ARR = std::array<T, MAX + 1>;
    template <typename T, bool F> using COND = std::conditional_t<F, T, bool>;

    ARR<bool> isP;
    std::vector<u32> primes;
    COND<ARR<PF>, PRIME_FACTOR> prime_factors;
    COND<ARR<std::vector<u32>>, DIVISOR> divisors; // 自明な約数は入らない

    static u64 pow2(u64 a) { return a * a; }

  public:
    PrimeUtil() {
        std::ranges::fill(isP, true);
        isP[0] = isP[1] = false;

        primes.reserve(MAX / 10);
        for (int i = 2; i <= MAX; i++) {
            // 約数列挙
            if constexpr (DIVISOR) {
                for (int j = 2 * i; j <= MAX; j += i)
                    divisors[j].push_back(i);
            }
            // エラトステネスの篩
            if (!isP[i])
                continue;
            primes.push_back(i);
            for (u64 j = pow2(i); j <= MAX; j += i)
                isP[j] = false;
            // 素因数分解
            if constexpr (PRIME_FACTOR) {
                for (int j = i; j <= MAX; j += i)
                    prime_factors[j].emplace_back(i, 1);
                int limit = MAX / i + 1;
                for (u64 j = pow2(i); j <= MAX; j *= i) {
                    for (int k = j; k <= MAX; k += j)
                        prime_factors[k].back().second++;
                    if (j > limit)
                        break;
                }
            }
        }
    }

    bool is_prime(u64 x) const {
        if (x <= MAX)
            return isP[x];
        for (int p : primes) {
            if (pow2(p) > x)
                return true;
            if (x % p == 0)
                return false;
        }
        for (int p = primes.back() + 1; pow2(p) <= x; p++)
            if (x % p == 0)
                return false;
        return true;
    }

    std::vector<u32> prime_list() const { return primes; }

    // 素因数分解
    PF prime_factor(u64 n) const {
        assert(n <= pow2(MAX));

        if constexpr (PRIME_FACTOR)
            if (n <= MAX)
                return prime_factor[n];
        PF ret;
        for (u64 p : primes) {
            if (p * p > n)
                break;
            if (n % p)
                continue;
            ret.emplace_back(p, 0);
            while (n % p == 0) {
                ret.back().second++;
                n /= p;
            }
        }

        if (n > 1)
            ret.emplace_back(n, 1);

        return ret;
    }
};
