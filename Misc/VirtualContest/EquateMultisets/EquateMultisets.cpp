#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i =0;i < n; i++) {
		cin >> a[i];
		while(a[i]%2 == 0) a[i]/= 2;
		//cout << a[i] << " ";
	}
	//cout << "\n";
	for(int i =0;i < n; i++) {
		cin >> b[i];
		while(b[i]%2 == 0) b[i]/= 2;
		//cout << b[i] << " ";
	}
	//cout << "\n";
	// sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	multiset<int> aSet(a.begin(), a.end());
	//for(auto& x  : aSet) cout << x << ' ';
	//cout <<"\n";
	//set<int> bSet(b.begin(), b.end());
	for(int i = n-1; i >= 0;i--){
		//bool is_in = container.find(element) != container.end();
		//cout << b[i] << ",";
		while(aSet.find(b[i]) == aSet.end() && b[i] > 0){
			b[i]/=2;

		}
		//cout << b[i] << " | ";
		if(b[i] == 0) {cout << "NO\n"; return;}
		aSet.erase(aSet.find(b[i]));
	}
	//cout << "\n";
	//cout << ((a == b) ? "YES\n" : "NO\n");
	cout << "YES\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i =0;i < t; i++) solve();
}