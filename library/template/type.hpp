#include "library/template/base.hpp"

#define TYPE1(T) template <class T>
#define TYPE2(T, U) template <class T, class U>
#define TYPE3(T, U, V) template <class T, class U, class V>
#define TYPE4(T, U, V, W) template <class T, class U, class V, class W>
#define TYPE5(T, U, V, W, X)                                                   \
    template <class T, class U, class V, class W, class X>
#define TYPE(...)                                                              \
    overload5(__VA_ARGS__, TYPE5, TYPE4, TYPE3, TYPE2, TYPE1)(__VA_ARGS__)
#define TYPES1(T) template <class... T>
#define TYPES2(H, T) template <class H, class... T>
#define TYPES(...) overload2(__VA_ARGS__, TYPES2, TYPES1)(__VA_ARGS__)

TYPE(T)
using vec<T> = std::vector<T>;
TYPE(T)
using vvec<T> = vec<vec<T>>;
TYPE(T)
using vvvec<T> = vec<vvec<T>>;
TYPE(T)
using vvvvec<T> = vec<vvvec<T>>;
TYPE(T)
using ptt<T> = std::pair<T, T>;
using ll = long long;
using ld = long double;
using vi = vec<int>;
using vvi = vvec<int>;
using vvvi = vvvec<int>;
using vvvvi = vvvvec<int>;
using vll = vec<ll>;
using vvll = vvec<ll>;
using vvvll = vvvec<ll>;
using vvvvll = vvvvec<ll>;
using vs = vec<std::string>;
using pi = ptt<int>;
using pll = ptt<ll>;

TYPE(T)
using pq = std::priority_queue<T>;
TYPE(T)
using pqg = std::priority_queue<T, vec<T>, std::greater<T>>;
