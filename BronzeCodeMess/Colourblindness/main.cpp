#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n;
  string str, str1;
  cin >> n >> str >> str1;
  for(int i = 0; i < n; i++){
    if(str[i] == 'G') str[i] = 'B';
    if(str1[i] == 'G') str1[i] = 'B';
  }
  if(str == str1) {cout << "YES\n"; return;}
  cout << "NO\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t; 
  for(int j = 0; j < t; j++){
    solve();
  }
}