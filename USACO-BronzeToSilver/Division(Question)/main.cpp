#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    int num, div;
    div = 0;
    cin >> num;
    if(num < 1400){
      div = 4;
    }else if (num < 1600){
      div = 3;
    }else if(num < 1900){
      div  = 2;
    }else{
      div = 1;
    }
    cout << "Division " << div << '\n';
  }
}