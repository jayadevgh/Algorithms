// https://codeforces.com/contest/1133/problem/F1

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<bool> vis;
vector<int> deg;
vector<int> edges;
// struct DSU {
// 	vi e; void init(int N) { e = vi(N,-1); }
// 	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
// 	bool sameSet(int a, int b) { return get(a) == get(b); }
// 	int size(int x) { return -e[get(x)]; }
// 	bool unite(int x, int y) { // union by size
// 		x = get(x), y = get(y); if (x == y) return 0;
// 		if (e[x] > e[y]) swap(x,y);
// 		e[x] += e[y]; e[y] = x; return 1;
// 	}
// };

// void dfs(int node){
// 	//cout << node << " ";
// 	if(vis[node]) return;
// 	vis[node] = true;
// 	for(int i =0;i < adj[node].size(); i++){
// 		if(edges[adj[node][i]] == 0) edges[adj[node][i]] = node;
// 		dfs(adj[node][i]);
		
// 	}
// }
void bfs(int node){
  queue<int> q;
  q.push(node);
  vis[node] = true;
  while(q.size() != 0){
    int n = q.front();
    q.pop();
    
    for(int i =0;i < adj[n].size(); i++){
      if(!vis[adj[n][i]]){
        q.push(adj[n][i]);
        edges[adj[n][i]] = n;
        vis[adj[n][i]] = true;
      }
    }
  }
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> n >> m;
  adj.resize(n+1, vector<int>());
  vis.resize(n+1);
  deg.resize(n+1, 0);
  edges.resize(n+1, 0);
  for(int i= 0;i < m; i++){
  	int v, u;
  	cin >> v >> u;
  	adj[v].push_back(u);
  	adj[u].push_back(v);
  	deg[v]++;
  	deg[u]++;
  }
  int maxDeg = 1, maxi = deg[1];
  for(int i =2; i< n+1; i++){
    if(deg[i] > maxi){
      maxi = deg[i];
      maxDeg = i;
    }
  }
  bfs(maxDeg);
  for(int i = 1; i < n+1; i++){
    if(i != maxDeg) cout << i << " " << edges[i] << "\n";
  }
  

}