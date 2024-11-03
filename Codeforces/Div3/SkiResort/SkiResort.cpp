#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> arr;
	for(int i =0 ; i < n; i++){
		int var;
		cin >> var;
		arr.push_back(var);
	}
	int ans = 0;
	arr.push_back(q+1);
	int count = 0;
	for(int i = 0; i < n+1; i++){
		if(arr[i] <= q) count++;
		else{
			if(count >=k){
				ans += (count-k+1) * (count-k+2)/2;
			}
			count = 0;
		}
	}
	cout << ans << '\n';
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i = 0; i < t; i++) solve();
}