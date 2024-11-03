#include <iostream>
#include <bits/stdc++.h>
#define ll long long
using namespace std;
int N, K; 
const ll MAX_N = 1e9;
vector<int> v;
bool valid(int x){
	int temp = K - 1;
	int range = v[0] + 2 * x;
	for(int i = 0; i < N; i++){
		if(range < v[i]){range = v[i] + 2*x; temp--;}
		if(temp < 0) return false;
	}
	return true;
}
int bs(){
	ll lo = 0;
	ll hi = MAX_N;
	while(lo < hi){
		ll mid = lo + (hi - lo)/2;
		if(valid(mid)) hi = mid;
		else lo = mid+1;
	}
	return lo;
}
int main() {

  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N >> K;
  v.resize(N);
  for(int i = 0; i < N; i++){
  	cin >> v[i];
  }
  sort(v.begin(), v.end());
  cout << bs();
}