#include <vector>
#include <functional>
#include <ranges>

template <typename T> struct Valarray : std::vector<T> {
    using std::vector<T>::vector; // コンストラクタ継承

  private:
    template <typename Op>
    Valarray &apply_inplace(const Valarray &other, Op op) {
        if (this->size() < other.size())
            this->resize(other.size(), T(0));

        for (auto [a, b] : std::views::zip(*this, other))
            a = op(a, b);

        return *this;
    }

  public:
    Valarray &operator+=(const Valarray &other) {
        return apply_inplace(other, std::plus<>());
    }
    Valarray &operator-=(const Valarray &other) {
        return apply_inplace(other, std::minus<>());
    }
    Valarray &operator*=(const Valarray &other) {
        return apply_inplace(other, std::multiplies<>());
    }
    Valarray &operator/=(const Valarray &other) {
        return apply_inplace(other, std::divides<>());
    }

    friend Valarray operator+(Valarray a, const Valarray &b) { return a += b; }
    friend Valarray operator-(Valarray a, const Valarray &b) { return a -= b; }
    friend Valarray operator*(Valarray a, const Valarray &b) { return a *= b; }
    friend Valarray operator/(Valarray a, const Valarray &b) { return a /= b; }
};