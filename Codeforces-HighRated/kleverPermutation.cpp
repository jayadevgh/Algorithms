// https://codeforces.com/contest/1927/problem/E

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// We start off with k numbers 
// ex  1 4 8 10
// then next number based on first of last k sequence (+ or -)
// ex 1 - 4 8 10 2 - 
// 1 4 - 8 10 2 3
// but we have to be careful with the starting sequence

// 1  2     3   4 
// 1 15 6 20 2 14 7 19 3 13 8 18 4 12 9 17 5 11 10 16
// 1 17 7 22 2 16 6 
// q= n /k + r
// 1, n-2q, 1+q,n-q , 1+2q, n

// k = 4 n = 14
// 1 11 5 14 2 10 6 13 3 9 7 12 4 8 
void solve(){
	int n, k;
  	cin >> n >> k;
  	vector<int> arr(n, -1);
  	int countere = 1;
  	int countero = n;

  	for(int sp= 0; sp < k; sp++){
  		for(int jmp = sp; jmp < n; jmp += k){
  			if(sp%2) {arr[jmp] = countero; countero--;}
  			else {
  				arr[jmp] = countere; 
  				countere++;
  			}
  		}
  	}

  	for(int i : arr) cout << i << " ";
  	cout << "\n";
}
int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t; cin >> t;
  	while(t--){
  		solve();
  	}
}