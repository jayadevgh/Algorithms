#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	int n, k, b;
	cin >> n >> k >> b;
	vector<int> arr(n+1, 0);
	for (int i = 0; i < b; ++i){
		int x;
		cin >> x;
		arr[x] = 1;
	}
	for(int i =0; i < n+1; i++){
		arr[i] += arr[i-1];
	}
	int ans = INT_MAX;
	for(int i = k;i <= n; i++){
		ans = min(ans, arr[i] - arr[i-k]);
	}	
  	cout << ans;
  	
}