#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("lostcow.in","r",stdin);
	freopen("lostcow.out","w",stdout);
  int x;
  int y;
  cin >> x >> y;
  int dist = y-x;
  int pattern_break=0;
  if(dist > 0){
    pattern_break = 2*ceil(log(dist)/log(4));
    
  }
  if(dist < 0){
    pattern_break = ceil(log(-dist)/log(2));
    pattern_break += ((pattern_break%2)^1);
    
  }
  dist = abs(dist);
  int travel = 1;
  for(int i = 0; i < pattern_break; i++){
    travel += ceil(pow(2,i) + pow(2, i+1));
  }
  cout << travel - (ceil(pow(2,pattern_break))- dist);
}