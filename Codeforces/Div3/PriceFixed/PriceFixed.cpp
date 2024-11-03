#include <iostream>
#include <bits/stdc++.h>
#define ll long long int
#define pll pair<ll, ll>
using namespace std;


int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pll> arr;
  ll ans = 0;
  for(int i =0; i < n; i++){
  	ll a, b;
  	cin >> a >> b;
  	arr.push_back(make_pair(b, a));
  	ans += a;
  }
  sort(arr.begin(), arr.end());
  ll count = 0;
  ans *= 2;
  ll tot = ans/2;
  for(int i = 0; i < n; i++){
  	if(count <= arr[i].first) count = arr[i].first;
  	if(count >= tot) break;
  	count += arr[i].second;
  	ans -= arr[i].second;
  	if(count >= tot) {
  		ans += count - tot;
  		count -=(count - tot);
  		
  		//cout << count << " " << ans << "\n";
  		break;
  	}
  	//cout << count << " " << ans << "\n";
  }
  cout << ans;
}