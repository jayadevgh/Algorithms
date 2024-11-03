#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){

	int n;
	cin >> n;
	int mini = n;
	
	vector<int> arr(n);
	for(int i =0; i < n; i++) cin >> arr[i];
	int ans = 0;
	int minini = arr[0];
	for(int i = 1; i < n; i++){
		//cout << "HI";
		if(arr[i] > mini) continue;

		if(minini < arr[i]) {
			//cout << "HI";
			if(arr[i] <= mini) ans++;
			mini = min(mini, arr[i]);
		}else if(arr[i] < minini) minini = arr[i];
	}
	cout << ans << "\n";
}
int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	for(int i =0;i < t; i++){
		solve();
	}
}