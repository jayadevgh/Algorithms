#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int intlen(set<string> A, set<string> B){
  int len =0;
  for(string str : A){
    if(B.find(str) != B.end()) len++;
  }
  return len;
}
int main() {
  freopen("guess.in","r",stdin);
	freopen("guess.out","w",stdout);
  int n; 
  cin >> n;
  vector<set<string>> arr(n);
  for(int i = 0; i < n; i++){
    string temp;
    int num;
    cin >> temp >> num;
    for(int j = 0; j < num; j++){
      string trait;
      cin >> trait;
      arr[i].insert(trait);
    }
  }
  int ans =0;
  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++){
      ans = max(ans, intlen(arr[i], arr[j])+1);
    }
  }
  cout << ans;
}