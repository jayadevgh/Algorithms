#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	int count = 0;
	for(int i =1; i <= n ;i++){
		int x;
		cin >> x;
		if(x == i) count++;
	}
	cout << count / 2 + count %2 << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i = 0; i < t; i++) solve();
}
