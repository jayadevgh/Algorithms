// https://codeforces.com/contest/1833/problem/D

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
vector<int> flipper(int l, int r){
	vector<int> beg(arr.begin(), arr.begin()+l);
	vector<int> mid(arr.begin() + l, arr.begin() + r);
	vector<int> en(arr.begin()+r, arr.end());
	reverse(mid.begin(), mid.end());
	vector<int> flip;
	flip.insert(flip.end(), en.begin(), en.end());
	flip.insert(flip.end(), mid.begin(), mid.end());
	flip.insert(flip.end(), beg.begin(), beg.end());
	return flip;

}
bool compare(vector<int> ans, vector<int> test){
	for(int i =0;i < ans.size(); i++){
		if(ans[i] > test[i]) return false;
		else if (ans[i] < test[i]) return true;
	}
	return false;
}
void solve(){
	int n; cin >> n;
	vector<int> ans(n);
	arr.clear();
	arr.resize(n, 0);
	int f; int s;
	for(int i =0 ; i < n; i++) {
		int x; cin >> x;
		arr[i]=x;
		if(x == n) f = i;
		if(x == n-1) s = i;
		if(n == 1) {cout << 1 << "\n"; return;}
	}
	if(f == 0){
		for(int i = 0; i < s; i++){
			vector<int> test = flipper(i, s);
			if(compare(ans, test)) ans = test;
		}
		vector<int> test = flipper(s, n);
		if(compare(ans, test)) ans = test;
	}else{
		for(int i = 0; i < f; i++){
			vector<int> test = flipper(i, f);
			if(compare(ans, test)) ans = test;
		}
		vector<int> test = flipper(f, n);
		if(compare(ans, test)) ans = test;

	}
	for(int x : ans) cout << x << " ";
	cout << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0 ; i< t; i++) solve();
}
