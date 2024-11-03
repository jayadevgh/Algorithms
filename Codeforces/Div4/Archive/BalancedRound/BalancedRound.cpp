#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, b;
	cin >> n >> b;
	vector<int> arr(n);
	for(int i =0; i < n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	// cout << b << "\n";
	// for(int x : arr) cout << x << " ";
	// cout << "\n";
	int idx = 0;
	int flen = 0;
	int prev = arr[0];
	for(int i =0; i < n; i++){
		if(abs(arr[i] - prev) > b){
			//cout << flen << " ";
			if(flen < i-idx) flen = (i)-idx;
			idx = i;
			//cout << idx << " ";
		}
		prev = arr[i];
	}
	//cout << flen << " ";
	if(flen < n-idx) flen = n-idx;
	cout << n-flen << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) solve();
}