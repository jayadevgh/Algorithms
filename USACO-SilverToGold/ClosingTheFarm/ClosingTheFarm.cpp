#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> father;
    vector<int> size;

    DSU(int n) {
        // we can use nodes from 0 to n (inclusive)
        father.resize(n + 1);
        size.resize(n + 1);

        for(int i = 0; i <= n; i++) {
            father[i] = i;
            size[i] = 1;
        }
    }

    int find(int x) {
        if(father[x] == x) {
            return x;
        }
        return father[x] = find(father[x]); // Path-compression - Optimization 1
    }

    bool Join(int x, int y) { // -> return true if and only if x and y were in different sets
        x = find(x);
        y = find(y);

        if(x == y) {
            return false; // If the two were already in the same set, return false
        }

        if(size[x] < size[y]) { // I will always make the larger in size one the father
            swap(x, y); // Size-based Merging - Optimization 2
        }

        father[y] = x;
        size[x] += size[y];
        return true;
    }

    bool SameSet(int x, int y) {
        return find(x) == find(y);
    }
};
int main() {
	//Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);

	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);

	int N, M;
	cin >> N >> M;
  	vector<vector<int>> adj(N+1, vector<int>());

  	for(int i =0;i < M; i++){
  		int a, b;
  		cin >> a >> b;
  		adj[a].push_back(b);
  		adj[b].push_back(a);
  	}

  	vector<int> seq(N);
  	vector<bool> isadded(N, 0);
  	DSU dsu(N);
  	for(int i=0; i < N; i++) cin >> seq[i];

  	reverse(seq.begin(), seq.end());
  	vector<string> ans;
  	int cc =0;
  	for(int i = 0;i < N; i++){
  		cc += 1;
  		isadded[seq[i]] =1;
  		for(int neighbor : adj[seq[i]]){
  			if(isadded[neighbor]){
  				if(dsu.Join(neighbor, seq[i]))cc-= 1;
  			}
  		}
  		if(cc == 1) ans.push_back("YES\n");
  		else ans.push_back("NO\n");
  	}
  	reverse(ans.begin(), ans.end());
  	for(string res : ans){
  		cout << res;
  	}
}