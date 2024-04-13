#include "library/template/base.hpp"
#include "library/template/type.hpp"

TYPE(T)
std::istream &operator>>(std::istream &is, vec<T> &v) {
    for (T &a : v)
        is >> a;
    return is;
}

TYPE(T, S)
std::istream &operator>>(std::istream &is, std::std::pair<T, S> &p) {
    return is >> p.first >> p.second;
}