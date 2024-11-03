#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct cow{
  ll x, d, w;
}
int main() {
  freopen("meetings.in","r",stdin);
	freopen("meetings.out","w",stdout);
  int n, l;
  cin >> n >> l;
  vector<cow> cows(n);

  ll sum = 0;
  ll plus = 0;
  for(int i = 0; i < n; i++){
    cin >> cows[i].x >> cows[i].d >> cows[i].w;
    sum += cows[i].w;
    if (cows[i].d == 1) plus++;
  }
  sort(cows.begin(), cows.end());
  vector<pair<int, int>> reach_barn(n);
  int left_barn = 0;
  int right_barn = n - plus;
  for(int i =0; i < n; i++){
    if(cows[i].d== -1){
      reach_barn[i] = {cows[i].x, cows[left_barn].w};
      left_barn++;
    } else {
      reach_barn[i] = {cows[l - i].x, cows[right_barn].w};
      right_barn++;
    }
  }

  sort(reach_barn.begin(), reach_barn.end());
  ll cur_sum = 0;
  int T = 0;
  int k = 0;
  while(k < n &&)
}