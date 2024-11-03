#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N; 
  cin >> N;
  vector<int> arr;
  for(int i = 0; i < N; i++){
    int num;
    cin >> num;
    arr.push_back(num);
  }
  int ans = 0;
  for(int i = 0; i < N; i++){
    int sum = 0;
    for(int j = i; j < N; j++){
      sum += arr[j];
      for(int k = i; k < j+1; k++){
        if(((float) arr[k]) == ((float)((float)sum) / (float)(j-i+1))){
          ans++;
          break;
        }
      }
    }
  }
  cout << ans;
}