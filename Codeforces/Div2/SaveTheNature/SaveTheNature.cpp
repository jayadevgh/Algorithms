#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define llll pair<pair<ll, ll>, pair<ll, ll>>
using namespace std;

void solve(){
	ll n;
	cin >> n;
	vector<ll> arr(n);
	for(ll i =0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end(), greater<>());
	ll x, a, y, b, k;
	cin >> x >> a >> y >> b >> k;


	vector<ll> prefixArr(n+1);
	prefixArr[0] =0;
	for(ll i =0;i < n; i++){
		prefixArr[i+1] = prefixArr[i] + arr[i];
	}


	vector<llll> indices;
	indices.push_back(make_pair(make_pair(0, 0), make_pair(0, 0)));

	llll quadP = indices[0];
	for(ll i = 1; i <= n; i++){
		if(i%a == 0 && i%b == 0) {
			//quadP = indices[indices.size() -1];
			quadP.first.first = i;
			quadP.first.second++;
			indices.push_back(quadP);
		}
		else if(i%a == 0 ) {
			//quadP = indices[indices.size() -1];
			quadP.first.first = i;
			quadP.second.first++;
			indices.push_back(quadP);
		}
		else if(i%b == 0) {
			//quadP = indices[indices.size() -1];
			quadP.first.first = i;
			quadP.second.second++;
			indices.push_back(quadP);
		}
	}

	// for(llll pr : indices) cout << pr.first.first << " " << pr.first.second << " " << pr.second.first << " " << pr.second.second << "\n";
	// cout << "\n";
	ll sz = indices.size()-1;
	// cout << indices[sz].first.second << " " << indices[sz].second.first << " " << indices[sz].second.second;
	ll checker = 0;
	ll lo = 1;
	ll hi = indices.size();
	ll mid;
	while(lo < hi){
		mid = (lo + hi)/2;
		ll tot = 0, pos = 0, prevpos = 0;
		pos += indices[mid].first.second;
		tot += (prefixArr[pos] / 100) * (x+y);//cout << tot << " ";

		if(x >= y){
			prevpos = pos;
			pos += indices[mid].second.first;
			tot += ((prefixArr[pos] - prefixArr[prevpos]) / 100) * (x);//cout << tot << " ";
			prevpos = pos;	
			pos += indices[mid].second.second;
			tot += ((prefixArr[pos] - prefixArr[prevpos]) / 100) * (y);//cout << tot << " ";
		}
		else if(y > x){
			prevpos = pos;
			pos += indices[mid].second.second;
			tot += ((prefixArr[pos] - prefixArr[prevpos]) / 100) * (y);//cout << tot << " ";
			prevpos = pos;	
			pos += indices[mid].second.first;
			tot += ((prefixArr[pos] - prefixArr[prevpos]) / 100) * (x);//cout << tot << " ";
		}
		//cout << tot << " " << pos << "\n";
		checker = max(checker, tot);
		if(tot >= k){
			hi = mid;
		}else{
			lo = mid+1;
		}
	}
	if(checker < k) cout << -1 << "\n";
	else{
		cout << indices[lo].first.first << "\n";
	}
}
int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll q; cin >> q;
  for(ll i= 0; i < q; i++) solve();
}
