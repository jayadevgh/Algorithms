#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> arr;
vector<ll> val;
vector<ll> val2;
bool poss = true;
ll sum = 0;
void dfs(ll node, ll parent){
	if(val[node] != -1){
		val[parent] = (val[parent] == -1) ? LLONG_MAX : val[parent];
		val[parent] = min(val[node], val[parent]);
	}
	for(ll i =0; i < arr[node].size(); i++){
		dfs(arr[node][i], node);
	}
}
void dfs2(ll node, ll num){
	if(!poss) return;
	for(ll i= 0; i< arr[node].size(); i++){
		if(val[arr[node][i]] != -1 && val[arr[node][i]] < num){poss = false; return;}
		dfs2(arr[node][i], val[arr[node][i]]);
		if(!poss) return;
	}
	
}
void dfs3(ll node){
	if(val[node] == -1) return;
	for(ll i =0;i < arr[node].size(); i++){
		val2[arr[node][i]] -= val[node];
		dfs3(arr[node][i]);
	}
	sum += val2[node];
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll n;
  cin >> n;
  arr.resize(n+1, vector<ll>());
  for(ll i =2 ;i <=n; i++){
  	ll x; cin >> x;
  	arr[x].push_back(i);
  }
  val.resize(n+1);
  for(ll i = 1; i <= n; i++){
  	cin >> val[i];
  }
  val[0] =val[1];
  dfs(1,0);
  dfs2(1,val[1]);
  val2 = val;
  if(poss){
  	dfs3(1);
  	cout << sum;
  }
  else cout << -1;
  // for(ll i =0;i < n+1; i++){
  // 	cout << val[i] << " ";
  // }
  //cout << poss;
}	