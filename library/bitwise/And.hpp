#pragma once
#include <bit>
#include <cassert>
#include <ranges>
#include <vector>
struct BitwiseAnd {
  private:
    static int log2_power_of_two(std::size_t size) {
        assert(std::has_single_bit(size));
        return static_cast<int>(std::countr_zero(size));
    }
    static constexpr bool has_bit(int value, int bit) {
        return (value >> bit) & 1;
    }

  public:
    template <typename T> static void zeta(std::vector<T> &A) {
        const int n = log2_power_of_two(A.size());
        for (int k : std::views::iota(0, n)) {
            for (int S : std::views::iota(0, 1 << n)) {
                if (!has_bit(S, k)) {
                    A[S] += A[S ^ (1 << k)];
                }
            }
        }
    }
    template <typename T> static void mobius(std::vector<T> &A) {
        const int n = log2_power_of_two(A.size());
        for (int k : std::views::iota(0, n)) {
            for (int S : std::views::iota(0, 1 << n)) {
                if (!has_bit(S, k)) {
                    A[S] -= A[S ^ (1 << k)];
                }
            }
        }
    }
    template <typename T>
    static std::vector<T> convolution(std::vector<T> A, std::vector<T> B) {
        assert(A.size() == B.size());
        zeta(A);
        zeta(B);
        for (auto &&[a, b] : std::views::zip(A, B)) a *= b;
        mobius(A);
        return A;
    }
};
