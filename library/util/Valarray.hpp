#include <cstddef>
#include <functional>
#include <vector>

template <typename Derived, typename T> struct Valarray : std::vector<T> {
    using std::vector<T>::vector; // コンストラクタ継承
    Valarray(const std::vector<T> &v) : std::vector<T>(v.begin(), v.end()) {}

  private:
    Derived &self() { return static_cast<Derived &>(*this); }
    const Derived &self() const { return static_cast<const Derived &>(*this); }

    template <typename Op>
    Derived &apply_inplace(const Derived &other, Op op) {
        if (this->size() < other.size())
            this->resize(other.size(), T(0));

        for (size_t i = 0; i < other.size(); i++)
            (*this)[i] = op((*this)[i], other[i]);

        return self();
    }

  public:
    Derived &operator+=(const Derived &other) {
        return apply_inplace(other, std::plus<>());
    }
    Derived &operator-=(const Derived &other) {
        return apply_inplace(other, std::minus<>());
    }
    Derived &operator*=(const Derived &other) {
        return apply_inplace(other, std::multiplies<>());
    }
    Derived &operator/=(const Derived &other) {
        return apply_inplace(other, std::divides<>());
    }

    friend Derived operator+(Derived a, const Derived &b) { return a += b; }
    friend Derived operator-(Derived a, const Derived &b) { return a -= b; }
    friend Derived operator*(Derived a, const Derived &b) { return a *= b; }
    friend Derived operator/(Derived a, const Derived &b) { return a /= b; }

    Derived operator-() const {
        Derived g = self();
        for (T &a : g)
            a = -a;
        return g;
    }
};
