#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  for(int i = 0; i < n; i++){
  	ll x;
  	cin >> x;
  	ll sum = x;
  	while(x > 0){
  		sum += x /= 2;
  	}
  	cout << sum << "\n";
  }
}