#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){

    int n;
    cin >> n;
    int parodd = -1;
    int pareven = -1;
    bool possible = true;
    for(int j = 0; j < n; j++){
      int num;
      cin >> num;
      if(j%2 == 1){
        if(parodd == -1) parodd = num%2;
        if(num%2 != parodd%2) possible = false;
      }
      if(j%2 == 0){
        if(parodd == -1) pareven = num%2;
        if(num%2 != pareven%2) possible = false;
      }
    }
    if(possible) cout << "YES" << "\n";
    else cout << "NO" << "\n";
  }
}