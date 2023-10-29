#include "library/template/base.hpp"
#include "library/template/type.hpp"

TYPE(T)
std::istream &operator>>(std::istream &is, vec<T> &v);

TYPE(T, S)
std::istream &operator>>(std::istream &is, std::pair<T, S> &p);
