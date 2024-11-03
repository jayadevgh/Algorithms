#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> grid;
vector<vector<ll>> cond;
vector<vector<ll>> prefixCond;
ll maxi;


void solve(){
	ll n, m;
	cin >> n >> m;
	maxi = min(n, m);
	grid.clear();
	grid.resize(n, vector<ll>(m));
	cond.clear();
	cond.resize(n, vector<ll>(m));
	prefixCond.clear();
	prefixCond.resize(n+1, vector<ll>(m+1, 0));
	for(ll i =0;i < n; i++){
		for(ll j = 0; j < m; j++){
			cin >> grid[i][j];
		}
	}

	//bs

	ll lo = 1;
	ll hi = maxi;
	while(lo < hi){
		ll mid = (lo + hi + ((lo+hi)%2))/2;
		for(ll i =0;i < n; i++){
			for(ll j = 0; j < m; j++){
				cond[i][j] = (grid[i][j] >= mid);
			}
		}
		for(ll i =1;i <= n; i++){
			for(ll j = 1; j <= m; j++){
				prefixCond[i][j] = cond[i-1][j-1] + prefixCond[i][j-1] + prefixCond[i-1][j] - prefixCond[i-1][j-1] ;
			}
		}
		// if(mid == 3){
		// 	for(ll i =1;i <= n; i++){
		// 		for(ll j = 1; j <= m; j++){
		// 			cout << prefixCond[i][j] <<" ";
		// 		}
		// 		cout << "\n";
		// 	}
		// }
		ll check= mid * mid;
		bool chc = false;
		for(ll i =mid;i <= n; i++){
			for(ll j = mid; j <= m; j++){
				//cout << (prefixCond[i][j]-prefixCond[i-mid][j]-prefixCond[i][j-mid]+prefixCond[i-mid][j-mid]);
				chc = chc || (prefixCond[i][j]-prefixCond[i-mid][j]-prefixCond[i][j-mid]+prefixCond[i-mid][j-mid]) == check;
			}
		}
		if(chc){
			lo = mid;
		}else{
			hi = mid-1;
		}
	}
	cout << lo << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t; cin >> t;
  for(ll i =0;i < t; i++) solve();
}