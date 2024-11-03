// https://codeforces.com/contest/1165/problem/D
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
ll ans;
bool isIn(ll d, vector<ll> arr){
  return binary_search(arr.begin(), arr.end(), d);
}

// bool isPrime(ll d)
// {
//   if (d == 1) return false;
//   ll i = 2;
//   while (i*i <= d){
//       if (d % i == 0) return false;
//       i += 1;
//   }
//   return true;
// }



void solve(){
  ll n;
  cin >> n;
  vector<ll> arr, primeArr, primeCount;
  for(ll i =0; i < n; i++){
    ll d; 
    cin >> d;
    arr.push_back(d);
    //if(isPrime(d)) primeArr.push_back(d);
  }
  sort(arr.begin(), arr.end());
  // ans = 1;
  // ll divisorCount = 1;
  // for(ll i =0; i < primeArr.size(); i++){
  //   ll prime = primeArr[i];
  //   primeCount.push_back(1);
  //   while(isIn(prime *= primeArr[i], arr)) primeCount[i]++;
  //   ans *= prime/primeArr[i];
  //   divisorCount *= (primeCount[i] + 1);
  // }
  ans = arr[0] * arr[n-1];
  // divisorCount -= 2;
  bool check = true;

  ll divCount= 0;
  for(ll i =2; i <= sqrt(ans); i++){

    if(!(ans %i)){
      //cout << i << " " << ans/i << "\n";
      check = check && isIn(i, arr);
      divCount+= 2;
      if(ans/i != i) check = check && isIn(ans/i, arr);
      else divCount--;
    }
  }
  check = check && (divCount == n);
  //cout << divCount <<  " ";
  if(check ) cout << ans << "\n";
  else cout << -1 << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0; i < t; i++) solve();
}