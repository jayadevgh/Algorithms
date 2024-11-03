#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<int> arr(n);
  for(int i =0; i< n; i++){
  	cin >> arr[i];
  }
  int t; cin >> t;
  for(int i = 0 ; i < t; i++){
  	int a, b;
  	cin >> a >> b;
  	arr[a-1] = arr[a-1] + arr[b-1];
  	for(int x : arr){
  		cout << x << " ";
  	}
  	cout << "\n";
  }
}