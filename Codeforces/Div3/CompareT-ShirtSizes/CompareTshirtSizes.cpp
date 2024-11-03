#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_map<char, int> um;
  um['S'] = -1;
  um['M'] = 0;
  um['L'] = 1;
  int n; cin >> n;

  for(int i =0; i < n; i++)
  {
  	string a, b;
  	cin >> a >> b;
  	int as = um[a[a.length()-1]];
  	int bs = um[b[b.length()-1]];
  	int asum = as * a.length();
  	int bsum = bs * b.length();
  	if(asum > bsum) cout << ">\n";
  	else if(asum == bsum) cout << "=\n";
  	else cout << "<\n";
  }
}