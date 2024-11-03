#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin >> n;
	int a, b;
	cin >> a >> b;
	int ans = a;
	for(int i =0 ; i < n-1; i++){
		int x, y;
		cin >> x >> y;
		if(x >= ans && y >= b) ans = -1;
	}
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while(t--) solve();
}
