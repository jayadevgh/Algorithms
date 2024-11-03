#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int N; 
vector<char> v;
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for(int i = 0; i < N; i++){
  	char x; cin >> x;
  	v.push_back(x);
  }
  vector<int> pvec(N+1);
  vector<int> evec(N+1);
  vector<int> tvec(N+1);
  pvec[0] = 0;
  evec[0] = 0;
  tvec[0] = 0;
  for(int i = 1; i <= N; i++){
  	pvec[i] = pvec[i-1];
  	evec[i] = evec[i-1];
  	tvec[i] = tvec[i-1];
  	if(v[i-1] == 'E') pvec[i]++;
  	if(v[i-1] == 'T') evec[i]++;
  	if(v[i-1] == 'P') tvec[i]++;
  }
  // for(int i = 1; i <= N; i++){
  // 	cout << pvec[i] << " " << evec[i] << " " << tvec[i] << "\n";
  // }
  int ans =0;
  for(int i = 1; i <= N; i++) {
  	ans = max(ans, (pvec[i] + max((evec[N] - evec[i-1]), (tvec[N] - tvec[i-1]))));
  // 	cout << ans << "\n";
  }
  for(int i = 1; i <= N; i++) {
  	ans = max(ans, (evec[i] + max((pvec[N] - pvec[i-1]), (tvec[N] - tvec[i-1]))));
  	//cout << ans << "\n";
  }	
  for(int i = 1; i <= N; i++) {
  	ans = max(ans, (tvec[i] + max((evec[N] - evec[i-1]), (pvec[N] - pvec[i-1]))));
  }
  cout << ans;
}