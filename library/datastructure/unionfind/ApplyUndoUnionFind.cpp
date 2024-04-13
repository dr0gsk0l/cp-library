#include <bits/stdc++.h>

template <typename AbelGroup> class UndoUnionFind {
    using T = typename AbelGroup::value_type;
    size_t n, num;
    std::vector<size_t> sz, parent;
    std::stack<std::std::pair<size_t, size_t>> sta;
    std::vector<T> value;

  public:
    UndoUnionFind() = default;
    UndoUnionFind(size_t n)
        : n(n), num(n), sz(n, 1), parent(n, 0), value(n, AbelGroup::unit()) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    size_t leader(size_t x) const {
        assert(0 <= x and x < n);
        return (x == parent[x] ? x : leader(parent[x]));
    }

    T get(size_t x) const {
        assert(0 <= x and x < n);
        if (x == parent[x])
            return value[x];
        T ret = value[x];
        while (x != parent[x]) {
            x = parent[x];
            AbelGroup::Rchop(ret, value[x]);
        }
        return ret;
    }

    bool same(size_t x, size_t y) const {
        assert(0 <= x and x < n and 0 <= y and y < n);
        return leader(x) == leader(y);
    }

    bool merge(size_t x, size_t y) {
        assert(0 <= x and x < n and 0 <= y and y < n);
        x = leader(x);
        y = leader(y);
        if (x == y)
            return false;
        if (sz[x] < sz[y])
            swap(x, y);
        sz[x] += sz[y];
        parent[y] = x;
        AbelGroup::Rchop(value[y], AbelGroup::inverse(value[x]));
        num--;
        sta.emplace(x, y);
        return true;
    }

    void undo() {
        if (!sta.size())
            return;
        auto [x, y] = sta.top();
        sta.pop();
        sz[x] -= sz[y];
        parent[y] = y;
        AbelGroup::Rchop(value[y], value[x]);
        num++;
    }

    size_t size(const size_t x) const {
        assert(0 <= x and x < n);
        return sz[leader(x)];
    }

    size_t count() const { return num; }
};