#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
vector<vector<int>> arr;
vector<pair<ii, char>> edges;
// change adjency list to reference edge list only
//dfs tree
vector<bool> vis;
vector<pair<vector<int>, int>> dfsTree;
void dfs(int node, int parent){
	vis[node] = true;
	for(auto x : arr[node]){
		if(vis[x] && x != parent){
			dfsTree[x].second--;
			dfsTree[node].second++;
		}
		else if(!vis[x]){
			dfsTree[node].first.push_back(x);
			dfs(x, node);
		}
	}
}

//marking cycle edges
void dfs2(int node){
	for(auto x: dfsTree[node].first){
		dfs2(x);
		dfsTree[node].second
	}
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  arr.resize(n+1, vector<int>());
  edges.resize(m);
  vis.resize(n+1, 0);
  for(int i =0; i < m; i++){
  	int a, b;
  	cin >> a >> b;
  	arr[a].push_back(b);
  	arr[b].push_back(a);
  	edges[i].first = make_pair(a, b);
  	edges[i].second = 'B';
  }

  //dfs tree
  for(int i = 1; i <= n; i++){
  	if(!vis[i]){
  		dfs(i, 0);
  	}
  }
}