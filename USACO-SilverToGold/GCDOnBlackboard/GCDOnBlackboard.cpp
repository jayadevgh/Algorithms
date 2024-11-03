#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sol(){
	int n; cin >> n;
	vector<int> blackboard(n);
	for(int i =0;i < n; i++) cin >> blackboard[i];

	vector<int> prefix(n+1);
	vector<int> suffix(n+1);
	prefix[0] =0;
	suffix[n] = 0;
	for(int i =1; i < n+1; i++) {
		prefix[i] = gcd(prefix[i-1], blackboard[i-1]);
	}
	for(int i =n-1; i >=0; i--) {
		suffix[i] = gcd(suffix[i+1], blackboard[i]);
	}
	int ans = 0;
	for(int i =0; i < n; i++){
		ans = max(ans, gcd(prefix[i], suffix[i+1]));
	}
	cout << ans << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	
  	int t = 1;
  	//cin >> t;
  	for(int i = 0;i < t; i++){
  		sol();
  	}
}