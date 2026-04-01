#define PROBLEM "https://judge.yosupo.jp/problem/min_cost_b_flow"
#define IGNORE
#include <bits/stdc++.h>

using ll = long long;
using i128 = __int128_t;

struct InputEdge {
    int s, t;
    ll lower, upper, cost;
};

struct ConstraintEdge {
    int from, to;
    ll weight;
};

class MinCostFlow {
    struct Edge {
        int to, rev;
        ll cap, cost;
    };

  public:
    struct ArcRef {
        int v, idx;
        ll cap0;
    };

  private:
    int n;
    std::vector<std::vector<Edge>> g;

  public:
    explicit MinCostFlow(int n) : n(n), g(n) {}

    ArcRef add_arc(int from, int to, ll cap, ll cost) {
        int rf = (int)g[from].size();
        int rr = (int)g[to].size();
        g[from].push_back({to, rr, cap, cost});
        g[to].push_back({from, rf, 0, -cost});
        return {from, rf, cap};
    }

    std::pair<ll, i128> flow(int s, int t, ll maxf) {
        const ll INF = (1LL << 62);
        std::vector<ll> h(n, 0), dist(n);
        std::vector<int> pv(n), pe(n);

        // Initial potential with Bellman-Ford to handle negative costs.
        std::fill(dist.begin(), dist.end(), INF);
        dist[s] = 0;
        for (int iter = 0; iter < n - 1; iter++) {
            bool updated = false;
            for (int v = 0; v < n; v++) {
                if (dist[v] == INF)
                    continue;
                for (const auto &e : g[v]) {
                    if (e.cap == 0)
                        continue;
                    if (dist[e.to] > dist[v] + e.cost) {
                        dist[e.to] = dist[v] + e.cost;
                        updated = true;
                    }
                }
            }
            if (!updated)
                break;
        }
        for (int v = 0; v < n; v++)
            if (dist[v] < INF)
                h[v] = dist[v];

        ll sent = 0;
        i128 cost = 0;
        while (sent < maxf) {
            std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>,
                                std::greater<std::pair<ll, int>>>
                pq;
            std::fill(dist.begin(), dist.end(), INF);
            dist[s] = 0;
            pq.emplace(0, s);
            while (!pq.empty()) {
                auto [d, v] = pq.top();
                pq.pop();
                if (dist[v] != d)
                    continue;
                for (int i = 0; i < (int)g[v].size(); i++) {
                    const auto &e = g[v][i];
                    if (e.cap == 0)
                        continue;
                    ll nd = d + e.cost + h[v] - h[e.to];
                    if (dist[e.to] > nd) {
                        dist[e.to] = nd;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        pq.emplace(nd, e.to);
                    }
                }
            }
            if (dist[t] == INF)
                break;
            for (int v = 0; v < n; v++)
                if (dist[v] < INF)
                    h[v] += dist[v];

            ll addf = maxf - sent;
            for (int v = t; v != s; v = pv[v])
                addf = std::min(addf, g[pv[v]][pe[v]].cap);
            for (int v = t; v != s; v = pv[v]) {
                auto &e = g[pv[v]][pe[v]];
                auto &r = g[e.to][e.rev];
                e.cap -= addf;
                r.cap += addf;
            }
            sent += addf;
            cost += i128(addf) * i128(h[t] - h[s]);
        }
        return {sent, cost};
    }

    ll used(const ArcRef &ref) const { return ref.cap0 - g[ref.v][ref.idx].cap; }
};

std::string to_string_i128(i128 x) {
    if (x == 0)
        return "0";
    bool neg = (x < 0);
    if (neg)
        x = -x;
    std::string s;
    while (x > 0) {
        s.push_back(char('0' + (x % 10)));
        x /= 10;
    }
    if (neg)
        s.push_back('-');
    std::reverse(s.begin(), s.end());
    return s;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<ll> b(n);
    for (int i = 0; i < n; i++)
        std::cin >> b[i];

    std::vector<InputEdge> edges(m);
    for (int i = 0; i < m; i++) {
        auto &e = edges[i];
        std::cin >> e.s >> e.t >> e.lower >> e.upper >> e.cost;
    }

    std::vector<ll> demand = b;
    i128 lower_cost_sum = 0;
    for (const auto &e : edges) {
        demand[e.s] -= e.lower;
        demand[e.t] += e.lower;
        lower_cost_sum += i128(e.lower) * i128(e.cost);
    }

    ll pos_sum = 0, neg_sum = 0;
    for (int v = 0; v < n; v++) {
        if (demand[v] > 0)
            pos_sum += demand[v];
        if (demand[v] < 0)
            neg_sum -= demand[v];
    }
    if (pos_sum != neg_sum) {
        std::cout << "infeasible\n";
        return 0;
    }

    const int S = n, T = n + 1;
    MinCostFlow mcf(n + 2);

    std::vector<MinCostFlow::ArcRef> refs(m);
    for (int i = 0; i < m; i++) {
        const auto &e = edges[i];
        refs[i] = mcf.add_arc(e.s, e.t, e.upper - e.lower, e.cost);
    }
    for (int v = 0; v < n; v++) {
        if (demand[v] > 0)
            mcf.add_arc(S, v, demand[v], 0);
        else if (demand[v] < 0)
            mcf.add_arc(v, T, -demand[v], 0);
    }

    auto [sent, shifted_cost] = mcf.flow(S, T, pos_sum);
    if (sent != pos_sum) {
        std::cout << "infeasible\n";
        return 0;
    }

    std::vector<ll> flow(m);
    for (int i = 0; i < m; i++)
        flow[i] = edges[i].lower + mcf.used(refs[i]);

    std::vector<ConstraintEdge> cons;
    cons.reserve(2 * m);
    for (int i = 0; i < m; i++) {
        const auto &e = edges[i];
        if (flow[i] > e.lower)
            cons.push_back({e.s, e.t, e.cost});
        if (flow[i] < e.upper)
            cons.push_back({e.t, e.s, -e.cost});
    }

    std::vector<ll> p(n, 0);
    for (int iter = 0; iter < n; iter++) {
        bool updated = false;
        for (const auto &e : cons) {
            if (p[e.to] > p[e.from] + e.weight) {
                p[e.to] = p[e.from] + e.weight;
                updated = true;
            }
        }
        if (!updated)
            break;
    }

    i128 ans = lower_cost_sum + i128(shifted_cost);
    std::cout << to_string_i128(ans) << '\n';
    for (int i = 0; i < n; i++)
        std::cout << p[i] << '\n';
    for (int i = 0; i < m; i++)
        std::cout << flow[i] << '\n';
}
