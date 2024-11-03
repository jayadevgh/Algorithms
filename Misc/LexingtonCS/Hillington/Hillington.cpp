#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;



void solve(){
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n));
	vector<pair<int, pair<int, int>>> locs;
	vector<vector<int>> inc =grid;
	vector<vector<int>> dec = grid;
	vector<vector<bool>> visInc(n, vector<bool>(n, 0));
	vector<vector<bool>> visDec = visInc;
	for(int i =0;i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> grid[i][j];
			if(grid[i][j] > 0){
				locs.push_back(make_pair(grid[i][j], make_pair(i, j)));
				// visInc[i][j] = 1;
				// visDec[i][j] = 1;
			}
		}
	}
	sort(locs.begin(), locs.end());
	//vector<pair<int, ii>> locs2 = locs;
	// for(pair<int, ii> x : locs) cout << x.first << " ";
	// cout << "\n";
	queue<pair<int, ii>> q;
	int sub[] = {0, 1, 0, -1};
	int idx = locs.size()-2;
	q.push(locs[idx+1]);
	while(q.size() > 0){
		int curnum = q.front().first;
		ii f= q.front().second;
		dec[f.first][f.second] = curnum;
		while(idx >=0 && curnum-1 == locs[idx].first){
			q.push(locs[idx]);
			idx--;
		}
		q.pop();
		for(int i =0;i < 4; i++){
			int x = f.first + sub[i];
			int y = f.second + sub[(i+1)%4];
			if(x < n && x > -1 && y < n && y > -1 && !visDec[x][y]){
				q.push(make_pair(curnum-1, make_pair(x, y)));

			}

		}
		visDec[f.first][f.second] = true;

	}



	idx = 1;
	q.push(locs[0]);
	while(q.size() > 0){
		int curnum = q.front().first;
		ii f= q.front().second;
		inc[f.first][f.second] = curnum;
		while(idx < locs.size() && curnum+1 == locs[idx].first){
			q.push(locs[idx]);
			idx++;
		}
		q.pop();
		for(int i =0;i < 4; i++){
			int x = f.first + sub[i];
			int y = f.second + sub[(i+1)%4];
			if(x < n && x > -1 && y < n && y > -1 && !visInc[x][y]){
				q.push(make_pair(curnum+1, make_pair(x, y)));

			}

		}
		visInc[f.first][f.second] = true;

	}
	//cout << idx << "\n";
	for(int i =0;i < n; i ++){
		for(int j = 0; j < n; j++){
			cout << dec[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	for(int i =0;i < n; i ++){
		for(int j = 0; j < n; j++){
			cout << inc[i][j] << " ";
		}
		cout << "\n";
	}
		cout << "\n\n";
	// for(int i =0;i < n; i ++){
	// 	for(int j = 0; j < n; j++){
	// 		cout << (inc[i][j] == dec[i][j] ? inc[i][j] : 0) << " ";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";



}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0;i < t; i++) solve();
}