#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  while(t>0){
	  ll n; cin >> n;
	  ll ans =0;
	  ll check;
	  ll num;
	  for(int j =1;j <= n; j++){
		  ll sum = 0;
		  ll maxi = 0;
		  ll x = j;
		  for(ll i =1;i <= n; i++){
		  	ll tempsum = sum;
		  	if(i < x)sum += i*i;
		  	if(i >= x)sum += (n + x-i) * i;
		  	maxi = max(maxi, sum-tempsum);
		  }
		  if(sum-maxi > ans) {ans = sum-maxi; num = x;}
		  if(x == (n*3)/4) check = sum-maxi;
		  //if(x == (n*3)/4)
		  //cout << sum - maxi << "\n";
		}
		if(ans == check) cout << "YES" << " ";
		cout << (n*3)/4 << " " << num << " " << ans<< " " <<check<< "\n";
		//cout << ans << "\n";
	  t--;
	}
}