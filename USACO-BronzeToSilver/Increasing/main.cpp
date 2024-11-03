#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int j = 0; j < t; j++){
    int n;
    cin >> n;
    set<int> s;
    for(int i = 0; i < n; i++){
      int num;
      cin >> num;
      s.insert(num);
    }
    if(s.size() == n) cout << "YES";
    else cout << "NO";
    cout << "\n";
  }
}