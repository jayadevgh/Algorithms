#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<vector<int>> pmat(n+1, vector<int>(n+1, 0));
  for(int i = 0; i < n; i++){
    string str;
    cin >> str;
    for(int j = 0; j < n; j++){
      if(str[j] == '*') {
        pmat[i+1][j+1]++;
      }
    }
  }
  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= n; j++){
      pmat[i][j] += pmat[i-1][j] + pmat[i][j-1] - pmat[i-1][j-1];
      // cout << pmat[i][j];
    }
    // cout << '\n';
  }
  for(int i = 0; i < q; i++){
    int x1, x2, y1, y2;
    cin >> y1 >> x1>> y2 >> x2;
    cout << pmat[y2][x2] - pmat[y2][x1-1] - pmat[y1-1][x2] + pmat[y1-1][x1-1] << '\n';
    
  }

}