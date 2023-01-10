#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll divs(ll n, priority_queue<ll, vector<ll>, greater<ll>> pq){
  ll ans = 0;
  if (n == 1) return pq.top();
  while(pq.size() > 1){
    ll num = pq.top();
    pq.pop();
    num += pq.top();
    pq.pop();
    ans += num;
    pq.push(num);
  }
  return ans;
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll x, n;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  cin >> x >> n;
  for (ll i =0; i<n; i++){
    ll num; 
    cin >> num;
    pq.push(num);
  }
  cout << divs(n, pq);
}