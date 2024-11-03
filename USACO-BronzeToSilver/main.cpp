#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int solve(){
  int l, r, x, a, b;
  cin >> l >> r >> x >> a >> b;
  int op = 0;
  bool lbool = (b-l) >= x;
  bool rbool = (r-b) >= x;
  if(a == b) return op;
  else if(abs(a-b) >= x) {op = 1; return op;}
  else if(!lbool && !rbool){op = -1; return op;}
  if(lbool){
    if(a-l >= x) op = 2;
    else if(r-a >= x) op = 3;
    else op = -1;
  }
  if(rbool){
    if(r-a >= x) op = min(op, 2);
    else if(a-l >= x) op = 3;
    else op = -1;
  }
  
  return op;
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; 
  cin >> t;
  for(int i = 0; i < t; i++){cout << solve() << "\n";}
}