#include <iostream>  
#include <queue>
using namespace std;           
void solve()                       
{                       
	int N; 
	cin >> N;
	vector<vector<char>> grid;
	for(int i = 0; i < N; i++){
		string s;
		cin >> s;
		vector<char> v(s.begin(), s.end());
		grid.push_back(v);
	} 
	vector<vector<bool>> vis(N, vector<bool>(N,0));
	int ans = 0;
	for(int i = 0; i < N; i++){ 
		for(int j = 0; j < N; j++){ 
			if(vis[i][j]) continue;
			if(grid[i][j] == '*'){
				ans++;
				queue<pair<int, int>> q;
				q.push(make_pair(i,j));
				while(q.size() > 0){
					pair<int, int> p = q.front();
					q.pop();
					if(p.first >= N || p.first < 0 || p.second >= N || p.second < 0) continue;
					if(vis[p.first][p.second] || grid[p.first][p.second] == '.') continue;
					vis[p.first][p.second] = true;
					q.push(make_pair(p.first+1, p.second));
					q.push(make_pair(p.first, p.second-1));
					q.push(make_pair(p.first-1, p.second));
					q.push(make_pair(p.first, p.second+1));
				}
			}
		}
	}
	cout << ans;
}
                          
int main()                        
{                                     
	solve();                       
}   