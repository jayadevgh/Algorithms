#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> arr(101);
	for(int i =0; i < n; i++){
		int x; cin >> x;
		arr[x]++;
	}
	bool ans = true;
	for(int i = 1;i < 101; i++){
		if(arr[i] > arr[i-1]){ans = false; break;};
	}
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++) solve();
}
