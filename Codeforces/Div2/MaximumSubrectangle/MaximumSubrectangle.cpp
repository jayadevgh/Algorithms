#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int m, n;
  cin >> m >> n;
  vector<int> a(n), b(m);
  for(auto& x : a) cin >> x;
  for(auto& x : b) cin >> x;
  for(int x : a) cout << x << " ";
}