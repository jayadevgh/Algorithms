#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int solve(){
	int n; cin >> n; 
	vector<int> arr(n);
	for(int i =0; i < n; i++) cin >> arr[i];

	int fi = arr[0];
	int li = arr[n-1];
	int fl = 0; int ll = 0;
	bool check1 = true; bool check2 = true;
	for(int i =0;i < n; i++){
		if(check1 && fi == arr[i]) fl++;
		else check1 = false;
		if(check2 && li == arr[n-1-i]) ll++;
		else check2 = false;
	}
	if(fl == n) return 0;
	if(fi == li) return n - fl - ll;
	else return n- max(fl, ll);
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t;
  	while(t--) cout << solve() << "\n";
}