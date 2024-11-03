#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> arr(n);
	vector<int> arr2;
	for(int i =0;i < n; i ++) cin >> arr[i];
	arr2 = arr;
	sort(arr2.begin(), arr2.end());

	int count = n-1;
	while(count >= 0 && arr2[count] == arr[count] ) count--;
	if(count < 0) cout << 0 << "\n";
	else cout << arr2[count] << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) solve();
}