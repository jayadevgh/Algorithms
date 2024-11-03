#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int half = N/2 + N%2;
  //cout << half;
  vector<int> arr(N);
  for(int i = 0; i < N; i++){
  	cin >> arr[i];
  }

  vector<int> cwWinSum(N);
  int sum = 0;
  for(int i = (N - (half)); i < N; i++){
  	sum += arr[i];
  }
  //iniSum += arr[0];

  for(int i = 0; i < N; i++){
  	int idx = i - half;
  	if(idx < 0) {idx = N+idx;}
  	//cout << arr[idx] << "\n";
  	sum -= arr[idx];
  	sum += arr[i];
  	cwWinSum[i] = sum;
  }
  // for(int i = 0; i < N; i++){
  // 	cout << cwWinSum[i] << "\n";
  // }

  vector<int> ccwWinSum(N);
  sum = 0;
  for(int i = 0; i < half; i++){
  	sum += arr[i];
  }

  for(int i = N-1; i >= 0; i--){
  	int idx = i + half;
  	if(idx >= N) idx -= N;
  	sum -= arr[idx];
  	sum += arr[i];
  	ccwWinSum[i] = sum;
  }
  int ans = INT_MIN;
  for(int i = 0; i < N; i++){
  	ans = max(ans, min(cwWinSum[i], ccwWinSum[i]));
  }
  cout << ans;


}