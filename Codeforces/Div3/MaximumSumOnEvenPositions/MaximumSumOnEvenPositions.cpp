#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n; cin >> n;
	vector<ll> arr1;
  	vector<ll> arr2;
  	vector<ll> arr(n);
  	arr1.push_back(0); 
  	arr2.push_back(0);
  	ll ans = 0;
  	for(ll i = 0; i < n; i++) {cin >> arr[i]; if(i % 2==0) ans+= arr[i]; }

  	ll sum = 0;
  	for(ll i = 0; i< n; i+=2){
  		if(i + 1 < n ) { sum += arr[i+1]-arr[i]; arr1.push_back(sum); }
  	}
  	sum = 0;
  	for(ll i = 1; i< n; i+=2){
  		if(i + 1 < n ) { sum += arr[i]-arr[i+1]; arr2.push_back(sum); }
  	}
  	ll ansSum = 0;
  	ll mini = LLONG_MAX;

  	// for(ll x : arr1) cout << x << " ";
  	// cout << "\n";
    // for(ll x : arr2) cout << x << " ";
  	// cout << "\n";
  	for(ll i = 0; i < arr1.size(); i++){
  		mini = min(mini , arr1[i]);
  		ansSum = max(ansSum, arr1[i] - mini);
  	}
  	mini = LLONG_MAX;
  	for(ll i = 0; i < arr2.size(); i++){
  		mini = min(mini , arr2[i]);
  		ansSum = max(ansSum, arr2[i] - mini);
  	}
  	cout << max(ans, ans + ansSum) << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0 ; i < t; i++) solve();

}