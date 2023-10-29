#include "library/template/base.hpp"
#include "library/template/macro.hpp"
#include "library/template/type.hpp"

TYPES(T)
void input(T &...a) { (cin >> ... >> a); }

#define INPUT(T, ...)                                                          \
  T __VA_ARGS__;                                                               \
  input(__VA_ARGS__);

#define INT(...) INPUT(int, __VA_ARGS__)
#define STR(...) INPUT(string, __VA_ARGS__)
#define LL(...) INPUT(long long, __VA_ARGS__)
#define CHR(...) INPUT(char, __VA_ARGS__)
#define DBL(...) INPUT(double, __VA_ARGS__)

#define VI2(n, v)                                                              \
  vi v(n);                                                                     \
  cin >> v;
#define VI3(n, v, w)                                                           \
  vi v(n), w(n);                                                               \
  cin >> v >> w;
#define VI4(n, v, w, x)                                                        \
  vi v(n), w(n), x(n);                                                         \
  cin >> v >> w >> x;
#define VI(...) overload5(__VA_ARGS__, VI4, VI3, VI2)(__VA_ARGS__)

#define VLL2(n, v)                                                             \
  vll v(n);                                                                    \
  cin >> v;
#define VLL3(n, v, w)                                                          \
  vll v(n), w(n);                                                              \
  cin >> v >> w;
#define VLL4(n, v, w, x)                                                       \
  vll v(n), w(n), x(n);                                                        \
  cin >> v >> w >> x;
#define VLL(...) overload5(__VA_ARGS__, VLL4, VLL3, VLL2)(__VA_ARGS__)

#define VS2(n, v)                                                              \
  vs v(n);                                                                     \
  cin >> v;
#define VS3(n, v, w)                                                           \
  vs v(n), w(n);                                                               \
  cin >> v >> w;
#define VS4(n, v, w, x)                                                        \
  vs v(n), w(n), x(n);                                                         \
  cin >> v >> w >> x;
#define VS(...) overload5(__VA_ARGS__, VS4, VS3, VS2)(__VA_ARGS__)

#define VVI(n, m, v)                                                           \
  vvi v(n, vi(m));                                                             \
  std::cin >> v;

#define VVLL(n, m, v)                                                          \
  vvll v(n, vll(m));                                                           \
  std::cin >> v;
