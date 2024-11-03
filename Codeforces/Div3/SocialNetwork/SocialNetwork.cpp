#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	bool same_set(int a, int b) { return get(a) == get(b); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return true;
	}
};
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, d;
  cin >> n >> d;
  DSU ds(n+1);
  int xtra = 0;
  for(int i = 0 ; i < d; i++){
  	int a, b;
  	cin >> a >> b;
  	if(!ds.unite(a, b)) xtra++;
  	vector<bool> vis(n+1, 0);
  	vector<int> arr;
  	for(int i = 1; i < n+1; i++){
  		if(!vis[ds.get(i)]){
  			arr.push_back(ds.size(i));
  			vis[ds.get(i)] = true;
  		}
  	}
  	sort(arr.begin(), arr.end());
  	int sz = arr.size();
  	int ans = 0;
  	int counts = 1+xtra;
  	for(int i =sz-1 ; i >= 0 && counts > 0; i--){
  		ans +=arr[i];
  		counts--;
  	}
  	cout << ans-1 << "\n";
  }
}