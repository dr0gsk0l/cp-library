#define PROBLEM "https://judge.yosupo.jp/problem/range_kth_smallest"
#include <bits/stdc++.h>
using namespace std;

#include "library/datastructure/WaveletMatrix.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n,q;cin>>n>>q;
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  WaveletMatrix<int> WM(v);
  while(q--){
    int l,r,k;cin>>l>>r>>k;
    cout<< WM.kth_smallest(l,r,k) <<"\n";
  }
}
