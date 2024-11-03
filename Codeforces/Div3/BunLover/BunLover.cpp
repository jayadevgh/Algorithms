#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++){
  	ll n;
  	cin >> n;
  	ll ans = 0;
  	ans += 4 * n; //outer layer
  	ans += ((n) * (n-1))/2;
  	ans += ((n-2) * (n-1))/2;
  	ans += 1;
  	cout << ans << "\n";
  }
}