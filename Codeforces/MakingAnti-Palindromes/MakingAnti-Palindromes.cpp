#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(int n){
	 string str;
	cin >> str;
	if(n%2) {cout << -1 << "\n"; return;}
	vector<int> problems;
	set<char> alphabet;
	vector<int> count(25, 0);
	for(int i = 0; i < n; i++){
		count[str[i]-'a']++;
	}
	for(int i : count){
		if(i > n/2) {cout << -1 << "\n"; return;}
	}
	for(int i = 0; i < 25; i++){
		alphabet.insert('a' + i);
	}
	for(int i = 0; i < n/2; i++){
		if(str[i] == str[n-i-1]) problems.push_back(i);
	}
	cout << problems.size()/2 + (problems.size() % 2) << "\n";

}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  while(cin >> t){
  	solve(t);
  }
}