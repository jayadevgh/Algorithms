#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
  int n, q;
  cin >> n >> q;
  ll sum = 0;
  int evennum = 0;
  int oddnum = 0;
  for(int i = 0; i < n; i++){
    ll num;
    cin >> num;
    sum += num;
    if(num%2==0) evennum++; 
    else oddnum++;
  }
  for(int i = 0; i < q; i++){
    ll type, x;
    cin >> type >> x;
    if(type == 0){
      sum += x * evennum;
      if(x % 2 == 1){
        oddnum += evennum;
        evennum = 0;
      }
    }
    if(type == 1){
      sum += x*oddnum;
      if(x % 2 == 1){
        evennum += oddnum;
        oddnum = 0;
      }
    }
    cout << sum << "\n";
    
  }
  
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}