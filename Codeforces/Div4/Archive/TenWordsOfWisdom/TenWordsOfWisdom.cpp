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
  	int n;
  	cin >> n;
  	int m = INT_MIN;
  	int idx = 0;
  	for(int j = 0; j < n; j++){
  		int a, b;
  		cin >> a >> b;
  		if(a < 11 && b > m){m = b; idx = j+1;}
  	}
  	cout << idx << "\n";
  }
}