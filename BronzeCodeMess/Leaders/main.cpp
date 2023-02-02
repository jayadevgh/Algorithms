#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //File
  int n;
  string str;
  cin >> n >> str;
  int fg = -1;
  int fh = -1;
  int lg = -1;
  int lh = -1;
  int tempg = 0;
  int temph = 0;
  vector<int> arr(n);
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    arr[i] = num;
    if(str[i] == 'G') {
      if(fg == lg) {
        tempg = i;
      } 
      lg = i;
    }
    if(str[i] == 'H') {if(fh == lh) {temph = i;} lh = i;}
  }
  fg = tempg;
  fh = temph;
  int ans = 0;
  if(fg < fh){
    if(arr[0] >= min(lg+1, fh+1)) ans++;
    for(int i = 1; i < fh; i++){
      if(arr[i] >= fh+1){ans++;}
    }
  }
  if(fh < fg){
    if(arr[0] >= min(lh+1, fg+1)) ans++;
    for(int i = 1; i < fg; i++){
      if(arr[i] >= fg+1) {ans++;}
    }
  }
  cout << ans;
}