#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <bits/stdc++.h>
using namespace std;

#include "segtree/SegmentTree.cpp"
#include "algebra/group/Add.cpp"

using ll=long long;
using G=GroupAdd<ll>;

int main(){
  int n,q;cin>>n>>q;
  vector<ll> v(n);
  for(int i=0;i<n;i++)cin>>v[i];
  SegmentTree<G> seg(v);
  while(q--){
    int t,l,r;cin>>t>>l>>r;
    if(t)cout<<seg.prod(l,r)<<"\n";
    else seg.multiply(l,r);
  }
}