#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"
#include <bits/stdc++.h>
using namespace std;

#include "library/algebra/group/Affine.cpp"
#include "library/tree/Tree.cpp"
#include "library/tree/TreeMonoid.cpp"
#include "library/mod/Modint.cpp"
using mint=Mint<long long>;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  using G=AlgebraReverse<GroupAffine<mint>>;
  using F=G::value_type;

  int n,q;cin>>n>>q; 

  vector<F> f(n);
  for(int i=0;i<n;i++)cin>>f[i];

  Tree t(n);
  t.scan(0);

  TreeMonoid<Tree,G> TM(t,f);

  while(q--){
    int c;cin>>c;
    if(c){
      int u,v,x;cin>>u>>v>>x;
      F g=TM.path_prod(u,v);
      cout<<g(x)<<endl;
    }
    else{
      int p;cin>>p;
      F f;cin>>f;
      TM.set(p,f);
    }
  }
}