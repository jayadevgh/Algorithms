#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  for(int i = 0; i < n; i++){
  	int x;
  	cin >> x;
  	if(x == 3) {cout << -1 << "\n"; continue;}
  	if(x%2 == 0) for(int j = x; j > 0; j--) cout << j << " ";
  	else{
  		cout << x << " " << x-1 << " ";
  		for(int j =1; j < x-1; j++) cout << j << " ";
  	}
    cout << "\n";
  }
}