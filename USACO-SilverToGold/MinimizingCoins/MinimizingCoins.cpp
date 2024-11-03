#include <iostream>
#include <bits/stdc++.h>
using namespace std;

 
int main() {
  //Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> dp(1e6+1, -1);
	vector<int> val(n);
	//int lar = 0;
	for(int i = 0; i < n; i++){
		int num;
		cin >> num;
		dp[num] = 1;
		val[i] = num;
		//lar = num;
	}
	//sort(val.be)
	for(int i = 1; i <= x; i++){
		for(int j = 0; j < n; j++){
	  		if(val[j] == i){
	  			dp[i] = 1;
	  		}
	  		else if(i < val[j]) continue;
		  	else if(dp[i - val[j]] != -1){
		    
		    	if(dp[i] == -1) dp[i] = dp[i - val[j]] + 1;
		    	else dp[i] = min(dp[i], dp[i - val[j]] + 1);
		  	}
		}
	}
	cout << dp[x];
  
}