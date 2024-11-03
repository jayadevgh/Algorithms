#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> arr(n);
	ll sum = 0;
	for(ll i =0;i < n; i++) { cin >> arr[i]; sum += arr[i]; }
	if(n == 1){ cout << "NO\n"; return; }

	if(sum < 2 * n){
		ll nonOne = 0;
		for(ll i =0; i < n; i++){
			if(arr[i]!=1)nonOne++;
		}
		ll needed = 2*n-sum;
		if(needed > nonOne){ cout << "NO\n"; return; }
	}
	cout << "YES\n"; 
	return;
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >>t;
  for(ll i =0; i < t; i++) solve();
}