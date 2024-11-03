#include <iostream>
#include <bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll N;
  	cin >> N;
  	vector<ll> arr(N);
  	for(ll i=0; i < N; i++) cin >> arr[i];
  	stack<ii> order;
    order.push(make_pair(arr[0], 0));
    ll ans = 0;
  	for(ll i =1;i < N; i++){
  		ii p = make_pair(arr[i], i);
  		//bool check = 1;
  		if(!order.empty() && order.top().first > p.first){
			ans += i - order.top().second + 1;
		}
  		while(!order.empty() && order.top().first < p.first ){
  			//check = 0;
  			ans += i - order.top().second + 1;
  			//cout << order.top().first << " ";
  			order.pop();
  			if(order.top().first == )
  			if(!order.empty() && order.top().first > p.first){
  				ans += i - order.top().second + 1;
  			}
  		}
  		//cout << "\n";
  		//if(check) ans += 2;
  		order.push(p);
  	}
  	cout << ans;
}