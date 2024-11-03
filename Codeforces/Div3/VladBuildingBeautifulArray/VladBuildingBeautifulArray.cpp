#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(){
	int n; cin >> n;
	//int parity[2];
	//vector<int> arr(n); 
	int num = INT_MAX;
	//int numo = INT_MAX;
	vector<int> arr(n);
	for(int i =0; i < n; i++){
		int x;
		cin >> x;
		arr[i] = x;
		//parity[x%2]++;
		num = min(x, num);
		//if((x%2)) numo = min(numo, x);
	}
	bool x = true;
	for(int i = 0; i < n; i++){
		if(num % 2 == 0 && arr[i] %2 == 1) x = false;
	}
	if(x) return "YES";
	return "NO";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++) cout << solve() << "\n";
}