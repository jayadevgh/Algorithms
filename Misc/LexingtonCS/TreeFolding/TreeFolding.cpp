#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> edgeList;
vector<int> nodeNum;

void treeSize(int node){
	for(int i =0;i < edgeList[node].size(); i++){
		treeSize(edgeList[node][i]);
		nodeNum[node] += edgeList[node][i];
	}
	nodeNum[node]++;
}
bool dfs(int node){
	if(node == 1) treeSize(node);
	bool ans = true;
	int oddCount = 0;
	for(int i =0;i < edgeList[node].size(); i++){
		if(nodeNum[edgeList[node][i]] % 2)oddCount++;
	}
	if(node == 1 && oddCount != 1 && edgeList[node].size() != 0) return false;
	for(int i =0;i < edgeList[node].size(); i++){
		ans = ans && dfs(edgeList[node][i]);
	}
	return ans;
}
void solve(){
	int n;
	cin >> n;
	edgeList.clear();
	edgeList.resize(n+2, vector<int>());
	nodeNum.clear();
	nodeNum.resize(n+1);
	int l = 1;
	for(int i =2;i <= n+1; i++){
		l++;
		int a;
		cin >> a;
		edgeList[a].push_back(i);
		if((l &(l-1))){
			cout << "NO\n";
		}else{
			if(dfs(1))cout << "YES\n";
			else cout << "NO\n";
		}

	}
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i= 0;i < t; i++) solve();
}