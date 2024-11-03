#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
 int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
 ll n;
  cin >> n;
  vector <ll> cows, stall;
  for(ll i = 0; i < n; i++){
   ll num; 
    cin >> num;
    cows.push_back(num);
  }
  for(ll i = 0; i < n; i++){
   ll num; 
    cin >> num;
    stall.push_back(num);
  }
 ll ans = 1;
  sort(cows.begin(), cows.end());
  sort(stall.begin(), stall.end());
  for(ll i = 0; i < n; i++){
   ll multiplier = 0;
   ll j = n-i-1;
   ll k = n-1;
    while(true){
      if(cows[j] <= stall[k]){
        multiplier++;
        if(k==0){break;}
      }else{
        break;
      }
      k--;
    }
    ans *= (multiplier - i);
    if(multiplier == 0) {ans = 0; break;}
  }
  cout << ans;
}