#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"
#include <bits/stdc++.h>
using namespace std;

#include "library/mod/Modint.cpp"
#include "library/convolution/NTT.cpp"

using mint = Mint<long long,998244353>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,m;cin>>n>>m;
  vector<mint> f(n),g(m);
  for(mint&p:f)cin>>p;
  for(mint&p:g)cin>>p;
  auto h = convolution(f,g);
  for(mint&p:h)cout<<p<<" ";cout<<endl;
}