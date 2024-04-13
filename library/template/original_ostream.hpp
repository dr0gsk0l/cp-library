#include "library/template/base.hpp"
#include "library/template/type.hpp"

TYPE(T)
std::ostream &operator<<(std::ostream &os, vec<T> &v) {
    if (&os == &std::cerr)
        os << "[";
    for (int i = 0; i < v.size(); i++) {
        os << v[i];
        if (i + 1 < v.size())
            os << (&os == &std::cerr ? "," : " ");
    }
    if (&os == &std::cerr)
        os << "]";
    return os;
}

TYPE(T, S)
std::ostream &operator<<(std::ostream &os, std::pair<T, S> &p) {
    if (&os == &std::cerr)
        return os << "(" << p.first << "," << p.second << ")";
    return os << p.first << " " << p.second;
}

template <class... Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    std::apply([&](const auto &...xs) { outputs(os, xs); });
    return os;
}