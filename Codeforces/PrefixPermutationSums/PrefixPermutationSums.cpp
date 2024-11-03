#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n;
	cin >> n;

	set<ll> s;
	for (ll i = 1; i <= n; ++i)
	{
		s.insert(i);
	}
	vector<ll> arr(n);
	arr[0] = 0;
	for(ll i =1; i < n; i++){
		cin >> arr[i];
	}
	vector<ll> rem;
	for(ll i =n-1; i >0; i--){
		ll diff = arr[i] - arr[i-1];
		if(s.find(diff) != s.end()) s.erase(diff);
		else rem.push_back(diff);
	}
	if(rem.size() > 1) cout << "NO\n";
	else{
		ll sum = 0;
		ll count = 0;
		for(ll x : s){
			sum += x;
			count++;

		}
		if(count == 1 && rem.size() == 0) cout << "YES\n";
		else if(rem.size() == 0) cout << "NO\n";
		else if(sum == rem[0]) cout << "YES\n";
		else cout << "NO\n";
	}
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  for(ll i =0; i < t; i++) solve();
}