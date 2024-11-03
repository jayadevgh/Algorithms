#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}
void solve(){
	int n; cin >> n;
	vector<int> arr;
	set<int> s;
	arr.push_back(1);
	cout << 1 << " ";
	for(int i =2;i <= n; i++){
		int x = i;
		if(s.find(x) != s.end()) continue;
		while(x <= n){
			cout << x << " ";
			arr.push_back(x);
			s.insert(x);
			x *= 2;
		}
	}
	//if (n == 10) arr = {1, 2, 3, 4, 8, 5, 10, 6, 9, 7};
	for(int i =0; i < n-1; i++){
		//cout << gcd(arr[i], arr[i+1]) << " ";
	
	}
	//cout << gcd(arr[n-1], arr[0]);
	cout << "\n";	
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}