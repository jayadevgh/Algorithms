#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int mod = (1e9)+7;
char s[5005], t[5005];
 
int a[5005][5005], i, j, ans;
int dp[5003][5003];
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //string s, t;
  cin >> s >> t;
  // int i, j;
  
  // for(i = 0;i < s.size(); i++){
  // 	for(j = 0; j< t.size(); j++){
  // 		dp[i+1][j+1] = (dp[i+1][j] + ((t[j] == s[j]) * (dp[i][j]+1))) % mod;
  // 	}
  // }
  // int ans = 0;
  // for(i =0;i < s.size(); i++) ans =(ans+ dp[i+1][j])%mod;
  // cout << ans;
	
	for (i = 0; s[i]; i++)
	    for (j = 0; t[j]; j++)
	      a[i + 1][j + 1] = (a[i + 1][j] + (t[j] == s[i]) * (a[i][j] + 1)) % mod;
 
    for (i = 0; s[i]; i++)
      ans = (ans + a[i + 1][j]) % mod;
  cout << ans;
}