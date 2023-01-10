#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void solve(){
  int n, s;
  cin >> n >> s;
  priority_queue<int, vector<int>, greater<int>> pq;
  for(int i = 0; i < n; i++){
    int num;
    cin >> num;
    pq.push(num);
  }
  int count = 1;
  while(!pq.empty()){
    
    if(pq.top() == count){
      pq.pop();
      
    }
    else{
      s -= count;
    }
    count++;
  }
  while(s > 0){
    s -= count;
    count++;
  }
  if(s < 0) cout << "NO\n";
  else cout << "YES\n";
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t; 
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}