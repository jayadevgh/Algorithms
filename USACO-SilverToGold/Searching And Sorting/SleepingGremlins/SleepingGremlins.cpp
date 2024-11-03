#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N, K, B;
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K >> B;
  vector<bool> arr(N, true);
  for (int i = 0; i < N; ++i){
  	int x; cin >> x;
  	arr[x-1] = false;
  }
  //window
  int ans = INT_MAX;
  int sleepCount = 0;
  for (int i = 0; i < K; ++i){
  	sleepCount += arr[i] ^ 1;
  }
  ans = sleepCount;
  int lo = 0;
  for (int hi = K; hi < N; hi++)
  {
  	sleepCount -= arr[lo] ^1;
  	sleepCount += arr[hi] ^1;
  	ans = min(ans, sleepCount);
  	lo++;
  }
  cout << ans;
}