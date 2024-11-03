#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sol(){
	int n;
	cin >> n;
	//vector<int> trace(n);
	vector<int> indices(2e5 + 10, 0);
	for(int i =0; i< n; i++){
		int trace;
		cin >> trace;

		indices[trace]++;
		cout << char(indices[trace] + 96);
	}
	cout << "\n";

}

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	
  	int t = 1; cin >> t;
  	for(int i =0;i < t; i++){
  		sol();
  	}
}	