#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<bool> vis;
vector<vector<int>> adj;
vector<int> child;

void sumUp(int x){
	if(vis[x]) return;
	vis[x] = true;
	for(int y: adj[x]){
		if(!vis[y]){
			sumUp(y);
			child[x] += child[y];
		}
	}
}
void solve(){
	int n; cin >> n;
	vis.clear();
	adj.clear();
	child.clear();
	vis.resize(n+1, 0);

	adj.resize(n+1, vector<int>());
	child.resize(n+1, 0);
	for(int i =0; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	//queue<int> q;
	for(int i = 2; i <= n; i++){
		if(adj[i].size() ==1){
			//q.push(i);
			//cout << i << " ";
			child[i] = 1;
		}
	}
	//cout << "\n";
	sumUp(1);
	//for(int i = 1; i < n+1; i++){cout << child[i] << " ";}
	// for(int i = 1; i < n+1; i++){
	// 	for(int x : adj[i]){
	// 		cout << x << " ";
	// 	}
	// 	cout << "\n";
	// }
	//cout << "\n";
	int qu;
	cin >> qu;
	for(int i = 0; i <qu; i++){
		int a, b;
		cin >> a >> b;
		ll product = 1;
		product *= child[a];
		product *= child[b];
		cout << product << "\n";
	}
	
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for (int i = 0; i < t; ++i)
  {
  	solve();
  }
}