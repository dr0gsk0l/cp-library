#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"
#include <bits/stdc++.h>
using namespace std;

#include "library/algebra/group/Add.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  using G=GroupAdd<long long>;

  int n,q;cin>>n>>q; 
  vector<long long> a(n);
  for(int i=0;i<n;i++)cin>>a[i];

  Tree t(n);
  t.scan_root(0);

  TreeMonoid<Tree,G> TM(t,a);

  while(q--){
    int c;cin>>c;
    if(c){
      int u;cin>>u;
      cout<< TM.subtree_prod(u) <<"\n";
    }
    else{
      int u,x;cin>>u>>x;
      TM.multiply(u,x);
    }
  }
}