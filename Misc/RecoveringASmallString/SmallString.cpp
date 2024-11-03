#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void solve(){
	int n; cin >> n;
	string s = "aaa";
	n-= 3;
	if(n < 26){
		s[2] = n + 'a';
	}
	else{
		n-= 25;
		s[2] = 'z';
		if(n < 26){
			s[1] = n + 'a';

		}
		else{
			n-= 25;
			s[1] = 'z';
			s[0] = n + 'a';
		}

	}
	cout << s << "\n";
}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t;
  	while(t--) solve();
}