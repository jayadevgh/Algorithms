#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sol(){
	int n;
	string s;
	cin >> n >> s;
	int firstB = -1;
	int lastB = 0;
	for(int i =0;i < n; i++){
		if(s[i] == 'B'){
			if(firstB == -1) firstB = i;
			lastB =i;
		}
	}
	cout << lastB - firstB + 1 << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t = 1; cin >> t;
  	for(int i =0; i < t; i++){
  		sol();
  	}
}