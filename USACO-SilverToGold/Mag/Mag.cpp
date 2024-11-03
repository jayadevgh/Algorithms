#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edges;
vector<int> val;
vector<bool> vis;
int temproot;
vector<vector<int>> temptre;
vector<int> marked;
void dfs1(int x, int par){
	vis[x] = true;
	if(val[x] == 1 && par != 1) temproot =x;
	if(val[x] == 1 && par == 1) temptre[par].push_back(x);
	for(int i =0;i < edges[x].size(); i++){
		int node = edges[x][i];
		if(node == par) continue;
		if(val[x] ==1 && val[node] != 1) continue;

		dfs1(node, x);
	}
}

void printer(int x){
	if(temptre.size() > 0) cout << x << " ";
	for(int i =0;i < temptre[x].size(); i++){
		printer(temptre[x][i]);
	}	
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	int ans = INT_MAX;
	vector<vector<int>> edge(n+1, vector<int>());
	edges = edge;
	for(int i =0;i < n-1; i++){
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
		
	}
	
	vector<int> values(n+1);
	vector<bool> visa(n+1, 0);
	vis = visa;
	val = values;
	temptre.resize(n, vector<int>());
	for(int i =0;i < n; i++){
		cin >> val[i+1];
		ans = min(val[i+1], ans);
	}
	if(ans ==1){
		for(int i =1;i < n+1; i++){
			if(!vis[i])dfs1(i, -1);
			printer(i);
			cout << "\n";
			temptre.clear();
		}

	}
}
