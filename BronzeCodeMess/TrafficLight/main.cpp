#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
  int n;
  char c;
  string str;
  cin >> n >> c >> str;
  priority_queue<int, vector<int>, greater<int>> gidx;
  if(c == 'g'){
    cout << 0 << '\n';
    return;
  }
  for(int i = 0; i < n; i++){
    if(str[i] == 'g') gidx.push(i);
  }
  int maxs = 0;
  gidx.push(gidx.top() + n);
  for(int i = 0; i < n; i++){
    if(i == gidx.top()) gidx.pop();
    if(str[i] == c) maxs = max(maxs, gidx.top() - i);
  }
  cout << maxs << '\n';
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}