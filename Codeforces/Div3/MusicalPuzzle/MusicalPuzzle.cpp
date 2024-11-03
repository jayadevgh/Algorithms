#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t; cin >> t;
  //cout << 'a' + 5 - 5;
  for(int i = 0; i < t; i++){
  	vector<bool> all(49, 0);
  	int n; cin >> n;
  	string str; cin >> str;
  	int ans = 0;
  	for(int i = 1; i < n; i++){
  		//cout << (str[i-1]-97) * 7 + (str[i]-97) << " ";
  		if(!all[(str[i-1]-97) * 7 + (str[i]-97)]){
  			all[(str[i-1]-97) * 7 + (str[i]-97)] = true;
  			ans++;
  		}
  	}
  	cout << ans << '\n';
  }
}