#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cbarn.in","r",stdin);
	freopen("cbarn.out","w",stdout);
  int n;
  cin >> n;
  vector<int> rooms(n);
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    rooms[i] = num;
  }
  int ans = INT_MAX;
  
  for(int i = 0; i < n; i++){
    int sum = 0;
    int count = i;
    for(int j = 0; j < n; j++){
      sum += rooms[count] * j;
      count++;
      if(count == n) count = 0;
    }
    ans = min(ans, sum);
  }
  cout << ans;
}