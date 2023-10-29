#include "library/template/base.hpp"
#include "library/template/type.hpp"

TYPE(T)
std::ostream &operator<<(std::ostream &os, vec<T> &v);

TYPE(T, S)
std::ostream &operator<<(std::ostream &os, std::pair<T, S> &p);
