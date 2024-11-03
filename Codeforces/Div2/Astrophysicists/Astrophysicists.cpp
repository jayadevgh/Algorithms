#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll n, k, g;
	cin >> n >> k >> g;
	ll tot = k * g;
	ll maxmin = (g%2) ?  g/2 : g/2-1;
	if(n == 1) {cout << 0 << "\n"; return;}

	ll savings = (n) * maxmin;
	//cout << savings << " ";
	if(savings >= tot) cout << tot << "\n";

	else{
		//cout << savings << " ";
		savings -= maxmin;
		ll rest = (tot-savings)%g;
		if(rest > maxmin) savings -= (g-rest);
		else savings += rest;
		cout << savings << "\n";
	}	
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i = 0; i < t; i++) solve();
}