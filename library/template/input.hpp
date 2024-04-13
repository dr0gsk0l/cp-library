#include "library/template/base.hpp"
#include "library/template/macro.hpp"
#include "library/template/type.hpp"

TYPES(T)
void input(T &...a) { (std::cin >> ... >> a); }

#define INPUT(T, ...)                                                          \
    T __VA_ARGS__;                                                             \
    input(__VA_ARGS__);

#define INT(...) INPUT(int, __VA_ARGS__)
#define STR(...) INPUT(std::string, __VA_ARGS__)
#define LL(...) INPUT(long long, __VA_ARGS__)
#define CHR(...) INPUT(char, __VA_ARGS__)
#define DBL(...) INPUT(double, __VA_ARGS__)

#define VI2(n, v)                                                              \
    vi v(n);                                                                   \
    input(v);
#define VI3(n, v, w)                                                           \
    vi v(n), w(n);                                                             \
    input(v, w);
#define VI4(n, v, w, x)                                                        \
    vi v(n), w(n), x(n);                                                       \
    input(v, w, x);
#define VI(...) overload5(__VA_ARGS__, VI4, VI3, VI2)(__VA_ARGS__)

#define VLL2(n, v)                                                             \
    vll v(n);                                                                  \
    input(v);
#define VLL3(n, v, w)                                                          \
    vll v(n), w(n);                                                            \
    input(v, w);
#define VLL4(n, v, w, x)                                                       \
    vll v(n), w(n), x(n);                                                      \
    input(v, w, x);
#define VLL(...) overload5(__VA_ARGS__, VLL4, VLL3, VLL2)(__VA_ARGS__)

#define VS2(n, v)                                                              \
    vs v(n);                                                                   \
    input(v);
#define VS3(n, v, w)                                                           \
    vs v(n), w(n);                                                             \
    input(v, w);
#define VS4(n, v, w, x)                                                        \
    vs v(n), w(n), x(n);                                                       \
    input(v, w, x);
#define VS(...) overload5(__VA_ARGS__, VS4, VS3, VS2)(__VA_ARGS__)

#define VVI(n, m, v)                                                           \
    vvi v(n, vi(m));                                                           \
    input(v);

#define VVLL(n, m, v)                                                          \
    vvll v(n, vll(m));                                                         \
    input(v);
