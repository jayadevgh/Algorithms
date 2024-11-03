// https://codeforces.com/contest/1730/problem/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int mini = INT_MAX;
	int maxi = INT_MIN;
	int maxWei = INT_MIN;
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> weight(n);
	for(int i =0; i < n; i++) cin >> arr[i];
	for(int i =0; i < n; i++) {cin >> weight[i]; maxWei = max(weight[i], maxWei);}
	for(int i =0; i < n; i++){
		mini = min(mini, arr[i] - weight[i] + maxWei);
		maxi = max(maxi, arr[i] + weight[i] - maxWei);
	}
	double ans = (mini+maxi)/2 + (((mini+maxi) %2) ? 0.5 : 0.0);
	cout << fixed << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++) solve();
}