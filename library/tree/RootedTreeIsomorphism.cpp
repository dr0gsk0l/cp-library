template <typename TREE>
std::pair<int, std::vector<int>> rooted_tree_isomorphism(TREE &t) {
    assert(~t.root);
    std::vector<int> res(t.n);
    std::map<std::vector<int>, int> mp;
    for (const int v : t.DFS) {
        std::vector<int> h;
        for (int to : t.son(v))
            h.push_back(res[to]);
        std::ranges::sort(h);
        if (!mp.count(h))
            mp[h] = mp.size();
        res[v] = mp[h];
    }
    return {mp.size(), res};
}