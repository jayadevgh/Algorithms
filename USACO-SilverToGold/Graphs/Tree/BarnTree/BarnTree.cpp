#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>
#define iii pair<ll, pair<ll, ll>>

using namespace std;
ll n;
vector<ll> w;
vector<vector<ll>> adj;
vector<vector<ll>> adj2;
vector<ii> sumNum;
vector<bool> vis;
vector<iii> ans;
ll tar;

void adjes(int parent, int node){
	//cout << node << " ";
	for(int i = 0; i < adj2[node].size();i++){

		if(adj2[node][i] != parent) {
			adjes(node, adj2[node][i]);
			adj[node].push_back(adj2[node][i]);
		}
	}

}


ii sumNums(ll node){
	sumNum[node] = make_pair(1, w[node]);
	for(ll i =0;i < adj[node].size(); i++){
		ii subTree = sumNums(adj[node][i]);
		sumNum[node].first += subTree.first;
		sumNum[node].second += subTree.second;
	}
	return sumNum[node];
}

void dfs(ll node){
	if(sumNum[node].first == 1){
		//sumNum[node].second = tar;
		w[node] = tar;
		return;
	}

	else{
		for(ll i = 0;i < adj[node].size(); i++){
			ii p = sumNum[adj[node][i]];
			if(p.second > tar*p.first){
				w[node] += (p.second - tar*p.first);
				dfs(adj[node][i]);
				w[adj[node][i]] = tar;
				//cout << sumNum[adj[node][i]].second << " ";
				ans.push_back(make_pair(adj[node][i] ,make_pair( node , p.second - tar*p.first)));
				

				vis[adj[node][i]] = true;
			}
		}

		for(ll i = 0;i < adj[node].size(); i++){
			ii p = sumNum[adj[node][i]];
			if(p.second <= tar*p.first && !vis[adj[node][i]]){
				w[node] -= (p.first *tar - p.second);
				w[adj[node][i]] += (p.first *tar - p.second);
				sumNum[adj[node][i]].second = p.first * tar;
				if(tar*p.first-p.second != 0)ans.push_back(make_pair(node ,make_pair( adj[node][i] , tar*p.first - p.second)));
				dfs(adj[node][i]);
				
			}
		}
	}
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	w.resize(n+1);
	for(ll i =0;i < n; i++) cin >> w[i+1];
	adj.resize(n+1, vector<ll>());
	adj2.resize(n+1, vector<ll>());
	vis.resize(n+1);
	for(ll i =0;i < n-1; i++) {
		ll a, b; cin >> a >> b;
		adj2[a].push_back(b);
		adj2[b].push_back(a);
	}
	adj[1] = adj2[1];		
	for(int i = 0; i < adj2[1].size(); i++){
		adjes(1, adj2[1][i]);
	}
	//for(int i =0;i < adj2[1713].size(); i++) cout<<adj2[1713][i] << " ";
	//cout << "\n";
	// edge.resize(n+1, vector<ll>());
	// for(ll i =0;i < adj[1].size(); i++){
	// 	edge[1].push_back(adj[1][i]);
	// 	makeEdge(1, adj[1][i]);
	// }

	sumNum.resize(n+1);
	sumNums(1);
	//for(ll i =0;i < n+1; i++) cout << sumNum[i].first << " " << sumNum[i].second << "\n";

	tar = sumNum[1].second / sumNum[1].first;
	dfs(1);
	// ll sum = 0;
	// for(ll i =0;i < n+1; i++)cout << w[i] << "\n" ;
	// for(ll i =0;i < n+1; i++)sum += w[i] ;
	// cout << sum;
	cout << ans.size() << "\n";
	for(iii x : ans) cout << x.first << " " << x.second.first << " " << x.second.second << "\n";

	
	


}