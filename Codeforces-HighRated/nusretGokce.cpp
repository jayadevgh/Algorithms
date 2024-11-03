// https://codeforces.com/gym/104114/problem/N

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	vector<int> s(n);

	priority_queue<pair<int, int>> first_salt;
	for(int i =0;i < n; i++) {
		cin >> s[i];
		first_salt.push(make_pair(s[i], i));
		s[i] =0;
	}
	while(!first_salt.empty()){
		pair<int, int> piece = first_salt.top();
		first_salt.pop();
		if(s[piece.second] < piece.first){
			s[piece.second] = piece.first;
			if(piece.second > 0) first_salt.push(make_pair(piece.first - m, piece.second-1));
			if(piece.second <n-1) first_salt.push(make_pair(piece.first - m, piece.second+1));
		}
		
	}	
	for(int p : s) cout << p << " ";
  	
}