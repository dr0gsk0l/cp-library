#pragma once
#include "library/algebra/group/Add.cpp"
#include "library/sequence/ForString.cpp"
template <typename CHAR, int SIGMA, typename AbelMonoid = GroupAdd<int>>
class Trie {
  protected:
    using X = typename AbelMonoid::value_type;
    struct Node {
        std::array<int, SIGMA> nxt;
        int pre;
        X val, suffix_val; // suffix_val は自身を含まない
        Node(int pre)
            : pre(pre), val(AbelMonoid::unit()),
              suffix_val(AbelMonoid::unit()) {
            std::ranges::fill(nxt, -1);
        }
    };
    std::vector<Node> nodes;

  public:
    Trie() : nodes(1, Node(-1)) {}

    int &nxt(int now, const CHAR &a) { return nodes[now].nxt[a]; }
    const int &nxt(int now, const CHAR &a) const { return nodes[now].nxt[a]; }

    int add(const std::vector<CHAR> &v, X x = 1) {
        int now = 0;
        for (const CHAR &a : v) {
            assert(0 <= a and a < SIGMA);
            if (!~nxt(now, a)) {
                nxt(now, a) = nodes.size();
                nodes.emplace_back(now);
            }
            AbelMonoid::Rchop(nodes[now].suffix_val, x);
            now = nxt(now, a);
        }
        AbelMonoid::Rchop(nodes[now].val, x);
        return now;
    }
    int node_idx(const std::vector<CHAR> &v) const {
        // s の Node を返す　追加されて無ければ -1
        int now = 0;
        for (const CHAR &a : v) {
            if (!~nxt(now, a))
                return -1;
            now = nxt(now, a);
        }
        return now;
    }
    X val(const std::vector<CHAR> &v) {
        int id = node_idx(v);
        return (~id ? nodes[id].val : AbelMonoid::unit());
    }
    X &val(int node_id) { return nodes[node_id].val; }
    // vは含まない
    X prefix_prod(const std::vector<CHAR> &v) {
        int now = 0;
        X sum = AbelMonoid::unit();
        for (const CHAR &a : v) {
            if (!~nxt(now, a))
                break;
            AbelMonoid::Rchop(sum, nodes[now].val);
            now = nxt(now, a);
        }
        return sum;
    }
    // vは含まない
    X suffix_prod(const std::vector<CHAR> &v) const {
        int id = node_idx(v);
        return (~id ? nodes[id].suffix_val : AbelMonoid::unit());
    }
    std::vector<CHAR> restore(int node_id) {
        assert(0 <= node_id and node_id < nodes.size());
        std::vector<CHAR> res;
        while (~nodes[node_id].pre) {
            int pre = nodes[node_id].pre;
            for (int j = 0; j < SIGMA; j++)
                if (nxt(pre, j) == node_id) {
                    res.push_back(j);
                    break;
                }
            node_id = pre;
        }
        std::ranges::reverse(res);
        return res;
    }
    X prod() const { return nodes[0].suffix_val; }
    int size() const { return nodes.size(); }

    template <typename F>
    void query(const std::vector<CHAR> &v, const F &f, int l = 0, int r = -1) {
        if (r < 0)
            r = v.size();
        int now = 0;
        for (int i = l; i < r; i++) {
            now = nxt(now, v[i]);
            if (~now)
                f(now);
            else
                break;
        }
    }
};
