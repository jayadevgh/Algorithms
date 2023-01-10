#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){
    ll n;
    cin >> n;
    vector<ll> vt(n);
    vector<ll> ans(n);
    ll maxs = 0; 
    ll maxs2 = 0;
    
    for(ll j = 0; j < n; j++){
      ll num;
      cin >> num;
      vt[j] = num;
      if (num <= maxs) maxs2 = max(maxs2, num);
      else {maxs2 = maxs; maxs = num;}
      
    }
    
    ll diff = maxs-maxs2; 
    for(ll j = 0; j < n; j++){
      if(vt[j] == maxs) ans[j] = diff;
      else ans[j] = vt[j] - maxs;
      cout << ans[j] << " ";
    }
    cout << "\n";
  }
}