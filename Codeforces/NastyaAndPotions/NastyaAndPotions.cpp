#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N, K;
vector<ll> cost;
vector<vector<ll>> mixes;
vector<bool> vis;
ll dfs(ll idx){
	//if(mixes[idx].size() == 0){vis[idx] = true; return cost[idx];}
	//cout << vis[idx];
	if(vis[idx] == true) return cost[idx];
	if(mixes[idx].size() == 0) {vis[idx] = true; return cost[idx];}
	ll tot = 0;
	for(ll i =0; i< mixes[idx].size(); i++){
		tot += dfs(mixes[idx][i]);
	}
	//cout << idx <<" " << tot << ", ";
	cost[idx] = min(cost[idx], tot);
	vis[idx] = true;
	return cost[idx];
}


void solve(){
	ll n, k;
	cin >> n >> k;
	N = n; K = k;
	vector<ll> costs(n);
	vector<bool>viss(n, 0);
	vis = viss;
	for(ll i =0; i < n; i++){
		cin >> costs[i];
	}

	for(ll i = 0; i < k; i++){
		ll x;
		cin >> x;
		costs[x-1] = 0;
		vis[x-1] = true;
	}
	cost = costs;
	vector<vector<ll>> mix(n, vector<ll>());
	for(ll i =0; i< n; i++){
		ll m; cin >> m;
		for(ll j = 0; j < m; j++){
			ll x; cin >>x;
			mix[i].push_back(x-1);
		}
	}
	mixes = mix;
	for(ll i =0 ; i < n; i++){
		if(vis[i] == false) dfs(i);
	}
	//cout << "\n";
	for(ll x : cost){
		cout << x << " ";
	}
	cout << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  for(ll i =0 ; i < t; i++) solve();
}