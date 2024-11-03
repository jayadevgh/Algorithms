#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N; 
	cin >> N;
	vector<int> arr(N, 0);
  	for(int i =0; i < N; i++){
  		cin >> arr[i];
  	}
  	sort(arr.begin(), arr.end());
  	int mini = arr[0]/4;
  	int ah = arr[0];
  	set<int> nums;
  	int l = INT_MAX;
  	for(int i =0;i < N; i++){
  		arr[i] -= ah;
  		if(nums.size() < 3) nums.insert(arr[i]);
  		//cout << arr[i] << " ";
  		if(nums.size() == 3) l = arr[i];
  	}

  
  	if(N > 3) mini= min(mini, l);
  	//cout << mini << " ";
  	int sum = 0;
  	for(int i =1; i <= mini; i++){
  		set<int> x;
  		for(int j =0;j < N; j++){
  			//if(i == 5) cout << arr[j] % i << " ";
  			x.insert(arr[j] % i);
  			if(x.size() > 3){
  				break;
  			}
  			if(j == N-1) {
  				cout << i;
  				sum += i;
  			}
  		}

  	}
  	cout << sum;
}