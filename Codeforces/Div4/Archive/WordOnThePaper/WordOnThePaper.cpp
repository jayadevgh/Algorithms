#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){
  	string x = "";
  	for(int j = 0; j < 8; j++){
  		string str;
  		cin >> str;
  		for(int k = 0; k < 8; k++){
  			if(str[k] != '.') x += str[k];
  		}
  	}
  	cout << x << "\n";
  }
}