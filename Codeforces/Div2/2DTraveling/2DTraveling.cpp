#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define ii pair<ll, ll>

using namespace std;

void solve(){
	ll n, k, a, b;
	cin >> n >> k >> a >> b;
	vector<ii> arr;
	for(ll i = 0;i < n; i++){
		ll x, y;

		cin >> x >> y;
		arr.push_back(make_pair(x, y));

	}
	ll tot = abs(arr[a-1].first - arr[b-1].first) + abs(arr[a-1].second - arr[b-1].second), mida = 4e9+5, midb =4e9+5 ;
	for(ll i =0;i < k;i++){
		mida = min(mida, abs(arr[a-1].first - arr[i].first) + abs(arr[a-1].second - arr[i].second));
		midb = min(midb, abs(arr[b-1].first - arr[i].first) + abs(arr[b-1].second - arr[i].second));
	}
	ll tot2 =mida + midb;
	cout <<min(tot, tot2) << "\n";
	//cout <<tot << " " << mida << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t; 
	while(t--) solve();
	// ll x = 1000000000 +1000000000+1000000000+ 1000000000;
	// cout << x;
}