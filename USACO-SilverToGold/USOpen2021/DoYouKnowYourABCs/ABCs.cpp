#include <iostream>
#include <bits/stdc++.h>
using namespace std;


void ans(){
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i =0;i < n; i++) cin >> arr[i];
	int ps = 0;
	sort(arr.begin(), arr.end());
	set<set<int>> triplets;
	if(n == 4){
		vector<int> arr(4);
		cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
		int f, s, t, fo;
		sort(arr.begin(), arr.end());
		f= arr[0];
		s= arr[1];
		t = arr[2]; 
		fo = arr[3];
		if(f+s+t == fo) 
	}
}





int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	int t;
  	cin >> t;
  	while(t--) ans();
}