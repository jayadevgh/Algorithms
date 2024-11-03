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
		return find(father[x]);
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
	int cc = n;
	DSU dsu(n+1);
	
	int maxsize = 0;
	for(int i =0;i < m; i++){
		int a, b;
		cin >> a >> b;
		//cc--;
		if(dsu.unite(a, b)) cc--;
		maxsize = max(maxsize, dsu.getSize(a));
		cout << cc << " " << maxsize << "\n";
	}
  	
}