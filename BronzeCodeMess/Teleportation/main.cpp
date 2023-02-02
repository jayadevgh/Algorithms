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
  freopen("teleport.in","r",stdin);
	freopen("teleport.out","w",stdout);
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int dist = INT_MAX;
  dist = min(dist, abs(b-a));
  dist = min(dist, abs(a-x) + abs(b-y));
  dist = min(dist, abs(a-y) + abs(b-x));
  cout << dist;
}