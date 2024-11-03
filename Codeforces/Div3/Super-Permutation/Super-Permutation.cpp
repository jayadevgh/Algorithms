#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0 ; i < t; i++){
  	int n;
  	cin >> n;
  	if(n == 1) {cout << 1 << "\n"; continue;}
  	if(n % 2) {cout << -1 << "\n"; continue;}
  	cout << n << " ";
  	for(int i = 1; i < n; i++){
  		if(i%2) cout << n - i << " ";
  		else cout << i << " ";
  	}
  	cout << "\n";
  }
}