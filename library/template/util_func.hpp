#include "library/template/base.hpp"
#include "library/template/type.hpp"

TYPE(T)
T pick(std::queue<T> &que);
TYPE(T)
T pick(pq<T> &que);
TYPE(T)
T pick(pqg<T> &que);
TYPE(T)
T pick(stack<T> &sta);