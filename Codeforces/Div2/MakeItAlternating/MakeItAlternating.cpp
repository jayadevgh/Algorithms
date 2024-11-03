 #include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n;
	cin >> n;
	for(ll i =0; i < n; i++){

		string s;
		cin >> s;
		char cur = 0;
		vector<ll> sizes;
		ll sz = 1;
		for(ll i =1 ;i < s.size(); i++){
			//cout << s[i] << " ";
			if(s[i] != s[cur]){
				sizes.push_back(sz);
				sz = 1;
				cur = i;
			}else sz++;
		}
		sizes.push_back(sz);
		ll ans = 1;
		//cout << "\n";
		// for(ll a : sizes) cout << a << "\n";
		// cout << "\n";
		cout << s.size() - sizes.size() << " ";

		for(ll num : sizes){
			ans *= num;
			ans %= 998244353;
		}
		for(ll i =1; i <= s.size()-sizes.size(); i++){
			ans *= i;
			ans %= 998244353; 
		}
		cout << ans << "\n";


	}
	// for(int i =0;i < 1e5; i++){
	// 	cout << 0;
	// }
	// ll test = 998244352;
	// test *= 1e5;
	// test %= 998244353;
	// cout << test;
}