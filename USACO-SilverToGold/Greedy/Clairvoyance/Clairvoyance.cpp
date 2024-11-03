#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> nums(2 * N);
  int x = 2* N;
  generate(nums.begin(), nums.end(), [&x]{ return x--;});
  priority_queue<int> pq;
  set<int> s;
  for(int i = 0; i < N; i++){
    cin >> x;
    pq.push(x);
    s.insert(x);
  }

  int ans = 0;
  int val = pq.top();
  // for(int i = 0; i < nums.size(); i++){
  //   cout << nums[i] << "\n";
  // }
  for(int i =0; i < 2 * N; i++){
    //cout << nums[i] << " " << val << "\n";
    if(s.find(nums[i]) != s.end()){if(val == nums[i]) pq.pop(); else continue;}
    else if(nums[i] > val) { ans++;pq.pop();}
    if(pq.size() == 0) break;
    val = pq.top();
  }
  cout << ans;
}