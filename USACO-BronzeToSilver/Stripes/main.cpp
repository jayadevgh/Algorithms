#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  bool rcheck = true;
  string ans = "B\n";
  for(int i = 0; i < 8; i++){
    rcheck = true;
    string c;
    cin >> c;
    for(int k = 0; k < 8; k++){
      char s = c[k];
      if(s != 'R') {rcheck = false; break;}
    }
    if (rcheck) {ans = "R\n";}
  }
  cout << ans;
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int j = 0; j < t; j++){solve();}
}