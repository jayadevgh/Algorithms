#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n; cin >> n;
  vector<ll> lineOne;
  vector<ll> lineTwo;
  ll ans = 0;
  for(ll i =0;i < n; i++){
  	ll x, y;
  	cin >> x >> y;
  	if(y==1)lineOne.push_back(x);
  	else lineTwo.push_back(x);
  }
  sort(lineOne.begin(), lineOne.end());
  sort(lineTwo.begin(), lineTwo.end());

  //for(ll x : lineOne) cout << x << " ";
  //cout << "\n";
  //for(ll x : lineTwo) cout << x << " ";
  //cout << "\n";
  ans += 2*lineTwo.size();
  ll j = 0;
  for(ll i = 0; i < lineOne.size(); i++){
  	ll x = lineOne[i];
  	while((j < lineTwo.size()) && lineTwo[j] <= x) j++;
  	//ll zero = 1e9;
  	//cout << i+1 + 2*(lineTwo.size()-j) << " ";
  	if( ans < i+1 + 2*(lineTwo.size()-j)) ans = i+1 + 2*(lineTwo.size()-j);
  }
  cout << ans + (ll)1e9;
}