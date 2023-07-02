#define PROBLEM "https://yukicoder.me/problems/no/1036"
#include <bits/stdc++.h>
using namespace std;

#include "library/algebra/monoid/Gcd.cpp"
#include "library/datastructure/SWAG.cpp"

using ll=long long;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;cin>>n;

  SWAG<MonoidGcd<ll>> S;

  ll ans=ll(n)*ll(n+1)/2;
  while(n--){
    ll a;cin>>a;
    S.push_back(a);
    while(S.prod()==1)S.pop_front();
    ans-=S.size();
  }
  cout<<ans<<endl;
}
