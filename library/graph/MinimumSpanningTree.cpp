#include "library/datastructure/unionfind/UnionFind.cpp"
template <typename WG, typename W = typename WG::weight_type>
std::pair<W, std::vector<int>> minimum_spanning_tree(const WG &g) {
    assert(g.is_prepared());
    int n = g.n, m = g.edges.size();
    UnionFind uf(n);
    std::vector<int> id(m);
    std::iota(id.begin(), id.end(), 0);
    std::ranges::sort(id, [&](const int i, const int j) {
        return g.edges[i].weight < g.edges[j].weight;
    });
    W res = 0;
    std::vector<int> tree;
    tree.reserve(n - 1);
    for (int i : id) {
        const auto &[from, to, weight] = g.edges[i];
        if (uf.same(from, to))
            continue;
        tree.push_back(i);
        uf.merge(from, to);
        res += weight;
    }
    assert(uf.count() == 1);
    return {res, tree};
}