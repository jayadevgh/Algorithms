#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, k; cin >> n >> k;
	vector<int> a(n);
	vector<int> b(n);
	for(int i =0; i < n; i++){cin >> a[i];}
	for(int i = 0;i < n; i++){cin >> b[i];}

	vector<int> idx(n);
	vector<int> c(n);

	iota(idx.begin(), idx.end(), 0);
	stable_sort(idx.begin(), idx.end(), [&a](int i, int j){return a[i] < a[j];});
	// for(int x : a){cout <<x << " ";}
	// cout << "\n";
	// for(int x : idx){cout <<x << " ";}
	// cout << "\n";
	sort(b.begin(), b.end());
	// for(int x : b){cout <<x << " ";}
	// cout << "\n";
	for(int i = 0; i < n; i++){
		c[idx[i]] = b[i];
	}
	for(int i : c) cout << i << " ";
	cout << "\n";

}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i = 0; i < t; i++){solve();}
}