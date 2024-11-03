#include <iostream>
#include <bits/stdc++.h>
#define ii pair<ll, ll>
#define ll long long 
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll N, K;
  	cin >> N >> K;


  	vector<ii> ana(N + 1, make_pair(0, 0));
  	vector<ii> bes(N + 1, make_pair(-1, -1));
  	vector<ll> remains(N+1, 0);
  	ll beg; cin >> beg;
  	ll prev = beg;
  	ll last = prev;
  	remains[beg]++;
  	for(ll i =1;i < K; i++){
  		ll x;
  		cin >> x;
  		ana[prev].second = x;
  		ana[x].first = prev;
  		prev = x;
  		last = prev;
  		remains[x]++;
  	}
  	ana[last].second = beg;
  	ana[beg].first = last;

  	ll beg2; cin >> beg2;
  	ll prev2 = beg2;
  	ll last2 = prev2;
  	remains[beg2]++;
  	for(ll i =1;i < K; i++){
  		ll x;
  		cin >> x;
  		bes[prev2].second = x;
  		bes[x].first = prev2;
  		prev2 = x;
  		last2 = prev2;
  		remains[x]++;
  	}
  	bes[last2].second = beg2;
  	bes[beg2].first = last2;

  	ll ans = 0;
  	for(ll i =1; i < N+1; i++){
  		//cout << remains[i] << " ";
  		if(remains[i] == 0) ans++;
  	}
  	// for(ll i = 0;i < N+1; i++){
  	// 	cout << ana[i].first << " " << ana[i].second << " | ";
  	// }
  	// cout << "\n";
  	// for(ll i = 0;i < N+1; i++){
  	// 	cout << bes[i].first << " " << bes[i].second << " | ";
  	// }
  	// cout << ans;
  	//if(7)cout << "hi";

  	vector<ll> vis(N+1, 0);
  	ll maxi = 0;
  	for(ll i =1;i <= N; i++){
  		ll idx = i;
  		if(vis[i]) continue;
  		ll count = 0;
  		//cout << i << ": ";
  		if(ana[idx].first != 0 && bes[idx].first != -1) count++;
  		while(ana[idx].first == bes[idx].first){
  			idx = ana[idx].first;
  			if(idx == i) break;
  			
  			if(vis[idx]){
  				count += vis[idx];
  				break;
  			}
  			//count++;
  			count++;
  			vis[idx] = 1;
  		}

  		//cout << count << " ";
  		vis[i] = count;
  		maxi = max(maxi, vis[i]);
  	}
  	for(ll i =0;i < N+1; i++){
  		ll x = bes[i].first;
  		bes[i].first = bes[i].second;
  		bes[i].second = x;
  	}

  	vector<ll> vis2(N+1, 0);
  	vis = vis2;
  	for(ll i =1;i <= N; i++){
  		ll idx = i;
  		if(vis[i]) continue;
  		ll count = 0;
  		//cout << i << ": ";
  		if(ana[idx].first != 0 && bes[idx].first != -1) count++;
  		while(ana[idx].first == bes[idx].first){
  			idx = ana[idx].first;
  			if(idx == i) break;
  			
  			if(vis[idx]){
  				count += vis[idx];
  				break;
  			}
  			//count++;
  			count++;
  			vis[idx] = 1;
  		}

  		//cout << count << " ";
  		vis[i] = count;
  		maxi = max(maxi, vis[i]);
  	}
  	//cout << "\n";
  	cout << maxi << " " << ans << " ";
  	cout << maxi + ans;
}