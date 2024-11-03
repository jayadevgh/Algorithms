#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int sum = 0, odds = 0, evens = 0;
	for(int i = 0;i < n; i++){
		int x; cin >> x;
		sum += x;
		odds += (x % 2);
		evens += (x %2 == 0);
	}
	if(sum %2 ==0 && odds %2 == 0) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}