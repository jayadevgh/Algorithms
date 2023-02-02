#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
void solve(){
  int n;
  cin >> n;
  int goal = n;
  int op = 0;
  priority_queue<int> pq;
  for(int i = 1; i < n+1; i++){
    int num;
    cin >> num;
    goal -= log2(num & -num);
    if(log2(i & -i) > 0) pq.push(log2(i & -i));
  }
  while(goal > 0){
    if(pq.empty()) {cout << -1 << "\n"; return;}
    goal -= pq.top();
    pq.pop();
    op++;
    
  }
  cout << op << '\n';
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}