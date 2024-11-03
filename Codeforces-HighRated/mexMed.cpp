// https://codeforces.com/contest/1744/problem/F

#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#define ll long long
using namespace std;
void solve(){
  int n;
  cin >> n;
  vector<int> a(n), p(n);
  for(int i = 0; i < n; i++){
    int num; 
    cin >> num;
    a[i] = num;
    p[num] = i;
  }
  ll ans = 0;
  int l = p[0]; 
  int r = p[0];
  for(int i = 1; i <= n; i++){
    int x = (i-1)/2;
    l = min(p[x], l);
    r = max(p[x], r);
    if(r-l + 1 > i) continue;
    else ans += min(n-i, l) - max(r-i+1, 0) + 1;
  }
  cout << ans << "\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++){solve();}
}