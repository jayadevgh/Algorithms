// https://codeforces.com/contest/920/problem/E

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

set<int> nodes;
vector<set<int>> pairings(200010);
vector<int> idxs;
int cnt =0;
void bfs(int node){
	cnt++;

	queue<int> ccomp;
	ccomp.push(node);
	nodes.erase(nodes.find(node));
	while(!ccomp.empty()){
		int cur = ccomp.front();
		ccomp.pop();

		vector<int> eraser;
		for(auto itr = nodes.begin(); itr != nodes.end(); itr++){
			int val = *itr;
			if(!pairings[val].count(cur)){
				eraser.push_back(*itr);
				//nodes.erase(nodes.find(val));
				ccomp.push(val);
				cnt++;
			}
		}
		for(int i : eraser){
			nodes.erase(nodes.find(i));
		}
	}
}
void solve(){
	int n, m;
	cin >> n >> m;
	for(int i =0;i < m; i++){
		int a, b;
		cin >> a >> b;
		pairings[a].insert(b);
		pairings[b].insert(a);
	}


	for(int i =1;i <= n; i++){
		nodes.insert(i);
	}

	vector<int> cntarr;
	for(int i = 1; i <= n; i++){
		if(nodes.count(i)){
			bfs(i);
			cntarr.push_back(cnt);
			cnt = 0;
		}
	}
	cout << cntarr.size() << "\n";
	sort(cntarr.begin(), cntarr.end());
	for(int c =0 ;c < cntarr.size(); c++){
		cout << cntarr[c] << " ";
	}
}	


int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	 int t =1;
  	 while(t--) solve();
}