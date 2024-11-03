#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> arr;
	vector<int> sortarr;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sortarr = arr;
	sort(sortarr.begin(), sortarr.end());
	bool flag = true;
	for(int i =0; i < n; i++){
		if(sortarr[i]%2 != arr[i]%2) flag = false;
	}
	if(flag) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) solve();
}
