#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N; cin >> N;
  for(int i = 0; i < N; i++){
  	int k;
  	cin >> k;
  	string str;
  	cin >> str;
  	string ans;
  	char cur = str[0];
  	for(int j = 1; j < k; j++){
  		if (str[j] == cur) {
  			ans += cur;
  			if(j+1 < k) {j++; cur = str[j];}
  		}
  	}
  	cout << ans << "\n";
  }
}