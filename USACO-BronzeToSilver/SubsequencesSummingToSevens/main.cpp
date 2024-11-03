#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("div7.in","r",stdin);
	freopen("div7.out","w",stdout);
  int n;
  cin >> n;
  vector<int> psum(n+1);
  vector<int> compr(7, -1);
  int maxi = 0;
  psum[0] = 0;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    psum[i+1] = (psum[i] + num) % 7;
  }
  for(int i = 0; i < n; i++){
    if(compr[psum[i+1]] == -1){
      compr[psum[i+1]] = i+1;
    } else {
      maxi = max(maxi, i+1 - compr[psum[i+1]]);
    }
  }
  cout <<  maxi;
}
  