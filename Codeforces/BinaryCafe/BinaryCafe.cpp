#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
  int t;
  cin >> t;
  for(int i = 0; i < t; i++) {
    ll n, k;
    cin >> n >> k;
    ll power = (k > 62) ? n+1 : pow(2, k);
    power = min(n+1, power);
    cout << power<< "\n";
  }

}