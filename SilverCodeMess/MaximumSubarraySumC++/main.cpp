#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  vector<ll> psum(n+1);
  psum[0] = 0;
  ll mins = 0;
  ll maxs = LLONG_MIN;
  for(ll i = 1; i <= n; i++){
    ll k;
    cin >> k;
    psum[i] = psum[i-1] + k;
    maxs = max(maxs, psum[i] - mins);
    mins = min(mins, psum[i]);
  }
  cout<< maxs;

}