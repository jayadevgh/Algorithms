#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i =0; i < n; i++){
  	int a, b, c;
  	cin >> a >> b >> c;
  	if(a+b > 9 || b+c > 9 || a + c > 9) cout << "YES\n";
  	else cout << "NO\n";
  }

}