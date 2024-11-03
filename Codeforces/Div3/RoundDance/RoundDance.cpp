#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n, cycles, concomp;
vector<int> arr;
vector<bool> vis;

void dfs(int start, int cur, int prev){
	//cout << cur << " ";
	if(vis[cur] && cur == start && start != arr[arr[cur]]) {
		//cout << "1\n";
		cycles++;
		concomp++;
		return;
	}
	else if(vis[cur] && prev == arr[cur]){
		//cout << "2\n";
		concomp++;
		return;

	}
	else if(vis[cur]) {return;}
	vis[cur] = true;
	
	dfs(start, arr[cur], cur);



}

void solve(){
	cin >> n;
	cycles = 0;
	concomp = 0;
	arr.resize(n, 0);
	vector<bool> v(n, false);
	vis = v;
	for(int i =0 ; i < n; i++){
		int x;
		cin >> x;
		arr[i] = x-1;
		//cout << arr[i] << " ";
	}
	//cout << "\n\n";
	for(int i =0; i < n; i++){
		if(!vis[i]){
			vis[i] = true;
			//cout << i << " ";
			dfs(i, arr[i], i);
		}

	}
	// cout << "\n";
	// cout << cycles << " " << concomp << "\n";
	int low = cycles + (concomp - cycles > 0);
	int hi = concomp;
	cout << low << " " << hi << "\n";
}



int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0 ; i < t; i++) solve();
}