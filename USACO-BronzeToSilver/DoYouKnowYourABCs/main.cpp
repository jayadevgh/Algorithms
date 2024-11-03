#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> arr;
  for(int i = 0; i < 7; i++){
    ll num;
    cin >> num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end());
  ll A = arr[0];
  ll B = arr[1];
  ll C = arr[6] - B - A;
  cout << A << " " << B << " " << C;
}