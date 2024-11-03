#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> req(102, 0);
vector<int> stalls(102);
vector<vector<int>> ac(10, vector<int>(4));
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  //File
  int n, m;
  cin >> n >> m;
  int const l = m;
  for(int i = 0; i < n; i++){
    int s, t, c;
    cin >> s >> t >> c;
    req[s] += c;
    req[t+1] -= c;
  }
  for(int i = 0; i < m; i++){
    int a, b, p, m;
    cin >> a >> b >> p >> m;
    ac[i][0] = a;
    ac[i][1] = b;
    ac[i][2] = p;
    ac[i][3] = m;
  }
  int ans = INT_MAX;
  for(int i = 1; i < pow(2, m); i++){
    stalls = req;
    bitset<10> bin(i);
    // cout << bin.to_string() << "\n";
    int cost = 0;
    for(int j = 0; j < m; j++){
      if(bin[j] == 1){
        // cout << j << "\n";
        stalls[ac[j][0]] -= ac[j][2];
        stalls[ac[j][1]+1] += ac[j][2];
        cost += ac[j][3];
      }
    }
    int g0 = INT_MIN;
    for(int i = 1; i < 101; i++){
      stalls[i+1] += stalls[i];
      g0 = max(stalls[i], g0);
    }
    if(g0 <= 0) ans = min(ans, cost);
  }
  cout << ans;
}