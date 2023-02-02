#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int triarea2(int a, int b){
  return a * b;
}
int main() {
  //Console
  freopen("triangles.in","r",stdin);
	freopen("triangles.out","w",stdout);
  int n;
  cin >> n;
  vector<pair<int, int>> v;
  vector<pair<int, int>> v2;
  for(int i = 0; i < n; i++){
    pair<int, int> coord;
    cin >> coord.first >> coord.second;
    v.push_back(coord);
    v2.push_back(coord);
  }
//   sort(v.begin(), v.end(), [](auto &left, auto &right) {
//     return left.second > right.second;
// });
//   sort(v2.begin(), v2.end(), [](auto &left, auto &right) {
//     return left.second < right.second;
// });
  int areamax = 0;
  for(int i = 0; i < n; i++){
    int begin = v[i].first;
    
    for(int j = i+1; j < n; j++){
      int dim1 = 0;
      int dim2j = 0;
      int dim2i = 0;
      if(begin == v[j].first){
        dim1 = abs(v[j].second - v[i].second);
        for(int k = 0; k < n; k++){
          if(k== i || k== j) continue;
          if(v[k].second == v[j].second){
            dim2j = max(dim2j, abs(v[k].first - v[j].first));
          }
          if(v[k].second == v[i].second){
            dim2i = max(dim2i, abs(v[k].first - v[i].first));
          }
        }
      }
      int dim2 = max(dim2i, dim2j);
      areamax = max(areamax, triarea2(dim1, dim2));
    }
    //cout << areamax << "\n";
  }
  cout << areamax;
}