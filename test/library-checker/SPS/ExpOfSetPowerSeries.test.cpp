#define PROBLEM "https://judge.yosupo.jp/problem/exp_of_set_power_series"
#include <bits/stdc++.h>
using namespace std;

#include <atcoder/modint>
#include <atcoder/convolution>
using namespace atcoder;
using mint = modint998244353;
namespace atcoder
{
  ostream &operator<<(ostream &os, mint a)
  {
    os << a.val();
    return os;
  }
  istream &operator>>(istream &is, mint &a)
  {
    long long b;
    is >> b;
    a = b;
    return is;
  }
}

#include "library/setpowerseries/Compose.cpp"
using SPS = SetPowerSeries<mint>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  std::cin >> n;

  SPS b(1 << n);
  for (auto &x : b)
    std::cin >> x;

  SPS c = exp(b);
  for (auto &x : c)
    std::cout << x << " ";
  std::cout << endl;
}