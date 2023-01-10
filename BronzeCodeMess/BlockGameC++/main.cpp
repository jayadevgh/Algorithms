#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("blocks.in","r",stdin);
	freopen("blocks.out","w",stdout);
  int n;
  cin >> n;
  vector<int> xyz(26, 0);
  vector<int> f(26);
  vector<int> s(26);
  for(int i = 0; i < n; i++){
    string a, b;
    cin >> a >> b;
    fill(f.begin(), f.end(), 0);
    fill(s.begin(), s.end(), 0);
    for(int j = 0; j < a.size(); j++){
      f[(int)a[j] - 97]++;
    }
    for(int j = 0; j < b.size(); j++){
      s[(int)b[j] - 97]++;
    }
    for(int j = 0; j < 26; j++){
      xyz[j] += max(f[j], s[j]);
    }
  }
  for(int i = 0; i < 26; i++){
    cout << xyz[i] << '\n';
  }
}