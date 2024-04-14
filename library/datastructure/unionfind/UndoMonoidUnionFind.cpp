template <typename AbelGroup> class UnionFind {
    using T = typename AbelGroup::value_type;
    int n, num;
    std::vector<int> sz, parent;
    std::vector<T> value;
    std::stack<std::pair<int, int>> sta;

  public:
    UnionFind() = default;
    UnionFind(int n)
        : n(n), num(n), sz(n, 1), parent(n), value(n, AbelGroup::unit()) {
        std::ranges::iota(parent, 0);
    }
    UnionFind(const std::vector<T> &v)
        : n(v.size()), num(n), sz(n, 1), parent(n), value(v) {
        std::ranges::iota(parent, 0);
    }

    int leader(int x) {
        assert(0 <= x and x < n);
        return (x == parent[x] ? x : leader(parent[x]));
    }

    T sum(int x) { return value[leader(x)]; }

    void multiply(int x, T a) { AbelGroup::Rchop(value[leader(x)], a); }

    bool same(int x, int y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        return leader(x) == leader(y);
    }

    void undo() {
        auto [x, y] = sta.top();
        sta.pop();
        sz[x] -= sz[y];
        parent[y] = y;
        AbelGroup::Rchop(value[x], AbelGroup::inverse(value[y]));
    }

    bool merge(int x, int y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        x = leader(x);
        y = leader(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            std::swap(x, y);
        sta.emplace(x, y);
        sz[x] += sz[y];
        parent[y] = x;
        AbelGroup::Rchop(value[x], value[y]);
        num--;
        return true;
    }

    int size(const int x) {
        assert(0 <= x and x < n);
        return sz[leader(x)];
    }

    int count() const { return num; }
};