#include "library/template/util_func.hpp"

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
ll sum(const vll &v) { return std::accumulate(ALL(v), 0LL); }

TYPE(T, Ns)
auto make_vector(T x, int n, Ns... ns) {
  if constexpr (sizeof...(ns) == 0)
    return vector<T>(n, x);
  else
    return vector(n, make_vector<T>(x, ns...));
}
#pragma endregion