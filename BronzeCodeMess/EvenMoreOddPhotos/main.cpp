#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> parity(2); //even = parity[0], odd = parity[1]
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    parity[num%2]++;
  }
  int ans = 0;
  int counter = 0;
  while(true){
    if(counter == 0){
      if(parity[0] > 0){
        parity[0]--;
        ans++;
      }else if(parity[1] > 1){
        parity[1] -= 2;
        ans++;
      }else{
        break;
      }
    }
    if(counter == 1){
      if(parity[1] > 0){
        parity[1]--;
        ans++;
      }else{
        break;
      }
    }
    counter = (counter+1)%2;
  }
  if(parity[1] == 1 && counter == 0){
    ans--;
  }
  cout << ans;
}