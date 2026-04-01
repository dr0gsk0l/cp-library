#pragma once
#include <cassert>
#include <cstddef>
#include <iostream>
#include <vector>
template <typename T> struct WeightedEdge {
    WeightedEdge() = default;
    WeightedEdge(int from, int to, T weight)
        : from(from), to(to), weight(weight) {}
    int from, to;
    T weight;
    operator int() const { return to; }
};

template <typename T> struct WeightedGraph {
    static std::size_t vertex_count(int n) {
        assert(n >= 0);
        return static_cast<std::size_t>(n);
    }

    std::size_t n;
    using weight_type = T;
    using edge_type = WeightedEdge<T>;
    std::vector<edge_type> edges;

  protected:
    std::vector<std::size_t> in_deg;
    bool prepared;
    class OutgoingEdges {
        WeightedGraph *g;
        std::size_t l, r;

      public:
        OutgoingEdges(WeightedGraph *g, std::size_t l, std::size_t r)
            : g(g), l(l), r(r) {}
        edge_type *begin() { return &(g->edges[l]); }
        edge_type *end() { return &(g->edges[r]); }
        edge_type &operator[](std::size_t i) { return g->edges[l + i]; }
        std::size_t size() const { return r - l; }
    };
    class ConstOutgoingEdges {
        const WeightedGraph *g;
        std::size_t l, r;

      public:
        ConstOutgoingEdges(const WeightedGraph *g, std::size_t l,
                           std::size_t r)
            : g(g), l(l), r(r) {}
        const edge_type *begin() const { return &(g->edges[l]); }
        const edge_type *end() const { return &(g->edges[r]); }
        const edge_type &operator[](std::size_t i) const {
            return g->edges[l + i];
        }
        std::size_t size() const { return r - l; }
    };

  public:
    OutgoingEdges operator[](int v) {
        assert(prepared);
        assert(0 <= v and static_cast<std::size_t>(v) < n);
        const auto vv = static_cast<std::size_t>(v);
        return {this, in_deg[vv], in_deg[vv + 1]};
    }
    const ConstOutgoingEdges operator[](int v) const {
        assert(prepared);
        assert(0 <= v and static_cast<std::size_t>(v) < n);
        const auto vv = static_cast<std::size_t>(v);
        return {this, in_deg[vv], in_deg[vv + 1]};
    }

    bool is_prepared() const { return prepared; }

    WeightedGraph() : n(0), in_deg(1, 0), prepared(false) {}
    WeightedGraph(int n)
        : n(vertex_count(n)), in_deg(this->n + 1, 0), prepared(false) {}
    WeightedGraph(int n, int m, bool directed = false, int indexed = 1)
        : n(vertex_count(n)), in_deg(this->n + 1, 0), prepared(false) {
        scan(m, directed, indexed);
    }

    void resize(std::size_t n_) {
        n = n_;
        in_deg.assign(n + 1, 0);
        edges.clear();
        prepared = false;
    }

    void add_arc(int from, int to, T weight) {
        assert(!prepared);
        assert(0 <= from and static_cast<std::size_t>(from) < n);
        assert(0 <= to and static_cast<std::size_t>(to) < n);
        edges.emplace_back(from, to, weight);
        in_deg[static_cast<std::size_t>(from) + 1]++;
    }
    void add_edge(int u, int v, T weight) {
        add_arc(u, v, weight);
        add_arc(v, u, weight);
    }
    void add_arc(const edge_type &e) { add_arc(e.from, e.to, e.weight); }
    void add_edge(const edge_type &e) { add_edge(e.from, e.to, e.weight); }

    void scan(int m, bool directed = false, int indexed = 1) {
        edges.reserve(static_cast<std::size_t>(directed ? m : 2 * m));
        while (m--) {
            int u, v;
            std::cin >> u >> v;
            u -= indexed;
            v -= indexed;
            T weight;
            std::cin >> weight;
            if (directed)
                add_arc(u, v, weight);
            else
                add_edge(u, v, weight);
        }
        build();
    }

    void build() {
        assert(!prepared);
        prepared = true;
        for (std::size_t v = 0; v < n; v++)
            in_deg[v + 1] += in_deg[v];
        std::vector<edge_type> new_edges(in_deg.back());
        auto counter = in_deg;
        for (auto &&e : edges)
            new_edges[counter[static_cast<std::size_t>(e.from)]++] = e;
        edges = new_edges;
    }

    void graph_debug() const {
#ifndef __DEBUG
        return;
#endif
        assert(prepared);
        for (std::size_t from = 0; from < n; from++) {
            std::cerr << from << ";";
            for (std::size_t i = in_deg[from]; i < in_deg[from + 1]; i++)
                std::cerr << "(" << edges[i].to << "," << edges[i].weight
                          << ")";
            std::cerr << "\n";
        }
    }
};
