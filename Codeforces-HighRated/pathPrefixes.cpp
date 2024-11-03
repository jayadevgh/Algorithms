// https://codeforces.com/contest/1714/problem/G

#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define iii pair<ll, ii>

using namespace std;
vector<iii> edge;
vector<vector<ll>> adj;
vector<ii> addTot;
vector<ll> dist;
vector<ll> ans;
vector<ll> diffs;
void dfsAdd(ll node, ll sum, ll diff){
	for(ll i =0;i < adj[node].size(); i++){
		ll newEdge = adj[node][i];
		ll newSum = sum + edge[newEdge].second.first;
		ll newDiff = diff + edge[newEdge].second.second;
		addTot[newEdge] = make_pair(newSum, newDiff);
		dfsAdd(newEdge, newSum, newDiff);
	}

}
// void dfsDist(ll node, ll dis){
// 	for(ll i =0;i < adj[node].size(); i++){
// 		ll newEdge = adj[node][i];
// 		dist[newEdge] = dis+1;
// 		dfsDist(newEdge, dis+1);
// 	}
// }

void dfsAlgo(ll node){
	diffs.push_back(addTot[node].second);
	if(node == 1) ans[1] = 0;


	else{
		ll idx = upper_bound(diffs.begin(), diffs.end(), addTot[node].first) - diffs.begin();
		ans[node] = idx-1;
	}
	for(ll i =0;i < adj[node].size(); i++){ dfsAlgo(adj[node][i]); }
	diffs.pop_back();


}

void solve(){
	ll n; cin >> n;
	adj.clear();
	adj.resize(n+1, vector<ll>());
	edge.clear();
	edge.resize(n+1);
	addTot.clear();
	addTot.resize(n+1);
	// dist.clear();
	// dist.resize(n+1);
	ans.clear();
	ans.resize(n+1);
	edge[1] = make_pair(0, make_pair(0, 0));
	for(ll i =2;i < n+1; i++){
		ll x, y, z;
		cin >> x >> y >> z;
		edge[i] = make_pair(x, make_pair(y, z));
		adj[x].push_back(i);
	}
	dfsAdd(1, 0, 0);
	// for(ii x : addTot) cout << x.first << " " << x.second << " | ";
	// cout << "\n";
	//dfsDist(1,0);
	// for(ll x : dist) cout << x << " | ";
	// cout << "\n";
	//vector<ll> xs;
	dfsAlgo(1);
	for(ll i = 2; i < n+1; i++) cout << ans[i] << " ";
	cout << "\n";


}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0;i < t; i++){
  	solve();
  }
}
