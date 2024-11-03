#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("sleepy.in","r",stdin);
	freopen("sleepy.out","w",stdout);
  int n; 
  cin >> n;
  int ans = 0;
  int prev = 0;
  for(int i =0; i < n; i++){
    int num;
    cin >> num;
    if(prev > num){
      ans = i;
    }
    prev = num;
  }
  cout << ans;
}