#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i =0; i < n; i++) cin >> arr[i];

	int sum = 0;
	vector<int> sums(n);
	for(int i = n-1; i >= 0; i--) {
		sum += arr[i]; 
		sums[i] = sum;
	}
	int quo = sum / n;
	string ans = "YES";
	for(int i = n-1; i >= 0; i--) {
		if(sums[i] > (quo)*(n-i)) ans = "NO";
	}
	cout << ans << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t; 
  	for(int i =0;i < t; i++) solve();
}