#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int k, n;
	cin >> n >> k;
	vector<int> arr(n);
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	int s = arr[0];
	int e = arr[n-1];
	int scount = 0;
	int ecount = 0;
	string ans = "NO";
	for(int i =0; i < n; i++){
		if(scount < k && arr[i] == s) scount++;
		else if(scount == k && e == s) {ans = "YES"; break;}
		else if(ecount == k) {ans = "YES"; break;}
		else if(scount == k && arr[i] == e) ecount++;
	}
	if(scount == k && e == s) ans = "YES";
	if(ecount == k) ans = "YES";
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) solve();
}