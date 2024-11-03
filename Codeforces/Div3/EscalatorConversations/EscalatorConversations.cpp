#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m, k, H; 
	cin >> n >> m >> k >> H;
	int count = 0;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		if(x%k == H%k && abs(H-x)/k < m && x != H) {count++;}
	}
	cout << count << "\n";
}


int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0; i < t; i++) solve();
}