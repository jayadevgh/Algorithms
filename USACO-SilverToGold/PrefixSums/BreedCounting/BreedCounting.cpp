#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	freopen("bcount.in", "r", stdin);
	freopen("bcount.out", "w", stdout);

	int N, Q;
	cin >> N >> Q;
	vector<int> arr(N);
	vector<int> h(N,0), g(N,0), j(N,0);

	for(int i =0;i < N; i++){

		cin >> arr[i];
		if(arr[i] == 1) h[i]++;
		else if(arr[i] == 2) g[i]++;
		else j[i]++;
		if(i > 0){
			h[i] += h[i-1];
			g[i] += g[i-1];
			j[i] += j[i-1];
		}
	}
	// for(int x : h) cout << x << " ";
	// cout << "\n";
	// for(int x : g) cout << x << " ";
	// cout << "\n";
	// for(int x : j) cout << x << " ";	
	for(int i =0 ; i < Q; i ++){
		int a, b;
		cin >> a >> b;
		if(a == 1){
			cout << h[b-1] << " " << g[b-1] << " " << j[b-1];
		}
		else{
			cout << h[b-1] - h[a-2] << " " << g[b-1] - g[a-2] << " " << j[b-1] - j[a-2];
		}
		cout << "\n";
	}
}