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
    pq.pop();
    cout << pq.top() << "\n";
  }
}