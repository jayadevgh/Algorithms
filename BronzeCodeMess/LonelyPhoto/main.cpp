#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  string seq;
  vector<ll> seqLen;
  cin >> n >> seq;
  
  char curr = seq[0];
  ll count = 0;
  for (ll i = 0; i < n; i++) { 
    if (seq[i] == curr) {
      count++;
      } else {
      seqLen.push_back(count);
      count = 1;
      curr = seq[i];
    }
  }
  seqLen.push_back(count);
  if (seqLen.size() == 1) {
    cout << 0;
  } else {
    ll ans = (seqLen[0] - 1) + (seqLen[seqLen.size() - 1] - 1);
    for (ll i = 1; i < seqLen.size() - 1; i++) {
      if (seqLen[i] == 1) {
        ans += (seqLen[i - 1] * seqLen[i + 1]);
      } else {
        ans += (2 * (seqLen[i] - 1));
      }
    }
    cout << ans;
  }
}