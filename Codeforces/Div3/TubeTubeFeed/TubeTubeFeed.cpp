#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void sol(){
	int n, t;
	cin >> n >> t;
	vector<int> time(n); vector<int> enter(n);
	for(int i = 0; i < n; i++){
		cin >> time[i];
	}
	for(int i = 0; i < n; i++){
		cin >> enter[i];
	}
	int ans = -2;
	int maxe = -1;
	for(int i =0; i < n; i++){
		//cout << time[i] << " "<< enter[i] << " ";
		if(time[i] <= (t-i) && enter[i] > maxe) {ans =i; maxe = enter[i];}
	}
	cout << ++ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i)
  {
  	sol();
  }
}