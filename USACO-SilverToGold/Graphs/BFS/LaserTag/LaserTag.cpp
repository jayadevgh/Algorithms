#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
#define iic pair<pair<int, int>, char>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int W, H;
  cin >> W >> H;
  vector<vector<char>> grid(W, vector<char>(H));
  vector<vector<bool>> vis(W, vector<bool>(H, 0));
  vector<vector<int>> ans(W, vector<int>(H, INT_MAX));
  ii start= {-1, -1}; ii end;
  for(int i = 0; i < W; i++){ 
  	for(int j = 0; j < H; j++){ 
  		cin >> grid[i][j];
  		if(grid[i][j] == 'C'){
  			if(start.first == -1) start = make_pair(i, j);
  			else end = make_pair(i, j);
  		}
  	}
  }
  queue<iic> q;
  q.push(make_pair(start, 'U'));
  ans[start.first][start.second] = 0;
  iic prevnode;

  while(q.size() > 0){
  	iic node = q.front();
    int x = node.first.first; int y = node.first.second;
    bool bounds = (x >= 0 && x < N && y >= 0 && y < N);
    q.pop();
    if(node.first == start){
      if(bounds) ans[x+1][y] = 0;
      if(bounds) ans[x-1][y] = 0;
      if(bounds) ans[x][y+1] = 0;
      if(bounds) ans[x][y-1] = 0;
      if(bounds) q.push(make_pair(make_pair(x+1,y),'R'));
      if(bounds) q.push(make_pair(make_pair(x-1,y),'L'));
      if(bounds) q.push(make_pair(make_pair(x,y+1),'D'));
      if(bounds) q.push(make_pair(make_pair(x,y-1),'U'));
    }
    else{ 
      if(bounds) q.push(make_pair(make_pair(x+1,y),'R'));
      if(bounds) q.push(make_pair(make_pair(x-1,y),'L'));
      if(bounds) q.push(make_pair(make_pair(x,y+1),'D'));
      if(bounds) q.push(make_pair(make_pair(x,y-1),'U'));
    }
  }
}