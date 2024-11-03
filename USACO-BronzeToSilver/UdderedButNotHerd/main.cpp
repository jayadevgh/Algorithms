#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string alphabet, str;
  cin >> alphabet >> str;
  int ans = 0;
  int count = 0;
  while (true){
    for(int i = 0; i < alphabet.size(); i++){
      if(count < str.size()){
        if(alphabet[i] == str[count]){
          count++;
        }
      }
    }
    ans++;
    if(count == str.size()){
      break;
    }
  }
  cout << ans;
}