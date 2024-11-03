#include <bits/stdc++.h>
#include <iostream>
#define ll long long
using namespace std;
int intVal(char x){
  return (int)x-65;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int g, y;
  g = 0;
  y = 0;
  vector<int> count(26);
  vector<int> pos(9);
  for(int i = 0; i < 3; i++){
    string s;
    cin >> s;
    for(int j = 0; j < 3; j++){
      pos[(3*i) + j] = s[j];
      count[intVal(s[j])]++;
    }
  }
  for(int i = 0; i < 3; i++){
    string s;
    cin >> s;
    for(int j = 0; j < 3; j++){
      if(pos[(3*i) + j] == s[j]){
        g++;
        count[intVal(s[j])]--;
        if(count[intVal(s[j])] < 0){
          y--;
        }
      }else if(count[intVal(s[j])] > 0){
        count[intVal(s[j])]--;
        y++;
      }
    }
  }
  cout << g << "\n" << y;
}