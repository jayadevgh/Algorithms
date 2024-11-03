#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;

  vector<int> v(N);
  for(int i =0; i < N; i++){
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  vector<int> bestLeft(N+1);
  bestLeft[0] = 0;
  vector<int> bestRight(N+1);
  bestRight[N] = 0;
  int ans = 0;
  int lo, hi; lo = 0;
  for(int i = 1; i <= N; i++){
    hi = i-1;
    while(v[lo] < (v[hi] - K)){
      lo++;
    }
    bestLeft[i] = (max(bestLeft[i-1], hi-lo + 1));
  }
  lo = N-1;
  for(int i = N-1; i >= 0; i--){
    hi = i;
    while(v[lo] > (v[hi] + K)){
      lo--;
    }
    bestRight[i] = (max(bestRight[i+1], lo - hi + 1));
  }
  for(int i = 0; i <= N; i++){
    ans = max(ans, bestLeft[i] + bestRight[i]);
  }
  cout << ans;
}