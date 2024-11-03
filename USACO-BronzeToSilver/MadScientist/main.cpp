#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("breedflip.in","r",stdin);
	freopen("breedflip.out","w",stdout);
  int n;
  string a, b;
  cin >> n >> a >> b;
  int op = 0;
  bool seq = false;
  for(int i = 0; i < n; i++){
    char ai = a[i];
    char bi = b[i];
    if(!seq && ai != bi) seq = true;
    if(seq && ai == bi){
      seq = false;
      op++;
    }
  }
  if(seq) op++;
  cout << op;
}