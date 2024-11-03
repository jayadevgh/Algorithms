#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// struct DSU {
// 	vi e; void init(int N) { e = vi(N,-1); }
// 	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
// 	bool sameSet(int a, int b) { return get(a) == get(b); }
// 	int size(int x) { return -e[get(x)]; }
// 	bool unite(int x, int y) { // union by size
// 		x = get(x), y = get(y); if (x == y) return 0;
// 		if (e[x] > e[y]) swap(x,y);
// 		e[x] += e[y]; e[y] = x; return 1;
// 	}
// };

void solve(){
	int n;
	cin >> n;
	vector<vector<int>> adj;
	for(int i =0 ;i < n; i++){
		
	}
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	while(t--) solve();
}