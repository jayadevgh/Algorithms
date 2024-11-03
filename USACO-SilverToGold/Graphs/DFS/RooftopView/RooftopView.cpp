#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int W, H;
vector<vector<char>> grid;
vector<vector<bool>> vis;
int val = 0;
int ans = 0;
void dfs(int x, int y){
	if(x < 0 || x >= H || y < 0 || y >= W) return;
	if(vis[x][y] || grid[x][y] == '.') return;
	val++;
	vis[x][y] = true;
	//cout << x << " " << y << "\n";
	dfs(x+1, y);
	dfs(x-1, y);
	dfs(x, y+1);
	dfs(x, y-1);
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> W >> H;
  for(int i = 0; i < H; i++){
  	string line;
  	cin >> line;
  	vector<char> v(line.begin(), line.end());
  	grid.push_back(v);
  }
  vis.resize(H, vector<bool>(W));
  for(int i = 0; i < H; i++){
  	for(int j = 0; j < W; j++){
  		if(!vis[i][j] && grid[i][j] == '*'){ 
  			dfs(i, j);
  			ans = max(ans, val);
  			val = 0;
  		}
  	}
  }
  cout << ans;
}
