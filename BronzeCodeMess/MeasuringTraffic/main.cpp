#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
  int n; 
  cin >> n;
  vector<string> set(n);
  vector<int> lbnd(n);
  vector<int> ubnd(n);
  vector<int> range(2);
  vector<int> irange(2);
  range[0] = 0;
  range[1] = 1001;
  irange[0] = 0;
  irange[1] = 1001;
  for(int i = 0; i < n; i++){
    string setting;
    int start, end;
    cin >> setting >> start >> end;
    set[i] = setting;
    lbnd[i] = start;
    ubnd[i] = end;
  }
  //initial range
  bool none = false;
  for(int i = n-1; i >= 0; i--){
    if(!none && set[i] != "none"){
      continue;
    }
    none = true;
    if(set[i] == "none"){
      irange[0] = max(irange[0], lbnd[i]);
      irange[1] = min(irange[1], ubnd[i]);
    }
    if(set[i] == "on"){
      irange[0] -= ubnd[i];
      irange[1] -= lbnd[i];
    }
    if(set[i] == "off"){
      irange[0] += lbnd[i];
      irange[1] += ubnd[i];
    }
  }
  if (irange[0] < 0) irange[0] = 0;
  cout << irange[0] << " " << irange[1] << "\n";
  //Final Range
  none = false;
  for(int i = 0; i < n; i++){
    if(!none && set[i] != "none"){
      continue;
    }
    none = true;
    if(set[i] == "none"){
      range[0] = max(range[0], lbnd[i]);
      range[1] = min(range[1], ubnd[i]);
    }
    if(set[i] == "on"){
      range[0] += lbnd[i];
      range[1] += ubnd[i];
    }
    if(set[i] == "off"){
      range[0] -= ubnd[i];
      range[1] -= lbnd[i];
    }
  }
  if (range[0] < 0) range[0] = 0;
  cout << range[0] << " " << range[1];
}