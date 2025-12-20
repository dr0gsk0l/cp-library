#pragma once
#include <bit>
#include <cassert>
#include <ranges>
#include <vector>
class BitwiseRanked {
    static int popcount(int S) { return __builtin_popcount(S); }
    static int log2_power_of_two(std::size_t size) {
        assert(std::has_single_bit(size));
        return static_cast<int>(std::countr_zero(size));
    }
    static constexpr bool has_bit(int value, int bit) {
        return (value >> bit) & 1;
    }

  public:
    template <typename T>
    static std::vector<std::vector<T>> zeta(const std::vector<T> &A) {
        const int n = log2_power_of_two(A.size());
        std::vector<std::vector<T>> RA(1 << n, std::vector<T>(n + 1, 0));
        for (int S : std::views::iota(0, 1 << n)) {
            RA[S][popcount(S)] = A[S];
        }
        for (int i : std::views::iota(0, n)) {
            for (int S : std::views::iota(0, 1 << n)) {
                if (has_bit(S, i)) {
                    continue;
                }
                for (int d : std::views::iota(0, n + 1)) {
                    RA[S | (1 << i)][d] += RA[S][d];
                }
            }
        }
        return RA;
    }
    template <typename T>
    static std::vector<T> mobius(std::vector<std::vector<T>> RA) {
        const int n = log2_power_of_two(RA.size());
        for (int i : std::views::iota(0, n)) {
            for (int S : std::views::iota(0, 1 << n)) {
                if (has_bit(S, i)) {
                    continue;
                }
                for (int d : std::views::iota(0, n + 1)) {
                    RA[S | (1 << i)][d] -= RA[S][d];
                }
            }
        }
        std::vector<T> A(1 << n);
        for (int S : std::views::iota(0, 1 << n)) {
            A[S] = RA[S][popcount(S)];
        }
        return A;
    }
    template <typename T>
    static std::vector<T> convolution(const std::vector<T> &A,
                                      const std::vector<T> &B) {
        const int n = log2_power_of_two(A.size());
        auto RA = zeta(A);
        auto RB = zeta(B);
        for (int S : std::views::iota(0, 1 << n)) {
            auto &ra = RA[S];
            auto &rb = RB[S];
            for (int d : std::views::iota(0, n + 1) | std::views::reverse) {
                ra[d] *= rb[0];
                for (int i : std::views::iota(0, d)) {
                    ra[d] += ra[i] * rb[d - i];
                }
            }
        }
        return mobius(RA);
    }
};
