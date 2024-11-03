#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N;
//vector<int> prefixSum;
vector<int> v;
vector<vector<int>> grid;
int ans = 0;
int sumFinder(){
  int ans3 = INT_MIN;
  for(int i = 0; i < N; i++){
    int sum = 0;
    int ans2 = INT_MIN;
    for(int j =0; j < N; j++){
      sum += v[j];
      ans2 = max(ans2, sum);
      if(sum < 0) sum = 0;
      //cout << v[j] << " ";
    }
    ans3 = max(ans2, ans3);
    rotate(v.begin(), v.begin() + 1, v.end());
    //cout << "\n";
  }
  return ans3;
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  //prefixSum.resize(N+1);
  //prefixSum[0] = 0;
  v.resize(N);
  grid.resize(N, vector<int>(N));

  vector<int> ansv;

  // for(int i =0 ; i < N; i++){
  //   cin >> v[i];
  // }
  // cout << sumFinder();
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      cin >> grid[i][j];
    }
  }
  for(int i = 0; i < N; i++){
    for(int j =0; j < N; j++){
      v[j] = grid[i][j];
    }
    int x = sumFinder();
    if(ans < x){ 
      ans = x;
      ansv = v;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j =0; j < N; j++){
      v[j] = grid[j][i];
    }
    int x = sumFinder();
    if(ans < x){ 
      ans = x;
      ansv = v;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      v[j] = grid[j%N][(i + j) % N];
      //cout << v[j] << " ";
    }
    //cout <<"\n";
    int x = sumFinder();
    if(ans < x){ 
      ans = x;
      ansv = v;
    }
  }
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      v[j] = grid[(N-j-1)%N][(i + j) % N];
      //cout << v[j] << " ";
    }
    //cout <<"\n";
    int x = sumFinder();
    if(ans < x){ 
      ans = x;
      ansv = v;
    }
  }
  cout << ans << "\n";
  // for(int i = 0; i < N; i++){
  //   cout << ansv[i] << " ";
  // }
}