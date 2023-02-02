#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(string model){
  string str;
  cin >> str;
  if(model.find(str) != string::npos){
    cout<< "YES\n";
    return;
  }
  cout << "NO\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string model = "";
  for(int i = 0; i < 25; i++){
    model += "Yes";
  }
  int t; 
  cin >> t;
  for(int i = 0; i < t; i++){solve(model);}
}