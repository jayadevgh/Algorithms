// https://codeforces.com/contest/1753/problem/B

#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, x; 
  cin >> n >> x;
  vector<int> count(500001, 0);
  for(int i =0; i < n; i++){
  	int x; cin >>x;
  	count[x]++;
  }
  bool ans = true;
  for(int i = 0 ; i < x; i++){
  	if(count[i] % (i+1) != 0){
  		ans = false; 
  		//cout << "bad"; 
  		break;
  	}
  	else count[i+1] += count[i] / (i+1);
  }
  if(count[x] == 0){
  	//cout << "bad2";
  	ans = false;
  }
  
  if (ans) cout << "Yes";
  else cout << "No";
}
