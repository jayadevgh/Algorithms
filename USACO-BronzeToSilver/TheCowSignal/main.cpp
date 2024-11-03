#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("cowsignal.in","r",stdin);
	freopen("cowsignal.out","w",stdout);
  int M, N, K;
  cin >> M >> N >> K;
  for(int i = 0; i < M; i++){
    string str;
    cin >> str;
    string ans = "";
    
    for(int j = 0; j < N; j++){
      for(int l = 0; l < K; l++){
        ans.push_back(str[j]);
      }
    }
    for(int o = 0; o < K; o++){
      cout << ans << "\n";
    }
  }
}