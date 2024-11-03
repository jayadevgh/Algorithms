#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll N;
  	cin >> N;
  	for(ll i =0;i < N; i++){
  		ll a, b;
  		cin >> a >> b;
  		ll cnt = 0;
  		while(a > b){
  			if(a%2){ a++; cnt++;}
  			cnt++;
  			a/=2;
  		}
  		//cout << a << " " << cnt << " -- > ";

  		if(a == b){
  			cout << cnt << "\n";
  			continue;
  		}
  		ll x = b;

  		ll cnt2 = 0;
  		
  		ll fin = LLONG_MAX;
  		while(x > a or x != 1){
  			ll dist = x-a;
  			ll temp = dist + cnt2;
  			cnt2+= 1 + x % 2;
  			x/= 2;
  			
  			if(a > x){
  				cnt2+= 1 + a%2;
  				a = (a+1)/2;
  			}
  			fin = min(fin, temp);
  		}
  		cout << fin + cnt << "\n";
  		//cout << a << " " << x << " " << fin<< " " << cnt << "\n";
  	}
}