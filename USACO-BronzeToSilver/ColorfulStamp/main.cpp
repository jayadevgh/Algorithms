#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){

    int n;
    cin >> n;
    bool possible = true;
    string str;
    cin >> str;
    set<char> str1;
    for(int j = 0; j < n; j++){
      if(str[j] == 'W'){
        if(str1.size() == 1) possible=false;
        str1.clear(); 
        continue;
      }
      str1.insert(str[j]);
    }
    if(str1.size() == 1) possible=false;
    if(possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}