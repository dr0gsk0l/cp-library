#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include <bits/stdc++.h>
using namespace std;

#include "library/graph/WeightedGraph.cpp"
#include "library/graph/MinimumSpanningTree.cpp"

int main(){
  int n,m;cin>>n>>m;
  WeightedGraph<int> g(n,m,false,0);
  auto [sum,tree]=minimum_spanning_tree(g);
  cout<<sum<<endl;
}