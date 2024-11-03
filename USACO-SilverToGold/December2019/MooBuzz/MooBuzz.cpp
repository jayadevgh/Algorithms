#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);
	freopen("moobuzz.in", "r", stdin);
	freopen("moobuzz.out", "w", stdout);
  	int N;
  	cin >> N;
  	vector<int> checker = {1, 2, 4, 7, 8, 11, 13, 14};

  	N--;
  	int ans = N/8 * 15 + checker[N % 8];
  	cout << ans;
}