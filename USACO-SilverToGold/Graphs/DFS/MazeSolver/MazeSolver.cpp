#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int M, N;
vector<vector<char>> grid;
vector<vector<bool>> vis;
string ans = "";
// void init_code(){
//     ios::sync_with_stdio(false);
//   	cin.tie(nullptr);
//     #ifndef ONLINE_JUDGE
//     freopen("cp.in", "r", stdin);
//     freopen("cp.out", "w", stdout);
//     #endif 
// }
void dfs(int x, int y, string path){
	if(x < 0 || y < 0 || x >= N || y >= M) return;
	if(vis[x][y] || grid[x][y] == '#') return;
	vis[x][y] = true;
	if(ans != "") return;
	if(grid[x][y] == 'F') {ans = path; return;}
	dfs(x+1, y, path + "D"); 
	dfs(x-1, y, path + "U");
	dfs(x, y-1, path + "L");
	dfs(x, y+1, path + "R");
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> M;
  int inix, iniy;
  vis.resize(N, vector<bool>(M));
  for(int i =0; i < N; i++){
  	string line;
  	cin >> line;
  	vector<char> v(line.begin(), line.end());
  	for(int j = 0; j < M; j++){
  		if(v[j] == 'S'){
  			inix = i; iniy = j;
  		}
  	}
  	grid.push_back(v);
  }
  dfs(inix, iniy, "");
  cout << ans;
}