#include <iostream>
#include <bits/stdc++.h>
#define lli long long int
using namespace std;


void solve(){
	int n; cin >> n;
	vector<int> arr(n);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	lli ans = LLONG_MIN;
	//cout << (long long int)1000000000 * 910000000;
	lli maxn = LLONG_MIN;
	lli maxn2 = LLONG_MIN;
	lli minn = LLONG_MAX;
	lli minn2 = LLONG_MAX;
	for(int i = 0; i < n; i++){
		if(maxn < arr[i]) {maxn2 = maxn; maxn = arr[i];}
		else if(maxn2 < arr[i]) maxn2 = arr[i];
		if(arr[i] < minn) {minn2 = minn; minn = arr[i];}
		else if(arr[i] < minn2) minn2 = arr[i];
	}
	ans = max(maxn2 * maxn, minn * minn2);
	cout << ans << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for(int i = 0; i < t; i++){solve();}
}