#include <iostream>
#include <bits/stdc++.h>
using namespace std;




void solve(){
	int n;
	cin >> n;
	//vector<vector<int>> holiday(3, vector<int> (n));
	vector<vector<pair<int, int>>> maxes(3, vector<pair<int, int>> (3, make_pair(0, 0)));
	priority_queue<int> 
	for(int i =0; i < 3; i++){
		for(int j =0; j < n; j++){
			int x;
			cin >> x;
			if(x > maxes[i][0].first){
				maxes[i][2] = maxes[i][1];
				maxes[i][1] = maxes[i][0];
				maxes[i][0] = make_pair(x, j);
			}
			else if(x > maxes[i][1].first){
				maxes[i][2] = maxes[i][1];
				maxes[i][1] = make_pair(x, j);
			}
			else if(x > maxes[i][2].first){
				maxes[i][2] = make_pair(x, j);
			}


		}
	}
	int ans = 0;
	for(int i= 0;i < 3; i++){
		for(int j =0; j < 3; j++){
			for(int k = 0; k < 3; k++){
				pair<int, int> p1 = maxes[0][i];
				pair<int, int> p2 = maxes[1][j];
				pair<int, int> p3 = maxes[2][k];
				if(p1.second == p2.second || p3.second == p2.second || p1.second == p3.second){
					continue;
				}
				ans = max(ans, p1.first + p2.first + p3.first);
			}
		}
	}
	cout << ans << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t;
  	while(t--) solve();
}