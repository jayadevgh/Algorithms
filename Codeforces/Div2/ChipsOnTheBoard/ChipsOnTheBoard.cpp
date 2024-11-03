#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


void solve(){
	ll n;
	cin >> n;
	//priority_queue <ll, vector<ll>, greater<ll>> pq;
	//vector<ll> arr1, arr2;
	ll min1 = LLONG_MAX;
	ll min2 = LLONG_MAX;
	ll sum1 = 0;
	ll sum2 = 0;
	for(ll i =0;i < n; i++){
		ll x;
		cin >> x; 
		min1 = min(min1, x);
		//arr1.push_back(x);
		sum1 += x;
	}
	for(ll i =0;i < n; i++){
		ll x;
		cin >> x; 
		min2 = min(min2, x);
		//arr2.push_back(x);
		sum2 += x;
	}
	sum1 += min2 * n;
	sum2 += min1 * n;
	//cout << min1;
	cout << min(sum1, sum2) << "\n";

}
int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;
	for(ll i =0;i < t; i++){
		solve();
	}
}