#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b;
	cin >> a >> b;
	vector<vector<int>> dp(a+1, vector<int>(b+1, 0));
  	

  	for(int i =1;i <= a; i++){
  		for(int j =1;j <= b; j++){
  			int mini = INT_MAX;
  			if(i == j) {dp[i][j] = 0; continue;}

  			for(int k =1; k <= i/2; k++){
  				mini = min(mini, dp[k][j] + dp[i-k][j] + 1);
  			}
  			for(int k =1; k <= j/2; k++){
				mini = min(mini, dp[i][k] + dp[i][j-k] + 1);
  			}
  			dp[i][j] = mini;
  			//cout << dp[i][j] << " ";
  		}
  		//cout << "\n";
  	}
  	cout << dp[a][b];
}