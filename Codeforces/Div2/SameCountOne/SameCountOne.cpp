#include <iostream>
#include <bits/stdc++.h>
#define iii pair<pair<int, int>, int>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m));
	vector<int> sums(n);
	int count = 0;
	for(int i = 0; i < n; i++){
		int sum = 0;
		for(int j = 0; j < m; j++){
			cin >> arr[i][j];	
			sum+= arr[i][j];
		}
		sums[i] = sum;
		count += sum;
	}
	//cout << count << " ";
	if(count %n){
		cout << -1 << "\n";
		return;
	}
	int sumPer = count/n;
	vector<int> lo, hi;
	int ans = 0;
	vector<iii> anss;
	for(int col =0; col < m; col++){

		for(int row = 0; row < n; row++){
			if(sums[row] < sumPer && arr[row][col] == 0) lo.push_back(row);
			if(sums[row] > sumPer && arr[row][col] == 1) hi.push_back(row);
		}
		for(int i =0; i < min(lo.size(), hi.size()); i++){
			//cout << col << " ";
			ans++;
			iii threeP;
			threeP.first.first = lo[i]+1;
			threeP.first.second = hi[i]+1;
			threeP.second= col+1;
			sums[lo[i]]++;
			sums[hi[i]]--;
			anss.push_back(threeP);
		}
		lo.clear();
		hi.clear();
	}
	cout << ans << "\n";
	for(iii x : anss){
		cout << x.first.first << " " << x.first.second << " " << x.second << "\n";
	}
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0 ; i < t; i++)solve();
  	

}