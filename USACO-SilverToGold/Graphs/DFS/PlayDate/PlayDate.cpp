#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<vector<pair<int, int>>> adj;
vector<bool> vis;
int x = 0;
void dfs(int node, int tar, int sum){
  //cout << "\n";
  vis[node] = true;
  for(int i = 0; i < adj[node].size(); i++){

    int nnode = adj[node][i].first;
     
    //cout << nnode << " " << sum + adj[node][i].second << "\n";
    if(nnode == tar) {sum += adj[node][i].second; x = sum; return;}
    if(!vis[nnode]) {
      dfs(nnode, tar, sum + adj[node][i].second);
    }
  }
  //return 0;
}
int main() {
  //Console
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cin >> N >> Q;
  // cout << "HI";
  adj.resize(N+1, vector<pair<int, int>>());
  vis.resize(N+1,0);
  for(int i = 1; i < N; i++){
    int a, b, w;
    cin >> a >> b >> w;
    adj[a].push_back(make_pair(b, w));
    adj[b].push_back(make_pair(a, w));
  }
  for(int i = 0; i < Q; i++){
    int p1, p2;
    cin >> p1 >> p2;
    dfs(p1, p2, 0);
    cout << x << "\n";
    fill(vis.begin(), vis.end(), 0);
    // for(bool x : vis){cout << x << " ";}
    // cout << '\n';
  }
}