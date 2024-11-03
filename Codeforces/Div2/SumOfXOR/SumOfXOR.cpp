#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll MAX_N = 1e6;

ll n, q, arr[MAX_N + 1], prefix[MAX_N + 1], a, b;
int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	for (ll i = 1; i <= n; ++i) { cin >> arr[i]; }

	prefix[1] = arr[1];
	for (ll i = 2; i <= n; i++) { prefix[i] = prefix[i - 1] ^ arr[i]; }
	ll ans =0;
	for(ll i =1;i <= n; i++){
		for(ll j = i; j <= n; j++){
			ll a = ((prefix[i-1] ^ prefix[j])*(j-i+1)) %998244353;
			if((j-i+1) == 3)cout << a/3 << " ";
			ans += a;
			ans %= 998244353;
		}
	}
	cout << ans;
}