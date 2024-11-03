#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
    int n;
    string str;
    cin >> n >> str;
    int maxs = 0;
    for(int j = 0; j < n; j++){
      maxs = max(maxs, int(str[j] - 96));
    }
    cout << maxs << "\n";
  }
}