#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


ll func(ll maxi, ll n, vector<ll> arr){
	ll par = 0;
	ll sum =0;
	ll days = 0;
	for(ll i =0;i < n; i++){
		if(arr[i]%2 != maxi %2){
			arr[i]++;
			par++;
		}
		sum += maxi - arr[i];
	}
	if(par > 0){
		sum -= 2 * (par-1);
		days += 2 * (par)-1;
	}
	//cout << sum << " " << days << "\n";
	if(sum > 0){
		days += 2 * (sum/3) + ((sum%3 && par>0) ? 1 : sum%3);
	}

	return days;
}
void solve(){
	ll n;
	cin >> n;
	vector<ll> arr(n);
	ll maxi = 0;
	for(ll i =0;i < n; i++) {cin >> arr[i]; maxi = max(maxi , arr[i]);}
	ll ans = min(func(maxi, n, arr), func(maxi+1, n, arr));
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0;i < t; i++) solve();
}