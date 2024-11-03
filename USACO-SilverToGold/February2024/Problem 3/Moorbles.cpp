#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long


void solve(){
	ll n , m , k;
	cin >> n >> m >> k;

	vector<vector<ll>> maxpar(m, vector<ll>(2));
	vector<vector<ll>> minpar = maxpar;
	vector<ll> psummin(m+1);
	vector<ll> maxidx(m);
	vector<string> ans(m, "."); 
	for(ll i =0;i < m; i++){
		ll mine = INT_MAX; 
		ll mino = INT_MAX;
		ll maxe = -1;
		ll maxo = -1;
		for(ll j = 0; j < k; j++){
			ll a; cin >> a;
			if(a%2==1){
				maxo = max(maxo, a);
				mino = min(mino, a);
			}
			if(a%2 == 0){
				maxe = max(maxe, a);
				mine = min(mine, a);
			}
			maxpar[i][0] = (maxe == -1) ? (-1) * mino : maxe;
			maxpar[i][1] = (maxe == -1) ? maxo: maxo;
			minpar[i][0] = mine;
			minpar[i][1] = mino;
			if(maxo == -1) {
				maxpar[i][1] = mine * (-1);

			}
		}
	}
	psummin[0] =0;

	// for(ll i =0;i < m; i++){
	// 	cout << maxpar[i][0] << " " << maxpar[i][1] << "\n";
	// }
	for(ll i =1;i <= m; i++){
		ll odd = maxpar[i-1][1];
		ll even = maxpar[i-1][0];
		//if(even == -1) {odd = -1 * minpar[i-1][1]; even = INT_MAX;}
		bool par = even < odd;

		//if(even == odd) odd = -1 * minpar[i-1][1];

		psummin[i] = (par) ? psummin[i-1] + even : psummin[i-1] + odd;
		if(!par) ans[i-1] = "Even";
		if(psummin[m] >= n) {cout << -1 << "\n"; return;}
	}
	//for(ll a : psummin)cout  << a << " ";
	//cout << " - ";
	//if(psummin[m] >= n) {cout << -1 << "\n"; return;}
	for(string a : ans) cout << a << " ";
	cout << "\n";
	maxidx[m-1] = m-1;

	for(ll i = m-1;i >= 1; i--){

		//cout << psummin[maxidx[i]+1] << " " << psummin[i] << " ";
		if(psummin[maxidx[i]+1] > psummin[i]){
			maxidx[i-1] = maxidx[i];
		}
		else{
			maxidx[i-1] = i-1;
		}
	}
	// cout << "\n";
	for(ll a : psummin)cout  << a << " ";
	cout << "\n";
	for(ll a : maxidx)cout  << a << " ";
	cout << "\n";
	
	ll newsum = 0;
	for(ll i =0; i< ans.size(); i++){
		string a = ans[i];
		
		if(a == "Even") {cout << newsum + psummin[i+1]<< " ";continue;}
		//cout << newsum + maxpar[i][1] - maxpar[i][0] + psummin[maxidx[i]+1] << " ";

		if(newsum + maxpar[i][1] - maxpar[i][0] + psummin[maxidx[i]+1] < n) {

			newsum += maxpar[i][1] - maxpar[i][0];
			ans[i] = "Even";
			//cout << newsum + psummin[maxidx[i]+1]<< " ";
		}
		else{
			ans[i] = "Odd";
		}
		cout << newsum + psummin[i+1]<< " ";
		
	}
	for(ll i = 0; i < m ;i++) {
		cout << ans[i];
		if(i != m-1) cout << " ";
	}
	cout << "\n";

}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll t; cin >> t;
  	while(t--) solve();
}