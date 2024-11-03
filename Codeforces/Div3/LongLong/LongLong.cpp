#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int>  arr(n);
	for(int i = 0; i< n; i++){
		cin >> arr[i];
	}
	ll sum = 0;
	int count = 0;
	int prev = 1;
	for(int i =0; i < n; i++){
		sum += abs(arr[i]);
		if(arr[i] > 0 && prev < 0) count++;
		if(arr[i] != 0) prev = arr[i];

	}
	if(prev < 0) count++;
	cout << sum << " " << count << "\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){ solve();}
}