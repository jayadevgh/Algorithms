#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  freopen("moobuzz.in","r",stdin);
	freopen("moobuzz.out","w",stdout);
  ll n;
  cin >> n;

  ll idx = n%8;
  vector<ll> a = {14, 1, 2, 4, 7, 8, 11, 13};
  cout << (n-1)/8 * 15 + a[idx];
  
  // Binary Search
  // ll l = 0;
  // ll r = LLONG_MAX;
  
  // while(l+1 < r){
  //   ll m = (l+r)/2;
  //   if((m-(m/3+m/5-m/15)) < n){
  //     l = m;
  //   }
  //   else{
  //     r = m;
  //   }
  // }
  // cout << r;
  
}