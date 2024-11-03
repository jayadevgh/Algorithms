#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
int coins[5];
vector<vector<int>> dp(1000, vector<int>(8));


void dp1(int num, int cycle){
	//if(cycle >= 6) return;
	cout <<dp[num][cycle] << " "<< num << " " << cycle << "\n";
	for(int i=num; i < num+5; i++){
		int val = num+5-i-1;
		if(coins[val] != 0){
			coins[val]--;
			dp[num+val+1][cycle+1] += dp[num][cycle];
			if(num+val+1 < n && cycle <6){

				dp1(num+val+1, cycle+1);

			}
			
			coins[val]++;
		}
	}

}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  cin >> coins[0] >> coins[1] >> coins[2] >> coins[3] >> coins[4];
  for(int i= 0;i < 5; i++){
  	dp[i+1][1] = (coins[i] > 0);
  	coins[i]--;
  	dp1(i+1, 1);
  	coins[i]++;
  }

  cout << dp[n][5];
}	