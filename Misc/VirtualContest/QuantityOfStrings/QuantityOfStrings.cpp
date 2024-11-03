#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll mod = 1e9+7;
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n, m, k;
  cin >> n >> m >> k;
  ll ans = 0;
  ans = m;
  if(k > 1 && n >1 && m > 1 && k%2 && k < n){
  	//cout << " yes";
  	ans += ((m) * (m-1)) % mod;
  }	else if(k == 1 || k > n){
	  	ans = 1;
	  	for(ll i = 0;i < n; i++){  	
		  	ans *= m;
		  	ans %= mod;
		}
  }else if(k == n){
  		ans = 1;
	 	for(ll i = 0;i < (n+1)/2; i++){  	
		  	ans *= m;
		  	ans %= mod;
	}
  }
  ans = ans % mod;
  cout << ans;
}