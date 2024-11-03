#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int> 
using namespace std;



int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
  	vector<vector<int>> grid(5000, vector<int>(5000,0));
  	//vector<vector<int>> tempgrid;
  	int cnt = 0;
  	for(int i =0;i < N; i++){
  		int a, b;
  		cin >> a >> b;
  		a += 2500;
  		b += 2500;
  		if(grid[a][b] == -1) cnt--;
  		grid[a][b] = 1;
  		//if(grid[a][b-1] > 0)grid[a][b-1]++;
  		queue<ii> q;
  		q.push(make_pair(a, b));
  		if(grid[a+1][b] != 0) q.push(make_pair(a+1, b));
		if(grid[a-1][b] != 0) q.push(make_pair(a-1, b));
		if(grid[a][b+1] != 0) q.push(make_pair(a, b+1));
		if(grid[a][b-1] != 0) q.push(make_pair(a, b-1));
  		//tempgrid = grid;
  		while(!q.empty()){
  			ii p = q.front();
  			q.pop();
  			int x = p.first;
  			int y = p.second;
  			int cntzero = 0;
  			int check = 0;
  			if(grid[x+1][y] == 0){ check=1; cntzero++;}
  			if(grid[x-1][y] == 0){ check=2; cntzero++;}
  			if(grid[x][y+1] == 0){ check=3; cntzero++;}
  			if(grid[x][y-1] == 0){ check=4; cntzero++;}
  			if(cntzero == 1){
  				cnt++;
  				int s, r;
  				if(check == 1) {
  					grid[x+1][y] = -1;
  					s = x+1;
  					r = y;
  				}
  				if(check == 2) {
  					grid[x-1][y] = -1;
  					s = x-1;
  					r = y;
  				}
  				if(check == 3) {
  					grid[x][y+1] = -1;
  					s = x;
  					r = y+1;
  				}
  				if(check == 4) {
  					grid[x][y-1] = -1;
  					s = x;
  					r = y-1;
  				}
  				q.push(make_pair(s, r));
  				if(grid[s+1][r] != 0) q.push(make_pair(s+1, r));
				if(grid[s-1][r] != 0) q.push(make_pair(s-1, r));
				if(grid[s][r+1] != 0) q.push(make_pair(s, r+1));
				if(grid[s][r-1] != 0) q.push(make_pair(s, r-1));
  			}
  		}
  		cout << cnt << "\n";
  	}
  	// for(int i = 930; i < 1100; i++){
  	// 	for(int j = 930; j < 1100; j++){
  	// 		int bla = (grid[i][j] > -1) ? grid[i][j] : (grid[i][j] + 3);
  	// 		cout << bla << "";
  	// 	}
  	// 	cout << "\n";
  	// }
}