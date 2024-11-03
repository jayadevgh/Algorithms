#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> groupidx;
//vector<set<int>> groups;
string cowtype;
vector<vector<int>> adj;
vector<bool> vis;

void dfs(int num, int gidx){
	if(vis[num]) return;
	vis[num] = true;
	groupidx[num] = gidx;
	for(int i = 0; i < adj[num].size(); i++){
		if(cowtype[num] == cowtype[adj[num][i]]){
			dfs(adj[num][i], gidx);
		}
	}
}

int main() {
	//Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	freopen("milkvisits.in", "r", stdin);
	freopen("milkvisits.out", "w", stdout);
  	cin >> N >> M;

  	cin >> cowtype;

  	adj = vector<vector<int>>(N, vector<int>());
  	vis = vector<bool>(N);
  	groupidx = vector<int>(N, 0);
  	for(int i =0;i < N-1; i++){
  		int a, b;
  		cin >> a >> b;
  		a--; b--;
  		adj[a].push_back(b);
  		adj[b].push_back(a);
  	}

  	// for(vector<int> a : adj){
  	// 	for(int b: a){
  	// 		cout << b << " ";
  	// 	}
  	// 	cout << "\n";

  	// }
  	// cout << "\n";
  	int gsetter =0;
  	for(int i =0; i < N; i++){
  		if(!vis[i]){ 
  			dfs(i, gsetter);
  			gsetter++;
  		}
  	}

  	// for(int i : groupidx) cout << i << " ";
  	// cout << "\n";

  	for(int i =0; i < M; i++){
  		int a, b;
  		cin >> a >> b;
  		a--;
  		b--;
  		char c;
  		cin >> c;
  		if(cowtype[a] == c || groupidx[a] != groupidx[b]) cout << 1;
  		else cout << 0;
  	}

}