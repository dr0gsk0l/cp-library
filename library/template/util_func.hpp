#include "library/template/macro.hpp"
#include "library/template/type.hpp"
#pragma region std::queue
TYPE(T)
T pick(std::queue<T> &que) {
    assert(que.size());
    T a = que.front();
    que.pop();
    return a;
}
TYPE(T)
T pick(pq<T> &que) {
    assert(que.size());
    T a = que.top();
    que.pop();
    return a;
}
TYPE(T)
T pick(pqg<T> &que) {
    assert(que.size());
    T a = que.top();
    que.pop();
    return a;
}
TYPE(T)
T pick(std::stack<T> &sta) {
    assert(sta.size());
    T a = sta.top();
    sta.pop();
    return a;
}
TYPE(T)
void clear(T &v) { v = decltype(v)(); }
#pragma endregion
#pragma region vec
vi iota(int n) {
    vi a(n);
    std::iota(ALL(a), 0);
    return a;
}
TYPE(T)
void add(vec<T> &v, const T &a = 1) {
    AFOR (p, v)
        p += a;
}
TYPE(T)
T rev(T a) {
    REVERSE(a);
    return a;
}

ll sum(const vi &v) { return std::accumulate(ALL(v), 0LL); }
TYPE(T) T sum(const vec<T> &v) { return std::accumulate(ALL(v), T(0)); }

TYPE(T, Ns)
auto make_vector(T x, int n, Ns... ns) {
    if constexpr (sizeof...(ns) == 0)
        return std::vector<T>(n, x);
    else
        return std::vector(n, make_vector<T>(x, ns...));
}
#pragma endregion