#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, m;
vector<vector<pair<int, int>>>g;
vector<int> p;
vector<int> comp;

void dfs(int u, int c, int minw){
  comp[u] = c;
  for(auto v : g[u]){
    if(comp[v.first] == 0 && v.second >= minw){
      dfs(v.first, c, minw);
    }
  }
}

bool valid(int minw){
  comp.clear();
  comp.resize(n);
  int c = 0;
  for(int i = 0; i < n; i++){
    if (comp[i] == 0){
      c++;
      dfs(i, c, minw);
    }
  }
  for(int i = 0; i < n; i++){
    if(comp[i] != comp[p[i]]) return false;
  }
  return true;
}
int main() {
  freopen("wormhole.in","r",stdin);
	freopen("wormhole.out","w",stdout);
  cin >> n >> m;
  p.resize(m);
  g.resize(n);

  for(int i = 0; i < n; i++){
    cin >> p[i];
    p[i]--;
  }
  for(int i = 0; i < m; i++){
    int a, b, w;
    cin >> a >> b >> w;
    g[a].push_back({b, w});
    g[b].push_back({a, w});
  }
  int l = 0;
  int r = 1'000'000'001;
  while(l+1 < r){
    int mid = (l+r)/2;
    if(valid(mid)){
      l= mid;
    }
    else{
      r = mid;
    }
  }
  cout << l;
}