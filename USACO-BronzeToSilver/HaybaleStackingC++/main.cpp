#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("stacking.in","r",stdin);
	freopen("stacking.out","w",stdout);
  int n, k;
  cin >> n >> k;
  vector<int> start(n, 0);
  vector<int> end(n, 0);
  vector<int> arr;
  for(int i = 0; i < k; i++){
    int a, b;
    cin >> a >> b;
    start[a-1]++;
    if(b < n) end[b]--;
  }
  arr.push_back(start[0] + end[0]);
  for(int i = 1; i < n; i++){
    start[i] += start[i-1];
    end[i] += end[i-1];
    arr.push_back(start[i] + end[i]);
  }
  sort(arr.begin(), arr.end());

  if (n%2== 0) cout<< (arr[n/2] + arr[(n/2) - 1])/2;
  else cout << arr[n/2];
  
}