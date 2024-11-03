#include <iostream>
#include <bits/stdc++.h>
#define ll __int128_t
using namespace std;


void solve(){
	long long n, area;
	cin >> n >> area;
	//vector<ll> arr(n);
	ll sum = 0;
	ll product = 0;
	for(ll i = 0; i < n; i++){
		long long x;
		cin >> x;
		sum += x;
		product += x*x;
	}
	ll c = (area - product)/4;
	ll b = sum;
	ll a = n;
	ll w = ((sqrt((b*b)+(4*a*c))));
	ll y = w*w;
	w = w - b;
	
	w = w / (2 * a);
	
	//cout << a << " " << b << " " << c << " " << y << " ";
	long long z = w;
	cout << z << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0 ; i < t; i++)solve();
}