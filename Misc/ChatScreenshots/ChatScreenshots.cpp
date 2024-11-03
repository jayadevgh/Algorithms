#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n, k;
	vector<int> arr(n-1);
	int fir; cin >> fir;
	for(int i =1;i < n; i++){
		cin >> arr[i-1];
	}
	k--;

	//vector<int> query(n-1);
	vector<int> fin;
	bool ans = true;
	int adder = 0;
	if(k > 0){
		cout << "HI ";
		int temp; cin >> temp;
		for(int i =0;i < n; i++){
			int x; cin >> x; 
			if(arr[i+adder] == temp) {
				fin.push_back(arr[i+adder]);
				adder = 1;
				continue;
			}
			
			 else if(x == fir){
				fin.push_back(x);
				continue;
			}else{
				ans = false;
			}
		}
		for(int i =0; i < n; i++) cout << fin[i] << " ";
		if(!ans) {cout << "NO\n"; return; } 
	}
	if(ans) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	for(int i = 0;i < t; i++) solve();
}