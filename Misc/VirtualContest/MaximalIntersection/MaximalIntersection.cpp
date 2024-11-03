#include <iostream>
#include <bits/stdc++.h>
#define ii pair<int, int>
using namespace std;


int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n; cin >> n;
  vector<ii> starts;
  vector<ii> ends;
  for(int i =0;i < n; i++){
  	int a, b;
  	cin >> a >> b;
  	starts.push_back(make_pair(a, b));
  	ends.push_back(make_pair(b, a));
  }
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  int cur = max(0, ends[0].first - starts[starts.size()-1].first);
  bool check = true;
  //ii temp = make_pair(ends[0].second, ends[0].first);
  if(starts[starts.size()-1].second == ends[0].first){
  	check = false;
  	cur = max(cur, ends[1].first - starts[starts.size()-2].first);

  }else{
  	cur = max(cur, ends[0].first - starts[starts.size()-2].first);
  }
  if(check){
  	cur = max(cur, ends[1].first - starts[starts.size()-1].first);
  }

  cout << cur;
}