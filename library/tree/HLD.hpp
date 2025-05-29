#pragma once
template <typename TREE> struct HLD {
    int n;
    TREE T;
    std::vector<int> sz, head, id, id2, rev_id;
    bool prepared;
    HLD(TREE T_)
        : T(T_), n(T_.n), sz(n), head(n), id(n), id2(n), rev_id(n), prepared(false) {}
    HLD() = default;

  private:
    void dfs_sz(int v) {
        sz[v] = 1;
        for (auto &e : T.son(v)) {
            dfs_sz(e.to);
            sz[v] += sz[e.to];
            if (sz[e.to] > sz[T.son(v)[0].to])
                std::swap(e, T.son(v)[0]);
        }
    }
    void dfs_hld(int v, int &k) {
        id[v] = k++;
        rev_id[id[v]] = v;
        for (int i = 0; i < T.son(v).size(); i++) {
            int to = T.son(v)[i];
            head[to] = (i ? to : head[v]);
            dfs_hld(to, k);
        }
        id2[v] = k;
    }

  public:
    std::vector<int> build(int r = 0) {
        assert(!prepared);
        prepared = true;
        if (~T.root)
            assert(T.root == r);
        else
            T.build(r);
        head[r] = r;
        dfs_sz(r);
        int k = 0;
        dfs_hld(r, k);
        return id;
    }

    int lca(int u, int v) const {
        assert(prepared);
        while (head[u] != head[v])
            if (T.depth[head[u]] > T.depth[head[v]])
                u = T.parent(head[u]);
            else
                v = T.parent(head[v]);
        return (T.depth[u] < T.depth[v] ? u : v);
    }
    int distance(int u, int v) const {
        int w = lca(u, v);
        return T.depth[u] + T.depth[v] - T.depth[w] * 2;
    }

    // v の k 個上の頂点を返す
    int kth_parent(int v, int k) const {
        assert(prepared);
        if(T.depth[v] < k)
            return -1;
        while(T.depth[v] - T.depth[head[v]] < k){
            k -= T.depth[v] - T.depth[head[v]] + 1;
            v = T.parent(head[v]);
        }
        return rev_id[id[v] - k];
    }

    // u から v へ k 回移動した頂点を返す
    int jump(int u, int v, int k) const {
        assert(prepared);
        int w = lca(u, v);
        if(T.depth[u] + T.depth[v] - T.depth[w] * 2 < k)
            return -1;
        if(T.depth[u] - T.depth[w] >= k)
            return kth_parent(u, k);
        return kth_parent(v, T.depth[u] + T.depth[v] - T.depth[w] * 2 - k);
    }

    // l=lca(u,v) とした時、[u,l] パスと [v,l] パス を閉区間の組みで返す
    using path_t = std::vector<std::pair<int, int>>;
    std::pair<path_t, path_t> path(int u, int v) const {
        assert(prepared);
        path_t path_u, path_v;
        while (u != v) {
            if (head[u] == head[v]) {
                if (T.depth[u] < T.depth[v])
                    path_v.emplace_back(id[v], id[u]);
                else
                    path_u.emplace_back(id[u], id[v]);
                break;
            }
            if (T.depth[head[u]] < T.depth[head[v]]) {
                path_v.emplace_back(id[v], id[head[v]]);
                v = T.parent(head[v]);
            } else {
                path_u.emplace_back(id[u], id[head[u]]);
                u = T.parent(head[u]);
            }
        }
        if (u == v)
            path_u.emplace_back(id[u], id[u]);
        return {path_u, path_v};
    }

    // [l,r) が v の部分木
    std::pair<int, int> subtree(int v) const {
        assert(prepared);
        return {id[v], id2[v]};
    }
};