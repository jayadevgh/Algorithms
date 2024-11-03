#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve(){
	ll m, k, a1, ak;
	cin >> m >> k >> a1 >> ak;
	int mo = m % k;
	ll oria1 = a1;
	ak += a1/k;
	a1 %= k;
	//cout << a1 << " " << ak << "\n";
	ll ze = 0;
	ll ans = max(ze, mo - a1) + max(m/k - ak, ze);
	if(oria1 >= k) {
		ans = min(max((m/k - (ak - 1)), ze), ans);
		//ll x = max((m/k - (ak - 1)), ze);
		//cout << x << "\n";
	}
	cout << ans << "\n";
}

int main() {
    //Console
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    for(ll i =0;i < t; i++) solve();

}