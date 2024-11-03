#include <iostream>
#include <bits/stdc++.h>
using namespace std;

	int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	for(int i = 0; i < t; i++){
		int n; cin >> n;
		vector<int> arr(n);
		for(int j = 0; j < n; j++) cin >> arr[j];
		int sum = 0, xsum = 0, xsum2 = 0;
		for(int j = 0; j < n; j++){
			sum += arr[j];
			xsum ^= arr[j];

		}

		cout << 4 << "\n"; 
		cout << 1 << " " << n << "\n";
		// for(int j =0;j < n; j++)cout << xsum << " ";
		// cout << "\n";
		cout << 1 << " " << n-(n%2) << "\n";
		// xsum =0;
		// xsum2 = xsum;
		// for(int j =0; j < n-(n%2); j++){
		// 	xsum ^= xsum;
		// 	//cout << xsum << ", ";
		// }
		//for(int j =0;j < n-(n%2); j++)cout << xsum << " ";
		// if(n%2) cout << arr[n-1];
		// cout << "\n";
		cout << n-(n%2) << " " << n << "\n";
		cout << n-(n%2) << " " << n << "\n";
		// if(xsum > 0){
			
		// }
		// else if(xsum == 0 && sum == 0){
		// 	cout << 0 << "\n";
		// }else{
		// 	cout << 1 << "\n";
		// 	cout << 1 << " " << n << "\n";
		// }
	}
}