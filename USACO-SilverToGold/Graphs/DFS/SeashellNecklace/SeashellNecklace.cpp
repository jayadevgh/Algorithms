#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
vector<vector<char>> grid;
vector<vector<bool>> vis;
int ans = 0;
bool isSymmetric(string necklace){
	int x = necklace.size()-1;
	int i = 0;

	if(x %2 ==0 ) return false;
	

	while(i < necklace.size()/2){
		if(necklace[i] == '>' || necklace[x] == '<') return false;
		i++;
		x--;
	}
	return true;
}
void dfs(int x, int y, string necklace){
	if(x < 0 || x >= N || y < 0 || y >= N) return;
	if(vis[x][y]) return;
	necklace = necklace + grid[x][y];
	// test = test + to_string(x) + to_string(y);
	int slen = necklace.size();
	//cout << necklace << "\n"; 
	if(isSymmetric(necklace)) {ans = max(ans, slen); /*cout << necklace << "\n";*/}
	vis[x][y] = true;
	dfs(x+1, y, necklace);
	dfs(x-1, y, necklace);
	dfs(x, y+1, necklace);
	dfs(x, y-1, necklace);
	vis[x][y] = false;
}
int main() {
  //Console
  // ios::sync_with_stdio(false);
  // cin.tie(nullptr);
  cin >> N;
  for(int i = 0; i < N; i++){
  	string line;
  	cin >> line;
  	vector<char> v(line.begin(), line.end());
  	grid.push_back(v);
  }
  vis.resize(N, vector<bool>(N));
  dfs(0, 0, "");
  cout << ans;
}
