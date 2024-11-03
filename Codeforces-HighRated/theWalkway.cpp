// https://codeforces.com/contest/1858/problem/B

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n, m, d;
	cin >> n >> m >> d;
	vector<int> arr(m+2);
	for(int i =0;i < m; i++){
		cin >> arr[i+1];
	}
	arr[0] = 1;
	arr[m+1] = n;
	int ans = 0;
	int count = 0;
	for(int i= 1; i <= m; i++){

		int removed = 0, with = 0;
		if(i >= 2 && i < m){
			removed = (arr[i+1] - arr[i-1] -1)/d + 2; 
			with = (arr[i+1] - arr[i] -1)/d + (arr[i] - arr[i-1]-1)/d +3;


		}
		else if(i == 1){
			removed = (arr[2] - arr[0]-1)/d + 1;

			with = (arr[2] - arr[1]-1)/d + 2;
			if(arr[1] != arr[0]) with += ((arr[1] - arr[0]-1)/d);
			else with = removed;
			//cout << "hi ";
		}
		else if(i == m){
			removed = (arr[m+1] - arr[m-1])/d+1;
			with = (arr[m+1] - arr[m])/d + (arr[m] - arr[m-1] -1)/d + 2;
			//cout << (arr[m+1] - arr[m])/d << " ";
		}
		//cout << removed << " " << with << ", ";
		int tempans = removed - with;
		if(tempans < ans){
			ans = tempans;
			count = 1;
		}
		else if(tempans == ans){
			count++;
		}
		//cout << tempans << " | ";
	}




	int sum = 1;
	for(int i = 1;i <= m; i++){
		if(arr[i] == 1) continue;
		sum += (arr[i] - arr[i-1]-1)/d + 1;
	}	
	sum += (arr[m+1] - arr[m])/d;
	ans += sum;
	cout << ans << " " << count << "\n";

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t; cin >> t;
  for(int i =0;i < t; i++) solve();
}