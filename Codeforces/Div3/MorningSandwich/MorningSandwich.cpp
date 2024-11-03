#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0; i < t; i++){
  	int a, b, c;
  	cin >> a >>  b >> c;

  	cout <<2 * min(a-1, b+c)+1 << "\n";
  }
}