template <typename TREE>
std::pair<int, vector<int>> rooted_tree_isomorphism(TREE &t) {
    assert(~t.root);
    std::vector<int> res(t.n);
    std<vector<int>, int> mp;
    for (const int v : t.DFS) {
        std::vector<int> h;
        for (int to : t.son(v))
            h.push_back(res[to]);
        sort(h.begin(), h.end());
        if (!mp.count(h))
            mp[h] = mp.size();
        res[v] = mp[h];
    }
    return {mp.size(), res};
}