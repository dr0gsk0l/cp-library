#include "library/template/base.hpp"
#include "library/template/type.hpp"

void print();

TYPES(T, Ts)
void print(const T &a, const Ts &...b);

TYPES(T, Ts)
void fin(const T &a, const Ts &...b)