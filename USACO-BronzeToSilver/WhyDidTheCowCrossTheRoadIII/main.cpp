#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cowqueue.in","r",stdin);
	freopen("cowqueue.out","w",stdout);

  int n;
  cin >> n;
  vector<tuple<int, int>> cows;
  for(int i = 0; i < n; i++){
    int arrive;
    int length;
    cin >> arrive >> length;
    cows.push_back({arrive, length});
  }
  sort(cows.begin(), cows.end());

  int time = 0;
  for(int i = 0; i < n; i++){
    time = max(time, get<0>(cows[i]));
    time += get<1>(cows[i]);
  }
  cout << time << endl;
}