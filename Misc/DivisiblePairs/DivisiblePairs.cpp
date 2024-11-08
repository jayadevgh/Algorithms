#include <iostream>
#include <bits/stdc++.h>

using namespace std;


void solve(){
	long long n, x, y; cin >> n >> x >> y;
	vector<long long> arr(n);
	vector<long long> modx(n);
	vector<long long> mody(n);
	for(long long i =0;i < n; i++){
		cin >> arr[i];
		modx[i] = arr[i] % x;
		mody[i] = arr[i] % y;
	}
	multiset<pair<long long, long long>> addsub;
	addsub.insert(make_pair(arr[0] % x, arr[0] % y));
	// map<pair<long long, long long>, long long> addsub;
	// addsub[make_pair(modx[0], mody[0])]++;
	long long ans =0;
	for(long long i =1; i< n; i++){
		ans += addsub.count(make_pair(((x-(arr[i] % x))%x), arr[i] % y));
		addsub.insert(make_pair(arr[i] % x, arr[i] % y));
		// ans += addsub[make_pair((x-modx[i])%x, mody[i])];
		// addsub[make_pair(modx[i], mody[i])]++;

	}
	cout << ans << "\n";
}
int main() {
	//Console
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	long long t; cin >> t;
  	for(long long i =0 ;i < t ;i++) solve();
}