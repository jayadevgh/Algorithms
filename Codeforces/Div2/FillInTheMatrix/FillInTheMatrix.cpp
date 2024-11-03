#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> arr(n, vector<int>(m, -1));
	vector<int> vec2(m);
	iota(vec2.begin(), vec2.end(), 0);
	for(int i =0;i < min(n, m-1); i++){
		rotate(vec2.begin(), vec2.begin()+vec2.size()-1, vec2.end());
		arr[i] = vec2;
		
	}
	for(int i = min(n, m-1); i < n; i++){
		arr[i] = vec2;
	}
	int ans = min(n+1, m);
	if(m == 1) ans = 0;
	cout << ans << "\n";
	for(vector<int> x : arr){
		for(int y : x) cout << y << " ";
		cout << "\n";
	}
	//cout << min(n, m);
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while(t--) solve();
}