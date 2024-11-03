#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	vector<int> x; 
	for(int i  = 0; i < (n*(n-1))/2; i++){
		int y;
		cin >>y;
		x.push_back(y);
	}
	sort(x.begin(), x.end());
	//vector<int> 
	int idx = -1;
	for(int i =0;i < n-1; i++){
		idx += n-i-1;
		cout << x[idx] << " ";
	}
	cout << (int)1e9 << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >>t;
  for(int i =0;i < t; i++){
  	solve();
  }
}