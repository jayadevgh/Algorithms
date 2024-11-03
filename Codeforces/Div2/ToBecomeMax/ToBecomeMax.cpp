#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define ll long long 



void solve(){
	ll n, k;
	cin >> n >> k;
	vector<ll> arr(n);
	ll maxi = 0;
	for(ll i =0; i < n; i++){ cin >> arr[i]; maxi = max(maxi, arr[i]); }
	vector<vector<ll>> sequences;
	vector<ll> temp;
	//temp.push_back(arr[n-1]);
	for(ll i =n-1; i >0; i--){
		vector<ll> tem;
		// temp = tem;
		temp.push_back(arr[i]); //cout << arr[i] << "\n";
		ll tempi = i-1;
		ll inc = 1; 
		while(tempi >= 0 && temp[0]+ inc >= arr[tempi] ){
			temp.push_back(arr[tempi]);
			inc++;
			tempi--;
		}
		reverse(temp.begin(), temp.end());
		sequences.push_back(temp);
		// for(ll z : temp) cout << z << " ";
		// cout << "\n";
		temp =tem;
		//temp.resize(0);

	}	
	if(temp.size() > 0) sequences.push_back(temp);
	for(vector<ll> x : sequences){
		// for(ll z : x) cout << z << " ";
		// cout << "\n";
		// vector<ll> x2 = x;
		//ll tempk = k;
		
		if(x.size() > 1){
			// for(ll i= x.size()-2; i >=0; i--){

			// 	tempk -= x[i+1]+1 - x[i];
			// 	x[i] = x[i+1]+1;
			// 	if(tempk < 0) break;
			// 	maxi = max(maxi, x[i]);
			// 	//if(maxi == 7) //cout << x[i];
			// 	// if(i>0){
			// 	// 	tempk2 -= x2[i-1] - x2[i];
			// 	// 	x2[i] = x2[i-1];
			// 	// 	if(tempk2 < 0) break;
			// 	// 	maxi = max(maxi, x2[i]);
			// 	// }
			// 	// tempk2 = max(tempk, tempk2);
			// }
			ll sum = 0;
			for(ll i =0 ;i < x.size()-1; i++) sum += x[i];

			for(ll i =0;i < x.size()-1; i++){
				ll k2 = k;
				ll hi = x[x.size()-1] + x.size()-i-1;
				ll lo = x[i];
				ll mid = (hi+lo)/2;
				while(lo <= hi){
					mid = (hi+lo)/2;
					ll dist = x.size()-1-i;
					ll sum2 = ((mid) * (mid+1))/2;
					sum2 -= ((mid-dist)* (mid-dist+1))/2;

					if(sum2-sum <= k){
						lo = (lo == mid)+mid;
						if(sum2-sum < 0) cout << sum2 << " " << sum << " " << lo << " | ";
					}else{
						hi = mid-1;
					}
					
				}
				maxi = max(maxi, hi);
				cout << "\n";
				sum -= x[i];

			}
			
		}
		//cout << "\n\n";
		//else cout << x.size() << " ";
	}
	cout << maxi << "\n";
}

int main() {
  //Console
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll t;
  cin >> t;
  for(ll i = 0; i < t; i++) solve();
}