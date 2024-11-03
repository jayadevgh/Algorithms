#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> arr;
int dp[300003], nums[300003];
void fun(int parent, int cur){
	dp[cur] = 0;
	nums[cur] = 1;
	int sum = 0;
	for(int i = 0; i < arr[cur].size(); i++){
		if(arr[cur][i] != parent){
			fun(cur, arr[cur][i]);
			nums[cur] += nums[arr[cur][i]];
			sum += dp[arr[cur][i]];
		}
	}
	for(int x : arr[cur]){
		if(x != parent){
			dp[cur] = max(dp[cur], (sum-dp[x])+nums[x]-1);
		}
	}
}

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> ar(n+1, vector<int>());
	arr = ar;
	for(int i =0 ; i < n-1; i++){
		int a, b;
		cin >> a >> b;
		arr[a].push_back(b);
		arr[b].push_back(a);
	}
	fun(0, 1);
	cout << dp[1] << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i = 0; i < t; i++) solve();
}