#include <iostream>
#include <bits/stdc++.h>
#define ll long long 
#define iii pair<ll, pair<ll, ll>>
using namespace std;

int main() {
	//Console
	// freopen("meetings.in", "r", stdin);
	// freopen("meetings.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
  	ll N, L;
  	cin >> N >> L;

  	vector<ll> rightcol;
	vector<ll> leftcol;

  	vector<iii> arr;
  	ll sumweight = 0;
  	for(ll i =0;i  < N; i++){
  		ll w, p, d;
  		cin >> w >> p >> d;
  		iii trip = make_pair(p, make_pair(w, d));
  		arr.push_back(trip);
  		sumweight += w;
  	}
  	sort(arr.begin(), arr.end());
  	vector<iii> arr2 = arr;

  	ll idx =0;
  	for(ll i = 0; i < N; i++){
  		if(arr2[i].second.second == -1){
  			arr2[i].second.first = arr[idx].second.first;
  			idx++;
  		}
  	}
  	idx = N-1;
  	for(ll i = N-1; i >= 0; i--){
  		if(arr2[i].second.second == 1){
  			//cout << i;
  			arr2[i].second.first = arr[idx].second.first;
  			idx--;
  		}
  	}

  	vector<iii> arr3 = arr2;
  	for(ll i =0; i< N; i++){
  		if(arr2[i].second.second == 1) arr2[i].first = L-arr2[i].first;
  	}
  	sort(arr2.begin(), arr2.end());
  	ll time = 0;
  	ll tempsum = 0;
  	for(ll i = 0; i < N; i++){

  		tempsum += arr2[i].second.first;
  		if(tempsum >= sumweight/2){
  			time = arr2[i].first;
  			break;
  		}
  	}
  	priority_queue<ll> pq;

  	ll cols = 0;
  	vector<ll> leftpos;
	vector<ll> rightpos;
  	for(ll i =0;i < N; i++){
  		if(arr3[i].second.second == 1){
  			rightpos.push_back(arr3[i].first);
  		}
  		if(arr3[i].second.second == -1){
  			leftpos.push_back(arr3[i].first);
  		}
  	}
  	//cout << time << "\n";
  	// for(ll a : leftpos){
  	// 	cout << a << "\n";
  	// }
  	for(ll i =0;i < N; i++){
  		ll l;
  		ll r;
  		if(arr3[i].second.second == 1){
  			l = lower_bound(leftpos.begin(), leftpos.end(), arr3[i].first) - leftpos.begin();
  			r = upper_bound(leftpos.begin(), leftpos.end(), arr3[i].first + 2*time) - leftpos.begin();
  			cols += r-l;

  			//cout << "\n" << arr3[i].first << " " << arr3[i].first + time << "\n"; 
  			//cout << r << " " << l << "\n";
  		}



  		
  		// if(arr3[i].second.second == -1){
  		// 	l = lower_bound(leftpos.begin(), leftpos.end(), arr3[i].first - time) - leftpos.begin();
  		// 	r = upper_bound(leftpos.begin(), leftpos.end(), arr3[i].first) - leftpos.begin();
  		// }
  		
  	}
  	cout << cols;
  	// pq = priority_queue<ll>();
  	// for(ll i =0;i < N; i++){
  	// 	if(arr3[i].second.second == 1){
  	// 		pq.push(arr3[i].first + time);
  	// 		numR++;
  	// 	}

  	// 	while(pq.empty() == false && arr3[i].first > pq.top()){
  	// 		pq.pop();
  	// 		numR--;
  	// 	}
  	// 	if(arr3[i].second.second == -1){
  	// 		cols+= numR;
  	// 	}
  	// }
  	//cout << cols;


}