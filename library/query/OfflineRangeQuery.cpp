#include <vector>

class OfflineRangeQuery {
    size_t n, cnt;

    void add_query(size_t b_l, size_t b_r, size_t l, size_t r) {
        if (b_r < l || r < b_l)
            return;
        if (l <= b_l and b_r <= r) {
            querys[b_r].first.push_back(cnt);
            querys[b_l].second.push_back(cnt);
            return;
        }
        add_query(b_l, (b_l + b_r) >> 1, l, r);
        add_query((b_l + b_r) >> 1, b_r, l, r);
    }

  public:
    std::vector<std::pair<std::vector<size_t>, std::vector<size_t>>> querys;

    OfflineRangeQuery(size_t n_) : n(1), cnt(0), querys(n + 1) {
        while (n < n_)
            n <<= 1;
    }

    size_t add_query(size_t l, size_t r) {
        add_query(0, n, l, r);
        return cnt++;
    }
};