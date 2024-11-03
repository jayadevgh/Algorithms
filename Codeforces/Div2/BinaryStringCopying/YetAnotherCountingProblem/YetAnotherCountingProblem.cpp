#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a, ll b){
	if (b==0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a, ll b){
	return a * (b/gcd(a, b));
}
void solve(){
	ll a, b, q;
	cin >> a >> b >> q;

	ll con = lcm(a, b);
	ll maxi = max(a, b);
	ll mini = min(a, b);
	b = maxi;
	a = mini;

	for(ll i = 0; i < q; i++){
		ll l, r, ans;
		cin >> l >> r;
		ans = r-l+1;
		ll lb = (l/con) * con;
		ll ub = (r/con) * con;

		




		// if(l < lb + b){
		// 	ans -= lb+b-l;
		// 	//cout << ans << " ";
		// 	if(r < lb + b) ans += lb+b-r-1;
		// 	//cout << ans << " "; 
		// }
		// else if(r < ub+b){
		// 	ans -= r-ub+1;
		// }
		// lb += con;
		// if(lb > ub){ cout << ans << " "; continue; }
		// ans -= (r/con - l/con + 0) * b;
		// if(r < ub+b) ans += b;
		// cout << ans <<" ";
	}
	cout << "\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0; i < t; i++) solve();
}