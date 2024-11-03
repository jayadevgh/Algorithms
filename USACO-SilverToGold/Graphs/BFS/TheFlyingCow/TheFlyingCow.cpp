#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int K; cin >> K;
  vector<int> dp(3e6);
  dp[1] = 0;
  dp[2] = 1;
  dp[3] = 1;
  for(int i =2; i <= K; i++){
  	if(i % 3 ==0) dp[3 * i] = dp[i] + 1;
  	else if(i % 3 == 1){
  		dp[i] = min(dp[i-1] + 1, dp[i+2] + 2);
  		dp[i*3] = dp[i]+1;
  	}else{
  		if(i != 2) dp[i] = min(dp[i-2] + 2, dp[i+1] + 1);
  		dp[i*3] = dp[i]+1;
  	}
  	//cout << dp[i] << "\n";
  }
  cout << dp[K];
}