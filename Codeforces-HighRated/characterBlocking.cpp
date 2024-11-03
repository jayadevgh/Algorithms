// https://codeforces.com/contest/1840/problem/E

#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

// int binarySearch(string s, string s1, int n){
// 	int lo = 0;
// 	int hi = n;
// 	while(lo < hi){
// 		int mid = lo + (hi-lo+1)/2;
// 		string temp = s.substr(0, mid);
// 		string temp2 = s1.substr(0, mid);
// 		if(temp == temp2){
// 			lo = mid;
// 		}else{
// 			hi = mid-1
// 		}
// 	}
// 	return lo;
// }

void solve(){
	vector<string> s(2);
	cin >> s[0] >> s[1];
	int n = s[0].size();
	int t, q;
	cin >> t >> q;
	int bad = 0;
	for(int i =0;i < n; i++){
		//cout << s[0][i] << " " << s[1][i] << " ";
		if(s[0][i] != s[1][i]) bad++;
	}
	//cout << bad << " ";
	queue<ii> SIdxIdx;
	for(int i =0;i < q; i++){
		int x; cin >> x;
		while(SIdxIdx.size() > 0 && i-SIdxIdx.front().second >= t){
			int idx = SIdxIdx.front().first;
			if(s[0][idx]!=s[1][idx]) bad++;
			SIdxIdx.pop();
		}

		if(x == 1){
			int idx; cin >> idx; idx--;
			if(s[0][idx] != s[1][idx]) bad--;
			SIdxIdx.push(make_pair(idx, i));
			//cout << bad << " - 1\n";
		}
		if(x == 2){
			int a, b, c, d;
			cin >> a >> b >> c >> d;
			a--; b--; c--; d--;
			if(s[a][b] != s[a^1][b]) bad--;
			if(s[c][d] != s[c^1][d]) bad--;
			swap(s[a][b], s[c][d]);
			if(s[a][b] != s[a^1][b]) bad++;
			if(s[c][d] != s[c^1][d]) bad++;
			//cout << bad << " - 2\n";
		}
		if(x == 3){
			cout << ((bad > 0) ? "NO\n" : "YES\n"); 
		}
	}
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++){
  	solve();
  }
}