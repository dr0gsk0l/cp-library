

// TYPES

// macro

#ifdef __DEBUG
#include <debug>
#else
#define debug(...) void(0)
#endif

std::string YES(bool f = true) { return (f ? "YES" : "NO"); }
std::string Yes(bool f = true) { return (f ? "Yes" : "No"); }
std::string yes(bool f = true) { return (f ? "yes" : "no"); }

constexpr int INF = 1e9 + 7;
constexpr ll LINF = ll(1e18) + 7;
constexpr ld EPS = 1e-10;

TYPE(T)
vector<pair<T, int>> query_sort(const std::vector<T> &v) {
    std::vector<pair<T, int>> res(v.size());
    REP (i, v.size())
        res[i] = {v[i], i};
    SORT(res);
    return res;
}

TYPE(T)
bool chmax(T &a, T b) { return (a < b && (a = b, true)); }
TYPE(T)
bool chmin(T &a, T b) { return (a > b && (a = b, true)); }

bool in(const ll S, const int a) { return (S >> a) & 1; }
int popcount(const ll S) { return __builtin_popcountll(S); }
int digit(char c) { return (c >= '0' and c <= '9' ? c - '0' : -1); }
ll sqrtll(ll a) {
    for (ll b = sqrt(a); b * b <= a; b++)
        if (b * b == a)
            return b;
    for (ll b = sqrt(a); b >= 0 and b * b >= a; b--)
        if (b * b == a)
            return b;
    return -1;
}