#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
// dfs through tree to find the sum for each sub tree in a new tree

//can do in one: 
// then dfs from leaf to top for sub trees greater than needed sums 
// then dfs back down for sub trees less than needed sums and distribute
vector<vector<ll>> adj;
ll n;
ll root = 1;
vector<ll> parents;
vector<pair<ll, ll>> sums;
vector<ll> weights;
ll val;
vector<pair<pair<ll, ll>, ll>> ans;
//int iter = 0;

pair<ll, ll> dfssum(ll cur, ll parent){
	//iter++;
	ll sum = weights[cur];
	ll count = 1;
	for(ll i =0;i < adj[cur].size(); i++){
		if(adj[cur][i] != parent) {
			pair<ll, ll> p = dfssum(adj[cur][i], cur);
			sum += p.first;
			count += p.second;
		}
	}
	sums[cur].first = sum;
	sums[cur].second = count;
	return {sum, count};
}

void dfs(ll cur, ll parent){
	//iter++;
	for(ll i =0;i < adj[cur].size(); i++){

		ll child = adj[cur][i];
		if(child == parent) continue;
		//cout << 1 << " ";
		if(sums[child].first > sums[child].second * val){

			dfs(child, cur);
			weights[cur] += sums[child].first - sums[child].second * val;
			weights[child] -= sums[child].first - sums[child].second * val;
			ans.push_back({{child, cur}, sums[child].first - sums[child].second * val});
			//cout << child << " " << cur << " " << sums[child].first - sums[child].second * val<< "\n";
		}
		if(sums[child].first == sums[child].second * val)dfs(child, cur);
		// if(sums[child].first < sums[child].second * val){
		// 	q.push(child);
		// }
	}
	for(ll i =0;i < adj[cur].size(); i++){

		ll child = adj[cur][i];
		if(child == parent) continue;
		//cout << 1 << " ";
		
		if(sums[child].first < sums[child].second * val){
			// cout << "HI";
			ans.push_back({{cur, child}, sums[child].second * val-sums[child].first});
			//cout << cur << " " << child << " " << sums[child].second * val-sums[child].first<< "\n";
			weights[cur] -= sums[child].second * val-sums[child].first;
			weights[child] += sums[child].second * val-sums[child].first;
			dfs(child, cur);
		}
	}
}	
void solve(){
	//ll n;
	cin >> n;
	weights = vector<ll>(n+1);
	for(ll i =1;i < n+1; i++) cin >> weights[i];
	adj = vector<vector<ll>>(n+1, vector<ll>());
	for(ll i =0;i < n-1; i++){
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	parents = vector<ll>(n+1);
	sums = vector<pair<ll, ll>>(n+1);
	dfssum(root, 0);
	val = sums[root].first/n;
	// for(ll i =1;i < n+1; i++) cout << sums[i].first << " ";
	// cout << "\n";
	dfs(root, 0);
	//cout << iter << "\n";
	cout << ans.size() << "\n";
	for(pair<pair<ll, ll>, ll> i : ans){
		cout << i.first.first << " " << i.first.second << " " << i.second << "\n";
	}
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t =1;
  	while(t--){
  		solve();
  	}
}