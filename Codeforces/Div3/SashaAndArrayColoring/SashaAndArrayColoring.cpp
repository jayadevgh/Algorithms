#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int>  arr(n);
	for(int i = 0; i< n; i++){
		cin >> arr[i];
	}
	sort(arr.begin(), arr.end());
	int beg = 0; int en = 0;
	for(int i = 0; i < n/2; i++){
		beg += arr[i];
	}
	for(int i = n/2 + (n%2); i < n; i++){
		en += arr[i];
	}
	cout << en - beg << "\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){ solve();}
}