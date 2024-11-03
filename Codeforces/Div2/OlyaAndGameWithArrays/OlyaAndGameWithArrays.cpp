#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
	ll n;
	cin >> n;
	// vector<vector<ll>>arr(n, vector<ll>());
	ll absMin = LLONG_MAX;
	priority_queue<ll> pq;
	for(ll i =0;i < n; i++){
		ll sz;
		cin >> sz;
		vector<ll> test(sz, 0);
		ll mini, mini2;
		for(ll j =0;j < sz; j++){
			cin >> test[j];
		}
		sort(test.begin(), test.end());
		mini = test[0];
		mini2 = test[1];
		// arr[i].push_back(mini);
		// arr[i].push_back(mini2);
		pq.push(mini2);
		absMin = min(absMin, mini);
	}
	ll sum = 0;
	while(pq.size() != 1){
		sum += pq.top();
		pq.pop();
	}
	sum += absMin;
	cout << sum << "\n";


}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0;i < t; i++){
  	solve();
  } 
}