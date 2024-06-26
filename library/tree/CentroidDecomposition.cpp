template <typename TREE> class CentroidDecomposition {
    TREE T;
    std::vector<int> sz, pre, timing;

    int find_centroid(int v) {
        std::vector<int> S{v};
        pre[v] = -1;
        for (int i = 0; i < S.size(); i++) {
            const int u = S[i];
            sz[u] = 1;
            for (int to : T[u]) {
                if (to == pre[u] || ~timing[to])
                    continue;
                pre[to] = u;
                S.push_back(to);
            }
        }
        int SZ = S.size();
        std::ranges::reverse(S);
        for (int u : S) {
            if (SZ - sz[u] <= SZ / 2)
                return u;
            sz[pre[u]] += sz[u];
        }
        assert(false);
        return -1;
    };

  public:
    std::vector<int> order;
    CentroidDecomposition(TREE T) : T(T), sz(T.n), pre(T.n), timing(T.n, -1) {
        order.reserve(T.n);
        std::queue<int> que;
        que.push(0);
        while (que.size()) {
            int c = find_centroid(que.front());
            que.pop();
            timing[c] = order.size();
            order.push_back(c);
            for (int to : T[c])
                if (timing[to] < 0)
                    que.push(to);
        }
    }

    template <typename X, typename F, typename G, typename H>
    void calc(int root, X initial_val, const F &next_val, const G &action,
              const H &finish) {
        std::queue<std::tuple<int, int, X>> que;

        auto f = [&](int v_, int pre_, X val_, bool is_all) {
            que.emplace(v_, pre_, val_);
            while (que.size()) {
                auto [v, pre, val] = que.front();
                que.pop();
                action(val, is_all);
                for (const auto &e : T[v]) {
                    if (e.to == pre || timing[e.to] <= timing[root])
                        continue;
                    que.emplace(e.to, v, next_val(val, e));
                }
            }
            finish(is_all);
        };

        for (const auto &e : T[root])
            if (timing[e.to] > timing[root])
                f(e.to, root, next_val(initial_val, e), false);

        f(root, -1, initial_val, true);
    }

    template <typename X, typename F, typename G, typename H>
    void all_calc(X initial_val, const F &next_val, const G &action,
                  const H &finish) {
        for (int i = 0; i < T.n; i++)
            calc(i, initial_val, next_val, action, finish);
    }
};