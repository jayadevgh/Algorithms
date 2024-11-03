#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll N;
vector<ll> pot;
vector<vector<ll>> adj;
vector<ll> maxtrav;
vector<ll> father;
vector<bool> vis;
//ll trav = 0;
ll dfs(ll num){
	vis[num] = true;
	ll trav = 0;
	for(ll i = 0; i < adj[num].size(); i++){
		if(!vis[adj[num][i]]){
			trav += dfs(adj[num][i]);
			father[adj[num][i]] = num;
		}

		//cout << 
	}

	if(trav != 0) {
		maxtrav[num] = trav;
		return trav;
	}
	
	else {
		maxtrav[num] = 1;
		return 1;
	}

}
void dfs3(ll num){
	maxtrav[num] = 0;
	for(ll i =0;i < adj[num].size(); i++){
		if(adj[num][i] != father[num]){
			dfs3(adj[num][i]);
		}
	}
}

void dfs2(ll num){
	maxtrav[num]--;
	if(maxtrav[num] == 0) {
		//vis = vector<bool>(N, 0);
		dfs3(num);
	}
	if(father[num] != 0) dfs2(father[num]);
}



int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	cin >> N;
  	adj = vector<vector<ll>>(N, vector<ll>());
  	maxtrav = vector<ll>(N, 0);
  	father = vector<ll>(N, 0);
  	vis = vector<bool>(N, 0);
  	for(ll i =0; i < N; i++){
  		ll a;
  		cin >> a;
  		a--;
  		pot.push_back(a);
  	}
  	for(ll i =0; i < N-1; i++){
  		ll a, b;
  		cin >> a >> b;
  		a--; b--;
  		adj[a].push_back(b);
  		adj[b].push_back(a);
  	}
  	dfs(0);

  	// for(ll i =1; i < N; i++){
  	// 	cout << father[i] << "\n";
  	// }
  	ll ans = 0;
  	ll rep = maxtrav[0];
  	for(ll i =0; i < rep; i++){
  		//cout << maxtrav[1] << " ";
  		if(maxtrav[pot[i]] != 0) {
  			dfs2(pot[i]);
  			ans++;
  			
  		}

  	}
  	cout << ans;


}