#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int a, b, c;
	cin >> a >> b >> c;
	string ans = "First";
	if(b > a) ans = "Second";
	if(b == a) ans = (c%2 ? "First" : "Second");
	cout << ans << "\n"; 
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}