#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll N, A, B;
vector<pair<ll, string>> v;
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> A >>B;
  v.resize(N);
  for(ll i = 0; i < N; i++){
  	ll a; string s;
  	cin >> s >> a;
  	v[i] = make_pair(a ,s); 
  }
  sort(v.begin(), v.end());
  pair<ll, string> cur = v[0];

  string fbound = v[0].second;
  vector<ll> bounds;
  for(ll i = 0; i < N; i++){
  	if(v[i].second != cur.second){
  		ll mid = (cur.first + v[i].first)/2;
  		if(cur.second == "NS" && (cur.first + v[i].first) % 2 == 0) mid--;
  		bounds.push_back(mid);
  	}
  	cur = v[i];
  }
  if(bounds[bounds.size()-1] != B) bounds.push_back(B);
  ll ans = (fbound == "S") ? bounds[0] - A +1: 0;
  for(ll i = (fbound == "S") + 1; i < bounds.size(); i+= 2){
  	ans += bounds[i] - bounds[i-1];
  }

  // for(ll i : bounds){
  // 	cout << i << "\n";
  // }
  cout << ans;
}