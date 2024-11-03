// https://codeforces.com/contest/1797/problem/C

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x, y;
	cin >> x >> y;
	cout << "? 1 1\n";
	cout.flush();
	int dist, dist2, dist3;
	cin >> dist;
	if(dist == 0){
		cout << "! 1 1\n";
		cout.flush();
		return;
	} 

	if(dist >= x){
		cout << "? " << x << " " << dist+1 << "\n";
		cout.flush();
		cin >> dist2;
		cout << "! " << x -dist2<< " " << dist+1 << "\n";
		cout.flush();
		return;
	}
	if(dist >= y){
		cout << "? " << dist+1 << " " << y << "\n";
		cout.flush();
		cin >> dist2;
		cout << "! " << dist+1<< " " << y -dist2 << "\n";
		cout.flush();
		return;
	}
	cout << "? " << dist+1 << " " << dist+1 << "\n";
	cout.flush();
	cin >> dist2;
	if(dist2 == 0){
		cout << "! " << dist+1 << " " << dist+1 << "\n";
		cout.flush();
		return;
	} 
	cout << "? 1" << " " << dist+1 << "\n";
	cout.flush();
	cin >> dist3;
	if(dist3 == dist - dist2) {
		cout << "! " << dist - dist2+1 << " " << dist+1 << "\n";
		cout.flush();
	}else{
		cout << "! " << dist+1  << " " << dist - dist2+1 << "\n";
		cout.flush();
	}
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0; i < t; i++) solve();
}