#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for(int i = 0; i < n; i++){
    priority_queue<int> pq;
    int a, b, c;
    cin >> a >> b >> c;
    pq.push(a);
    pq.push(b);
    pq.push(c);
    int sum = pq.top();
    pq.pop();
    a = pq.top();
    pq.pop();
    b = pq.top();
    if(sum == a+ b) cout << "YES";
    else cout << "NO";
    cout << "\n";
  }
}