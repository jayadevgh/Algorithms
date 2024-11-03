#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int ans(string str){
  string a = "MOO";
  string b = "MOM";
  string c = "OOO";
  string d = "OOM";
  if (str.find(a) != string::npos) return str.size() - 3;
  if (str.find(b) != string::npos) return str.size() - 3 + 1;
  if (str.find(c) != string::npos) return str.size() - 3 + 1;
  if (str.find(d) != string::npos) return str.size() - 3 + 2;
  return -1;
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //File
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    string str;
    cin >> str;
    cout << ans(str) << "\n";
  }
}