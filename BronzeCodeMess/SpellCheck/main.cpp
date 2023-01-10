#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  set<char> Timur;
  set<char> in;
  string str2 = "Timur";
  int n;
  string str;
  cin >> n >> str;
  if(n != 5) {cout << "NO\n"; return;}
  for(int i = 0; i < 5; i++){
    Timur.insert(str2[i]);
  }
  for(int i = 0; i < 5; i++){
    in.insert(str[i]);
  }
  
  if(in == Timur){ cout << "YES\n"; return;}
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