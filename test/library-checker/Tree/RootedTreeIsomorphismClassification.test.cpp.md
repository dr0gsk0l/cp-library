---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: library/graph/Graph.cpp
    title: library/graph/Graph.cpp
  - icon: ':x:'
    path: library/tree/RootedTreeIsomorphism.cpp
    title: library/tree/RootedTreeIsomorphism.cpp
  - icon: ':x:'
    path: library/tree/Tree.cpp
    title: library/tree/Tree.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
    links:
    - https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification
  bundledCode: "#line 1 \"test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp\"\
    \n#define PROBLEM                                                            \
    \    \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n#include <bits/stdc++.h>\n\n#line 1 \"library/tree/RootedTreeIsomorphism.cpp\"\
    \ntemplate <typename TREE>\npair<int, vector<int>> rooted_tree_isomorphism(TREE\
    \ &t) {\n    assert(~t.root);\n    std::vector<int> res(t.n);\n    map<vector<int>,\
    \ int> mp;\n    for (const int v : t.DFS) {\n        std::vector<int> h;\n   \
    \     for (int to : t.son(v))\n            h.push_back(res[to]);\n        sort(h.begin(),\
    \ h.end());\n        if (!mp.count(h))\n            mp[h] = mp.size();\n     \
    \   res[v] = mp[h];\n    }\n    return {mp.size(), res};\n}\n#line 2 \"library/graph/Graph.cpp\"\
    \nstruct Edge {\n    int from, to;\n    Edge() = default;\n    Edge(int from,\
    \ int to) : from(from), to(to) {}\n    operator int() const { return to; }\n};\n\
    \nstruct Graph {\n    int n;\n    using edge_type = Edge;\n    std::vector<edge_type>\
    \ edges;\n\n  protected:\n    std::vector<int> in_deg;\n    bool prepared;\n \
    \   class OutgoingEdges {\n        Graph *g;\n        int l, r;\n\n      public:\n\
    \        OutgoingEdges(Graph *g, int l, int r) : g(g), l(l), r(r) {}\n       \
    \ edge_type *begin() { return &(g->edges[l]); }\n        edge_type *end() { return\
    \ &(g->edges[r]); }\n        edge_type &operator[](int i) { return g->edges[l\
    \ + i]; }\n        int size() const { return r - l; }\n    };\n    class ConstOutgoingEdges\
    \ {\n        const Graph *g;\n        int l, r;\n\n      public:\n        ConstOutgoingEdges(const\
    \ Graph *g, int l, int r) : g(g), l(l), r(r) {}\n        const edge_type *begin()\
    \ const { return &(g->edges[l]); }\n        const edge_type *end() const { return\
    \ &(g->edges[r]); }\n        const edge_type &operator[](int i) const { return\
    \ g->edges[l + i]; }\n        int size() const { return r - l; }\n    };\n\n \
    \ public:\n    OutgoingEdges operator[](int v) {\n        assert(prepared);\n\
    \        return {this, in_deg[v], in_deg[v + 1]};\n    }\n    const ConstOutgoingEdges\
    \ operator[](int v) const {\n        assert(prepared);\n        return {this,\
    \ in_deg[v], in_deg[v + 1]};\n    }\n\n    bool is_prepared() const { return prepared;\
    \ }\n\n    Graph() : n(0), in_deg(1, 0), prepared(false) {}\n    Graph(int n)\
    \ : n(n), in_deg(n + 1, 0), prepared(false) {}\n    Graph(int n, int m, bool directed\
    \ = false, int indexed = 1)\n        : n(n), in_deg(n + 1, 0), prepared(false)\
    \ {\n        scan(m, directed, indexed);\n    }\n\n    void resize(int n) { n\
    \ = n; }\n\n    void add_arc(int from, int to) {\n        assert(!prepared);\n\
    \        assert(0 <= from and from < n and 0 <= to and to < n);\n        edges.emplace_back(from,\
    \ to);\n        in_deg[from + 1]++;\n    }\n    void add_edge(int u, int v) {\n\
    \        add_arc(u, v);\n        add_arc(v, u);\n    }\n    void add_arc(const\
    \ edge_type &e) { add_arc(e.from, e.to); }\n    void add_edge(const edge_type\
    \ &e) { add_edge(e.from, e.to); }\n\n    void scan(int m, bool directed = false,\
    \ int indexed = 1) {\n        edges.reserve(directed ? m : 2 * m);\n        while\
    \ (m--) {\n            int u, v;\n            cin >> u >> v;\n            u -=\
    \ indexed;\n            v -= indexed;\n            if (directed)\n           \
    \     add_arc(u, v);\n            else\n                add_edge(u, v);\n    \
    \    }\n        build();\n    }\n\n    void build() {\n        assert(!prepared);\n\
    \        prepared = true;\n        for (int v = 0; v < n; v++)\n            in_deg[v\
    \ + 1] += in_deg[v];\n        std::vector<edge_type> new_edges(in_deg.back());\n\
    \        auto counter = in_deg;\n        for (auto &&e : edges)\n            new_edges[counter[e.from]++]\
    \ = e;\n        edges = new_edges;\n    }\n\n    void graph_debug() const {\n\
    #ifndef __LOCAL\n        return;\n#endif\n        assert(prepared);\n        for\
    \ (int from = 0; from < n; from++) {\n            cerr << from << \";\";\n   \
    \         for (int i = in_deg[from]; i < in_deg[from + 1]; i++)\n            \
    \    cerr << edges[i].to << \" \";\n            cerr << \"\\n\";\n        }\n\
    \    }\n};\n#line 3 \"library/tree/Tree.cpp\"\nstruct Tree : Graph {\n    using\
    \ Graph::Graph;\n    Tree() = default;\n    int root = -1;\n    std::vector<int>\
    \ DFS, BFS, depth;\n\n    void scan_root(int indexed = 1) {\n        for (int\
    \ i = 1; i < n; i++) {\n            int p;\n            cin >> p;\n          \
    \  add_edge(p - indexed, i);\n        }\n        build();\n    }\n    void scan(int\
    \ indexed = 1) {\n        Graph::scan(n - 1, false, indexed);\n        build();\n\
    \    }\n\n    edge_type &parent(int v) {\n        assert(~root and root != v);\n\
    \        return (*this)[v][0];\n    }\n    OutgoingEdges son(int v) {\n      \
    \  assert(~root);\n        if (v == root)\n            return {this, in_deg[v],\
    \ in_deg[v + 1]};\n        return {this, in_deg[v] + 1, in_deg[v + 1]};\n    }\n\
    \n  private:\n    void dfs(int v, int pre = -1) {\n        for (auto &e : (*this)[v])\
    \ {\n            if (e.to == pre)\n                swap((*this)[v][0], e);\n \
    \           else {\n                depth[e.to] = depth[v] + 1;\n            \
    \    dfs(e.to, v);\n            }\n        }\n        DFS.push_back(v);\n    }\n\
    \n  public:\n    void build(int r = 0) {\n        if (!is_prepared())\n      \
    \      Graph::build();\n        if (~root) {\n            assert(r == root);\n\
    \            return;\n        }\n        root = r;\n        depth = vector<int>(n,\
    \ 0);\n        DFS.reserve(n);\n        BFS.reserve(n);\n        dfs(root);\n\
    \        queue<int> que;\n        que.push(root);\n        while (que.size())\
    \ {\n            int p = que.front();\n            que.pop();\n            BFS.push_back(p);\n\
    \            for (const auto &e : son(p))\n                que.push(e.to);\n \
    \       }\n    }\n};\n#line 7 \"test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp\"\
    \n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \n    int n;\n    cin >> n;\n    Tree t(n);\n    t.scan_root(0);\n\n    auto [k,\
    \ hsh] = rooted_tree_isomorphism(t);\n    std::cout << k << \"\\n\";\n    for\
    \ (int p : hsh)\n        std::cout << p << \" \";\n    std::cout << \"\\n\";\n\
    }\n"
  code: "#define PROBLEM                                                         \
    \       \\\n    \"https://judge.yosupo.jp/problem/rooted_tree_isomorphism_classification\"\
    \n#include <bits/stdc++.h>\n\n#include \"library/tree/RootedTreeIsomorphism.cpp\"\
    \n#include \"library/tree/Tree.cpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int n;\n    cin >> n;\n    Tree t(n);\n   \
    \ t.scan_root(0);\n\n    auto [k, hsh] = rooted_tree_isomorphism(t);\n    std::cout\
    \ << k << \"\\n\";\n    for (int p : hsh)\n        std::cout << p << \" \";\n\
    \    std::cout << \"\\n\";\n}"
  dependsOn:
  - library/tree/RootedTreeIsomorphism.cpp
  - library/tree/Tree.cpp
  - library/graph/Graph.cpp
  isVerificationFile: true
  path: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
  requiredBy: []
  timestamp: '2024-04-13 17:39:36+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
layout: document
redirect_from:
- /verify/test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
- /verify/test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp.html
title: test/library-checker/Tree/RootedTreeIsomorphismClassification.test.cpp
---
