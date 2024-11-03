#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;
bool sor(const ii& a, const ii& b){
    if (a.first != b.first) return (a.first > b.first);
    else return (a.second < b.second);
}
void solve(){
	int n, k;
	cin >> n >> k;
	vector<ii> arr(n);
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		int y = x%k;
		if(y == 0) y += k;
		arr[i] = make_pair(y, i+1);
	}
	sort(arr.begin(), arr.end(), sor);
	for(ii x : arr){
		cout << x.second << " ";
	}
	cout << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0 ; i < t; i++) solve();
}