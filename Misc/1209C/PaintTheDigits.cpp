#include <iostream>
#include <bits/stdc++.h>
using namespace std;


// void solve(){
// 	int n; 
// 	string s;
// 	cin >> n >> s;

// 	if(n == 1){ cout << 1 << "\n"; return;}
// 	vector<int> cnt(n);
// 	char cnt1, cnt2;
// 	// if(s[0] < s[1]) {
// 	// 	cnt[0] = 1; 
// 	// 	cnt[1] = 2;
// 	// 	cnt1 = s[0];
// 	// 	cnt2 = s[1];
// 	// }
// 	if(s[0] > s[1]){
// 		cnt[1] = 1; 
// 		cnt[0] = 2;
// 		cnt1 = s[1];
// 		cnt2 = s[0];
// 	}
// 	int start = 1;

// 	while(s[start-1] <= s[start]){
// 		cnt[0] = 1;
// 		cnt[start] = 1;
// 		cnt1 = s[0];
// 		start++;
// 		if(start >= n) break;

// 	}
// 	if(s[0] <= s[1] && start < n){cnt[start] =2; cnt2 = s[start]; start++;}
	
// 	if(s[0] <=s[1] && s[start-1] < s[0]){
// 		for(int i =0; i < start-1; i++) cnt[i] = 2;
// 		cnt1 = s[start-1];
// 		cnt2 = s[0];
// 		cnt[start-1] =1;
// 	}

// 	for(int i =start; i < n; i++){
// 		if(s[i] >= cnt2){cnt2 = s[i]; cnt[i] = 2;}
// 		else if(s[i] >= cnt1){cnt1 = s[i]; cnt[i] = 1;}
// 		else {cout << "-\n"; return;} 
// 	}
// 	for(int i : cnt) cout << i;
// 	cout << "\n";
// }

void solve(){
	int n;
	string s;
	cin >> n >> s;
	vector<int> num(n, 2);
	int latest = 0;
	//int earliest = 0;
	int digbnd = 9;
	int leastele = 9;
	//bool check = true;
	for(int i =0; i< n; i++){
		int ele = s[i] - '0';
		if(ele < leastele){
			digbnd = leastele;
			leastele = ele;
		}
	}

	for(int dig =0; dig <= digbnd; dig++){
		int bnd = latest;
		for(int i = bnd; i< n ;i++ ){
			if(s[i] == dig+'0'){
				latest = max(latest, i);
				num[i] = 1;
			}
		}
	}
	vector<int> cur = {0, 0, 0};
	for(int i =0;i < n; i++){
		if(cur[num[i]] > s[i]-'0'){cout << "-\n"; return;}
		cur[num[i]] = s[i]-'0';
	} 
	for(int i : num) cout << i;
	cout << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	while(t--) solve();
}