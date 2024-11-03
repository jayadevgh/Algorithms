#pragma GCC optimize("Ofast")
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct DSU{
	vector<int> father;
	vector<int> size;

	DSU(int n){
		father.resize(n);
		size.resize(n);
		for(int i =0;i < n;i++){
			father[i] = i;
			size[i] = 1;
		}
	}

	int find(int x){
		if(father[x] == x){
			return x;
		}
		return father[x] = find(father[x]);
	}

	bool unite(int x, int y){
		x = find(x);
		y = find(y);

		if(x == y) return false;

		if(y > x) swap(x, y);

		size[x] += size[y];
		father[y] = x;
		return true;

	}

	bool isin(int x, int y){
		if(find(x) == find(y)) return true;
		else return false;
	}
	int getSize(int x) {return size[find(x)];}
};

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int n, m;
  	cin >> n >> m;
  	vector<string> grid(n);
  	for(int i =0;i < n; i++){
		cin >> grid[i];
  	}
  	DSU dsu(m*n);
  	vector<int> dirx = {0, 1, 0, -1};
  	vector<int> diry = {1, 0, -1, 0};
  	int cc =0 ;
  	for(int i =0;i < n ;i++){
  		for(int j = 0; j < m; j++){
  			if(grid[i][j] == '.'){
  				cc++;

  				for(int k =0;k < 4; k++){
  					int x = i+dirx[k];
  					int y = j+diry[k];
  					bool isin = (x <n) && x >= 0 && y <m && y >= 0;
  					if(isin && grid[x][y] == '.'){
  						if(dsu.unite(j + i*m, x*m + y)) cc--;
  					}
  				}
  			}
  		}
  	}
  	cout << cc;
}