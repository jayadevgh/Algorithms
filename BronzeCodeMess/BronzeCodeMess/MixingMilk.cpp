#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<ll> A;
  vector<ll> C;
  ll c;
  ll a;
  for(int i = 0; i < 3; i++){
    cin >> c;
    cin >> a;
    C.push_back(c);
    A.push_back(a);
  }
  for(int i = 0; i < 100; i++){
    int idx = i%3;
    int nxt = (idx + 1)%3;
    ll amount = A[idx] + A[nxt];
    if(amount > C[nxt]){
      A[nxt] = C[nxt];
      A[idx] = amount-C[nxt];
    }
    else{
      A[idx] = 0;
      A[nxt] = amount;
    }
  }
  cout << A[0] << endl;
  cout << A[1] << endl;
  cout << A[2] << endl;
}